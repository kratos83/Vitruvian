/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 23 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"


#include <Message.h>

#include <map>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "rdef.h"
#include "compile.h"
#include "private.h"

using namespace std;

#define YYERROR_VERBOSE

static void yyerror(const char*);

struct ident_compare_t {  // allows the maps to compare identifier names
	bool
	operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

typedef std::map<const char*, int32, ident_compare_t> sym_tab_t;
typedef sym_tab_t::iterator sym_iter_t;

typedef std::map<const char*, type_t, ident_compare_t> type_tab_t;
typedef type_tab_t::iterator type_iter_t;

typedef std::map<const char*, define_t, ident_compare_t> define_tab_t;
typedef define_tab_t::iterator define_iter_t;


static sym_tab_t symbol_table;  // symbol table for enums
static int32 enum_cnt;          // counter for enum symbols without id
static type_tab_t type_table;  // symbol table for data types
static define_tab_t define_table;  // symbol table for defines


static void add_user_type(res_id_t, type_code, const char*, list_t);
static void add_symbol(const char*, int32);
static int32 get_symbol(const char*);

static bool is_type(const char* name);
static define_t get_define(const char* name);

static data_t make_data(size_t, type_t);
static data_t make_bool(bool);
static data_t make_int(uint64);
static data_t make_float(double);

static data_t import_data(char*);
static data_t resize_data(data_t, size_t);

static BMessage* make_msg(list_t);
static data_t flatten_msg(BMessage*);

static data_t make_default(type_t);
static data_t make_type(char* name, list_t);

static list_t make_field_list(field_t);
static list_t concat_field_list(list_t, field_t);
static list_t make_data_list(data_t);
static list_t concat_data_list(list_t, data_t);
static data_t concat_data(data_t, data_t);

static data_t cast(type_t, data_t);

static data_t unary_expr(data_t, char);
static data_t binary_expr(data_t, data_t, char);

static void add_resource(res_id_t, type_code, data_t);


//------------------------------------------------------------------------------

#line 152 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENUM = 3,                       /* ENUM  */
  YYSYMBOL_RESOURCE = 4,                   /* RESOURCE  */
  YYSYMBOL_ARCHIVE = 5,                    /* ARCHIVE  */
  YYSYMBOL_ARRAY = 6,                      /* ARRAY  */
  YYSYMBOL_MESSAGE = 7,                    /* MESSAGE  */
  YYSYMBOL_RTYPE = 8,                      /* RTYPE  */
  YYSYMBOL_IMPORT = 9,                     /* IMPORT  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_INTEGER = 11,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_RAW = 14,                       /* RAW  */
  YYSYMBOL_IDENT = 15,                     /* IDENT  */
  YYSYMBOL_TYPECODE = 16,                  /* TYPECODE  */
  YYSYMBOL_17_ = 17,                       /* '|'  */
  YYSYMBOL_18_ = 18,                       /* '^'  */
  YYSYMBOL_19_ = 19,                       /* '&'  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '%'  */
  YYSYMBOL_FLIP = 25,                      /* FLIP  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* ']'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '~'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_script = 37,                    /* script  */
  YYSYMBOL_enum = 38,                      /* enum  */
  YYSYMBOL_enumstart = 39,                 /* enumstart  */
  YYSYMBOL_symbols = 40,                   /* symbols  */
  YYSYMBOL_symboldef = 41,                 /* symboldef  */
  YYSYMBOL_typedef = 42,                   /* typedef  */
  YYSYMBOL_typedeffields = 43,             /* typedeffields  */
  YYSYMBOL_typedeffield = 44,              /* typedeffield  */
  YYSYMBOL_resource = 45,                  /* resource  */
  YYSYMBOL_id = 46,                        /* id  */
  YYSYMBOL_array = 47,                     /* array  */
  YYSYMBOL_arrayfields = 48,               /* arrayfields  */
  YYSYMBOL_message = 49,                   /* message  */
  YYSYMBOL_msgfields = 50,                 /* msgfields  */
  YYSYMBOL_msgfield = 51,                  /* msgfield  */
  YYSYMBOL_archive = 52,                   /* archive  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_type_or_define = 54,            /* type_or_define  */
  YYSYMBOL_typefields = 55,                /* typefields  */
  YYSYMBOL_typefield = 56,                 /* typefield  */
  YYSYMBOL_expr = 57,                      /* expr  */
  YYSYMBOL_data = 58,                      /* data  */
  YYSYMBOL_typecast = 59,                  /* typecast  */
  YYSYMBOL_datatype = 60,                  /* datatype  */
  YYSYMBOL_integer = 61,                   /* integer  */
  YYSYMBOL_float = 62                      /* float  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    24,    19,     2,
      33,    34,    22,    20,    29,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,    17,    27,    35,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   148,   149,   150,   154,   155,   156,   160,
     164,   165,   169,   174,   183,   187,   194,   195,   199,   206,
     213,   220,   230,   234,   238,   246,   249,   253,   258,   263,
     277,   283,   291,   292,   293,   294,   295,   299,   300,   304,
     310,   316,   322,   323,   324,   328,   329,   333,   338,   343,
     349,   358,   365,   374,   382,   395,   396,   401,   405,   409,
     426,   427,   431,   432,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   472,   473,   474,   475,   479,   480,
     481,   482,   486,   487,   491,   492
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ENUM", "RESOURCE",
  "ARCHIVE", "ARRAY", "MESSAGE", "RTYPE", "IMPORT", "BOOL", "INTEGER",
  "FLOAT", "STRING", "RAW", "IDENT", "TYPECODE", "'|'", "'^'", "'&'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "FLIP", "'{'", "'}'", "';'", "','",
  "'='", "'['", "']'", "'('", "')'", "'~'", "$accept", "script", "enum",
  "enumstart", "symbols", "symboldef", "typedef", "typedeffields",
  "typedeffield", "resource", "id", "array", "arrayfields", "message",
  "msgfields", "msgfield", "archive", "type", "type_or_define",
  "typefields", "typefield", "expr", "data", "typecast", "datatype",
  "integer", "float", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -101,    88,  -101,  -101,    -9,    -9,  -101,    15,  -101,  -101,
      -5,   183,    45,    -1,  -101,    37,     4,    68,  -101,    10,
      -8,    -4,    29,    74,  -101,  -101,  -101,  -101,   200,   306,
     126,   231,   306,  -101,  -101,  -101,  -101,  -101,   325,  -101,
     363,  -101,  -101,    64,    78,    80,   115,   -16,  -101,  -101,
     117,  -101,  -101,   129,  -101,   125,     2,   141,   244,    30,
      21,  -101,   275,   319,   411,   387,  -101,    -3,    -7,    83,
     114,   134,    81,  -101,   306,   306,   306,   306,   306,   306,
     306,   306,  -101,  -101,  -101,  -101,   306,  -101,  -101,  -101,
    -101,  -101,  -101,   107,   133,    21,  -101,   143,    13,   157,
     167,    43,   102,    21,  -101,  -101,    79,   411,   160,  -101,
    -101,   152,  -101,    71,  -101,   112,  -101,   195,   205,   151,
    -101,   123,  -101,   411,  -101,   -17,  -101,  -101,  -101,   306,
    -101,   418,   208,   252,   110,   110,  -101,  -101,  -101,   369,
     140,  -101,   209,   107,  -101,  -101,   206,  -101,  -101,  -101,
     147,    21,   233,   226,  -101,   306,  -101,   306,   232,   248,
    -101,    43,   237,   242,   306,  -101,   350,  -101,   399,  -101,
     235,   107,   148,   156,  -101,  -101,   236,   243,   263,   411,
     411,   306,   253,  -101,   306,    67,   411,  -101,  -101,  -101,
    -101,   306,   280,   264,   278,    43,   268,   411,   306,   411,
    -101,   173,   411,   265,  -101,   269,   190,    43,   411,  -101,
     270,    43,  -101,   193,   306,   196,  -101,   411,  -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     9,    25,    25,     3,     0,     4,     5,
       0,     0,     0,     0,   102,     0,     0,     0,    26,     0,
       0,    34,    44,     0,    74,   104,    77,    78,    59,     0,
       0,     0,     0,    79,    80,    81,    82,    58,     0,    73,
       0,    75,    76,     0,     0,    12,     0,     0,    11,    31,
       0,    29,   103,     0,    27,     0,     0,     0,     0,     0,
       0,    36,     0,     0,    57,     0,   105,     0,    34,    44,
      59,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    84,    87,    88,     0,    89,    90,    91,
      92,    85,    86,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,    35,    33,     0,    38,     0,    98,
      99,     0,   101,     0,    43,     0,    46,     0,     0,    59,
      56,     0,    61,    63,    23,     0,    94,    95,    97,     0,
      83,    69,    70,    71,    64,    65,    66,    67,    68,     0,
       0,    17,     0,     0,    13,     7,     0,    10,    30,    28,
       0,     0,     0,     0,    32,     0,   100,     0,     0,     0,
      42,     0,     0,    41,     0,    55,     0,    96,     0,    93,
       0,     0,    18,     0,     8,    51,     0,     0,     0,    37,
      47,     0,     0,    45,     0,     0,    62,    60,    24,    15,
      16,     0,     0,     0,     0,     0,     0,    49,     0,    48,
      40,     0,    19,     0,    14,     0,     0,     0,    50,    39,
      20,     0,    52,     0,     0,     0,    53,    21,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,  -101,   201,  -101,   155,   130,  -101,
     298,   266,  -101,   267,  -100,   144,   274,   282,  -101,  -101,
     138,   -11,  -101,  -101,   -90,    -6,   283
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     6,     7,    47,    48,     8,   140,   141,     9,
      11,    33,   106,    34,   115,   116,    35,    36,    37,   121,
     122,    64,    39,    40,   117,    41,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,   150,    57,   142,    19,    57,    14,    55,    15,   101,
      16,    97,   125,    98,    45,   102,    17,   167,    65,    58,
      72,    73,    58,   159,    10,    56,    46,   126,    45,    18,
      56,   103,    14,    50,    91,   108,   109,   110,    51,    53,
     146,    13,    17,   111,    54,   112,   113,   107,   108,   109,
     110,   123,    72,   142,   118,    59,   111,   114,   112,   113,
      43,    44,    60,   131,   132,   133,   134,   135,   136,   137,
     138,    49,   108,   109,   110,   139,   108,   109,   110,    52,
     111,   142,   112,   113,   158,   201,   112,    61,     2,   144,
      93,     3,     4,    94,   200,   206,     5,   153,    74,    75,
      76,    77,    78,    79,    80,    81,   154,   213,   155,    59,
      95,   215,   108,   109,   110,   130,    60,   127,   168,    20,
      21,    22,   112,    23,    24,    14,    25,    26,    27,    28,
      99,   151,    79,    80,    81,    30,   152,    52,    66,   160,
      62,   161,   100,    96,   179,   176,   180,    63,   128,    32,
     165,   101,   166,   186,   104,   123,    20,    21,    22,   143,
      23,    24,    14,    25,    26,    27,    28,   170,   129,   171,
     197,   145,    30,   199,   175,   156,   161,    62,   191,   192,
     202,   164,   157,   193,    63,   171,    32,   208,    20,    21,
      22,   148,    23,    24,    14,    25,    26,    27,    28,    29,
     209,   149,   161,   217,    30,    20,    21,    22,   162,    23,
      24,    14,    25,    26,    27,    28,    31,   212,    32,   161,
     216,    30,   161,   218,   172,   161,    62,    76,    77,    78,
      79,    80,    81,    63,   174,    32,    67,    68,    69,   163,
      23,    24,    14,    25,    26,    27,    70,    71,   177,    20,
      21,    22,    30,    23,    24,    14,    25,    26,    27,    28,
     178,   182,   181,   189,    63,    30,    32,   184,   185,   195,
     194,   105,    77,    78,    79,    80,    81,    63,   196,    32,
      20,    21,    22,   198,    23,    24,    14,    25,    26,    27,
     119,   203,   204,   205,   207,   211,    30,   210,   173,   147,
     214,   190,   120,    12,   187,   183,    87,    88,    63,     0,
      32,    20,    21,    22,    89,    23,    24,    14,    25,    26,
      27,    28,    90,    92,    67,    68,    69,    30,    23,    24,
      14,    25,    26,    27,    70,     0,     0,     0,     0,    63,
      30,    32,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    63,    82,    32,    20,    21,    22,     0,    23,
      24,    14,    25,    26,    27,   119,     0,     0,    20,    21,
      22,    30,    23,    83,    14,    25,    84,    85,    28,     0,
       0,     0,     0,    63,    30,    32,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    86,     0,     0,     0,
       0,     0,     0,   169,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,   124,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,   188,    74,    75,
      76,    77,    78,    79,    80,    81,    75,    76,    77,    78,
      79,    80,    81
};

static const yytype_int16 yycheck[] =
{
      11,   101,     9,    93,    10,     9,    11,    15,    13,    26,
      15,    27,    15,    29,    15,    13,    21,    34,    29,    26,
      31,    32,    26,   113,    33,    33,    27,    34,    15,    34,
      33,    29,    11,    29,    40,     5,     6,     7,    34,    29,
      27,    26,    21,    13,    34,    15,    16,    58,     5,     6,
       7,    62,    63,   143,    60,    26,    13,    27,    15,    16,
      15,    16,    33,    74,    75,    76,    77,    78,    79,    80,
      81,    34,     5,     6,     7,    86,     5,     6,     7,    11,
      13,   171,    15,    16,    13,   185,    15,    13,     0,    95,
      26,     3,     4,    15,    27,   195,     8,   103,    17,    18,
      19,    20,    21,    22,    23,    24,    27,   207,    29,    26,
      30,   211,     5,     6,     7,    34,    33,    34,   129,     5,
       6,     7,    15,     9,    10,    11,    12,    13,    14,    15,
      13,    29,    22,    23,    24,    21,    34,    11,    12,    27,
      26,    29,    13,    28,   155,   151,   157,    33,    34,    35,
      27,    26,    29,   164,    13,   166,     5,     6,     7,    26,
       9,    10,    11,    12,    13,    14,    15,    27,    34,    29,
     181,    28,    21,   184,    27,    15,    29,    26,    30,    31,
     191,    30,    30,    27,    33,    29,    35,   198,     5,     6,
       7,    34,     9,    10,    11,    12,    13,    14,    15,    16,
      27,    34,    29,   214,    21,     5,     6,     7,    13,     9,
      10,    11,    12,    13,    14,    15,    33,    27,    35,    29,
      27,    21,    29,    27,    15,    29,    26,    19,    20,    21,
      22,    23,    24,    33,    28,    35,     5,     6,     7,    34,
       9,    10,    11,    12,    13,    14,    15,    16,    15,     5,
       6,     7,    21,     9,    10,    11,    12,    13,    14,    15,
      34,    13,    30,    28,    33,    21,    35,    30,    26,    26,
      34,    27,    20,    21,    22,    23,    24,    33,    15,    35,
       5,     6,     7,    30,     9,    10,    11,    12,    13,    14,
      15,    11,    28,    15,    26,    26,    21,    32,   143,    98,
      30,   171,    27,     5,   166,   161,    40,    40,    33,    -1,
      35,     5,     6,     7,    40,     9,    10,    11,    12,    13,
      14,    15,    40,    40,     5,     6,     7,    21,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    33,
      21,    35,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    33,    28,    35,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,     5,     6,
       7,    21,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    33,    21,    35,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    17,    18,
      19,    20,    21,    22,    23,    24,    18,    19,    20,    21,
      22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,     0,     3,     4,     8,    38,    39,    42,    45,
      33,    46,    46,    26,    11,    13,    15,    21,    34,    61,
       5,     6,     7,     9,    10,    12,    13,    14,    15,    16,
      21,    33,    35,    47,    49,    52,    53,    54,    57,    58,
      59,    61,    62,    15,    16,    15,    27,    40,    41,    34,
      29,    34,    11,    29,    34,    15,    33,     9,    26,    26,
      33,    13,    26,    33,    57,    57,    12,     5,     6,     7,
      15,    16,    57,    57,    17,    18,    19,    20,    21,    22,
      23,    24,    28,    10,    13,    14,    33,    47,    49,    52,
      53,    61,    62,    26,    15,    30,    28,    27,    29,    13,
      13,    26,    13,    29,    13,    27,    48,    57,     5,     6,
       7,    13,    15,    16,    27,    50,    51,    60,    61,    15,
      27,    55,    56,    57,    28,    15,    34,    34,    34,    34,
      34,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      43,    44,    60,    26,    61,    28,    27,    41,    34,    34,
      50,    29,    34,    61,    27,    29,    15,    30,    13,    60,
      27,    29,    13,    34,    30,    27,    29,    34,    57,    34,
      27,    29,    15,    43,    28,    27,    61,    15,    34,    57,
      57,    30,    13,    51,    30,    26,    57,    56,    28,    28,
      44,    30,    31,    27,    34,    26,    15,    57,    30,    57,
      27,    50,    57,    11,    28,    15,    50,    26,    57,    27,
      32,    26,    27,    50,    30,    50,    27,    57,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    38,    38,    38,    39,
      40,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      44,    44,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    47,    47,    48,    48,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      55,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     4,     5,     6,     1,
       3,     1,     1,     3,     8,     7,     3,     1,     2,     4,
       5,     7,     4,     5,     7,     0,     2,     3,     5,     3,
       5,     3,     4,     3,     1,     3,     2,     3,     1,     7,
       6,     4,     4,     3,     1,     3,     1,     3,     4,     4,
       5,     5,     8,     9,    10,     4,     3,     2,     1,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     3,     3,     4,     3,     1,     1,
       2,     1,     1,     2,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 9: /* enumstart: ENUM  */
#line 160 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
               { enum_cnt = 0; }
#line 1382 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 12: /* symboldef: IDENT  */
#line 170 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			add_symbol((yyvsp[0].I), enum_cnt);
			++enum_cnt;
		}
