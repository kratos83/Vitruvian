#!/bin/sh

qemu_inject() {
    _chroot_dir="$1"
    _target_arch="$2"
    if ! is_cross_build "$_target_arch"; then
        return 0
    fi
    _qemu_bin="$(find_qemu_user_binary "$_target_arch")"
    _qemu_name="$(basename "$_qemu_bin")"
    log_info "Cross-build detected: injecting $_qemu_name into chroot"
    sudo cp "$_qemu_bin" "$_chroot_dir/usr/bin/$_qemu_name"
    sudo chmod +x "$_chroot_dir/usr/bin/$_qemu_name"
    register_binfmt
}

qemu_eject() {
    _chroot_dir="$1"
    _target_arch="$2"
    if ! is_cross_build "$_target_arch"; then
        return 0
    fi
    _qemu_name="$(arch_to_qemu_user "$_target_arch")"
    sudo rm -f "$_chroot_dir/usr/bin/$_qemu_name" \
        "$_chroot_dir/usr/bin/${_qemu_name%-static}" 2>/dev/null || true
}

# Debian mirror for debootstrap/apt in the chroot; override with DEBIAN_MIRROR.
: "${DEBIAN_MIRROR:=http://deb.debian.org/debian/}"

# Debian suite for the chroot and board rootfs; only trixie is proven.
: "${VOS_BASE_SUITE:=trixie}"

# Persistent per-arch .deb cache shared across chroot regenerations.
chroot_cache_dir() {
    echo "$1/deb"
}

chroot_mount() {
    _chroot_dir="$1"
    [ -d "$_chroot_dir" ] || die "Chroot directory not found: $_chroot_dir"

    sudo mkdir -p "$_chroot_dir/proc" "$_chroot_dir/sys" "$_chroot_dir/dev"

    if ! mountpoint -q "$_chroot_dir/proc" 2>/dev/null; then
        sudo mount -t proc / "$_chroot_dir/proc"
    fi
    if ! mountpoint -q "$_chroot_dir/sys" 2>/dev/null; then
        sudo mount --rbind /sys "$_chroot_dir/sys"
        sudo mount --make-rslave "$_chroot_dir/sys"
    fi
    if ! mountpoint -q "$_chroot_dir/dev" 2>/dev/null; then
        sudo mount --rbind /dev "$_chroot_dir/dev"
        sudo mount --make-rslave "$_chroot_dir/dev"
    fi

    # Provision DNS so `apt update` inside the chroot can reach the mirrors.
    # -L dereferences the host's systemd-resolved stub symlink.
    sudo mkdir -p "$_chroot_dir/etc"
    sudo cp -L /etc/resolv.conf "$_chroot_dir/etc/resolv.conf"
}

# chroot_isolated ROOT CMD [ARGS...]
# Runs CMD chrooted into ROOT with its own network, hostname, IPC, PID and mount namespaces and a
# read-only /proc/sys and /sys, so maintainer scripts cannot touch the host. /dev stays the host's.
_CHROOT_ISOLATED_INNER='r="$1"; shift
ip link set lo up 2>/dev/null
mount -t proc proc "$r/proc" || exit 1
mount --bind "$r/proc/sys" "$r/proc/sys" || exit 1
mount -o remount,bind,ro "$r/proc/sys" || exit 1
if mountpoint -q "$r/sys"; then umount -R "$r/sys" || exit 1; fi
mount -t sysfs -o ro sysfs "$r/sys" || exit 1
exec chroot "$r" "$@"'

chroot_isolated() {
    _ci_root="$1"
    shift
    sudo mkdir -p "$_ci_root/proc" "$_ci_root/sys"
    sudo unshare --net --uts --ipc --pid --fork --mount --propagation private \
        /bin/sh -c "$_CHROOT_ISOLATED_INNER" sh "$_ci_root" "$@"
}

chroot_umount() {
    _chroot_dir="$1"
    [ -d "$_chroot_dir" ] || return 0

    sudo umount -l "$_chroot_dir/var/cache/apt/archives" 2>/dev/null || true
    sudo umount -l "$_chroot_dir/proc" 2>/dev/null || true
    sudo umount -l "$_chroot_dir/sys" 2>/dev/null || true
    #sudo umount -l "$_chroot_dir/dev/pts" 2>/dev/null || true
    sudo umount -l "$_chroot_dir/dev" 2>/dev/null || true
}

