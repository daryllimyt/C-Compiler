/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
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
#line 1 "src/parser.y" /* yacc.c:355  */

  #include "../include/ast.hpp"
  #include <cassert>
  #include <stdio.h>

  extern const Node *g_root;


  int yylex(void);
  void yyerror(const char *);


#line 110 "src/parser.tab.cpp" /* yacc.c:355  */

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
#line 15 "src/parser.y" /* yacc.c:355  */

  const Node *node;
  double float_constant;
  long long int integer_constant;
  std::string *string;

#line 215 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  89
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1087

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    87,    91,    96,
      97,   101,   102,   106,   109,   110,   114,   115,   119,   120,
     124,   125,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   142,   143,   147,   148,   152,   153,   157,   158,   159,
     160,   161,   165,   170,   171,   176,   177,   178,   179,   180,
     185,   186,   187,   188,   192,   193,   194,   195,   199,   200,
     205,   206,   207,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   225,   226,   227,   228,   232,   236,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     253,   256,   259,   262,   263,   267,   271,   272,   273,   274,
     278,   279,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   295,   296,   297,   301,   302,   306,   307,   308,   309,
     310,   311,   312,   316,   317,   318,   319,   323,   324,   325,
     329,   330,   331,   335,   336,   337,   338,   339,   343,   344,
     345,   349,   350,   354,   355,   359,   360,   364,   365,   369,
     370,   374
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
  "STRUCT_DEFINITION", "STRUCT_DECLARATION", "STRUCT_ATTRIBUTE",
  "MULTIPLE_ATTRIBUTES", "SINGLE_ATTRIBUTE", "ASSIGNMENT_STATEMENT",
  "MATH_OR_BITWISE_EXPRESSION", "PRIMARY_EXPRESSION", "POSTFIX_EXPRESSION",
  "UNARY_EXPRESSION", "UNARY_OPERATOR", "MULTIPLICATIVE_EXPRESSION",
  "ADDITIVE_EXPRESSION", "SHIFT_EXPRESSION", "RELATIONAL_EXPRESSION",
  "EQUALITY_EXPRESSION", "BITWISE_AND_EXPRESSION",
  "BITWISE_XOR_EXPRESSION", "BITWISE_OR_EXPRESSION",
  "BOOLEAN_AND_EXPRESSION", "BOOLEAN_OR_EXPRESSION",
  "CONDITIONAL_EXPRESSION", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -110

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     694,  -151,  -151,   -74,  -151,  -151,  -151,  -151,  -151,   -72,
     366,  -151,  -151,   402,  -151,  -151,    28,  -151,   694,   694,
     694,   694,   -33,   694,   -32,   694,   -59,   -25,   -17,    -4,
       5,   566,   566,    14,    22,   728,    25,   448,    33,    35,
    -151,  -151,  -151,  -151,  -151,    36,  -151,  -151,  -151,  -151,
    1003,   -35,  -151,  -151,  -151,  -151,  -151,    52,   566,  -151,
    -151,  -151,  -151,  -151,    42,   559,  -151,  -151,   -32,  -151,
    -151,  -151,  -151,  -151,  -151,    24,  -151,  1003,    30,    51,
      31,   -16,    26,    94,   109,   110,    89,    90,  -151,  -151,
    -151,  -151,  -151,  -151,   694,  -151,   -23,   -43,  -151,  -151,
     366,    77,   366,    88,  -151,  -151,   127,  -151,   808,   922,
    -151,    91,   977,   -25,    81,   922,   922,  -151,   229,    87,
      93,  1003,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  1003,   987,  -151,  1003,   115,
    -151,  -151,   104,  -151,  1003,  1003,  1003,  1003,  1003,  1003,
    1003,  1003,  1003,  1003,  1003,  1003,  1003,  1003,  1003,  1003,
    1003,  1003,  -151,   284,   -10,    95,   123,   111,   112,   105,
     114,   366,  -151,   119,   808,   113,  -151,   125,   126,   116,
     129,   130,  -151,  -151,   117,  -151,   128,  -151,   132,   139,
    -151,  -151,  -151,  -151,    30,    30,    51,    51,    31,    31,
      31,    31,   -16,   -16,    26,    94,   110,   110,    89,  -151,
     135,   141,   -32,  -151,  -151,    77,  1003,   133,    77,   149,
     150,  -151,   922,   888,   566,  -151,  -151,  -151,   648,   566,
    -151,   -32,  -151,  1003,  -151,   366,  -151,   148,  -151,  -151,
    -151,  -151,  -151,   145,   566,   152,    38,   238,  -151,  -151,
    -151,  -151,  -151,  -151,   153,   154,  -151,   566,  -151,   922,
     157,   484,   151,   320,  -151,  -151,  -151,   159,   566,  -151,
    -151,  -151,   566,  -151,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    90,    95,     0,    94,    92,    93,    91,    96,     0,
       0,    97,    89,     0,    99,    98,     0,     2,     6,     5,
       3,     4,     0,     7,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   132,   131,   130,   129,     0,   126,   127,    68,    29,
       0,    84,   113,   114,   115,   116,    32,     0,    31,    37,
      36,    35,    34,    33,     0,   112,    70,    38,     0,    39,
      40,    83,    71,    72,   121,   124,   133,     0,   137,   140,
     143,   148,   151,   153,   155,   157,   159,   161,   110,     1,
      14,    13,    12,    15,     9,    16,    84,   109,    87,    10,
       0,     0,     0,     0,    66,    67,     0,    49,     0,     0,
      64,     0,     0,    99,     0,     0,     0,    85,   112,     0,
       0,     0,    28,    30,    69,    79,    78,    76,    77,    73,
      74,    75,    80,    81,    82,     0,     0,   118,     0,   109,
     122,   123,   112,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,    45,     0,    44,     0,
       0,   104,    88,     0,     0,     0,    65,     0,     0,     0,
       0,     0,   117,   102,     0,   107,   108,    25,     0,    27,
     111,   134,   135,   136,   139,   138,   142,   141,   144,   145,
     146,   147,   149,   150,   152,   154,   156,   158,   160,    20,
       0,    22,     0,    17,    18,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,   120,   119,   101,     0,     0,
      86,     0,    24,     0,    19,     0,    23,     0,    46,    41,
      43,   105,   100,     0,     0,     0,    47,     0,    51,    50,
      60,   106,    26,    21,     0,     0,    63,     0,    48,     0,
       0,    59,     0,    54,    42,    61,    62,     0,    58,    52,
      59,    53,    56,    57,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,    21,  -151,  -151,  -151,    -1,  -151,  -151,    -2,
      11,   -53,   -30,    54,  -150,  -151,    -9,  -151,   -27,  -151,
    -151,  -151,   -91,   -31,  -151,   -15,    99,   147,     0,   158,
    -151,  -151,    67,  -151,   -21,   -28,  -151,  -151,   -64,  -151,
     -44,   -24,   -94,    -6,    82,    97,  -151,    -8,    79,  -151,
    -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,   164,   210,   211,   137,   188,
      56,    57,    58,    59,   167,   168,    60,   249,   262,   263,
      61,    62,    63,    64,   138,    65,    66,    67,    68,    69,
      70,    71,   170,   171,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   106,   107,    98,   111,   123,    26,    45,    27,    97,
      28,    20,   120,   143,   100,   101,   135,   174,    24,    24,
      24,    24,   119,    24,   120,    24,   151,   152,    89,    20,
      20,    20,    20,   163,    20,   118,    20,   114,    94,    90,
      91,    92,    93,   121,    95,   -99,    99,    98,    96,   102,
      32,   153,   154,   139,    21,   121,    34,   198,   199,   200,
     201,   213,   142,   103,    13,   237,    38,   104,   240,   144,
     145,   146,    21,    21,    21,    21,   105,    21,   175,    21,
     191,   192,   193,   223,   180,   181,   140,   141,   147,   148,
     108,   149,   150,   184,    24,   155,   156,   177,   109,    22,
     165,   112,   169,   194,   195,    20,   118,   186,   189,   115,
     190,   116,   178,   124,   185,   162,   117,    22,    22,    22,
      22,   118,    22,   118,    22,   196,   197,   122,   157,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,    23,    21,   202,
     203,   206,   207,   158,   160,   159,   161,   166,    25,   172,
     173,   179,   176,   212,   182,    23,    23,    23,    23,   215,
      23,   169,    23,   183,   135,   214,    25,    25,    25,    25,
     136,    25,   216,    25,   218,   219,   217,   227,   238,   220,
     224,   243,   245,    22,   246,   222,   230,   236,   248,   250,
     231,   118,   225,   226,   239,   189,   228,   229,   123,   232,
     251,   233,   234,   235,   256,   273,   139,   261,   118,   274,
     241,   242,   255,   254,   264,   265,   269,   266,   267,   257,
     268,   252,   272,   270,   253,   212,   271,   258,   221,   204,
     208,    23,    29,   259,     1,     0,    30,   260,    31,     2,
      32,     3,    25,     4,    33,   205,    34,     5,     6,     0,
      35,     7,     8,    36,     0,    37,    38,    10,     0,    11,
      12,    39,    40,    41,    42,    43,    44,    45,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       1,     0,     0,     0,     0,     2,     0,     0,     0,     4,
      46,    47,     0,     5,     6,   136,     0,     7,     8,    48,
       0,     0,    13,    49,    50,    11,    12,     0,    51,    52,
      53,    54,    55,    15,    29,   259,     1,     0,    30,   260,
      31,     2,    32,     3,     0,     4,    33,     0,    34,     5,
       6,     0,    35,     7,     8,    36,     0,    37,    38,    10,
       0,    11,    12,    39,    40,    41,    42,    43,    44,    45,
       0,   209,     0,     0,    14,     0,     0,     0,     0,    15,
       0,     0,     1,     0,     0,     0,     0,     2,     0,     0,
       0,     4,    46,    47,     0,     5,     6,     0,     0,     7,
       8,    48,     0,     0,    13,     0,    50,    11,    12,     0,
      51,    52,    53,    54,    55,    15,    29,     0,     1,     0,
      30,     0,    31,     2,    32,     3,     0,     4,    33,     0,
      34,     5,     6,     0,    35,     7,     8,    36,     0,    37,
      38,    10,     0,    11,    12,    39,    40,    41,    42,    43,
      44,    45,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,     0,     0,     1,     0,     0,     0,     0,     2,
       0,     0,     0,     4,    46,    47,     0,     5,     6,     0,
       0,     7,     8,    48,     0,     0,    13,    49,    50,    11,
      12,     0,    51,    52,    53,    54,    55,    15,    29,     0,
       1,     0,    30,     0,    31,     2,    32,     3,     0,     4,
      33,     0,    34,     5,     6,     0,    35,     7,     8,    36,
       0,    37,    38,    10,     0,    11,    12,    39,    40,    41,
      42,    43,    44,    45,     0,     0,     0,     0,   113,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    13,   -31,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    15,
      29,     0,     1,     0,    30,     0,    31,     2,    32,     3,
       0,     4,    33,     0,    34,     5,     6,     0,    35,     7,
       8,    36,     0,    37,    38,    10,     0,    11,    12,    39,
      40,    41,    42,    43,    44,    45,     0,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
    -109,     0,  -109,     0,     0,   136,  -109,    48,     0,     0,
      13,     0,    50,     0,     0,     0,    51,    52,    53,    54,
      55,    15,    29,     0,     1,     0,    30,     0,    31,     2,
      32,     3,     0,     4,    33,     0,    34,     5,     6,     0,
      35,     7,     8,    36,     0,    37,    38,    10,     0,    11,
      12,    39,    40,    41,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     2,     0,     3,     0,     4,
      46,    47,     0,     5,     6,     0,     0,     7,     8,    48,
       0,     9,   247,    10,    50,    11,    12,     0,    51,    52,
      53,    54,    55,    15,     1,     0,     0,     0,     0,     2,
       0,     0,     0,     4,     0,     0,     0,     5,     6,     0,
       0,     7,     8,    36,     0,     0,     0,     0,     0,    11,
      12,     0,    40,    41,    42,    43,    44,    45,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    15,     1,     0,     0,     0,     0,     2,
       0,     0,     0,     4,     0,     0,     0,     5,     6,     0,
       0,     7,     8,    36,     0,     0,     0,     0,     0,    11,
      12,     0,    40,    41,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    15,     1,     0,     0,     0,     0,     2,
       0,     0,     0,     4,     0,     0,     0,     5,     6,     0,
       0,     7,     8,    36,     0,     0,     0,     0,     0,    11,
      12,     0,    40,    41,    42,    43,    44,    45,     1,     0,
       0,     0,     0,     2,     0,     0,     0,     4,     0,     0,
       0,     5,     6,     0,     0,     7,     8,    36,     0,     0,
      46,    47,     0,    11,    12,     0,    40,    41,    42,    43,
      44,    45,     0,     0,    50,   244,     0,     0,    51,    52,
      53,    54,    55,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    46,    47,     0,     0,     2,     0,
       0,     0,     4,     0,     0,     0,     5,     6,    50,     0,
       7,     8,    51,    52,    53,    54,    55,    15,    11,    12,
       0,     0,    36,     0,     0,     0,    45,     0,     0,     0,
       0,    40,    41,    42,    43,    44,    45,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    41,    42,
      43,    44,    45,     0,     0,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,    15,    50,   187,    46,    47,    96,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,    96,    52,    53,    54,    55
};