#line 1391 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 13: /* symboldef: IDENT '=' integer  */
#line 175 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			int32 id = (int32) (yyvsp[0].i);
			add_symbol((yyvsp[-2].I), id);
			enum_cnt = id + 1;
		}
#line 1401 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 14: /* typedef: RTYPE id TYPECODE IDENT '{' typedeffields '}' ';'  */
#line 184 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			add_user_type((yyvsp[-6].id), (yyvsp[-5].t), (yyvsp[-4].I), (yyvsp[-2].l));
		}
#line 1409 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 15: /* typedef: RTYPE id IDENT '{' typedeffields '}' ';'  */
#line 188 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			add_user_type((yyvsp[-5].id), B_RAW_TYPE, (yyvsp[-4].I), (yyvsp[-2].l));
		}
#line 1417 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 16: /* typedeffields: typedeffields ',' typedeffield  */
#line 194 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                         { (yyval.l) = concat_field_list((yyvsp[-2].l), (yyvsp[0].F)); }
#line 1423 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 17: /* typedeffields: typedeffield  */
#line 195 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                         { (yyval.l) = make_field_list((yyvsp[0].F)); }
#line 1429 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 18: /* typedeffield: datatype IDENT  */
#line 200 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.F).type   = (yyvsp[-1].T);
			(yyval.F).name   = (yyvsp[0].I);
			(yyval.F).resize = 0;
			(yyval.F).data   = make_default((yyvsp[-1].T));
		}