# chroot_exec_build CHROOT_PATH REPO_ROOT -- <command...>
#
# Runs <command...> inside CHROOT_PATH, with REPO_ROOT (the whole repo,
# generated.<arch>/ included) bind-mounted at the fixed internal path
# /build/vos -- fixed rather than mirroring the host's own clone path, so
# every path cmake/ninja bake into CMakeCache.txt/build.ninja is the same
# regardless of where the repo happens to live on a given machine.
#
# REPO_ROOT physically contains generated.<arch>/image_tree/chroot (= this
# very CHROOT_PATH), so the bind mount's target ends up nested inside its
# own source -- the same self-referential mount create_iso already does
# (see "mount -o bind ... $_chroot_dir/tmp" above) and has shipped safely
# with, because nothing recursively walks the whole tree past that
# mountpoint. cmake/ninja work off explicit file lists, not blind
# recursive scans, so this is safe the same way -- just never run a bare
# `find`/`cp -r` over /build/vos from the host side without -xdev.
#
# Unlike chroot_isolated(), this does NOT isolate net/PID/UTS or remount
# /proc/sys read-only -- that part of chroot_isolated's isolation exists
# to contain untrusted Debian maintainer scripts during package install,
# and would only get in the way of an ordinary compile (which may well
# want real network access, and isn't a security boundary issue).
#
# It DOES still run in its own private MOUNT namespace (via unshare), same
# as chroot_isolated -- not for containment, but so every mount made here
# (the /build/vos bind, chroot_mount's proc/sys/dev, and critically any
# *nested* mount a step running under this -- e.g. nexus-dkms's own
# build-nexus-dkms-chroot.sh, invoked by ninja while already inside this
# chroot -- makes on its own) is torn down automatically the moment this
# process tree exits, success or crash, without ever becoming visible to
# the host's real mount table. Relying on a trap for cleanup instead (as
# an earlier version of this function did) leaves a window where a nested
# `sudo mount --bind` from deep inside a long `ninja` run shares the
# host's mount namespace -- exactly the kind of leak that must not happen
# for something that runs for the entire length of a build, not a quick
# admin command.
_CHROOT_EXEC_BUILD_INNER='_mnt="$1"; _repo="$2"; _root="$3"; shift 3
mkdir -p "$_mnt" || exit 1
mount --bind "$_repo" "$_mnt" || exit 1
mkdir -p "$_root/proc" "$_root/sys" "$_root/dev" || exit 1
mountpoint -q "$_root/proc" || { mount -t proc proc "$_root/proc" || exit 1; }
mountpoint -q "$_root/sys" || { mount --rbind /sys "$_root/sys" || exit 1; }
mountpoint -q "$_root/dev" || { mount --rbind /dev "$_root/dev" || exit 1; }
cp -L /etc/resolv.conf "$_root/etc/resolv.conf" 2>/dev/null || true
exec chroot "$_root" /usr/bin/env PATH=/usr/sbin:/usr/bin:/sbin:/bin "$@"'

chroot_exec_build() {
    _ceb_chroot="$1"; shift
    _ceb_repo="$1"; shift
    [ "$1" = "--" ] && shift

    [ -d "$_ceb_chroot" ] || die "Chroot directory not found: $_ceb_chroot"
    [ -d "$_ceb_repo" ] || die "Repo root not found: $_ceb_repo"

    sudo unshare --mount --propagation private \
        /bin/sh -c "$_CHROOT_EXEC_BUILD_INNER" sh \
        "$_ceb_chroot/build/vos" "$_ceb_repo" "$_ceb_chroot" "$@"
}

