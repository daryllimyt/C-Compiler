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
    T_STRING_CONST = 339,
    T_BOOL = 340
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

#line 231 "src/parser.tab.cpp"

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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1050

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

#define YYUNDEFTOK  2
#define YYMAXUTOK   340


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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    81,    82,    83,    84,    85,    87,    88,
      89,    90,    91,    92,    93,    97,   101,   106,   107,   111,
     112,   116,   119,   120,   124,   125,   129,   130,   134,   135,
     139,   140,   141,   142,   143,   144,   145,   150,   151,   156,
     157,   161,   162,   166,   167,   168,   169,   170,   174,   180,
     181,   186,   187,   188,   189,   190,   195,   196,   197,   198,
     202,   203,   204,   205,   209,   210,   217,   218,   219,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     247,   248,   249,   253,   257,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   274,   275,   276,   277,
     281,   282,   286,   287,   288,   290,   291,   292,   293,   294,
     299,   300,   301,   305,   306,   310,   311,   312,   313,   314,
     315,   316,   320,   321,   322,   323,   327,   328,   329,   333,
     334,   335,   339,   340,   341,   342,   343,   347,   348,   349,
     353,   354,   358,   359,   363,   364,   368,   369,   373,   374,
     378
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
  "T_CHAR_CONST", "T_STRING_CONST", "T_BOOL", "$accept", "ROOT", "FRAME",
  "FUNCTION_DECLARATION", "FUNCTION_DEFINITION", "WRAPPED_ARGUMENTS",
  "MULTIPLE_ARGUMENTS", "SINGLE_ARGUMENT", "WRAPPED_PARAMETERS",
  "MULTIPLE_PARAMETERS", "SCOPE", "MULTIPLE_STATEMENTS",
  "SINGLE_STATEMENT", "ENUMERATION", "MULTIPLE_ENUMERATORS",
  "SINGLE_ENUMERATOR", "SELECTION_STATEMENT", "WRAPPED_CASE_STATEMENTS",
  "MULTIPLE_CASE_STATEMENTS", "SINGLE_CASE_STATEMENT",
  "ITERATION_STATEMENT", "JUMP_STATEMENT", "EXPRESSION_STATEMENT",
  "EXPRESSION", "ASSIGNMENT_OPERATOR", "DECLARATOR",
  "VARIABLE_DECLARATION", "TYPE_DEF", "TYPE_SPECIFIER",
  "ASSIGNMENT_STATEMENT", "MATH_OR_BITWISE_EXPRESSION",
  "PRIMARY_EXPRESSION", "POSTFIX_EXPRESSION", "UNARY_EXPRESSION",
  "UNARY_OPERATOR", "MULTIPLICATIVE_EXPRESSION", "ADDITIVE_EXPRESSION",
  "SHIFT_EXPRESSION", "RELATIONAL_EXPRESSION", "EQUALITY_EXPRESSION",
  "BITWISE_AND_EXPRESSION", "BITWISE_XOR_EXPRESSION",
  "BITWISE_OR_EXPRESSION", "BOOLEAN_AND_EXPRESSION",
  "BOOLEAN_OR_EXPRESSION", "CONDITIONAL_EXPRESSION", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-100)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     729,  -123,  -123,   -72,  -123,  -123,  -123,  -123,  -123,   933,
    -123,  -123,   376,  -123,  -123,    16,  -123,   729,   729,   729,
     729,   -25,   729,   -10,     5,   -26,   -15,   -13,   540,   540,
     -16,     7,   694,     9,    19,    32,  -123,  -123,  -123,  -123,
      35,  -123,  -123,  -123,  -123,  -123,   966,   -66,  -123,  -123,
    -123,  -123,    37,   540,  -123,  -123,  -123,  -123,  -123,    39,
     205,  -123,  -123,   -10,  -123,  -123,  -123,    31,  -123,   966,
      48,    60,    40,    -6,    34,   107,   100,   101,    80,    81,
    -123,  -123,  -123,  -123,  -123,  -123,   729,  -123,    70,   -32,
    -123,   933,    69,    79,  -123,  -123,   119,  -123,   762,   865,
    -123,    82,   658,   865,   865,  -123,   285,    77,   966,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   966,   935,  -123,   966,    96,  -123,  -123,    88,
    -123,   966,   966,   966,   966,   966,   966,   966,   966,   966,
     966,   966,   966,   966,   966,   966,   966,   966,   966,  -123,
     966,   902,   -29,    83,    97,    91,    95,  -123,    92,   762,
      93,  -123,    94,   102,   103,   106,  -123,  -123,    90,  -123,
     105,  -123,   108,   114,  -123,  -123,  -123,  -123,    48,    48,
      60,    60,    40,    40,    40,    40,    -6,    -6,    34,   107,
     101,   101,    80,  -123,   110,   118,   -10,  -123,  -123,    69,
     966,   120,    69,   865,   830,   540,  -123,  -123,   622,   540,
    -123,   -10,  -123,   966,  -123,   933,  -123,    98,  -123,  -123,
    -123,   115,   540,   116,    41,   212,  -123,  -123,  -123,  -123,
    -123,  -123,   123,   126,  -123,   540,  -123,   865,   129,   458,
      99,   294,  -123,  -123,  -123,   131,   540,  -123,  -123,  -123,
     540,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    91,     0,    90,    88,    89,    87,    92,     0,
      93,    85,     0,    95,    94,     0,     2,     6,     5,     3,
       4,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   120,   119,   118,
       0,   115,   116,   117,    64,    27,     0,    80,   103,   104,
     105,    30,     0,    29,    35,    34,    33,    32,    31,     0,
     102,    66,    36,     0,    67,    68,   110,   113,   122,     0,
     126,   129,   132,   137,   140,   142,   144,   146,   148,   150,
     100,     1,    12,    11,    10,    13,     8,    14,    80,    99,
      83,     0,     0,     0,    62,    63,     0,    45,     0,     0,
      60,     0,     0,     0,     0,    81,   102,     0,     0,    26,
      28,    65,    76,    75,    73,    74,    70,    71,    72,    77,
      78,    79,     0,     0,   107,     0,    99,   111,   112,   102,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     0,    41,     0,    40,    84,     0,     0,
       0,    61,     0,     0,     0,     0,    69,   106,     0,    97,
      98,    23,     0,    25,   101,   123,   124,   125,   128,   127,
     131,   130,   133,   134,   135,   136,   138,   139,   141,   143,
     145,   147,   149,    18,     0,    20,     0,    15,    16,     0,
       0,     0,     0,     0,     0,     0,   109,   108,     0,     0,
      82,     0,    22,     0,    17,     0,    21,     0,    42,    37,
      39,     0,     0,     0,    43,     0,    47,    46,    56,    96,
      24,    19,     0,     0,    59,     0,    44,     0,     0,    55,
       0,    50,    38,    57,    58,     0,    54,    48,    55,    49,
      52,    53,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,    30,  -123,  -123,  -123,    -9,  -123,  -123,    -3,
       6,   -50,   -27,    13,  -122,  -123,   -19,  -123,   -34,  -123,
    -123,  -123,   -91,   -28,  -123,   -12,    21,   143,     0,    -8,
     -41,  -123,  -123,   -59,  -123,   -17,   -31,   -75,    -5,    67,
      68,  -123,    -7,    64,  -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,   152,   194,   195,   124,   172,
      51,    52,    53,    54,   155,   156,    55,   227,   240,   241,
      56,    57,    58,    59,   125,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    96,    97,   110,   101,   107,    19,   159,    24,    25,
     130,    89,   108,    20,   -95,    90,    81,    23,    23,    23,
      23,    21,    23,    19,    19,    19,    19,   150,    19,    40,
      20,    20,    20,    20,   106,    20,   138,   139,    21,    21,
      21,    21,   197,    21,   151,    12,    86,    82,    83,    84,
      85,   126,    87,    29,    93,    90,    94,   129,    95,    31,
      98,   140,   141,   182,   183,   184,   185,   168,   204,    34,
      88,   160,   175,   176,   177,   164,   165,   217,    91,    92,
     220,   170,   173,    99,   174,   102,    23,   131,   132,   133,
     162,   153,    19,   127,   128,   103,   106,   134,   135,    20,
     136,   137,   163,   142,   143,   180,   181,    21,   104,   170,
     111,   106,   109,   106,   169,   105,   149,   178,   179,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   186,   187,   190,
     191,   144,   169,    22,   145,   147,   146,   148,   108,   154,
     157,   196,   158,   161,   167,   150,   200,   199,   198,   218,
      22,    22,    22,    22,   123,    22,   201,   202,   203,   210,
     205,   206,   173,   232,   247,   221,   223,   211,   224,   207,
     208,   226,   228,   209,   216,   212,   213,   214,   106,   110,
     215,   219,   233,   235,   242,   234,   251,   243,   239,   126,
     252,   106,   246,   229,   250,   236,   231,   249,   244,   245,
     230,   188,   192,   189,   248,   196,    26,   237,     1,     0,
      27,   238,    28,     2,    29,     3,     0,     4,    30,    22,
      31,     5,     6,     0,    32,     7,     8,    33,     0,     0,
      34,     9,     0,    10,    11,    35,     0,    36,    37,    38,
      39,    40,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,   -99,    43,   -99,     0,
       0,   123,   -99,    44,     0,     0,    12,    45,    46,     0,
       0,     0,    47,    48,    49,     0,    50,    14,    26,   237,
       1,     0,    27,   238,    28,     2,    29,     3,     0,     4,
      30,     0,    31,     5,     6,     0,    32,     7,     8,    33,
       0,     0,    34,     9,     0,    10,    11,    35,     0,    36,
      37,    38,    39,    40,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,   123,     0,     0,     0,    44,     0,     0,    12,     0,
      46,     0,     0,     0,    47,    48,    49,     0,    50,    14,
      26,     0,     1,     0,    27,     0,    28,     2,    29,     3,
       0,     4,    30,     0,    31,     5,     6,     0,    32,     7,
       8,    33,     0,     0,    34,     9,     0,    10,    11,    35,
       0,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,    44,     0,     0,
      12,    45,    46,     0,     0,     0,    47,    48,    49,     0,
      50,    14,    26,     0,     1,     0,    27,     0,    28,     2,
      29,     3,     0,     4,    30,     0,    31,     5,     6,     0,
      32,     7,     8,    33,     0,     0,    34,     9,     0,    10,
      11,    35,     0,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,     0,     0,    44,
       0,     0,    12,   -29,    46,     0,     0,     0,    47,    48,
      49,     0,    50,    14,    26,     0,     1,     0,    27,     0,
      28,     2,    29,     3,     0,     4,    30,     0,    31,     5,
       6,     0,    32,     7,     8,    33,     0,     0,    34,     9,
       0,    10,    11,    35,     0,    36,    37,    38,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     0,     0,     0,     0,
       0,    44,     0,     0,    12,     0,    46,     0,     0,     0,
      47,    48,    49,     0,    50,    14,    26,     0,     1,     0,
      27,     0,    28,     2,    29,     3,     0,     4,    30,     0,
      31,     5,     6,     0,    32,     7,     8,    33,     0,     0,
      34,     9,     0,    10,    11,    35,     0,    36,    37,    38,
      39,    40,     0,     0,     1,     0,     0,     0,     0,     2,
       0,     0,     0,     4,     0,     0,     0,     5,     6,     0,
       0,     7,     8,     0,    41,    42,     0,    43,     0,    10,
      11,     0,     0,    44,     0,     0,   225,    40,    46,     0,
       1,     0,    47,    48,    49,     2,    50,    14,     0,     4,
       0,     0,     0,     5,     6,     0,     0,     7,     8,    33,
       0,     0,     0,     0,     0,    10,    11,     0,     0,    36,
      37,    38,    39,    40,     0,     1,     0,     0,    47,     0,
       2,     0,     3,    14,     4,     0,     0,     0,     5,     6,
       0,     0,     7,     8,     0,     0,    41,    42,     9,    43,
      10,    11,     0,     0,     0,   100,     0,     0,     1,     0,
      46,     0,     0,     2,    47,    48,    49,     4,    50,    14,
       0,     5,     6,     0,     0,     7,     8,    33,     0,     0,
       0,     0,     0,    10,    11,     0,     0,    36,    37,    38,
      39,    40,     0,    12,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,    44,     0,     0,     1,     0,    46,     0,
       0,     2,    47,    48,    49,     4,    50,    14,     0,     5,
       6,     0,     0,     7,     8,    33,     0,     0,     0,     0,
       0,    10,    11,     0,     0,    36,    37,    38,    39,    40,
       0,     1,     0,     0,     0,     0,     2,     0,     0,     0,
       4,     0,     0,     0,     5,     6,     0,     0,     7,     8,
      33,     0,    41,    42,     0,    43,    10,    11,     0,     0,
      36,    37,    38,    39,    40,     0,    46,   222,     1,     0,
      47,    48,    49,     2,    50,    14,     0,     4,     0,     0,
       0,     5,     6,     0,     0,     7,     8,    41,    42,     0,
      43,     0,     0,    10,    11,     0,     0,     0,     0,     1,
       0,    46,     0,     0,     2,    47,    48,    49,     4,    50,
      14,     0,     5,     6,     0,     0,     7,     8,     0,     0,
      33,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      36,    37,    38,    39,    40,     0,     0,     0,     0,   193,
       0,     0,    13,     0,     0,     0,     0,    14,     0,     0,
       0,    33,     0,     0,     0,     0,     0,    41,    42,     0,
      43,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,    46,   171,    13,     0,    88,    48,    49,    14,    50,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,    88,    48,    49,     0,
      50
};