#line 1440 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 19: /* typedeffield: datatype IDENT '=' expr  */
#line 207 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.F).type   = (yyvsp[-3].T);
			(yyval.F).name   = (yyvsp[-2].I);
			(yyval.F).resize = 0;
			(yyval.F).data   = cast((yyvsp[-3].T), (yyvsp[0].d));
		}
#line 1451 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 20: /* typedeffield: datatype IDENT '[' INTEGER ']'  */
#line 214 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.F).type   = (yyvsp[-4].T);
			(yyval.F).name   = (yyvsp[-3].I);
			(yyval.F).resize = (size_t) (yyvsp[-1].i);
			(yyval.F).data   = resize_data(make_default((yyvsp[-4].T)), (yyval.F).resize);
		}
#line 1462 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 21: /* typedeffield: datatype IDENT '[' INTEGER ']' '=' expr  */
#line 221 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.F).type   = (yyvsp[-6].T);
			(yyval.F).name   = (yyvsp[-5].I);
			(yyval.F).resize = (size_t) (yyvsp[-3].i);
			(yyval.F).data   = resize_data(cast((yyvsp[-6].T), (yyvsp[0].d)), (yyval.F).resize);
		}
#line 1473 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 22: /* resource: RESOURCE id expr ';'  */
#line 231 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			add_resource((yyvsp[-2].id), (yyvsp[-1].d).type.code, (yyvsp[-1].d));
		}
#line 1481 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 23: /* resource: RESOURCE id TYPECODE expr ';'  */
#line 235 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			add_resource((yyvsp[-3].id), (yyvsp[-2].t), (yyvsp[-1].d));
		}
#line 1489 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 24: /* resource: RESOURCE id '(' TYPECODE ')' expr ';'  */
#line 239 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			add_resource((yyvsp[-5].id), (yyvsp[-3].t), (yyvsp[-1].d));
		}
#line 1497 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 25: /* id: %empty  */
#line 246 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = false; (yyval.id).has_name = false; (yyval.id).name = NULL;
		}
#line 1505 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 26: /* id: '(' ')'  */
#line 250 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = false; (yyval.id).has_name = false; (yyval.id).name = NULL;
		}
#line 1513 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 27: /* id: '(' integer ')'  */
#line 254 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = true; (yyval.id).id = (int32) (yyvsp[-1].i);
			(yyval.id).has_name = false; (yyval.id).name = NULL;
		}
#line 1522 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 28: /* id: '(' integer ',' STRING ')'  */
#line 259 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = true; (yyval.id).id = (int32) (yyvsp[-3].i);
			(yyval.id).has_name = true; (yyval.id).name = (char*) (yyvsp[-1].d).ptr;
		}
#line 1531 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 29: /* id: '(' IDENT ')'  */
#line 264 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = true; (yyval.id).id = get_symbol((yyvsp[-1].I));

			if (flags & RDEF_AUTO_NAMES)
			{
				(yyval.id).has_name = true; (yyval.id).name = (yyvsp[-1].I);
			}
			else
			{
				(yyval.id).has_name = false; (yyval.id).name = NULL;
				free_mem((yyvsp[-1].I));
			}
		}
#line 1549 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 30: /* id: '(' IDENT ',' STRING ')'  */
#line 278 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = true; (yyval.id).id = get_symbol((yyvsp[-3].I));
			(yyval.id).has_name = true; (yyval.id).name = (char*) (yyvsp[-1].d).ptr;
			free_mem((yyvsp[-3].I));
		}
#line 1559 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 31: /* id: '(' STRING ')'  */
#line 284 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.id).has_id = false;
			(yyval.id).has_name = true; (yyval.id).name = (char*) (yyvsp[-1].d).ptr;
		}
#line 1568 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 32: /* array: ARRAY '{' arrayfields '}'  */
#line 291 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = (yyvsp[-1].d); }
#line 1574 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 33: /* array: ARRAY '{' '}'  */
#line 292 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = make_data(0, get_type("raw")); }
#line 1580 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 34: /* array: ARRAY  */
#line 293 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = make_data(0, get_type("raw")); }
#line 1586 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 35: /* array: ARRAY IMPORT STRING  */
#line 294 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = import_data((char*) (yyvsp[0].d).ptr); }
#line 1592 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 36: /* array: IMPORT STRING  */
#line 295 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = import_data((char*) (yyvsp[0].d).ptr); }
#line 1598 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 37: /* arrayfields: arrayfields ',' expr  */
#line 299 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                               { (yyval.d) = concat_data((yyvsp[-2].d), (yyvsp[0].d)); }
#line 1604 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 38: /* arrayfields: expr  */
#line 300 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                               { (yyval.d) = (yyvsp[0].d); (yyval.d).type = get_type("raw"); }
#line 1610 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 39: /* message: MESSAGE '(' integer ')' '{' msgfields '}'  */
#line 305 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = make_msg((yyvsp[-1].l));
			msg->what = (int32) (yyvsp[-4].i);
			(yyval.d) = flatten_msg(msg);
		}
#line 1620 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 40: /* message: MESSAGE '(' integer ')' '{' '}'  */
#line 311 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = new BMessage;
			msg->what = (int32) (yyvsp[-3].i);
			(yyval.d) = flatten_msg(msg);
		}
#line 1630 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 41: /* message: MESSAGE '(' integer ')'  */
#line 317 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = new BMessage;
			msg->what = (int32) (yyvsp[-1].i);
			(yyval.d) = flatten_msg(msg);
		}
#line 1640 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 42: /* message: MESSAGE '{' msgfields '}'  */
#line 322 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = flatten_msg(make_msg((yyvsp[-1].l))); }
#line 1646 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 43: /* message: MESSAGE '{' '}'  */
#line 323 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = flatten_msg(new BMessage); }
#line 1652 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 44: /* message: MESSAGE  */
#line 324 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                    { (yyval.d) = flatten_msg(new BMessage); }
#line 1658 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 45: /* msgfields: msgfields ',' msgfield  */
#line 328 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                 { (yyval.l) = concat_data_list((yyvsp[-2].l), (yyvsp[0].d)); }
#line 1664 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 46: /* msgfields: msgfield  */
#line 329 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                 { (yyval.l) = make_data_list((yyvsp[0].d)); }
#line 1670 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 47: /* msgfield: STRING '=' expr  */
#line 334 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.d) = (yyvsp[0].d);
			(yyval.d).name = (char*) (yyvsp[-2].d).ptr;
		}