# create_iso purges the -dev packages from the chroot it squashes; put
# back whatever is missing before compiling. The .deb cache makes it an unpack.
chroot_restore_dev_packages() {
    _crd_basedir="$1"
    _crd_arch="$2"
    _crd_dir="$_crd_basedir/image_tree/chroot"
    [ -d "$_crd_dir" ] || return 0
    # Installed names plus what they provide (libfreetype6-dev is only provided).
    _crd_have="$(dpkg-query --admindir="$_crd_dir/var/lib/dpkg" -W \
        -f='${db:Status-Abbrev} ${Package},${Provides}\n' 2>/dev/null \
        | awk '$1 == "ii" { sub(/^ii +/, ""); n = split($0, a, ","); \
            for (i = 1; i <= n; i++) { sub(/^ +/, "", a[i]); sub(/ .*/, "", a[i]); \
            if (a[i] != "") print a[i] } }')"
    _crd_missing=""
    for _p in $(get_dev_packages "$_crd_arch"); do
        printf '%s\n' "$_crd_have" | grep -qx "$_p" || _crd_missing="$_crd_missing $_p"
    done
    [ -n "$_crd_missing" ] || return 0
    log_step "Reinstalling build packages:$_crd_missing"
    qemu_inject "$_crd_dir" "$_crd_arch"
    chroot_mount "$_crd_dir"
    chroot_mount_deb_cache "$_crd_dir" "$(chroot_cache_dir "$_crd_basedir")"
    sudo chroot "$_crd_dir" /usr/bin/env $CHROOT_PROXY DEBIAN_FRONTEND=noninteractive LC_ALL=C.UTF-8 \
        apt-get install -y --download-only --no-install-recommends $_crd_missing \
        || die "build package download failed"
    chroot_isolated "$_crd_dir" /usr/bin/env $CHROOT_PROXY DEBIAN_FRONTEND=noninteractive LC_ALL=C.UTF-8 \
        apt-get install -y --no-install-recommends $_crd_missing \
        || die "build package reinstall failed"
    chroot_umount "$_crd_dir"
    qemu_eject "$_crd_dir" "$_crd_arch"
}

# Bind the persistent .deb cache into the chroot. Idempotent.
chroot_mount_deb_cache() {
    _chroot_dir="$1"
    _cache_dir="$2"
    sudo mkdir -p "$_cache_dir/archives/partial"
    sudo mkdir -p "$_chroot_dir/var/cache/apt/archives"
    if ! mountpoint -q "$_chroot_dir/var/cache/apt/archives" 2>/dev/null; then
        sudo mount --bind "$_cache_dir/archives" \
            "$_chroot_dir/var/cache/apt/archives"
    fi
    # Keep downloaded .debs (default drops them after install), via a drop-in config.
    sudo mkdir -p "$_chroot_dir/etc/apt/apt.conf.d"
    echo 'Binary::apt::APT::Keep-Downloaded-Packages "true";' \
        | sudo tee "$_chroot_dir/etc/apt/apt.conf.d/99-keep-debs" >/dev/null
    cat <<'EOF' | sudo tee "$_chroot_dir/etc/apt/apt.conf.d/90-vos-gzip-indexes" >/dev/null
Acquire::GzipIndexes "true";
Acquire::CompressionTypes::Order { "gz"; };
EOF
}