static const yytype_int16 yycheck[] =
{
       0,    28,    29,    53,    32,    46,     0,    98,    80,     9,
      69,    23,    78,     0,    80,    23,     0,    17,    18,    19,
      20,     0,    22,    17,    18,    19,    20,    59,    22,    39,
      17,    18,    19,    20,    46,    22,    42,    43,    17,    18,
      19,    20,    71,    22,    76,    74,    71,    17,    18,    19,
      20,    63,    22,    12,    80,    63,    71,    69,    71,    18,
      76,    67,    68,   138,   139,   140,   141,   108,   159,    28,
      80,    99,   131,   132,   133,   103,   104,   199,    73,    74,
     202,   122,   123,    76,   125,    76,    86,    39,    40,    41,
     102,    91,    86,    62,    63,    76,   108,    37,    38,    86,
      60,    61,   102,    69,    70,   136,   137,    86,    76,   150,
      71,   123,    75,   125,   122,    80,    86,   134,   135,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   142,   143,   146,
     147,    34,   150,     0,    44,    65,    45,    66,    78,    80,
      71,   151,    33,    71,    77,    59,    59,    74,   152,   200,
      17,    18,    19,    20,    76,    22,    75,    72,    76,    79,
      77,    77,   213,    75,    75,   203,   204,    72,   205,    77,
      77,   208,   209,    77,   196,    77,    72,    77,   200,   239,
      72,    71,    77,    77,    71,   222,   246,    71,   225,   211,
     250,   213,    73,   211,    73,   224,   215,   241,   235,   237,
     213,   144,   148,   145,   241,   215,     4,     5,     6,    -1,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    86,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    71,    65,    73,    -1,
      -1,    76,    77,    71,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    80,    81,    82,    -1,    84,    85,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    -1,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    76,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    80,    81,    82,    -1,    84,    85,
       4,    -1,     6,    -1,     8,    -1,    10,    11,    12,    13,
      -1,    15,    16,    -1,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    82,    -1,
      84,    85,     4,    -1,     6,    -1,     8,    -1,    10,    11,
      12,    13,    -1,    15,    16,    -1,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    85,     4,    -1,     6,    -1,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    -1,    18,    19,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,
      80,    81,    82,    -1,    84,    85,     4,    -1,     6,    -1,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    -1,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    -1,    -1,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    24,    -1,    62,    63,    -1,    65,    -1,    31,
      32,    -1,    -1,    71,    -1,    -1,    74,    39,    76,    -1,
       6,    -1,    80,    81,    82,    11,    84,    85,    -1,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    39,    -1,     6,    -1,    -1,    80,    -1,
      11,    -1,    13,    85,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    62,    63,    29,    65,
      31,    32,    -1,    -1,    -1,    71,    -1,    -1,     6,    -1,
      76,    -1,    -1,    11,    80,    81,    82,    15,    84,    85,
      -1,    19,    20,    -1,    -1,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      38,    39,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,     6,    -1,    76,    -1,
      -1,    11,    80,    81,    82,    15,    84,    85,    -1,    19,
      20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
      -1,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    24,
      25,    -1,    62,    63,    -1,    65,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    76,    77,     6,    -1,
      80,    81,    82,    11,    84,    85,    -1,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    24,    62,    63,    -1,
      65,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,     6,
      -1,    76,    -1,    -1,    11,    80,    81,    82,    15,    84,
      85,    -1,    19,    20,    -1,    -1,    23,    24,    -1,    -1,
      25,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    76,    77,    80,    -1,    80,    81,    82,    85,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    81,    82,    -1,
      84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    15,    19,    20,    23,    24,    29,
      31,    32,    74,    80,    85,    87,    88,    89,    90,    96,
      99,   112,   113,   114,    80,   114,     4,     8,    10,    12,
      16,    18,    22,    25,    28,    33,    35,    36,    37,    38,
      39,    62,    63,    65,    71,    75,    76,    80,    81,    82,
      84,    96,    97,    98,    99,   102,   106,   107,   108,   109,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,    88,    88,    88,    88,    71,    88,    80,   111,
     115,    73,    74,    80,    71,    71,    98,    98,    76,    76,
      71,   109,    76,    76,    76,    80,   111,   116,    78,    75,
      97,    71,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    76,    94,   110,   111,    62,    63,   111,
     119,    39,    40,    41,    37,    38,    60,    61,    42,    43,
      67,    68,    69,    70,    34,    44,    45,    65,    66,    88,
      59,    76,    91,   114,    80,   100,   101,    71,    33,   108,
     109,    71,   111,   114,   109,   109,    59,    77,   116,   115,
     116,    77,    95,   116,   116,   119,   119,   119,   121,   121,
     122,   122,   123,   123,   123,   123,   124,   124,   125,   126,
     128,   128,   129,    77,    92,    93,   114,    71,    96,    74,
      59,    75,    72,    76,   108,    77,    77,    77,    77,    77,
      79,    72,    77,    72,    77,    72,   111,   100,   116,    71,
     100,   109,    77,   109,    98,    74,    98,   103,    98,   115,
      95,    92,    75,    77,    98,    77,   102,     5,     9,    98,
     104,   105,    71,    71,    98,   109,    73,    75,    98,   104,
      73,    97,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    91,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   103,   104,
     104,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   112,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   122,   122,   122,   123,
     123,   123,   124,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     2,     2,     2,     2,     4,     4,     3,     2,     3,
       1,     2,     3,     2,     3,     1,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     8,     3,
       1,     1,     3,     5,     6,     2,     5,     5,     3,     2,
       1,     4,     3,     3,     2,     1,     5,     7,     7,     6,
       2,     3,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     3,     2,     4,     4,
       1,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
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
#line 77 "src/parser.y"
                { g_root = new RootNode((yyvsp[0].node)); }
#line 1778 "src/parser.tab.cpp"
    break;

  case 3:
#line 81 "src/parser.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 1784 "src/parser.tab.cpp"
    break;

  case 4:
#line 82 "src/parser.y"
                                      { (yyval.node) = (yyvsp[0].node); }
#line 1790 "src/parser.tab.cpp"
    break;

  case 5:
#line 83 "src/parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1796 "src/parser.tab.cpp"
    break;

  case 6:
#line 84 "src/parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1802 "src/parser.tab.cpp"
    break;

  case 7:
#line 85 "src/parser.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1808 "src/parser.tab.cpp"
    break;

  case 8:
#line 87 "src/parser.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1814 "src/parser.tab.cpp"
    break;

  case 9:
#line 88 "src/parser.y"
                                           { (yyval.node) = new Frame((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1820 "src/parser.tab.cpp"
    break;

  case 10:
#line 89 "src/parser.y"
                                           { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1826 "src/parser.tab.cpp"
    break;

  case 11:
#line 90 "src/parser.y"
                                      { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1832 "src/parser.tab.cpp"
    break;

  case 12:
#line 91 "src/parser.y"
                                     { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1838 "src/parser.tab.cpp"
    break;

  case 13:
#line 92 "src/parser.y"
                                        { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1844 "src/parser.tab.cpp"
    break;

  case 14:
#line 93 "src/parser.y"
                                                                        { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1850 "src/parser.tab.cpp"
    break;

  case 15:
#line 97 "src/parser.y"
                                                             { (yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));; }
#line 1856 "src/parser.tab.cpp"
    break;

  case 16:
#line 101 "src/parser.y"
                                                      { (yyval.node) = new FunctionDefinition((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1862 "src/parser.tab.cpp"
    break;

  case 17:
#line 106 "src/parser.y"
                                                        { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1868 "src/parser.tab.cpp"
    break;

  case 18:
#line 107 "src/parser.y"
                                                        { (yyval.node) = new ParenthesisWrapper(NULL); }
#line 1874 "src/parser.tab.cpp"
    break;

  case 19:
#line 111 "src/parser.y"
                                                { (yyval.node) = new MultipleArguments((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1880 "src/parser.tab.cpp"
    break;

  case 20:
#line 112 "src/parser.y"
                                                { (yyval.node) = new MultipleArguments((yyvsp[0].node), NULL); }
#line 1886 "src/parser.tab.cpp"
    break;

  case 21:
#line 116 "src/parser.y"
                                { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1892 "src/parser.tab.cpp"
    break;

  case 22:
#line 119 "src/parser.y"
                                                       { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1898 "src/parser.tab.cpp"
    break;

  case 23:
#line 120 "src/parser.y"
                                                  { (yyval.node) = new ParenthesisWrapper(NULL); }
#line 1904 "src/parser.tab.cpp"
    break;

  case 24:
#line 124 "src/parser.y"
                                                           { (yyval.node) = new MultipleParameters((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1910 "src/parser.tab.cpp"
    break;

  case 25:
#line 125 "src/parser.y"
                                                      { (yyval.node) = new MultipleParameters((yyvsp[0].node), NULL); }
#line 1916 "src/parser.tab.cpp"
    break;

  case 26:
#line 129 "src/parser.y"
                                            { (yyval.node) = new Scope((yyvsp[-1].node)); }
#line 1922 "src/parser.tab.cpp"
    break;

  case 27:
#line 130 "src/parser.y"
                                       { (yyval.node) = new Scope(NULL); }
#line 1928 "src/parser.tab.cpp"
    break;

  case 28:
#line 134 "src/parser.y"
                                         { (yyval.node) = new MultipleStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1934 "src/parser.tab.cpp"
    break;

  case 29:
#line 135 "src/parser.y"
                                    { (yyval.node) = new MultipleStatements((yyvsp[0].node), NULL); }
#line 1940 "src/parser.tab.cpp"
    break;

  case 30:
#line 139 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1946 "src/parser.tab.cpp"
    break;

  case 31:
#line 140 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1952 "src/parser.tab.cpp"
    break;

  case 32:
#line 141 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1958 "src/parser.tab.cpp"
    break;

  case 33:
#line 142 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1964 "src/parser.tab.cpp"
    break;

  case 34:
#line 143 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1970 "src/parser.tab.cpp"
    break;

  case 35:
#line 144 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1976 "src/parser.tab.cpp"
    break;

  case 36:
#line 145 "src/parser.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 1982 "src/parser.tab.cpp"
    break;

  case 37:
#line 150 "src/parser.y"
                                                                             { (yyval.node) = new Enumeration(*(yyvsp[-4].string), NULL, (yyvsp[-2].node)); delete (yyvsp[-4].string); }
#line 1988 "src/parser.tab.cpp"
    break;

  case 38:
#line 151 "src/parser.y"
                                                                                                    { (yyval.node) = new Enumeration(*(yyvsp[-6].string), (yyvsp[-4].node), (yyvsp[-2].node)); delete (yyvsp[-6].string); }
#line 1994 "src/parser.tab.cpp"
    break;

  case 39:
#line 156 "src/parser.y"
                                                        { (yyval.node) = new MultipleEnumerators((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2000 "src/parser.tab.cpp"
    break;

  case 40:
#line 157 "src/parser.y"
                                                                        { (yyval.node) = new MultipleEnumerators((yyvsp[0].node), NULL); }
#line 2006 "src/parser.tab.cpp"
    break;

  case 41:
#line 161 "src/parser.y"
                                                         { (yyval.node) = new SingleEnumerator(*(yyvsp[0].string), NULL); delete (yyvsp[0].string); }
#line 2012 "src/parser.tab.cpp"
    break;

  case 42:
#line 162 "src/parser.y"
                                                         { (yyval.node) = new SingleEnumerator(*(yyvsp[-2].string), (yyvsp[0].node)); delete (yyvsp[-2].string); }
#line 2018 "src/parser.tab.cpp"
    break;

  case 43:
#line 166 "src/parser.y"
                                                                                                  { (yyval.node) = new IfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2024 "src/parser.tab.cpp"
    break;

  case 44:
#line 167 "src/parser.y"
                                                                                           { (yyval.node) = new IfStatement((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2030 "src/parser.tab.cpp"
    break;

  case 45:
#line 168 "src/parser.y"
                                                                                                         { (yyval.node) = (yyvsp[0].node); }
#line 2036 "src/parser.tab.cpp"
    break;

  case 46:
#line 169 "src/parser.y"
                                                                                              { (yyval.node) = new SwitchStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2042 "src/parser.tab.cpp"
    break;

  case 47:
#line 170 "src/parser.y"
                                                                                       { (yyval.node) = new SwitchStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2048 "src/parser.tab.cpp"
    break;

  case 48:
#line 174 "src/parser.y"
                                                       { (yyval.node) = (yyvsp[-1].node); }
#line 2054 "src/parser.tab.cpp"
    break;

  case 49:
#line 180 "src/parser.y"
                                                                { (yyval.node) = new MultipleCaseStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2060 "src/parser.tab.cpp"
    break;

  case 50:
#line 181 "src/parser.y"
                                                                                        { (yyval.node) = new MultipleCaseStatements((yyvsp[0].node), NULL); }
#line 2066 "src/parser.tab.cpp"
    break;

  case 51:
#line 186 "src/parser.y"
                                                                { (yyval.node) = new SingleCaseStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2072 "src/parser.tab.cpp"
    break;

  case 52:
#line 187 "src/parser.y"
                                                { (yyval.node) = new SingleCaseStatement((yyvsp[-1].node), NULL); }
#line 2078 "src/parser.tab.cpp"
    break;

  case 53:
#line 188 "src/parser.y"
                                                            { (yyval.node) = new DefaultStatement((yyvsp[0].node)); }
#line 2084 "src/parser.tab.cpp"
    break;

  case 54:
#line 189 "src/parser.y"
                                         { (yyval.node) = new DefaultStatement(NULL); }
#line 2090 "src/parser.tab.cpp"
    break;

  case 55:
#line 190 "src/parser.y"
                                                         { (yyval.node) = (yyvsp[0].node); }
#line 2096 "src/parser.tab.cpp"
    break;

  case 56:
#line 195 "src/parser.y"
                                                                                                                          { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 2102 "src/parser.tab.cpp"
    break;

  case 57:
#line 196 "src/parser.y"
                                                                                                                                   { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[-5].node), 1); }
#line 2108 "src/parser.tab.cpp"
    break;

  case 58:
#line 197 "src/parser.y"
                                                                                                                       { (yyval.node) = new ForLoop((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2114 "src/parser.tab.cpp"
    break;

  case 59:
#line 198 "src/parser.y"
                                                                                                            { (yyval.node) = new ForLoop((yyvsp[-3].node), (yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 2120 "src/parser.tab.cpp"
    break;

  case 60:
#line 202 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("RETURN", NULL); }
#line 2126 "src/parser.tab.cpp"
    break;

  case 61:
#line 203 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("RETURN", (yyvsp[-1].node)); }
#line 2132 "src/parser.tab.cpp"
    break;

  case 62:
#line 204 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("BREAK", NULL); }
#line 2138 "src/parser.tab.cpp"
    break;

  case 63:
#line 205 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("CONTINUE", NULL); }
#line 2144 "src/parser.tab.cpp"
    break;

  case 64:
#line 209 "src/parser.y"
                           { (yyval.node) = NULL; }
#line 2150 "src/parser.tab.cpp"
    break;

  case 65:
#line 210 "src/parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 2156 "src/parser.tab.cpp"
    break;

  case 66:
#line 217 "src/parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2162 "src/parser.tab.cpp"
    break;

  case 67:
#line 218 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2168 "src/parser.tab.cpp"
    break;

  case 68:
#line 219 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2174 "src/parser.tab.cpp"
    break;

  case 69:
#line 224 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("="); }
#line 2180 "src/parser.tab.cpp"
    break;

  case 70:
#line 225 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("*="); }
#line 2186 "src/parser.tab.cpp"
    break;

  case 71:
#line 226 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("/="); }
#line 2192 "src/parser.tab.cpp"
    break;

  case 72:
#line 227 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("%="); }
#line 2198 "src/parser.tab.cpp"
    break;

  case 73:
#line 228 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("+="); }
#line 2204 "src/parser.tab.cpp"
    break;

  case 74:
#line 229 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("-="); }
#line 2210 "src/parser.tab.cpp"
    break;

  case 75:
#line 230 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("<<="); }
#line 2216 "src/parser.tab.cpp"
    break;

  case 76:
#line 231 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator(">>="); }
#line 2222 "src/parser.tab.cpp"
    break;

  case 77:
#line 232 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("&="); }
#line 2228 "src/parser.tab.cpp"
    break;

  case 78:
#line 233 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("^="); }
#line 2234 "src/parser.tab.cpp"
    break;

  case 79:
#line 234 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("|="); }
#line 2240 "src/parser.tab.cpp"
    break;

  case 80:
#line 247 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[0].string), "NORMAL", NULL); delete (yyvsp[0].string); }
#line 2246 "src/parser.tab.cpp"
    break;

  case 81:
#line 248 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[0].string), "POINTER", NULL); delete (yyvsp[0].string); }
#line 2252 "src/parser.tab.cpp"
    break;

  case 82:
#line 249 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[-3].string), "ARRAY", (yyvsp[-1].node) ); delete (yyvsp[-3].string); }
#line 2258 "src/parser.tab.cpp"
    break;

  case 83:
#line 253 "src/parser.y"
                                                { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2264 "src/parser.tab.cpp"
    break;

  case 84:
#line 257 "src/parser.y"
                                                                                { (yyval.node) = new TypeDef(*(yyvsp[-1].string), (yyvsp[-2].node)); delete (yyvsp[-1].string);}
#line 2270 "src/parser.tab.cpp"
    break;

  case 85:
#line 260 "src/parser.y"
                                { (yyval.node) = new TypeSpecifier("VOID"); }
#line 2276 "src/parser.tab.cpp"
    break;

  case 86:
#line 261 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("CHAR"); }
#line 2282 "src/parser.tab.cpp"
    break;

  case 87:
#line 262 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("SHORT"); }
#line 2288 "src/parser.tab.cpp"
    break;

  case 88:
#line 263 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("INT"); }
#line 2294 "src/parser.tab.cpp"
    break;

  case 89:
#line 264 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("LONG"); }
#line 2300 "src/parser.tab.cpp"
    break;

  case 90:
#line 265 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("FLOAT"); }
#line 2306 "src/parser.tab.cpp"
    break;

  case 91:
#line 266 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("DOUBLE"); }
#line 2312 "src/parser.tab.cpp"
    break;

  case 92:
#line 267 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("SIGNED"); }
#line 2318 "src/parser.tab.cpp"
    break;

  case 93:
#line 268 "src/parser.y"
                        { (yyval.node) = new TypeSpecifier("UNSIGNED"); }
#line 2324 "src/parser.tab.cpp"
    break;

  case 94:
#line 269 "src/parser.y"
                                { (yyval.node) = new TypeSpecifier("BOOL"); }
#line 2330 "src/parser.tab.cpp"
    break;

  case 95:
#line 270 "src/parser.y"
                        { (yyval.node) = new CustomType(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 2336 "src/parser.tab.cpp"
    break;

  case 96:
#line 274 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2342 "src/parser.tab.cpp"
    break;

  case 97:
#line 275 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 2348 "src/parser.tab.cpp"
    break;

  case 98:
#line 276 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2354 "src/parser.tab.cpp"
    break;

  case 99:
#line 277 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[0].node), NULL, NULL); }
#line 2360 "src/parser.tab.cpp"
    break;

  case 100:
#line 281 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2366 "src/parser.tab.cpp"
    break;

  case 101:
#line 282 "src/parser.y"
                                                              { (yyval.node) = new AssignmentExpression((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2372 "src/parser.tab.cpp"
    break;

  case 102:
#line 286 "src/parser.y"
                                              { (yyval.node) = (yyvsp[0].node); }
#line 2378 "src/parser.tab.cpp"
    break;

  case 103:
#line 287 "src/parser.y"
                                         { (yyval.node) = new IntegerConstant( (yyvsp[0].integer_constant) ); }
#line 2384 "src/parser.tab.cpp"
    break;

  case 104:
#line 288 "src/parser.y"
                                          { (yyval.node) = new FloatConstant( (yyvsp[0].float_constant) ); }
#line 2390 "src/parser.tab.cpp"
    break;

  case 105:
#line 290 "src/parser.y"
                                         { (yyval.node) = new StringLiteral(*(yyvsp[0].string)); }
#line 2396 "src/parser.tab.cpp"
    break;

  case 106:
#line 291 "src/parser.y"
                                                                { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 2402 "src/parser.tab.cpp"
    break;

  case 107:
#line 292 "src/parser.y"
                                   { (yyval.node) = new FunctionCall((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2408 "src/parser.tab.cpp"
    break;

  case 108:
#line 293 "src/parser.y"
                                                            { (yyval.node) = new SizeOf((yyvsp[-1].node)); }
#line 2414 "src/parser.tab.cpp"
    break;

  case 109:
#line 294 "src/parser.y"
                                                        { (yyval.node) = new SizeOf((yyvsp[-1].node)); }
#line 2420 "src/parser.tab.cpp"
    break;

  case 110:
#line 299 "src/parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2426 "src/parser.tab.cpp"
    break;

  case 111:
#line 300 "src/parser.y"
                                 { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "++"); }
#line 2432 "src/parser.tab.cpp"
    break;

  case 112:
#line 301 "src/parser.y"
                                 { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "--"); }
#line 2438 "src/parser.tab.cpp"
    break;

  case 113:
#line 305 "src/parser.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 2444 "src/parser.tab.cpp"
    break;

  case 114:
#line 306 "src/parser.y"
                                     { (yyval.node) = new UnaryExpression((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2450 "src/parser.tab.cpp"
    break;

  case 115:
#line 310 "src/parser.y"
                { (yyval.node) = new UnaryOperator("++"); }
#line 2456 "src/parser.tab.cpp"
    break;

  case 116:
#line 311 "src/parser.y"
                { (yyval.node) = new UnaryOperator("--"); }
#line 2462 "src/parser.tab.cpp"
    break;

  case 117:
#line 312 "src/parser.y"
                { (yyval.node) = new UnaryOperator("&"); }
#line 2468 "src/parser.tab.cpp"
    break;

  case 118:
#line 313 "src/parser.y"
                { (yyval.node) = new UnaryOperator("+"); }
#line 2474 "src/parser.tab.cpp"
    break;

  case 119:
#line 314 "src/parser.y"
                { (yyval.node) = new UnaryOperator("-"); }
#line 2480 "src/parser.tab.cpp"
    break;

  case 120:
#line 315 "src/parser.y"
                   { (yyval.node) = new UnaryOperator("~"); }
#line 2486 "src/parser.tab.cpp"
    break;

  case 121:
#line 316 "src/parser.y"
                { (yyval.node) = new UnaryOperator("!"); }
#line 2492 "src/parser.tab.cpp"
    break;

  case 122:
#line 320 "src/parser.y"
                                                    { (yyval.node) = (yyvsp[0].node); }
#line 2498 "src/parser.tab.cpp"
    break;

  case 123:
#line 321 "src/parser.y"
                                                       { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 2504 "src/parser.tab.cpp"
    break;

  case 124:
#line 322 "src/parser.y"
                                                      { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 2510 "src/parser.tab.cpp"
    break;

  case 125:
#line 323 "src/parser.y"
                                                      { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "%", (yyvsp[0].node)); }
#line 2516 "src/parser.tab.cpp"
    break;

  case 126:
#line 327 "src/parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 2522 "src/parser.tab.cpp"
    break;

  case 127:
#line 328 "src/parser.y"
                                                          { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 2528 "src/parser.tab.cpp"
    break;

  case 128:
#line 329 "src/parser.y"
                                                           { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 2534 "src/parser.tab.cpp"
    break;

  case 129:
#line 333 "src/parser.y"
                                                   { (yyval.node) = (yyvsp[0].node); }
#line 2540 "src/parser.tab.cpp"
    break;

  case 130:
#line 334 "src/parser.y"
                                                       { (yyval.node) = new ShiftExpression((yyvsp[-2].node), "<<", (yyvsp[0].node)); }
#line 2546 "src/parser.tab.cpp"
    break;

  case 131:
#line 335 "src/parser.y"
                                                      { (yyval.node) = new ShiftExpression((yyvsp[-2].node), ">>", (yyvsp[0].node)); }
#line 2552 "src/parser.tab.cpp"
    break;

  case 132:
#line 339 "src/parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2558 "src/parser.tab.cpp"
    break;

  case 133:
#line 340 "src/parser.y"
                                                   { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<", (yyvsp[0].node)); }
#line 2564 "src/parser.tab.cpp"
    break;

  case 134:
#line 341 "src/parser.y"
                                                   { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">", (yyvsp[0].node)); }
#line 2570 "src/parser.tab.cpp"
    break;

  case 135:
#line 342 "src/parser.y"
                                                    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<=", (yyvsp[0].node)); }
#line 2576 "src/parser.tab.cpp"
    break;

  case 136:
#line 343 "src/parser.y"
                                                    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">=", (yyvsp[0].node)); }
#line 2582 "src/parser.tab.cpp"
    break;

  case 137:
#line 347 "src/parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 2588 "src/parser.tab.cpp"
    break;

  case 138:
#line 348 "src/parser.y"
                                                       { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "==", (yyvsp[0].node)); }
#line 2594 "src/parser.tab.cpp"
    break;

  case 139:
#line 349 "src/parser.y"
                                                       { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "!=", (yyvsp[0].node)); }
#line 2600 "src/parser.tab.cpp"
    break;

  case 140:
#line 353 "src/parser.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 2606 "src/parser.tab.cpp"
    break;

  case 141:
#line 354 "src/parser.y"
                                                      { (yyval.node) = new BitwiseANDExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2612 "src/parser.tab.cpp"
    break;

  case 142:
#line 358 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2618 "src/parser.tab.cpp"
    break;

  case 143:
#line 359 "src/parser.y"
                                                         { (yyval.node) = new BitwiseXORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2624 "src/parser.tab.cpp"
    break;

  case 144:
#line 363 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2630 "src/parser.tab.cpp"
    break;

  case 145:
#line 364 "src/parser.y"
                                                      { (yyval.node) = new BitwiseORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2636 "src/parser.tab.cpp"
    break;

  case 146:
#line 368 "src/parser.y"
                                                         { (yyval.node) = (yyvsp[0].node); }
#line 2642 "src/parser.tab.cpp"
    break;

  case 147:
#line 369 "src/parser.y"
                                                           { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "and", (yyvsp[0].node)); }
#line 2648 "src/parser.tab.cpp"
    break;

  case 148:
#line 373 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2654 "src/parser.tab.cpp"
    break;

  case 149:
#line 374 "src/parser.y"
                                                          { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "or", (yyvsp[0].node)); }
#line 2660 "src/parser.tab.cpp"
    break;

  case 150:
#line 378 "src/parser.y"
                                                                     { (yyval.node) = (yyvsp[0].node); }
#line 2666 "src/parser.tab.cpp"
    break;


#line 2670 "src/parser.tab.cpp"

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
#line 386 "src/parser.y"


// Definition of variable (to match declaration earlier).
const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