#line 1679 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 48: /* msgfield: datatype STRING '=' expr  */
#line 339 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.d) = cast((yyvsp[-3].T), (yyvsp[0].d));
			(yyval.d).name = (char*) (yyvsp[-2].d).ptr;
		}
#line 1688 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 49: /* msgfield: TYPECODE STRING '=' expr  */
#line 344 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.d) = (yyvsp[0].d);
			(yyval.d).type.code = (yyvsp[-3].t);
			(yyval.d).name = (char*) (yyvsp[-2].d).ptr;
		}
#line 1698 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 50: /* msgfield: TYPECODE datatype STRING '=' expr  */
#line 350 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.d) = cast((yyvsp[-3].T), (yyvsp[0].d));
			(yyval.d).type.code = (yyvsp[-4].t);
			(yyval.d).name = (char*) (yyvsp[-2].d).ptr;
		}
#line 1708 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 51: /* archive: ARCHIVE IDENT '{' msgfields '}'  */
#line 359 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = make_msg((yyvsp[-1].l));
			msg->AddString("class", (yyvsp[-3].I));
			free_mem((yyvsp[-3].I));
			(yyval.d) = flatten_msg(msg);
		}
#line 1719 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 52: /* archive: ARCHIVE '(' STRING ')' IDENT '{' msgfields '}'  */
#line 366 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = make_msg((yyvsp[-1].l));
			msg->AddString("class", (yyvsp[-3].I));
			msg->AddString("add_on", (char*) (yyvsp[-5].d).ptr);
			free_mem((yyvsp[-3].I));
			free_mem((yyvsp[-5].d).ptr);
			(yyval.d) = flatten_msg(msg);
		}
#line 1732 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 53: /* archive: ARCHIVE '(' ',' integer ')' IDENT '{' msgfields '}'  */
#line 375 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = make_msg((yyvsp[-1].l));
			msg->what = (int32) (yyvsp[-5].i);
			msg->AddString("class", (yyvsp[-3].I));
			free_mem((yyvsp[-3].I));
			(yyval.d) = flatten_msg(msg);
		}
#line 1744 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 54: /* archive: ARCHIVE '(' STRING ',' integer ')' IDENT '{' msgfields '}'  */
#line 383 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			BMessage* msg = make_msg((yyvsp[-1].l));
			msg->what = (int32) (yyvsp[-5].i);
			msg->AddString("class", (yyvsp[-3].I));
			msg->AddString("add_on", (char*) (yyvsp[-7].d).ptr);
			free_mem((yyvsp[-3].I));
			free_mem((yyvsp[-7].d).ptr);
			(yyval.d) = flatten_msg(msg);
		}
#line 1758 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 55: /* type: IDENT '{' typefields '}'  */
#line 395 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                   { (yyval.d) = make_type((yyvsp[-3].I), (yyvsp[-1].l)); }
#line 1764 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 56: /* type: IDENT '{' '}'  */
#line 397 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			list_t list; list.count = 0; list.items = NULL;
			(yyval.d) = make_type((yyvsp[-2].I), list);
		}
#line 1773 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 57: /* type: IDENT expr  */
#line 402 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			(yyval.d) = make_type((yyvsp[-1].I), make_data_list((yyvsp[0].d)));
		}
#line 1781 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 58: /* type: type_or_define  */
#line 405 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                         { (yyval.d) = (yyvsp[0].d); }
#line 1787 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 59: /* type_or_define: IDENT  */
#line 410 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                {
			if (is_type((yyvsp[0].I)))
			{
				list_t list; list.count = 0; list.items = NULL;
				(yyval.d) = make_type((yyvsp[0].I), list);
			}
			else
			{
				define_t define = get_define((yyvsp[0].I));
				(yyval.d) = cast(get_type("int32"), make_int(define.value));
				free_mem((yyvsp[0].I));
			}
		}
#line 1805 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 60: /* typefields: typefields ',' typefield  */
#line 426 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                   { (yyval.l) = concat_data_list((yyvsp[-2].l), (yyvsp[0].d)); }
#line 1811 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 61: /* typefields: typefield  */
#line 427 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                   { (yyval.l) = make_data_list((yyvsp[0].d)); }
#line 1817 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 62: /* typefield: IDENT '=' expr  */
#line 431 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                         { (yyval.d) = (yyvsp[0].d); (yyval.d).name = (yyvsp[-2].I); }
#line 1823 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 63: /* typefield: expr  */
#line 432 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                         { (yyval.d) = (yyvsp[0].d); }
#line 1829 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 64: /* expr: expr '+' expr  */
#line 436 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '+'); }
#line 1835 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 65: /* expr: expr '-' expr  */
#line 437 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '-'); }
#line 1841 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 66: /* expr: expr '*' expr  */
#line 438 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '*'); }
#line 1847 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 67: /* expr: expr '/' expr  */
#line 439 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '/'); }
#line 1853 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 68: /* expr: expr '%' expr  */
#line 440 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '%'); }
#line 1859 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 69: /* expr: expr '|' expr  */
#line 441 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '|'); }
#line 1865 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 70: /* expr: expr '^' expr  */
#line 442 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '^'); }
#line 1871 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 71: /* expr: expr '&' expr  */
#line 443 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = binary_expr((yyvsp[-2].d), (yyvsp[0].d), '&'); }
#line 1877 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 72: /* expr: '~' expr  */
#line 444 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = unary_expr((yyvsp[0].d), '~'); }
#line 1883 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 73: /* expr: data  */
#line 445 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = (yyvsp[0].d); }
#line 1889 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 74: /* data: BOOL  */
#line 449 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast(get_type("bool"), make_bool((yyvsp[0].b))); }
#line 1895 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 75: /* data: integer  */
#line 450 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast(get_type("int32"), make_int((yyvsp[0].i))); }
#line 1901 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 76: /* data: float  */
#line 451 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast(get_type("float"), make_float((yyvsp[0].f))); }
#line 1907 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 77: /* data: STRING  */
#line 452 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[0].d).type, (yyvsp[0].d)); }
#line 1913 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 78: /* data: RAW  */
#line 453 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[0].d).type, (yyvsp[0].d)); }
#line 1919 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 79: /* data: array  */
#line 454 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[0].d).type, (yyvsp[0].d)); }
#line 1925 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 80: /* data: message  */
#line 455 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[0].d).type, (yyvsp[0].d)); }
#line 1931 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 81: /* data: archive  */
#line 456 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[0].d).type, (yyvsp[0].d)); }
#line 1937 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 82: /* data: type  */
#line 457 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[0].d).type, (yyvsp[0].d)); }
#line 1943 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 83: /* data: '(' expr ')'  */
#line 458 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = (yyvsp[-1].d); }
#line 1949 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 84: /* data: typecast BOOL  */
#line 459 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), make_bool((yyvsp[0].b))); }
#line 1955 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 85: /* data: typecast integer  */
#line 460 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), make_int((yyvsp[0].i))); }
#line 1961 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 86: /* data: typecast float  */
#line 461 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), make_float((yyvsp[0].f))); }
#line 1967 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 87: /* data: typecast STRING  */
#line 462 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), (yyvsp[0].d)); }
#line 1973 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 88: /* data: typecast RAW  */
#line 463 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), (yyvsp[0].d)); }
#line 1979 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 89: /* data: typecast array  */
#line 464 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), (yyvsp[0].d)); }
#line 1985 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 90: /* data: typecast message  */
#line 465 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), (yyvsp[0].d)); }
#line 1991 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 91: /* data: typecast archive  */
#line 466 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), (yyvsp[0].d)); }
#line 1997 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 92: /* data: typecast type  */
#line 467 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-1].T), (yyvsp[0].d)); }
#line 2003 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 93: /* data: typecast '(' expr ')'  */
#line 468 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.d) = cast((yyvsp[-3].T), (yyvsp[-1].d)); }
#line 2009 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 94: /* typecast: '(' ARRAY ')'  */
#line 472 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.T) = get_type("raw"); }
#line 2015 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 95: /* typecast: '(' MESSAGE ')'  */
#line 473 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.T) = get_type("message"); }
#line 2021 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 96: /* typecast: '(' ARCHIVE IDENT ')'  */
#line 474 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.T) = get_type("message"); free_mem((yyvsp[-1].I)); }
#line 2027 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 97: /* typecast: '(' IDENT ')'  */
#line 475 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                                { (yyval.T) = get_type((yyvsp[-1].I)); free_mem((yyvsp[-1].I)); }
#line 2033 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 98: /* datatype: ARRAY  */
#line 479 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                        { (yyval.T) = get_type("raw"); }
#line 2039 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 99: /* datatype: MESSAGE  */
#line 480 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                        { (yyval.T) = get_type("message"); }
#line 2045 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 100: /* datatype: ARCHIVE IDENT  */
#line 481 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                        { (yyval.T) = get_type("message"); free_mem((yyvsp[0].I)); }
#line 2051 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 101: /* datatype: IDENT  */
#line 482 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                        { (yyval.T) = get_type((yyvsp[0].I)); free_mem((yyvsp[0].I)); }
#line 2057 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 102: /* integer: INTEGER  */
#line 486 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                      { (yyval.i) = (yyvsp[0].i); }
#line 2063 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 103: /* integer: '-' INTEGER  */
#line 487 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                      { (yyval.i) = -((yyvsp[0].i)); }
#line 2069 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 104: /* float: FLOAT  */
#line 491 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                      { (yyval.f) = (yyvsp[0].f); }
#line 2075 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;

  case 105: /* float: '-' FLOAT  */
