#!/bin/sh
# build-nexus-dkms-chroot.sh CHROOT_PATH PKG_SRCDIR
#
# Runs `dpkg-buildpackage -uc -us` for nexus-dkms inside CHROOT_PATH instead
# of on the bare host. VITRUVIAN_CHROOT_BUILD exists precisely because the
# host (e.g. an Arch machine) has no reason to carry Debian-only build
# dependencies like debhelper/dkms -- those live in the chroot's sysroot
# already (see get_dev_packages in lib/packages.sh). Bare dpkg-buildpackage
# on the host fails there with "unmet build dependencies".
#
# PKG_SRCDIR is the package root (contains debian/), e.g.
# .../src/system/kernel/nexus. Its parent is bind-mounted into the chroot so
# dpkg-buildpackage's own convention -- build products land one directory
# above the source tree -- writes straight back to the host through the
# bind mount; no separate copy-out step is needed.
#
# Foreign-arch chroots (e.g. an arm64 chroot on an amd64 host) are not
# handled here: running debhelper/perl inside one needs qemu-user binfmt
# registered (lib/chroot.sh's qemu_inject, ejected again once the chroot
# finishes building) which this script does not set up. nexus-dkms is
# arch:all, so this only bites you on a cross chroot, not a native one.

set -eu

CHROOT_PATH="${1:?usage: build-nexus-dkms-chroot.sh CHROOT_PATH PKG_SRCDIR}"
PKG_SRCDIR="${2:?usage: build-nexus-dkms-chroot.sh CHROOT_PATH PKG_SRCDIR}"

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
# shellcheck source=lib/common.sh
. "$SCRIPT_DIR/lib/common.sh"

[ -d "$CHROOT_PATH" ] || die "Chroot not found: $CHROOT_PATH"
[ -d "$PKG_SRCDIR" ] || die "Package source dir not found: $PKG_SRCDIR"

# Canonicalize first: CMake hands this in as ".../nexus/nexus/..", and
# basename() of that literal string is "..", not "nexus" -- it does not
# resolve ".." itself, only a real cd+pwd does.
PKG_SRCDIR="$(cd "$PKG_SRCDIR" && pwd)"
_host_parent="$(dirname "$PKG_SRCDIR")"
_leaf="$(basename "$PKG_SRCDIR")"
_mnt_rel="build/nexus-dkms-src"
_mnt_abs="$CHROOT_PATH/$_mnt_rel"

sudo mkdir -p "$_mnt_abs"

# A stale bind mount from a killed previous run would make this mount a
# no-op over the old content; clear it first so we are never silently
# building against yesterday's tree.
if mountpoint -q "$_mnt_abs" 2>/dev/null; then
    sudo umount -l "$_mnt_abs"
fi

sudo mount --bind "$_host_parent" "$_mnt_abs"
trap 'sudo umount -l "$_mnt_abs" 2>/dev/null || true' EXIT INT TERM

log_step "Building nexus-dkms inside chroot ($CHROOT_PATH)..."
# Same PATH-must-be-explicit reasoning as lib/chroot.sh: chroot() does not
# reset PATH, and debhelper/dpkg-buildpackage/dkms live in the guest's
# /usr/sbin, which the host's inherited PATH has no reason to include.
# (Stale nexus-dkms_* siblings were already cleared on the host before this
# script ran, through the same bind-mounted directory -- nothing to redo here.)
sudo chroot "$CHROOT_PATH" /usr/bin/env \
    PATH=/usr/sbin:/usr/bin:/sbin:/bin \
    LC_ALL=C.UTF-8 \
    DEB_BUILD_OPTIONS=nocheck \
    /bin/bash -c "cd /$_mnt_rel/$_leaf && dpkg-buildpackage -uc -us"
