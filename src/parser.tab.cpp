/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

  #include "../include/ast.hpp"
  #include <cassert>
  #include <stdio.h>

  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

  // extern void yyset_in(FILE* fd);

#line 127 "src/parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_AUTO = 258,
    T_BREAK = 259,
    T_CASE = 260,
    T_CHAR = 261,
    T_CONST = 262,
    T_CONTINUE = 263,
    T_DEFAULT = 264,
    T_DO = 265,
    T_DOUBLE = 266,
    T_ELSE = 267,
    T_ENUM = 268,
    T_EXTERN = 269,
    T_FLOAT = 270,
    T_FOR = 271,
    T_GOTO = 272,
    T_IF = 273,
    T_INT = 274,
    T_LONG = 275,
    T_REGISTER = 276,
    T_RETURN = 277,
    T_SHORT = 278,
    T_SIGNED = 279,
    T_SIZEOF = 280,
    T_STATIC = 281,
    T_STRUCT = 282,
    T_SWITCH = 283,
    T_TYPEDEF = 284,
    T_UNION = 285,
    T_UNSIGNED = 286,
    T_VOID = 287,
    T_WHILE = 288,
    T_AND = 289,
    T_NOT = 290,
    T_INVERT = 291,
    T_MINUS = 292,
    T_PLUS = 293,
    T_MULT = 294,
    T_DIV = 295,
    T_MOD = 296,
    T_LT = 297,
    T_GT = 298,
    T_XOR = 299,
    T_OR = 300,
    T_QUESTION = 301,
    T_DOT = 302,
    T_ELLIPSIS = 303,
    T_RSHIFT_ASSIGN = 304,
    T_LSHIFT_ASSIGN = 305,
    T_ADD_ASSIGN = 306,
    T_SUB_ASSIGN = 307,
    T_MUL_ASSIGN = 308,
    T_DIV_ASSIGN = 309,
    T_MOD_ASSIGN = 310,
    T_AND_ASSIGN = 311,
    T_XOR_ASSIGN = 312,
    T_OR_ASSIGN = 313,
    T_EQ_ASSIGN = 314,
    T_RSHIFT_OP = 315,
    T_LSHIFT_OP = 316,
    T_INC_OP = 317,
    T_DEC_OP = 318,
    T_PTR_OP = 319,
    T_AND_OP = 320,
    T_OR_OP = 321,
    T_LE_OP = 322,
    T_GE_OP = 323,
    T_EQ_OP = 324,
    T_NE_OP = 325,
    T_SEMICOLON = 326,
    T_COMMA = 327,
    T_COLON = 328,
    T_L_BRACE = 329,
    T_R_BRACE = 330,
    T_L_PARENTHESIS = 331,
    T_R_PARENTHESIS = 332,
    T_L_BRACKET = 333,
    T_R_BRACKET = 334,
    T_IDENTIFIER = 335,
    T_INT_CONST = 336,
    T_FLOAT_CONST = 337,
    T_CHAR_CONST = 338,
    T_STRING_CONST = 339
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "src/parser.y"

  const Node *node;
  double float_constant;
  long long int integer_constant;
  std::string *string;

#line 230 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