#line 492 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"
                      { (yyval.f) = -((yyvsp[0].f)); }
#line 2081 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"
    break;


#line 2085 "/home/angelo/Scaricati/Vitruvian/buildtools/src/bin/rc/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 495 "/home/angelo/Scaricati/Vitruvian/src/bin/rc/parser.y"

//------------------------------------------------------------------------------


void
yyerror(const char* msg)
{
	// This function is called by the parser when it encounters
	// an error, after which it aborts parsing and returns from
	// yyparse(). We never call yyerror() directly.

	rdef_err = RDEF_COMPILE_ERR;
	rdef_err_line = yylineno;
	strcpy(rdef_err_file, lexfile);
	strcpy(rdef_err_msg, msg);
}


void
add_symbol(const char* name, int32 id)
{
	if (symbol_table.find(name) != symbol_table.end())
		abort_compile(RDEF_COMPILE_ERR, "duplicate symbol %s", name);

	symbol_table.insert(make_pair(name, id));
}


int32
get_symbol(const char* name)
{
	sym_iter_t i = symbol_table.find(name);

	if (i == symbol_table.end())
		abort_compile(RDEF_COMPILE_ERR, "unknown symbol %s", name);

	return i->second;
}


static void
add_builtin_type(type_code code, const char* name)
{
	type_t type;
	type.code     = code;
	type.name     = name;
	type.count    = 0;
	type.fields   = NULL;
	type.def_id   = 1;
	type.def_name = NULL;

	type_table.insert(make_pair(name, type));
}


void
add_user_type(res_id_t id, type_code code, const char* name, list_t list)
{
	if (type_table.find(name) != type_table.end())
		abort_compile(RDEF_COMPILE_ERR, "duplicate type %s", name);

	type_t type;
	type.code     = code;
	type.name     = name;
	type.count    = list.count;
	type.fields   = (field_t*) list.items;
	type.def_id   = 1;
	type.def_name = NULL;

	if (id.has_id)
		type.def_id = id.id;

	if (id.has_name)
		type.def_name = id.name;

	type_table.insert(make_pair(name, type));
}


static bool
is_builtin_type(type_t type)
{
	return type.count == 0;
}


static bool
same_type(type_t type1, type_t type2)
{
	return type1.name == type2.name;  // no need for strcmp
}


type_t
get_type(const char* name)
{
	type_iter_t i = type_table.find(name);

	if (i == type_table.end())
		abort_compile(RDEF_COMPILE_ERR, "unknown type %s", name);

	return i->second;
}


bool
is_type(const char* name)
{
	return type_table.find(name) != type_table.end();
}


define_t
get_define(const char* name)
{
	define_iter_t i = define_table.find(name);

	if (i == define_table.end())
		abort_compile(RDEF_COMPILE_ERR, "unknown define %s", name);

	return i->second;
}


data_t
make_data(size_t size, type_t type)
{
	data_t out;
	out.type = type;
	out.name = NULL;
	out.size = size;
	out.ptr  = alloc_mem(size);
	return out;
}


data_t
make_bool(bool b)
{
	data_t out = make_data(sizeof(bool), get_type("bool"));
	*((bool*)out.ptr) = b;
	return out;
}


data_t
make_int(uint64 i)
{
	data_t out = make_data(sizeof(uint64), get_type("uint64"));
	*((uint64*)out.ptr) = i;
	return out;
}


data_t
make_float(double f)
{
	data_t out = make_data(sizeof(double), get_type("double"));
	*((double*)out.ptr) = f;
	return out;
}


data_t
import_data(char* filename)
{
	data_t out;
	out.type = get_type("raw");
	out.name = NULL;

	char tmpname[B_PATH_NAME_LENGTH];
	if (open_file_from_include_dir(filename, tmpname)) {
		BFile file(tmpname, B_READ_ONLY);
		if (file.InitCheck() == B_OK) {
			off_t size;
			if (file.GetSize(&size) == B_OK) {
				out.size = (size_t) size;
				out.ptr  = alloc_mem(size);

				if (file.Read(out.ptr, out.size) == (ssize_t) out.size) {
					free_mem(filename);
					return out;
				}
			}
		}
	}

	abort_compile(RDEF_COMPILE_ERR, "cannot import %s", filename);
	return out;
}


data_t
resize_data(data_t data, size_t newSize)
{
	if (newSize == 0) {
		abort_compile(RDEF_COMPILE_ERR, "invalid size %lu", newSize);
	} else if (data.size != newSize) {
		void* newBuffer = alloc_mem(newSize);

		memset(newBuffer, 0, newSize);
		memcpy(newBuffer, data.ptr, min(data.size, newSize));

		if (data.type.code == B_STRING_TYPE)
			((char*)newBuffer)[newSize - 1] = '\0';

		free_mem(data.ptr);
		data.ptr  = newBuffer;
		data.size = newSize;
	}

	return data;
}


BMessage*
make_msg(list_t list)
{
	BMessage* msg = new BMessage;

	for (int32 t = 0; t < list.count; ++t) {
		data_t data = ((data_t*)list.items)[t];
		msg->AddData(data.name, data.type.code, data.ptr, data.size, false);
		free_mem(data.name);
		free_mem(data.ptr);
	}

	free_mem(list.items);
	return msg;
}


data_t
flatten_msg(BMessage* msg)
{
#ifndef B_BEOS_VERSION_DANO
	data_t out = make_data(msg->FlattenedSize(), get_type("message"));
	msg->Flatten((char*)out.ptr, out.size);
#else
	data_t out = make_data(msg->FlattenedSize(B_MESSAGE_VERSION_1),
		get_type("message"));
	msg->Flatten(B_MESSAGE_VERSION_1, (char*)out.ptr, out.size);
#endif
	delete msg;
	return out;
}


data_t
make_default(type_t type)
{
	data_t out;

	if (is_builtin_type(type)) {
		switch (type.code) {
			case B_BOOL_TYPE:
				out = make_data(sizeof(bool), type);
				*((bool*)out.ptr) = false;
				break;

			case B_INT8_TYPE:
			case B_UINT8_TYPE:
				out = make_data(sizeof(uint8), type);
				*((uint8*)out.ptr) = 0;
				break;

			case B_INT16_TYPE:
			case B_UINT16_TYPE:
				out = make_data(sizeof(uint16), type);
				*((uint16*)out.ptr) = 0;
				break;

			case B_INT32_TYPE:
			case B_UINT32_TYPE:
			case B_SIZE_T_TYPE:
			case B_SSIZE_T_TYPE:
			case B_TIME_TYPE:
				out = make_data(sizeof(uint32), type);
				*((uint32*)out.ptr) = 0;
				break;

			case B_INT64_TYPE:
			case B_UINT64_TYPE:
			case B_OFF_T_TYPE:
				out = make_data(sizeof(uint64), type);
				*((uint64*)out.ptr) = 0;
				break;

			case B_FLOAT_TYPE:
				out = make_data(sizeof(float), type);
				*((float*)out.ptr) = 0.0f;
				break;

			case B_DOUBLE_TYPE:
				out = make_data(sizeof(double), type);
				*((double*)out.ptr) = 0.0;
				break;

			case B_STRING_TYPE:
				out = make_data(sizeof(char), type);
				*((char*)out.ptr) = '\0';
				break;

			case B_RAW_TYPE:
				out = make_data(0, type);
				break;

			case B_MESSAGE_TYPE:
				out = flatten_msg(new BMessage);
				break;
		}
	} else {
		// For user-defined types, we copy the default values of the fields
		// into a new data_t object. There is no need to call resize_data()
		// here, because the default values were already resized to their
		// proper length when we added them to the type.

		size_t size = 0;
		for (int32 t = 0; t < type.count; ++t) {
			size += type.fields[t].data.size;
		}

		out = make_data(size, type);

		uint8* ptr = (uint8*) out.ptr;
		for (int32 t = 0; t < type.count; ++t) {
			data_t field_data = type.fields[t].data;
			memcpy(ptr, field_data.ptr, field_data.size);
			ptr += field_data.size;
		}
	}

	return out;
}