static const yytype_int16 yycheck[] =
{
       0,    31,    32,    24,    35,    58,    80,    39,    80,    24,
      10,     0,    47,    77,    73,    74,    59,   108,    18,    19,
      20,    21,    50,    23,    47,    25,    42,    43,     0,    18,
      19,    20,    21,    76,    23,    50,    25,    37,    71,    18,
      19,    20,    21,    78,    23,    80,    25,    68,    80,    74,
      12,    67,    68,    68,     0,    78,    18,   151,   152,   153,
     154,    71,    77,    80,    74,   215,    28,    71,   218,    39,
      40,    41,    18,    19,    20,    21,    71,    23,   109,    25,
     144,   145,   146,   174,   115,   116,    62,    63,    37,    38,
      76,    60,    61,   121,    94,    69,    70,   112,    76,     0,
     100,    76,   102,   147,   148,    94,   121,   135,   136,    76,
     138,    76,   112,    71,   135,    94,    80,    18,    19,    20,
      21,   136,    23,   138,    25,   149,   150,    75,    34,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,    94,   155,
     156,   159,   160,    44,    65,    45,    66,    80,     0,    71,
      33,    80,    71,   163,    77,    18,    19,    20,    21,    74,
      23,   171,    25,    80,    59,   164,    18,    19,    20,    21,
      76,    23,    59,    25,    72,    80,    75,    71,   216,    75,
      77,   222,   223,    94,   224,    76,    79,   212,   228,   229,
      72,   216,    77,    77,    71,   233,    77,    77,   261,    77,
     231,    72,    77,    72,   244,   268,   231,   247,   233,   272,
      71,    71,    77,    75,    71,    71,    75,   257,   259,    77,
      73,   233,    73,   263,   235,   235,   263,   246,   171,   157,
     161,    94,     4,     5,     6,    -1,     8,     9,    10,    11,
      12,    13,    94,    15,    16,   158,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,
      62,    63,    -1,    19,    20,    76,    -1,    23,    24,    71,
      -1,    -1,    74,    75,    76,    31,    32,    -1,    80,    81,
      82,    83,    84,    85,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    13,    -1,    15,    16,    -1,    18,    19,
      20,    -1,    22,    23,    24,    25,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    77,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    15,    62,    63,    -1,    19,    20,    -1,    -1,    23,
      24,    71,    -1,    -1,    74,    -1,    76,    31,    32,    -1,
      80,    81,    82,    83,    84,    85,     4,    -1,     6,    -1,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    -1,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    85,    -1,    -1,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    62,    63,    -1,    19,    20,    -1,
      -1,    23,    24,    71,    -1,    -1,    74,    75,    76,    31,
      32,    -1,    80,    81,    82,    83,    84,    85,     4,    -1,
       6,    -1,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    -1,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
       4,    -1,     6,    -1,     8,    -1,    10,    11,    12,    13,
      -1,    15,    16,    -1,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      71,    -1,    73,    -1,    -1,    76,    77,    71,    -1,    -1,
      74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,
      84,    85,     4,    -1,     6,    -1,     8,    -1,    10,    11,
      12,    13,    -1,    15,    16,    -1,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    11,    -1,    13,    -1,    15,
      62,    63,    -1,    19,    20,    -1,    -1,    23,    24,    71,
      -1,    27,    74,    29,    76,    31,    32,    -1,    80,    81,
      82,    83,    84,    85,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,     6,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    24,    25,    -1,    -1,
      62,    63,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    -1,    -1,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    62,    63,    -1,    -1,    11,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    20,    76,    -1,
      23,    24,    80,    81,    82,    83,    84,    85,    31,    32,
      -1,    -1,    25,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    85,    76,    77,    62,    63,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    81,    82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    15,    19,    20,    23,    24,    27,
      29,    31,    32,    74,    80,    85,    87,    88,    89,    90,
      96,    99,   112,   113,   114,   115,    80,    80,   114,     4,
       8,    10,    12,    16,    18,    22,    25,    27,    28,    33,
      34,    35,    36,    37,    38,    39,    62,    63,    71,    75,
      76,    80,    81,    82,    83,    84,    96,    97,    98,    99,
     102,   106,   107,   108,   109,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,     0,
      88,    88,    88,    88,    71,    88,    80,   111,   120,    88,
      73,    74,    74,    80,    71,    71,    98,    98,    76,    76,
      71,   109,    76,    80,   114,    76,    76,    80,   111,   121,
      47,    78,    75,    97,    71,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    76,    94,   110,   111,
      62,    63,   111,   124,    39,    40,    41,    37,    38,    60,
      61,    42,    43,    67,    68,    69,    70,    34,    44,    45,
      65,    66,    88,    76,    91,   114,    80,   100,   101,   114,
     118,   119,    71,    33,   108,   109,    71,   111,   114,    80,
     109,   109,    77,    80,   121,   120,   121,    77,    95,   121,
     121,   124,   124,   124,   126,   126,   127,   127,   128,   128,
     128,   128,   129,   129,   130,   131,   133,   133,   134,    77,
      92,    93,   114,    71,    96,    74,    59,    75,    72,    80,
      75,   118,    76,   108,    77,    77,    77,    71,    77,    77,
      79,    72,    77,    72,    77,    72,   111,   100,   121,    71,
     100,    71,    71,   109,    77,   109,    98,    74,    98,   103,
      98,   120,    95,    92,    75,    77,    98,    77,   102,     5,
       9,    98,   104,   105,    71,    71,    98,   109,    73,    75,
      98,   104,    73,    97,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    90,    91,
      91,    92,    92,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   103,   104,   104,   105,   105,   105,   105,   105,
     106,   106,   106,   106,   107,   107,   107,   107,   108,   108,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   116,   117,   118,   118,   119,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   127,   127,   127,
     128,   128,   128,   129,   129,   129,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     2,     2,     2,     2,     4,     4,     3,
       2,     3,     1,     2,     3,     2,     3,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     8,     3,     1,     1,     3,     5,     6,     2,
       5,     5,     3,     2,     1,     4,     3,     3,     2,     1,
       5,     7,     7,     6,     2,     3,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     4,     3,     2,     1,     3,     5,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     2,     4,
       4,     1,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 67 "src/parser.y" /* yacc.c:1646  */
    { g_root = new RootNode((yyvsp[0].node)); }
#line 1701 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1707 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1713 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1719 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1725 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1731 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1737 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1743 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1749 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1755 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1761 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1767 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1773 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1779 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 83 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1785 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 87 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));; }
#line 1791 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDefinition((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1797 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1803 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper(NULL); }
#line 1809 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleArguments((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1815 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 102 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleArguments((yyvsp[0].node), NULL); }
#line 1821 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1827 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1833 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper(NULL); }
#line 1839 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleParameters((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1845 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleParameters((yyvsp[0].node), NULL); }
#line 1851 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Scope((yyvsp[-1].node)); }
#line 1857 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Scope(NULL); }
#line 1863 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1869 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 125 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleStatements((yyvsp[0].node), NULL); }
#line 1875 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1881 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1887 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1893 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1899 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 133 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1905 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 134 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1911 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1917 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1923 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 137 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1929 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 142 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Enumeration(*(yyvsp[-4].string), NULL, (yyvsp[-2].node)); delete (yyvsp[-4].string); }
#line 1935 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Enumeration(*(yyvsp[-6].string), (yyvsp[-4].node), (yyvsp[-2].node)); delete (yyvsp[-6].string); }
#line 1941 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 147 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleEnumerators((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1947 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 148 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleEnumerators((yyvsp[0].node), NULL); }
#line 1953 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 152 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SingleEnumerator(*(yyvsp[0].string), NULL); delete (yyvsp[0].string); }
#line 1959 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 153 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SingleEnumerator(*(yyvsp[-2].string), (yyvsp[0].node)); delete (yyvsp[-2].string); }
#line 1965 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 157 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1971 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfStatement((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1977 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1983 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 160 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SwitchStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1989 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SwitchStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1995 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2001 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleCaseStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2007 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleCaseStatements((yyvsp[0].node), NULL); }
#line 2013 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SingleCaseStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2019 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SingleCaseStatement((yyvsp[-1].node), NULL); }
#line 2025 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DefaultStatement((yyvsp[0].node)); }
#line 2031 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DefaultStatement(NULL); }
#line 2037 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2043 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 2049 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[-5].node), 1); }
#line 2055 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ForLoop((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2061 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ForLoop((yyvsp[-3].node), (yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 2067 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("RETURN", NULL); }
#line 2073 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("RETURN", (yyvsp[-1].node)); }
#line 2079 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("BREAK", NULL); }
#line 2085 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("CONTINUE", NULL); }
#line 2091 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2097 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2103 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2109 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 206 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2115 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2121 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("*="); }
#line 2127 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("/="); }
#line 2133 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("%="); }
#line 2139 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("+="); }
#line 2145 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("-="); }
#line 2151 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("<<="); }
#line 2157 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator(">>="); }
#line 2163 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("&="); }
#line 2169 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 220 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("^="); }
#line 2175 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("|="); }
#line 2181 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2187 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable(*(yyvsp[0].string), "NORMAL", NULL); delete (yyvsp[0].string); }
#line 2193 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable(*(yyvsp[0].string), "POINTER", NULL); delete (yyvsp[0].string); }
#line 2199 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable(*(yyvsp[-3].string), "ARRAY", (yyvsp[-1].node) ); delete (yyvsp[-3].string); }
#line 2205 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 232 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2211 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 236 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeDef(*(yyvsp[-1].string), (yyvsp[-2].node)); delete (yyvsp[-1].string);}
#line 2217 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("VOID"); }
#line 2223 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("CHAR"); }
#line 2229 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 241 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("SHORT"); }
#line 2235 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("INT"); }
#line 2241 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 243 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("LONG"); }
#line 2247 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("FLOAT"); }
#line 2253 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("DOUBLE"); }
#line 2259 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("SIGNED"); }
#line 2265 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("UNSIGNED"); }
#line 2271 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("BOOL"); }
#line 2277 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CustomType(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 2283 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StructDefinition(*(yyvsp[-4].string), (yyvsp[-2].node));}
#line 2289 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StructDeclaration((yyvsp[-2].node), *(yyvsp[-1].string));}
#line 2295 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 259 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StructAttribute(*(yyvsp[-2].string), *(yyvsp[0].string)); delete (yyvsp[-2].string);delete (yyvsp[0].string); }
#line 2301 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleAttributes((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2307 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleAttributes((yyvsp[0].node), NULL); }
#line 2313 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SingleAttribute((yyvsp[-2].node), *(yyvsp[-1].string));}
#line 2319 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 271 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2325 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 272 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 2331 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 273 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2337 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[0].node), NULL, NULL); }
#line 2343 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2349 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentExpression((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2355 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2361 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IntegerConstant( (yyvsp[0].integer_constant) ); }
#line 2367 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FloatConstant( (yyvsp[0].float_constant) ); }
#line 2373 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CharConstant( *(yyvsp[0].string) ); }
#line 2379 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StringLiteral(*(yyvsp[0].string)); }
#line 2385 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 2391 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionCall((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2397 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SizeOf((yyvsp[-1].node)); }
#line 2403 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SizeOf((yyvsp[-1].node)); }
#line 2409 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2415 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "++"); }
#line 2421 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "--"); }
#line 2427 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2433 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryExpression((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2439 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("++"); }
#line 2445 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("--"); }
#line 2451 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("&"); }
#line 2457 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 309 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("+"); }
#line 2463 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("-"); }
#line 2469 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("~"); }
#line 2475 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("!"); }
#line 2481 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 316 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2487 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 2493 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 2499 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "%", (yyvsp[0].node)); }
#line 2505 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2511 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 2517 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 2523 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2529 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 330 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ShiftExpression((yyvsp[-2].node), "<<", (yyvsp[0].node)); }
#line 2535 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ShiftExpression((yyvsp[-2].node), ">>", (yyvsp[0].node)); }
#line 2541 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 335 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2547 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<", (yyvsp[0].node)); }
#line 2553 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">", (yyvsp[0].node)); }
#line 2559 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<=", (yyvsp[0].node)); }
#line 2565 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 339 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">=", (yyvsp[0].node)); }
#line 2571 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2577 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "==", (yyvsp[0].node)); }
#line 2583 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "!=", (yyvsp[0].node)); }
#line 2589 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 349 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2595 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 350 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BitwiseANDExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2601 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 354 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2607 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 355 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BitwiseXORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2613 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 359 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2619 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 360 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BitwiseORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2625 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2631 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "and", (yyvsp[0].node)); }
#line 2637 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 369 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2643 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "or", (yyvsp[0].node)); }
#line 2649 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 374 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2655 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2659 "src/parser.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 378 "src/parser.y" /* yacc.c:1906  */


const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