chroot_create() {
    _basedir="$1"
    _arch="$2"
    _deb_arch="$(arch_to_deb "$_arch")"
    _chroot_dir="$_basedir/image_tree/chroot"

    if [ -d "$_chroot_dir" ]; then
        die "A chroot already exists at $_chroot_dir. Run bake.sh --regenerate-chroot to recreate it."
    fi

    mkdir -p "$_basedir/image_tree"

    _cache_dir="$(chroot_cache_dir "$_basedir")"
    _debootstrap_cache="$_cache_dir/debootstrap"
    sudo mkdir -p "$_debootstrap_cache" "$_cache_dir/archives/partial"
    log_info "Using package cache: $_cache_dir (mirror: $DEBIAN_MIRROR)"

    if is_cross_build "$_arch"; then
        log_step "Bootstrapping Debian $VOS_BASE_SUITE ($_deb_arch) [foreign]..."
        sudo debootstrap --arch="$_deb_arch" --variant=minbase --foreign \
            --cache-dir="$_debootstrap_cache" \
            "$VOS_BASE_SUITE" "$_chroot_dir" "$DEBIAN_MIRROR"
        qemu_inject "$_chroot_dir" "$_arch"
    else
        log_step "Bootstrapping Debian $VOS_BASE_SUITE ($_deb_arch)..."
        sudo debootstrap --arch="$_deb_arch" --variant=minbase \
            --cache-dir="$_debootstrap_cache" \
            "$VOS_BASE_SUITE" "$_chroot_dir" "$DEBIAN_MIRROR"
    fi

    trap 'chroot_umount "$_chroot_dir"' EXIT
    chroot_mount "$_chroot_dir"
    chroot_mount_deb_cache "$_chroot_dir" "$_cache_dir"

    # Pin apt to the debootstrap mirror.
    : "${DEBIAN_SECURITY_MIRROR:=http://security.debian.org/debian-security}"
    sudo tee "$_chroot_dir/etc/apt/sources.list" >/dev/null <<EOF
deb $DEBIAN_MIRROR $VOS_BASE_SUITE main contrib non-free non-free-firmware
deb $DEBIAN_MIRROR $VOS_BASE_SUITE-updates main contrib non-free non-free-firmware
deb $DEBIAN_SECURITY_MIRROR $VOS_BASE_SUITE-security main contrib non-free non-free-firmware
EOF

    # Written only when a key is supplied: an unverifiable repo fails the
    # whole apt update, taking Debian access down with it.
    : "${VOS_REPO_URL:=https://repo.v-os.dev}"
    if [ -n "${VOS_REPO_KEY:-}" ] && [ -f "$VOS_REPO_KEY" ]; then
        # No default suite on purpose: a stale default once resolved to a retired suite.
        [ -n "${VOS_REPO_SUITE:-}" ] || die "VOS_REPO_SUITE is unset and a repo key was supplied; name the suite to install from (trixie, testing, trixie-nightly, testing-nightly)"
        sudo install -d -m 755 "$_chroot_dir/etc/apt/keyrings"
        sudo install -m 644 "$VOS_REPO_KEY" \
            "$_chroot_dir/etc/apt/keyrings/vitruvian-archive-keyring.asc"
        sudo install -d -m 755 "$_chroot_dir/etc/apt/sources.list.d"
        sudo tee "$_chroot_dir/etc/apt/sources.list.d/vitruvian.sources" >/dev/null <<VOSEOF
Types: deb
URIs: $VOS_REPO_URL
Suites: $VOS_REPO_SUITE
Components: main
Signed-By: /etc/apt/keyrings/vitruvian-archive-keyring.asc
VOSEOF
        log_info "VitruvianOS repo enabled: $VOS_REPO_URL $VOS_REPO_SUITE"
    else
        log_warn "VOS_REPO_KEY unset or missing; image will NOT see the VitruvianOS repo"
    fi

    log_step "Verifying mount points before second-stage..."
    log_info "Checking proc: mountpoint=$(mountpoint -q "$_chroot_dir/proc" 2>/dev/null && echo yes || echo no), stat=$([ -f "$_chroot_dir/proc/1/stat" ] && echo exists || echo missing)"
    if mountpoint -q "$_chroot_dir/proc" 2>/dev/null; then
        log_info "proc mounted"
    elif [ -f "$_chroot_dir/proc/1/stat" ]; then
        log_info "proc accessible"
    else
        die "proc mount failed - cannot proceed with second-stage"
    fi
    mountpoint -q "$_chroot_dir/sys" || die "sys mount failed"
    mountpoint -q "$_chroot_dir/dev" || die "dev mount failed"

    if is_cross_build "$_arch"; then
        # Second stage unpacks from /var/cache/apt/archives, bound to $_cache_dir/archives.
        sudo sh -c 'cp -n "$1"/*.deb "$2"/ 2>/dev/null || true' _ \
            "$_debootstrap_cache" "$_cache_dir/archives"
        log_step "Running debootstrap second stage..."
        chroot_isolated "$_chroot_dir" /debootstrap/debootstrap --second-stage
        log_step "Re-mounting after second-stage..."
        chroot_mount "$_chroot_dir"
    fi

    log_step "Verifying mount points after second-stage..."
    if mountpoint -q "$_chroot_dir/proc" 2>/dev/null; then
        log_info "proc mounted"
    elif [ -f "$_chroot_dir/proc/1/stat" ]; then
        log_info "proc accessible"
    else
        log_warn "proc mount may have failed - continuing anyway"
    fi

    log_step "Creating essential directories..."
    sudo mkdir -p "$_chroot_dir/dev"
    sudo mkdir -p "$_chroot_dir/proc"
    sudo mkdir -p "$_chroot_dir/sys"
    sudo mkdir -p "$_chroot_dir/run"
    sudo mkdir -p "$_chroot_dir/tmp"
    for _d in dev/hugepages dev/mqueue run/lock \
              sys/kernel/debug sys/kernel/tracing \
              sys/fs/fuse/connections sys/kernel/config; do
        sudo mkdir -p "$_chroot_dir/$_d"
    done

    _base_pkgs="$(get_base_packages "$_arch")"
    _dev_pkgs="$(get_dev_packages "$_arch")"

    log_step "Installing packages..."
    # Skip dpkg fsyncs on a throwaway chroot; opt-in.
    if [ "${VOS_UNSAFE_IO:-0}" = 1 ]; then
        sudo install -d -m 755 "$_chroot_dir/etc/dpkg/dpkg.cfg.d"
        printf 'force-unsafe-io\n' \
          | sudo tee "$_chroot_dir/etc/dpkg/dpkg.cfg.d/vos-build-unsafe-io" >/dev/null
    fi
    # chroot() doesn't reset PATH — it inherits whatever the host shell (and
    # sudo) had, which may lack /usr/sbin even though that's where Debian
    # ships sbin-only binaries like locale-gen in a non-merged-usr chroot.
    # Set it explicitly so lookups resolve against the guest, not the host.
    _vos_chroot_path="/usr/sbin:/usr/bin:/sbin:/bin"
    # Download with the network, install isolated: cups-pdf's postinst ran lpadmin against the host's cupsd.
    sudo chroot "$_chroot_dir" /usr/bin/env $CHROOT_PROXY PATH="$_vos_chroot_path" DEBIAN_FRONTEND=noninteractive LC_ALL=C.UTF-8 /bin/bash -c "\
echo 'vitruvian' > /etc/hostname && \
apt update && apt install -y --download-only --no-install-recommends $_base_pkgs $_dev_pkgs \$DEBUG_PACKAGES"
    if [ "${VOS_NATIVE_UNPACK:-0}" = 1 ]; then
        # Unpack with the host dpkg (no emulation); configure stays in-chroot.
        # Any refusal falls back to the emulated apt transaction.
        _native_ok=0
        if native_pkg_unpack "$_chroot_dir" \
           && chroot_isolated "$_chroot_dir" /usr/bin/env $CHROOT_PROXY PATH="$_vos_chroot_path" DEBIAN_FRONTEND=noninteractive LC_ALL=C.UTF-8 /bin/bash -c "\
dpkg --configure -a && \
echo 'en_US.UTF-8 UTF-8' > /etc/locale.gen && locale-gen && \
exit"; then
            _native_ok=1
        else
            log_warn "native unpack path failed — falling back to emulated apt install"
        fi
    fi
    if [ "${_native_ok:-0}" = 0 ]; then
        chroot_isolated "$_chroot_dir" /usr/bin/env $CHROOT_PROXY PATH="$_vos_chroot_path" DEBIAN_FRONTEND=noninteractive LC_ALL=C.UTF-8 /bin/bash -c "\
apt install -y --no-install-recommends $_base_pkgs $_dev_pkgs \$DEBUG_PACKAGES && \
echo 'en_US.UTF-8 UTF-8' > /etc/locale.gen && locale-gen && \
exit"
    fi

    ls "$_chroot_dir/lib/modules" | head -n1 > "$_basedir/imagekernelversion.conf"

    qemu_eject "$_chroot_dir" "$_arch"
    chroot_umount "$_chroot_dir"

    log_info "Chroot created at $_chroot_dir"
}

chroot_regenerate() {
    _basedir="$1"
    _arch="$2"
    _chroot_dir="$_basedir/image_tree/chroot"

    if [ -d "$_chroot_dir" ]; then
        log_step "Regenerating chroot..."
        chroot_umount "$_chroot_dir"
        # A bind mount still attached would let rm reach the host.
        if findmnt -rn -o TARGET | grep -qF "$_chroot_dir/"; then
            die "Still mounted under $_chroot_dir; unmount it and retry."
        fi
        sudo rm -rf --one-file-system "$_chroot_dir"
    fi

    chroot_create "$_basedir" "$_arch"
}