static data_t*
fill_slots(type_t type, list_t list)
{
	data_t* slots = (data_t*)alloc_mem(type.count * sizeof(data_t));
	memset(slots, 0, type.count * sizeof(data_t));

	for (int32 t = 0; t < list.count; ++t) {
		data_t data = ((data_t*)list.items)[t];

		if (data.name == NULL) {
			bool found = false;
			for (int32 k = 0; k < type.count; ++k) {
				if (slots[k].ptr == NULL) {
					slots[k] = cast(type.fields[k].type, data);
					found = true;
					break;
				}
			}

			if (!found)
				abort_compile(RDEF_COMPILE_ERR, "too many fields");
		} else {
			// named field
			bool found = false;
			for (int32 k = 0; k < type.count; ++k) {
				if (strcmp(type.fields[k].name, data.name) == 0) {
					if (slots[k].ptr != NULL)
						free_mem(slots[k].ptr);

					slots[k] = cast(type.fields[k].type, data);
					free_mem(data.name);
					found = true;
					break;
				}
			}

			if (!found)
				abort_compile(RDEF_COMPILE_ERR, "unknown field %s", data.name);
		}
	}

	return slots;
}


static data_t
convert_slots(type_t type, data_t* slots)
{
	size_t size = 0;
	for (int32 k = 0; k < type.count; ++k) {
		if (slots[k].ptr == NULL) {
			// default value
			size += type.fields[k].data.size;
		} else if (type.fields[k].resize != 0)
			size += type.fields[k].resize;
		else
			size += slots[k].size;
	}

	data_t out = make_data(size, type);
	uint8* ptr = (uint8*) out.ptr;

	for (int32 k = 0; k < type.count; ++k) {
		if (slots[k].ptr == NULL) {
			// default value
			memcpy(ptr, type.fields[k].data.ptr, type.fields[k].data.size);
			ptr += type.fields[k].data.size;
		} else if (type.fields[k].resize != 0) {
			data_t temp = resize_data(slots[k], type.fields[k].resize);
			memcpy(ptr, temp.ptr, temp.size);
			ptr += temp.size;
			free_mem(temp.ptr);
		} else {
			memcpy(ptr, slots[k].ptr, slots[k].size);
			ptr += slots[k].size;
			free_mem(slots[k].ptr);
		}
	}

	free_mem(slots);
	return out;
}


data_t
make_type(char* name, list_t list)
{
	// Some explanation is in order. The "list" contains zero or more data_t
	// items. Each of these items corresponds to a data field that the user
	// specified, but not necessarily to a field from the type definition.
	// So here we have to figure out which data item goes where. It is fairly
	// obvious where names items should go, but for items without a name we
	// simply use the first available slot. For any fields that the user did
	// not fill in we use the default value from the type definition. This
	// algorithm allows for variable size fields, such as strings and arrays.

	type_t type = get_type(name);

	data_t* slots = fill_slots(type, list);
	data_t out = convert_slots(type, slots);

	free_mem(name);
	free_mem(list.items);
	return out;
}


list_t
make_field_list(field_t field)
{
	list_t out;
	out.count = 1;
	out.items = alloc_mem(sizeof(field_t));
	*((field_t*)out.items) = field;
	return out;
}


list_t
concat_field_list(list_t list, field_t field)
{
	list_t out;
	out.count = list.count + 1;
	out.items = alloc_mem(out.count * sizeof(field_t));

	memcpy(out.items, list.items, list.count * sizeof(field_t));
	memcpy((field_t*)out.items + list.count, &field, sizeof(field_t));

	free_mem(list.items);
	return out;
}


list_t
make_data_list(data_t data)
{
	list_t out;
	out.count = 1;
	out.items = alloc_mem(sizeof(data_t));
	*((data_t*)out.items) = data;
	return out;
}


list_t
concat_data_list(list_t list, data_t data)
{
	list_t out;
	out.count = list.count + 1;
	out.items = (data_t*)alloc_mem(out.count * sizeof(data_t));

	memcpy(out.items, list.items, list.count * sizeof(data_t));
	memcpy((data_t*)out.items + list.count, &data, sizeof(data_t));

	free_mem(list.items);
	return out;
}


data_t
concat_data(data_t data1, data_t data2)
{
	data_t out = make_data(data1.size + data2.size, get_type("raw"));

	memcpy(out.ptr, data1.ptr, data1.size);
	memcpy((uint8*)out.ptr + data1.size, data2.ptr, data2.size);

	free_mem(data1.ptr);
	free_mem(data2.ptr);
	return out;
}


static data_t
cast_to_uint8(type_t new_type, data_t data)
{
	data_t out = make_data(sizeof(uint8), new_type);

	switch (data.type.code) {
		case B_INT8_TYPE:
		case B_UINT8_TYPE:
			*((uint8*)out.ptr) = *(uint8*)data.ptr;
			break;

		case B_INT16_TYPE:
		case B_UINT16_TYPE:
			*((uint8*)out.ptr) = (uint8)*(uint16*)data.ptr;
			break;

		case B_INT32_TYPE:
		case B_UINT32_TYPE:
		case B_SIZE_T_TYPE:
		case B_SSIZE_T_TYPE:
		case B_TIME_TYPE:
			*((uint8*)out.ptr) = (uint8)*(uint32*)data.ptr;
			break;

		case B_INT64_TYPE:
		case B_UINT64_TYPE:
		case B_OFF_T_TYPE:
			*((uint8*)out.ptr) = (uint8)*(uint64*)data.ptr;
			break;

		default:
			abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	}

	free_mem(data.ptr);
	return out;
}


static data_t
cast_to_uint16(type_t new_type, data_t data)
{
	data_t out = make_data(sizeof(uint16), new_type);

	switch (data.type.code) {
		case B_INT8_TYPE:
		case B_UINT8_TYPE:
			*((uint16*)out.ptr) = (uint16)*(uint8*)data.ptr;
			break;

		case B_INT16_TYPE:
		case B_UINT16_TYPE:
			*((uint16*)out.ptr) = *(uint16*)data.ptr;
			break;

		case B_INT32_TYPE:
		case B_UINT32_TYPE:
		case B_SIZE_T_TYPE:
		case B_SSIZE_T_TYPE:
		case B_TIME_TYPE:
			*((uint16*)out.ptr) = (uint16)*(uint32*)data.ptr;
			break;

		case B_INT64_TYPE:
		case B_UINT64_TYPE:
		case B_OFF_T_TYPE:
			*((uint16*)out.ptr) = (uint16)*(uint64*)data.ptr;
			break;

		default:
			abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	}

	free_mem(data.ptr);
	return out;
}


static data_t
cast_to_uint32(type_t new_type, data_t data)
{
	data_t out = make_data(sizeof(uint32), new_type);

	switch (data.type.code) {
		case B_INT8_TYPE:
		case B_UINT8_TYPE:
			*((uint32*)out.ptr) = (uint32)*(uint8*)data.ptr;
			break;

		case B_INT16_TYPE:
		case B_UINT16_TYPE:
			*((uint32*)out.ptr) = (uint32)*(uint16*)data.ptr;
			break;

		case B_INT32_TYPE:
		case B_UINT32_TYPE:
		case B_SIZE_T_TYPE:
		case B_SSIZE_T_TYPE:
		case B_TIME_TYPE:
			*((uint32*)out.ptr) = *(uint32*)data.ptr;
			break;

		case B_INT64_TYPE:
		case B_UINT64_TYPE:
		case B_OFF_T_TYPE:
			*((uint32*)out.ptr) = (uint32)*(uint64*)data.ptr;
			break;

		default:
			abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	}

	free_mem(data.ptr);
	return out;
}


static data_t
cast_to_uint64(type_t new_type, data_t data)
{
	data_t out = make_data(sizeof(uint64), new_type);

	switch (data.type.code) {
		case B_INT8_TYPE:
		case B_UINT8_TYPE:
			*((uint64*)out.ptr) = (uint64)*(uint8*)data.ptr;
			break;

		case B_INT16_TYPE:
		case B_UINT16_TYPE:
			*((uint64*)out.ptr) = (uint64)*(uint16*)data.ptr;
			break;

		case B_INT32_TYPE:
		case B_UINT32_TYPE:
		case B_SIZE_T_TYPE:
		case B_SSIZE_T_TYPE:
		case B_TIME_TYPE:
			*((uint64*)out.ptr) = (uint64)*(uint32*)data.ptr;
			break;

		case B_INT64_TYPE:
		case B_UINT64_TYPE:
		case B_OFF_T_TYPE:
			*((uint64*)out.ptr) = *(uint64*)data.ptr;
			break;

		default:
			abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	}

	free_mem(data.ptr);
	return out;
}