#define YYUNDEFTOK  2
#define YYMAXUTOK   339


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   101,   105,   110,   111,   115,   116,   120,   127,
     128,   132,   133,   137,   138,   139,   140,   141,   145,   146,
     180,   181,   186,   187,   194,   201,   202,   203,   230,   235,
     236,   237,   242,   247,   248,   251,   252,   253,   257,   258,
     259,   263,   278,   279,   280,   281,   285,   286,   287,   291,
     297,   298,   299,   300,   301,   305,   306,   307,   311,   316,
     321,   326,   327,   331,   332,   336,   343,   344,   348,   349,
     353,   354,   360,   361,   362,   363,   364,   365,   366,   367,
     368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AUTO", "T_BREAK", "T_CASE", "T_CHAR",
  "T_CONST", "T_CONTINUE", "T_DEFAULT", "T_DO", "T_DOUBLE", "T_ELSE",
  "T_ENUM", "T_EXTERN", "T_FLOAT", "T_FOR", "T_GOTO", "T_IF", "T_INT",
  "T_LONG", "T_REGISTER", "T_RETURN", "T_SHORT", "T_SIGNED", "T_SIZEOF",
  "T_STATIC", "T_STRUCT", "T_SWITCH", "T_TYPEDEF", "T_UNION", "T_UNSIGNED",
  "T_VOID", "T_WHILE", "T_AND", "T_NOT", "T_INVERT", "T_MINUS", "T_PLUS",
  "T_MULT", "T_DIV", "T_MOD", "T_LT", "T_GT", "T_XOR", "T_OR",
  "T_QUESTION", "T_DOT", "T_ELLIPSIS", "T_RSHIFT_ASSIGN",
  "T_LSHIFT_ASSIGN", "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN",
  "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_AND_ASSIGN", "T_XOR_ASSIGN",
  "T_OR_ASSIGN", "T_EQ_ASSIGN", "T_RSHIFT_OP", "T_LSHIFT_OP", "T_INC_OP",
  "T_DEC_OP", "T_PTR_OP", "T_AND_OP", "T_OR_OP", "T_LE_OP", "T_GE_OP",
  "T_EQ_OP", "T_NE_OP", "T_SEMICOLON", "T_COMMA", "T_COLON", "T_L_BRACE",
  "T_R_BRACE", "T_L_PARENTHESIS", "T_R_PARENTHESIS", "T_L_BRACKET",
  "T_R_BRACKET", "T_IDENTIFIER", "T_INT_CONST", "T_FLOAT_CONST",
  "T_CHAR_CONST", "T_STRING_CONST", "$accept", "ROOT", "FRAME",
  "FUNCTION_DECLARATION", "FUNCTION_DEFINITION", "WRAPPED_ARGUMENTS",
  "MULTIPLE_ARGUMENTS", "SINGLE_ARGUMENT", "SCOPE", "MULTIPLE_STATEMENTS",
  "SINGLE_STATEMENT", "SELECTION_STATEMENT", "ITERATION_STATEMENT",
  "JUMP_STATEMENT", "EXPRESSION_STATEMENT", "EXPRESSION",
  "VARIABLE_DECLARATION", "ASSIGNMENT_STATEMENT",
  "MATH_OR_BITWISE_EXPRESSION", "PRIMARY_EXPRESSION", "POSTFIX_EXPRESSION",
  "UNARY_EXPRESSION", "MULTIPLICATIVE_EXPRESSION", "ADDITIVE_EXPRESSION",
  "SHIFT_EXPRESSION", "RELATIONAL_EXPRESSION", "EQUALITY_EXPRESSION",
  "BITWISE_AND_EXPRESSION", "BITWISE_XOR_EXPRESSION",
  "BITWISE_OR_EXPRESSION", "BOOLEAN_AND_EXPRESSION",
  "BOOLEAN_OR_EXPRESSION", "CONDITIONAL_EXPRESSION", "WRAPPED_PARAMETERS",
  "MULTIPLE_PARAMETERS", "DECLARATOR", "TYPE_SPECIFIER", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339
};
# endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     137,  -110,  -110,  -110,   -59,   -57,  -110,  -110,   143,  -110,
    -110,  -110,  -110,   -52,   -49,    66,   112,  -110,  -110,  -110,
      27,   220,  -110,  -110,    26,  -110,   137,  -110,  -110,  -110,
    -110,   -30,   -28,  -110,  -110,  -110,   -17,  -110,    72,    23,
    -110,   -32,    -6,  -110,  -110,  -110,   -26,    17,  -110,   -39,
     -33,   166,   166,  -110,     9,  -110,   -33,   166,  -110,  -110,
    -110,    16,    24,    28,  -110,  -110,  -110,  -110,    29,  -110,
    -110,  -110,  -110,  -110,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   126,  -110,
    -110,   -43,   166,    31,  -110,    44,    41,  -110,  -110,  -110,
    -110,  -110,  -110,    72,    72,  -110,  -110,  -110,  -110,   -32,
     -32,  -110,   -26,  -110,  -110,  -110,    53,    49,    47,   -53,
     166,   137,   137,   112,  -110,  -110,    50,    57,   -33,  -110,
    -110,    54,   118,  -110,  -110,  -110,   242,  -110,   137,   137,
    -110,  -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    83,    88,    87,     0,     0,    85,    86,     0,    84,
      89,    90,    82,     0,     0,     0,     0,    80,    44,    45,
       0,     2,     6,     5,     4,     3,    22,    27,    26,    25,
      24,     0,     0,    36,    37,    48,    51,    52,    56,    59,
      60,    65,    68,    69,    70,    71,    73,    75,    42,    43,
       0,     0,     0,    32,     0,    35,     0,     0,    81,    20,
      23,     0,     0,    43,     1,    10,     9,     8,     0,    21,
      34,     7,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      38,    41,     0,     0,    33,    41,     0,    19,    46,    11,
      53,    54,    55,    58,    57,    61,    62,    63,    64,    66,
      67,    72,    74,    39,    40,    77,    79,     0,     0,     0,
       0,     0,     0,     0,    76,    15,     0,    17,     0,    12,
      13,     0,    28,    30,    78,    14,     0,    18,     0,     0,
      16,    31,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,  -110,  -110,   111,   113,  -110,    -1,  -110,     4,     8,
    -109,  -110,  -110,  -110,   -37,    -3,     7,   -47,   -14,  -110,
    -110,    40,    -9,  -110,    14,    -8,  -110,  -110,  -110,    48,
      58,  -110,  -110,  -110,    13,     0,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    23,   119,   126,   127,    60,    25,
      26,    27,    28,    29,    30,    31,    55,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    89,   117,    63,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    62,    90,    24,    54,    14,    32,    49,    90,
      79,    80,   132,   133,    92,    49,    87,    51,   129,    52,
      87,    15,    50,    61,    57,    67,    49,    64,    68,   141,
     142,    58,   -41,   118,    69,    81,    82,    88,   -41,    85,
     113,    70,   -23,    71,   -23,    72,    73,    17,   -23,    93,
      91,    49,    49,     1,    96,   120,    95,    49,     2,   -23,
      77,    78,     3,    83,    84,   -23,     6,     7,   103,   104,
       9,    10,     1,   114,   116,   109,   110,     2,    11,    12,
      94,     3,     4,    86,     5,     6,     7,    49,     8,     9,
      10,    97,    49,   105,   106,   107,   108,    11,    12,    13,
      99,    98,   -23,    87,    88,    14,   -23,   -23,   121,   116,
     -23,    74,    75,    76,   100,   101,   102,   131,   122,   128,
      49,    49,    49,   130,   125,   123,   124,   135,   137,   136,
     139,   138,    65,   111,    66,   140,   134,   128,    49,    49,
      15,    59,    16,     1,   112,     0,    17,    18,     2,     1,
      19,    14,     3,     4,     2,     5,     6,     7,     3,     8,
       9,    10,     6,     7,     0,    14,     9,    10,    11,    12,
      13,     0,     1,     0,    11,    12,    14,     2,     0,     0,
       0,     3,    14,     0,     0,     6,     7,     0,    16,     9,
      10,     0,    17,    18,     0,     0,    19,    11,    12,     0,
       0,     0,    16,   115,     0,    14,    17,    18,     0,     0,
      19,    15,     0,    16,    53,     0,     0,    17,    18,    16,
       0,    19,     0,    17,    18,     0,     1,    19,     0,     0,
       0,     2,     0,     0,     0,     3,     0,     0,     0,     6,
       7,     0,    16,     9,    10,     0,    17,    18,     1,     0,
      19,    11,    12,     2,     0,     0,     0,     3,     0,     0,
       0,     6,     7,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
       0,     0,    16,    50,     0,     8,    39,     0,     8,    56,
      42,    43,   121,   122,    51,    15,    59,    76,    71,    76,
      59,    74,    21,    15,    76,    21,    26,     0,    21,   138,
     139,    80,    71,    76,    26,    67,    68,    76,    77,    65,
      87,    71,    16,    71,    18,    62,    63,    80,    22,    52,
      50,    51,    52,     6,    57,    92,    56,    57,    11,    33,
      37,    38,    15,    69,    70,    39,    19,    20,    77,    78,
      23,    24,     6,    87,    88,    83,    84,    11,    31,    32,
      71,    15,    16,    66,    18,    19,    20,    87,    22,    23,
      24,    75,    92,    79,    80,    81,    82,    31,    32,    33,
      71,    77,    76,    59,    76,    39,    80,    81,    77,   123,
      84,    39,    40,    41,    74,    75,    76,   120,    77,   118,
     120,   121,   122,   119,    77,    72,    77,    77,   128,    72,
      12,    77,    21,    85,    21,   136,   123,   136,   138,   139,
      74,    75,    76,     6,    86,    -1,    80,    81,    11,     6,
      84,    39,    15,    16,    11,    18,    19,    20,    15,    22,
      23,    24,    19,    20,    -1,    39,    23,    24,    31,    32,
      33,    -1,     6,    -1,    31,    32,    39,    11,    -1,    -1,
      -1,    15,    39,    -1,    -1,    19,    20,    -1,    76,    23,
      24,    -1,    80,    81,    -1,    -1,    84,    31,    32,    -1,
      -1,    -1,    76,    77,    -1,    39,    80,    81,    -1,    -1,
      84,    74,    -1,    76,    71,    -1,    -1,    80,    81,    76,
      -1,    84,    -1,    80,    81,    -1,     6,    84,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,
      20,    -1,    76,    23,    24,    -1,    80,    81,     6,    -1,
      84,    31,    32,    11,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    11,    15,    16,    18,    19,    20,    22,    23,
      24,    31,    32,    33,    39,    74,    76,    80,    81,    84,
      86,    87,    88,    89,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   120,
     121,    76,    76,    71,   100,   101,   121,    76,    80,    75,
      93,    94,   103,   120,     0,    88,    89,    93,   101,    94,
      71,    71,    62,    63,    39,    40,    41,    37,    38,    42,
      43,    67,    68,    69,    70,    65,    66,    59,    76,   118,
     102,   120,    99,   100,    71,   120,   100,    75,    77,    71,
     106,   106,   106,   107,   107,   109,   109,   109,   109,   110,
     110,   114,   115,   102,   103,    77,   103,   119,    76,    90,
      99,    77,    77,    72,    77,    77,    91,    92,   121,    71,
      93,   100,    95,    95,   119,    77,    72,   120,    77,    12,
      91,    95,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    89,    90,    90,    91,    91,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    99,   100,   100,   100,   101,   102,
     102,   102,   103,   104,   104,   104,   104,   104,   105,   105,
     105,   106,   107,   107,   107,   107,   108,   108,   108,   109,
     110,   110,   110,   110,   110,   111,   111,   111,   112,   113,
     114,   115,   115,   116,   116,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     4,     4,     3,     2,     3,     1,     2,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     5,     7,
       5,     7,     2,     3,     2,     1,     1,     1,     2,     3,
       3,     1,     1,     1,     1,     1,     3,     2,     1,     2,
       2,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     2,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 75 "src/parser.y"
                { g_root = new RootNode((yyvsp[0].node)); }