static data_t
cast_to_float(type_t new_type, data_t data)
{
	data_t out = make_data(sizeof(float), new_type);

	switch (data.type.code) {
		case B_INT8_TYPE:
		case B_UINT8_TYPE:
			*((float*)out.ptr) = (float)*((uint8*)data.ptr);
			break;

		case B_INT16_TYPE:
		case B_UINT16_TYPE:
			*((float*)out.ptr) = (float)*((uint16*)data.ptr);
			break;

		case B_INT32_TYPE:
		case B_UINT32_TYPE:
		case B_SIZE_T_TYPE:
		case B_SSIZE_T_TYPE:
		case B_TIME_TYPE:
			*((float*)out.ptr) = (float)*((uint32*)data.ptr);
			break;

		case B_INT64_TYPE:
		case B_UINT64_TYPE:
		case B_OFF_T_TYPE:
			*((float*)out.ptr) = (float)*((uint64*)data.ptr);
			break;

		case B_DOUBLE_TYPE:
			*((float*)out.ptr) = (float)*((double*)data.ptr);
			break;

		default:
			abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	}

	free_mem(data.ptr);
	return out;
}


static data_t
cast_to_double(type_t new_type, data_t data)
{
	data_t out = make_data(sizeof(double), new_type);

	switch (data.type.code) {
		case B_INT8_TYPE:
		case B_UINT8_TYPE:
			*((double*)out.ptr) = (double)*((uint8*)data.ptr);
			break;

		case B_INT16_TYPE:
		case B_UINT16_TYPE:
			*((double*)out.ptr) = (double)*((uint16*)data.ptr);
			break;

		case B_INT32_TYPE:
		case B_UINT32_TYPE:
		case B_SIZE_T_TYPE:
		case B_SSIZE_T_TYPE:
		case B_TIME_TYPE:
			*((double*)out.ptr) = (double)*((uint32*)data.ptr);
			break;

		case B_INT64_TYPE:
		case B_UINT64_TYPE:
		case B_OFF_T_TYPE:
			*((double*)out.ptr) = (double)*((uint64*)data.ptr);
			break;

		case B_FLOAT_TYPE:
			*((double*)out.ptr) = (double)*((float*)data.ptr);
			break;

		default:
			abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	}

	free_mem(data.ptr);
	return out;
}


data_t
cast(type_t newType, data_t data)
{
	if (same_type(newType, data.type)) {
		// you can't cast bool, string,
		// message, or user-defined type
		// to another type, only to same
		return data;
	}

	if (is_builtin_type(newType)) {
		switch (newType.code) {
			case B_INT8_TYPE:
			case B_UINT8_TYPE:
				return cast_to_uint8(newType, data);

			case B_INT16_TYPE:
			case B_UINT16_TYPE:
				return cast_to_uint16(newType, data);

			case B_INT32_TYPE:
			case B_UINT32_TYPE:
			case B_SIZE_T_TYPE:
			case B_SSIZE_T_TYPE:
			case B_TIME_TYPE:
				return cast_to_uint32(newType, data);

			case B_INT64_TYPE:
			case B_UINT64_TYPE:
			case B_OFF_T_TYPE:
				return cast_to_uint64(newType, data);

			case B_FLOAT_TYPE:
				return cast_to_float(newType, data);

			case B_DOUBLE_TYPE:
				return cast_to_double(newType, data);

			case B_RAW_TYPE:
				// you can always cast anything to raw
				data.type = newType;
				return data;
		}
	}

	abort_compile(RDEF_COMPILE_ERR, "cannot cast to this type");
	return data;
}


data_t
unary_expr(data_t data, char oper)
{
	data_t op = cast_to_uint32(get_type("int32"), data);
	int32 i = *((int32*)op.ptr);
	data_t out;

	switch (oper) {
		case '~':
			out = make_int(~i);
			break;
	}

	free_mem(op.ptr);

	return cast(get_type("int32"), out);
}


data_t
binary_expr(data_t data1, data_t data2, char oper)
{
	data_t op1 = cast_to_uint32(get_type("int32"), data1);
	data_t op2 = cast_to_uint32(get_type("int32"), data2);
	int32 i1 = *((int32*) op1.ptr);
	int32 i2 = *((int32*) op2.ptr);
	data_t out;

	switch (oper) {
		case '+':
			out = make_int(i1 + i2);
			break;
		case '-':
			out = make_int(i1 - i2);
			break;
		case '*':
			out = make_int(i1 * i2);
			break;

		case '/':
			if (i2 == 0)
				abort_compile(RDEF_COMPILE_ERR, "division by zero");
			else
				 out = make_int(i1 / i2);
			break;

		case '%':
			if (i2 == 0)
				abort_compile(RDEF_COMPILE_ERR, "division by zero");
			else
				out = make_int(i1 % i2);
			break;

		case '|':
			out = make_int(i1 | i2);
			break;
		case '^':
			out = make_int(i1 ^ i2);
			break;
		case '&':
			out = make_int(i1 & i2);
			break;
	}

	free_mem(op1.ptr);
	free_mem(op2.ptr);

	return cast(get_type("int32"), out);
}


void
add_resource(res_id_t id, type_code code, data_t data)
{
	if (!id.has_id)
		id.id = data.type.def_id;

	if (!id.has_name)
		id.name = (char*)data.type.def_name;

	if (!(flags & RDEF_MERGE_RESOURCES) && rsrc.HasResource(code, id.id))
		abort_compile(RDEF_COMPILE_ERR, "duplicate resource");

	status_t err = rsrc.AddResource(code, id.id, data.ptr, data.size, id.name);
	if (err != B_OK) {
		rdef_err = RDEF_WRITE_ERR;
		rdef_err_line = 0;
		strcpy(rdef_err_file, rsrc_file);
		sprintf(rdef_err_msg, "cannot add resource (%s)", strerror(err));
		abort_compile();
	}

	if (id.has_name)
		free_mem(id.name);

	free_mem(data.ptr);
}


static void
add_point_type()
{
	field_t* fields  = (field_t*)alloc_mem(2 * sizeof(field_t));
	fields[0].type   = get_type("float");
	fields[0].name   = "x";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);
	fields[1].type   = get_type("float");
	fields[1].name   = "y";
	fields[1].resize = 0;
	fields[1].data   = make_default(fields[1].type);

	type_t type;
	type.code     = B_POINT_TYPE;
	type.name     = "point";
	type.fields   = fields;
	type.count    = 2;
	type.def_id   = 1;
	type.def_name = NULL;

	type_table.insert(make_pair(type.name, type));
}


static void
add_rect_type()
{
	field_t* fields  = (field_t*)alloc_mem(4 * sizeof(field_t));
	fields[0].type   = get_type("float");
	fields[0].name   = "left";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);
	fields[1].type   = get_type("float");
	fields[1].name   = "top";
	fields[1].resize = 0;
	fields[1].data   = make_default(fields[1].type);
	fields[2].type   = get_type("float");
	fields[2].name   = "right";
	fields[2].resize = 0;
	fields[2].data   = make_default(fields[2].type);
	fields[3].type   = get_type("float");
	fields[3].name   = "bottom";
	fields[3].resize = 0;
	fields[3].data   = make_default(fields[3].type);

	type_t type;
	type.code     = B_RECT_TYPE;
	type.name     = "rect";
	type.fields   = fields;
	type.count    = 4;
	type.def_id   = 1;
	type.def_name = NULL;

	type_table.insert(make_pair(type.name, type));
}


static void
add_rgb_color_type()
{
	field_t* fields  = (field_t*)alloc_mem(4 * sizeof(field_t));
	fields[0].type   = get_type("uint8");
	fields[0].name   = "red";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);
	fields[1].type   = get_type("uint8");
	fields[1].name   = "green";
	fields[1].resize = 0;
	fields[1].data   = make_default(fields[1].type);
	fields[2].type   = get_type("uint8");
	fields[2].name   = "blue";
	fields[2].resize = 0;
	fields[2].data   = make_default(fields[2].type);
	fields[3].type   = get_type("uint8");
	fields[3].name   = "alpha";
	fields[3].resize = 0;
	fields[3].data   = make_default(fields[3].type);

	*((uint8*)fields[3].data.ptr) = 255;

	type_t type;
	type.code     = B_RGB_COLOR_TYPE;
	type.name     = "rgb_color";
	type.fields   = fields;
	type.count    = 4;
	type.def_id   = 1;
	type.def_name = NULL;

	type_table.insert(make_pair(type.name, type));
}