#line 1567 "src/parser.tab.cpp"
    break;

  case 3:
#line 78 "src/parser.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 1573 "src/parser.tab.cpp"
    break;

  case 4:
#line 79 "src/parser.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 1579 "src/parser.tab.cpp"
    break;

  case 5:
#line 80 "src/parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1585 "src/parser.tab.cpp"
    break;

  case 6:
#line 81 "src/parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1591 "src/parser.tab.cpp"
    break;

  case 7:
#line 82 "src/parser.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1597 "src/parser.tab.cpp"
    break;

  case 8:
#line 83 "src/parser.y"
                                          { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1603 "src/parser.tab.cpp"
    break;

  case 9:
#line 84 "src/parser.y"
                                         { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1609 "src/parser.tab.cpp"
    break;

  case 10:
#line 85 "src/parser.y"
                                         { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1615 "src/parser.tab.cpp"
    break;

  case 11:
#line 86 "src/parser.y"
                                             { (yyval.node) = new Frame((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1621 "src/parser.tab.cpp"
    break;

  case 12:
#line 101 "src/parser.y"
                                                             { (yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));; }
#line 1627 "src/parser.tab.cpp"
    break;

  case 13:
#line 105 "src/parser.y"
                                                      { (yyval.node) = new FunctionDefinition((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1633 "src/parser.tab.cpp"
    break;

  case 14:
#line 110 "src/parser.y"
                                                        { (yyval.node) = new WrappedArguments((yyvsp[-1].node), NULL); }
#line 1639 "src/parser.tab.cpp"
    break;

  case 15:
#line 111 "src/parser.y"
                                                        { (yyval.node) = new WrappedArguments(NULL, NULL); }
#line 1645 "src/parser.tab.cpp"
    break;

  case 16:
#line 115 "src/parser.y"
                                                { (yyval.node) = new MultipleArguments((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1651 "src/parser.tab.cpp"
    break;

  case 17:
#line 116 "src/parser.y"
                                                { (yyval.node) = new MultipleArguments((yyvsp[0].node), NULL); }
#line 1657 "src/parser.tab.cpp"
    break;

  case 18:
#line 120 "src/parser.y"
                                { (yyval.node) = new VariableDeclaration(NULL, (yyvsp[0].node)); }
#line 1663 "src/parser.tab.cpp"
    break;

  case 19:
#line 127 "src/parser.y"
                                            { (yyval.node) = new Scope((yyvsp[-1].node)); }
#line 1669 "src/parser.tab.cpp"
    break;

  case 20:
#line 128 "src/parser.y"
                                       { (yyval.node) = new Scope(NULL); }
#line 1675 "src/parser.tab.cpp"
    break;

  case 21:
#line 132 "src/parser.y"
                                         { (yyval.node) = new MultipleStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1681 "src/parser.tab.cpp"
    break;

  case 22:
#line 133 "src/parser.y"
                                    { (yyval.node) = new MultipleStatements((yyvsp[0].node), NULL); }
#line 1687 "src/parser.tab.cpp"
    break;

  case 23:
#line 137 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1693 "src/parser.tab.cpp"
    break;

  case 24:
#line 138 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1699 "src/parser.tab.cpp"
    break;

  case 25:
#line 139 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1705 "src/parser.tab.cpp"
    break;

  case 26:
#line 140 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1711 "src/parser.tab.cpp"
    break;

  case 27:
#line 141 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1717 "src/parser.tab.cpp"
    break;

  case 28:
#line 145 "src/parser.y"
                                                                                              { (yyval.node) = new IfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1723 "src/parser.tab.cpp"
    break;

  case 29:
#line 146 "src/parser.y"
                                                                                              { (yyval.node) = new IfStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1729 "src/parser.tab.cpp"
    break;

  case 30:
#line 180 "src/parser.y"
                                                                                                                    { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1735 "src/parser.tab.cpp"
    break;

  case 31:
#line 181 "src/parser.y"
                                                                                                                 { (yyval.node) = new ForLoop((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1741 "src/parser.tab.cpp"
    break;

  case 32:
#line 186 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("return", NULL); }
#line 1747 "src/parser.tab.cpp"
    break;

  case 33:
#line 187 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("return", (yyvsp[-1].node)); }
#line 1753 "src/parser.tab.cpp"
    break;

  case 34:
#line 194 "src/parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1759 "src/parser.tab.cpp"
    break;

  case 35:
#line 201 "src/parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1765 "src/parser.tab.cpp"
    break;

  case 36:
#line 202 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1771 "src/parser.tab.cpp"
    break;

  case 37:
#line 203 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1777 "src/parser.tab.cpp"
    break;

  case 38:
#line 230 "src/parser.y"
                                                { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1783 "src/parser.tab.cpp"
    break;

  case 39:
#line 235 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 1789 "src/parser.tab.cpp"
    break;

  case 40:
#line 236 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1795 "src/parser.tab.cpp"
    break;

  case 41:
#line 237 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[0].node), NULL, NULL); }
#line 1801 "src/parser.tab.cpp"
    break;

  case 42:
#line 242 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1807 "src/parser.tab.cpp"
    break;

  case 43:
#line 247 "src/parser.y"
                                              { (yyval.node) = (yyvsp[0].node); }
#line 1813 "src/parser.tab.cpp"
    break;

  case 44:
#line 248 "src/parser.y"
                                         { (yyval.node) = new IntegerConstant( (yyvsp[0].integer_constant) ); }
#line 1819 "src/parser.tab.cpp"
    break;

  case 45:
#line 251 "src/parser.y"
                                         { (yyval.node) = new StringLiteral(*(yyvsp[0].string)); }
#line 1825 "src/parser.tab.cpp"
    break;

  case 46:
#line 252 "src/parser.y"
                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1831 "src/parser.tab.cpp"
    break;

  case 47:
#line 253 "src/parser.y"
                                   { (yyval.node) = new FunctionCall((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1837 "src/parser.tab.cpp"
    break;

  case 48:
#line 257 "src/parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1843 "src/parser.tab.cpp"
    break;

  case 49:
#line 258 "src/parser.y"
                                 { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "++"); }
#line 1849 "src/parser.tab.cpp"
    break;

  case 50:
#line 259 "src/parser.y"
                                 { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "--"); }
#line 1855 "src/parser.tab.cpp"
    break;

  case 51:
#line 263 "src/parser.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 1861 "src/parser.tab.cpp"
    break;

  case 52:
#line 278 "src/parser.y"
                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1867 "src/parser.tab.cpp"
    break;

  case 53:
#line 279 "src/parser.y"
                                                       { (yyval.node) = new ArithmeticExpression((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 1873 "src/parser.tab.cpp"
    break;

  case 54:
#line 280 "src/parser.y"
                                                      { (yyval.node) = new ArithmeticExpression((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 1879 "src/parser.tab.cpp"
    break;

  case 55:
#line 281 "src/parser.y"
                                                      { (yyval.node) = new ArithmeticExpression((yyvsp[-2].node), "%", (yyvsp[0].node)); }
#line 1885 "src/parser.tab.cpp"
    break;

  case 56:
#line 285 "src/parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1891 "src/parser.tab.cpp"
    break;

  case 57:
#line 286 "src/parser.y"
                                                          { (yyval.node) = new ArithmeticExpression((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 1897 "src/parser.tab.cpp"
    break;

  case 58:
#line 287 "src/parser.y"
                                                           { (yyval.node) = new ArithmeticExpression((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 1903 "src/parser.tab.cpp"
    break;

  case 59:
#line 291 "src/parser.y"
                                                   { (yyval.node) = (yyvsp[0].node); }
#line 1909 "src/parser.tab.cpp"
    break;

  case 60:
#line 297 "src/parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 1915 "src/parser.tab.cpp"
    break;

  case 61:
#line 298 "src/parser.y"
                                                   { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<", (yyvsp[0].node)); }
#line 1921 "src/parser.tab.cpp"
    break;

  case 62:
#line 299 "src/parser.y"
                                                   { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">", (yyvsp[0].node)); }
#line 1927 "src/parser.tab.cpp"
    break;

  case 63:
#line 300 "src/parser.y"
                                                    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<=", (yyvsp[0].node)); }
#line 1933 "src/parser.tab.cpp"
    break;

  case 64:
#line 301 "src/parser.y"
                                                    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">=", (yyvsp[0].node)); }
#line 1939 "src/parser.tab.cpp"
    break;

  case 65:
#line 305 "src/parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 1945 "src/parser.tab.cpp"
    break;

  case 66:
#line 306 "src/parser.y"
                                                       { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "==", (yyvsp[0].node)); }
#line 1951 "src/parser.tab.cpp"
    break;

  case 67:
#line 307 "src/parser.y"
                                                       { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "!=", (yyvsp[0].node)); }
#line 1957 "src/parser.tab.cpp"
    break;

  case 68:
#line 311 "src/parser.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 1963 "src/parser.tab.cpp"
    break;

  case 69:
#line 316 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1969 "src/parser.tab.cpp"
    break;

  case 70:
#line 321 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1975 "src/parser.tab.cpp"
    break;

  case 71:
#line 326 "src/parser.y"
                                                         { (yyval.node) = (yyvsp[0].node); }
#line 1981 "src/parser.tab.cpp"
    break;

  case 72:
#line 327 "src/parser.y"
                                                           { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "and", (yyvsp[0].node)); }
#line 1987 "src/parser.tab.cpp"
    break;

  case 73:
#line 331 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1993 "src/parser.tab.cpp"
    break;

  case 74:
#line 332 "src/parser.y"
                                                          { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "or", (yyvsp[0].node)); }
#line 1999 "src/parser.tab.cpp"
    break;

  case 75:
#line 336 "src/parser.y"
                                                                     { (yyval.node) = (yyvsp[0].node); }
#line 2005 "src/parser.tab.cpp"
    break;

  case 76:
#line 343 "src/parser.y"
                                                         { (yyval.node) = new WrappedParameters((yyvsp[-1].node), NULL); }
#line 2011 "src/parser.tab.cpp"
    break;

  case 77:
#line 344 "src/parser.y"
                                                          { (yyval.node) = new WrappedParameters(NULL, NULL); }
#line 2017 "src/parser.tab.cpp"
    break;

  case 78:
#line 348 "src/parser.y"
                                                           { (yyval.node) = new MultipleParameters((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2023 "src/parser.tab.cpp"
    break;

  case 79:
#line 349 "src/parser.y"
                                                      { (yyval.node) = new MultipleParameters((yyvsp[0].node), NULL); }
#line 2029 "src/parser.tab.cpp"
    break;

  case 80:
#line 353 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[0].string), "normal", NULL); delete (yyvsp[0].string); }
#line 2035 "src/parser.tab.cpp"
    break;

  case 81:
#line 354 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[0].string), "pointer", NULL); delete (yyvsp[0].string); }
#line 2041 "src/parser.tab.cpp"
    break;

  case 82:
#line 360 "src/parser.y"
               { (yyval.node) = new TypeSpecifier("void"); }
#line 2047 "src/parser.tab.cpp"
    break;

  case 83:
#line 361 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("char"); }
#line 2053 "src/parser.tab.cpp"
    break;

  case 84:
#line 362 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("short"); }
#line 2059 "src/parser.tab.cpp"
    break;

  case 85:
#line 363 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("int"); }
#line 2065 "src/parser.tab.cpp"
    break;

  case 86:
#line 364 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("long"); }
#line 2071 "src/parser.tab.cpp"
    break;

  case 87:
#line 365 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("float"); }
#line 2077 "src/parser.tab.cpp"
    break;

  case 88:
#line 366 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("double"); }
#line 2083 "src/parser.tab.cpp"
    break;

  case 89:
#line 367 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("signed int"); }
#line 2089 "src/parser.tab.cpp"
    break;

  case 90:
#line 368 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("unsigned int"); }
#line 2095 "src/parser.tab.cpp"
    break;


#line 2099 "src/parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 371 "src/parser.y"


// Definition of variable (to match declaration earlier).
const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