static void
add_app_signature_type()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("string");
	fields[0].name   = "signature";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);

	type_t type;
	type.code     = 'MIMS';
	type.name     = "app_signature";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 1;
	type.def_name = "BEOS:APP_SIG";

	type_table.insert(make_pair(type.name, type));
}


static void
add_app_name_catalog_entry()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("string");
	fields[0].name   = "catalog_entry";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);

	type_t type;
	type.code     = B_STRING_TYPE;
	type.name     = "app_name_catalog_entry";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 1;
	type.def_name = "SYS:NAME";

	type_table.insert(make_pair(type.name, type));
}


static void
add_app_flags()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("uint32");
	fields[0].name   = "flags";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);

	type_t type;
	type.code     = 'APPF';
	type.name     = "app_flags";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 1;
	type.def_name = "BEOS:APP_FLAGS";

	type_table.insert(make_pair(type.name, type));
}


static void
add_app_version()
{
	field_t* fields  = (field_t*)alloc_mem(7 * sizeof(field_t));
	fields[0].type   = get_type("uint32");
	fields[0].name   = "major";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);
	fields[1].type   = get_type("uint32");
	fields[1].name   = "middle";
	fields[1].resize = 0;
	fields[1].data   = make_default(fields[1].type);
	fields[2].type   = get_type("uint32");
	fields[2].name   = "minor";
	fields[2].resize = 0;
	fields[2].data   = make_default(fields[2].type);
	fields[3].type   = get_type("uint32");
	fields[3].name   = "variety";
	fields[3].resize = 0;
	fields[3].data   = make_default(fields[3].type);
	fields[4].type   = get_type("uint32");
	fields[4].name   = "internal";
	fields[4].resize = 0;
	fields[4].data   = make_default(fields[4].type);
	fields[5].type   = get_type("string");
	fields[5].name   = "short_info";
	fields[5].resize = 64;
	fields[5].data   = make_data(fields[5].resize, fields[5].type);
	fields[6].type   = get_type("string");
	fields[6].name   = "long_info";
	fields[6].resize = 256;
	fields[6].data   = make_data(fields[6].resize, fields[6].type);

	memset(fields[5].data.ptr, '\0', fields[5].data.size);
	memset(fields[6].data.ptr, '\0', fields[6].data.size);

	type_t type;
	type.code     = 'APPV';
	type.name     = "app_version";
	type.fields   = fields;
	type.count    = 7;
	type.def_id   = 1;
	type.def_name = "BEOS:APP_VERSION";

	type_table.insert(make_pair(type.name, type));
}


static void
add_png_icon()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("raw");
	fields[0].name   = "icon";
	fields[0].resize = 0;
	fields[0].data   = make_data(fields[0].resize, fields[0].type);

	type_t type;
	type.code     = 'PNG ';
	type.name     = "png_icon";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 101;
	type.def_name = "BEOS:ICON";

	type_table.insert(make_pair(type.name, type));
}


static void
add_vector_icon()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("raw");
	fields[0].name   = "icon";
	fields[0].resize = 0;
	fields[0].data   = make_data(fields[0].resize, fields[0].type);

	type_t type;
	type.code     = 'VICN';
	type.name     = "vector_icon";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 101;
	type.def_name = "BEOS:ICON";

	type_table.insert(make_pair(type.name, type));
}


static void
add_large_icon()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("raw");
	fields[0].name   = "icon";
	fields[0].resize = 1024;
	fields[0].data   = make_data(fields[0].resize, fields[0].type);

	type_t type;
	type.code     = 'ICON';
	type.name     = "large_icon";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 101;
	type.def_name = "BEOS:L:STD_ICON";

	type_table.insert(make_pair(type.name, type));
}


static void
add_mini_icon()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("raw");
	fields[0].name   = "icon";
	fields[0].resize = 256;
	fields[0].data   = make_data(fields[0].resize, fields[0].type);

	type_t type;
	type.code     = 'MICN';
	type.name     = "mini_icon";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 101;
	type.def_name = "BEOS:M:STD_ICON";

	type_table.insert(make_pair(type.name, type));
}


static void
add_file_types()
{
	field_t* fields  = (field_t*)alloc_mem(1 * sizeof(field_t));
	fields[0].type   = get_type("message");
	fields[0].name   = "types";
	fields[0].resize = 0;
	fields[0].data   = make_default(fields[0].type);

	type_t type;
	type.code     = 'MSGG';
	type.name     = "file_types";
	type.fields   = fields;
	type.count    = 1;
	type.def_id   = 1;
	type.def_name = "BEOS:FILE_TYPES";

	type_table.insert(make_pair(type.name, type));
}


static void
add_define(const char* name, int32 value)
{
	define_t define;
	define.name  = name;
	define.value = value;

	define_table.insert(make_pair(define.name, define));
}


void
init_parser()
{
	add_builtin_type(B_BOOL_TYPE,    "bool");
	add_builtin_type(B_INT8_TYPE,    "int8");
	add_builtin_type(B_UINT8_TYPE,   "uint8");
	add_builtin_type(B_INT16_TYPE,   "int16");
	add_builtin_type(B_UINT16_TYPE,  "uint16");
	add_builtin_type(B_INT32_TYPE,   "int32");
	add_builtin_type(B_UINT32_TYPE,  "uint32");
	add_builtin_type(B_SIZE_T_TYPE,  "size_t");
	add_builtin_type(B_SSIZE_T_TYPE, "ssize_t");
	add_builtin_type(B_TIME_TYPE,    "time_t");
	add_builtin_type(B_INT64_TYPE,   "int64");
	add_builtin_type(B_UINT64_TYPE,  "uint64");
	add_builtin_type(B_OFF_T_TYPE,   "off_t");
	add_builtin_type(B_FLOAT_TYPE,   "float");
	add_builtin_type(B_DOUBLE_TYPE,  "double");
	add_builtin_type(B_STRING_TYPE,  "string");
	add_builtin_type(B_RAW_TYPE,     "raw");
	add_builtin_type(B_RAW_TYPE,     "buffer");
	add_builtin_type(B_MESSAGE_TYPE, "message");

	add_point_type();
	add_rect_type();
	add_rgb_color_type();
	add_app_signature_type();
	add_app_name_catalog_entry();
	add_app_flags();
	add_app_version();
	add_large_icon();
	add_mini_icon();
	add_vector_icon();
	add_png_icon();
	add_file_types();

	add_define("B_SINGLE_LAUNCH",    0x0);
	add_define("B_MULTIPLE_LAUNCH",  0x1);
	add_define("B_EXCLUSIVE_LAUNCH", 0x2);
	add_define("B_BACKGROUND_APP",   0x4);
	add_define("B_ARGV_ONLY",        0x8);

	add_define("B_APPV_DEVELOPMENT",   0x0);
	add_define("B_APPV_ALPHA",         0x1);
	add_define("B_APPV_BETA",          0x2);
	add_define("B_APPV_GAMMA",         0x3);
	add_define("B_APPV_GOLDEN_MASTER", 0x4);
	add_define("B_APPV_FINAL",         0x5);
}


void
clean_up_parser()
{
	// The symbol table entries have several malloc'ed objects associated
	// with them (such as their name). They were allocated with alloc_mem(),
	// so we don't need to free them here; compile.cpp already does that
	// when it cleans up. However, we do need to remove the entries from
	// the tables, otherwise they will still be around the next time we are
	// asked to compile something.

#ifdef DEBUG
	// Note that in DEBUG mode, we _do_ free these items, so they don't show
	// up in the mem leak statistics. The names etc of builtin items are not
	// alloc_mem()'d but we still free_mem() them. Not entirely correct, but
	// it doesn't seem to hurt, and we only do it in DEBUG mode anyway.

	for (sym_iter_t i = symbol_table.begin(); i != symbol_table.end(); ++i) {
		free_mem((void*) i->first);
	}

	for (type_iter_t i = type_table.begin(); i != type_table.end(); ++i) {
		free_mem((void*) i->first);
		type_t type = i->second;

		for (int32 t = 0; t < type.count; ++t) {
			free_mem((void*) type.fields[t].name);
			free_mem((void*) type.fields[t].data.ptr);
		}
		free_mem((void*) type.fields);
		free_mem((void*) type.name);
		free_mem((void*) type.def_name);
	}
#endif

	symbol_table.clear();
	type_table.clear();
	define_table.clear();
}

