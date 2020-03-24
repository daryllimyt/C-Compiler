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

  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

  // extern void yyset_in(FILE* fd);

#line 113 "src/parser.tab.cpp" /* yacc.c:355  */

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
#line 18 "src/parser.y" /* yacc.c:355  */

  const Node *node;
  double float_constant;
  long long int integer_constant;
  std::string *string;

#line 217 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    80,    81,    82,    84,    85,    86,    87,
      88,   103,   107,   112,   113,   117,   118,   122,   125,   126,
     130,   131,   135,   136,   140,   141,   145,   146,   147,   148,
     149,   154,   155,   156,   190,   191,   196,   197,   198,   199,
     204,   211,   212,   213,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   240,   241,   242,   246,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   261,   262,
     263,   264,   268,   269,   273,   274,   275,   277,   278,   279,
     283,   284,   285,   289,   290,   294,   295,   296,   297,   298,
     299,   300,   304,   305,   306,   307,   311,   312,   313,   317,
     318,   319,   323,   324,   325,   326,   327,   331,   332,   333,
     337,   338,   342,   343,   347,   348,   352,   353,   357,   358,
     362
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
  "MULTIPLE_ARGUMENTS", "SINGLE_ARGUMENT", "WRAPPED_PARAMETERS",
  "MULTIPLE_PARAMETERS", "SCOPE", "MULTIPLE_STATEMENTS",
  "SINGLE_STATEMENT", "SELECTION_STATEMENT", "ITERATION_STATEMENT",
  "JUMP_STATEMENT", "EXPRESSION_STATEMENT", "EXPRESSION",
  "ASSIGNMENT_OPERATOR", "DECLARATOR", "VARIABLE_DECLARATION",
  "TYPE_SPECIFIER", "ASSIGNMENT_STATEMENT", "MATH_OR_BITWISE_EXPRESSION",
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
     335,   336,   337,   338,   339
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     200,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     165,    20,   -66,   200,   200,   200,   -42,   -34,   -37,   -28,
     244,   -35,   -29,   316,   -26,   -66,   -66,   -66,   -27,   -66,
     -66,   -66,   -66,   -66,   374,   -22,   -66,   -66,   -66,   -66,
       7,   244,   -66,   -66,   -66,   -66,   -12,   240,   -66,   -34,
     -66,   -66,   -66,   -18,   -66,   374,    -2,    52,    33,   -16,
      36,    27,    29,    34,    21,    42,   -66,   -66,   -66,   -66,
     -66,   200,   -48,   -66,   -66,   -66,   -66,    72,    72,   -66,
      31,    72,   -66,   370,    23,   374,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   374,
     326,   -66,   374,    53,   -66,   -66,    51,   -66,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   -66,   374,    43,   -53,
      72,    59,   -66,    61,   -66,   -66,    40,   -66,    68,   -66,
      67,    73,   -66,   -66,   -66,   -66,    -2,    -2,    52,    52,
      33,    33,    33,    33,   -16,   -16,    36,    27,    34,    34,
      21,   -66,    70,    79,   -34,   -66,   -66,    72,   244,   244,
     -66,   -34,   -66,   374,   -66,   202,   -66,    78,    24,   -66,
     -66,   -66,   -66,   244,   -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    60,    65,    64,    62,    63,    61,    66,    67,    59,
       0,     0,     2,     5,     4,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    89,    88,     0,    90,
      85,    86,    87,    23,     0,    55,    75,    76,    77,    26,
       0,    25,    30,    29,    28,    27,     0,    74,    41,     0,
      42,    43,    80,    83,    92,     0,    96,    99,   102,   107,
     110,   112,   114,   116,   118,   120,    72,     1,    10,     9,
       8,     6,    71,    58,    38,    39,    33,     0,     0,    36,
       0,     0,    56,    74,     0,     0,    22,    24,    40,    51,
      50,    48,    49,    45,    46,    47,    52,    53,    54,     0,
       0,    79,     0,    71,    81,    82,    74,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,    37,     0,    44,    78,     0,    69,    70,    19,
       0,    21,    73,    93,    94,    95,    98,    97,   101,   100,
     103,   104,   105,   106,   108,   109,   111,   113,   115,   117,
     119,    14,     0,    16,     0,    11,    12,     0,     0,     0,
      57,     0,    18,     0,    13,     0,    17,     0,    31,    34,
      68,    20,    15,     0,    32,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,    -7,   -66,   -66,   -66,   -17,   -66,   -66,   -13,
      10,   118,   -19,    -4,   -66,   -66,   -65,   -21,   -66,    -1,
      17,     0,   -14,   -30,   -66,   -66,    13,   -66,     3,     4,
      15,     5,    41,    39,   -66,    18,    54,   -66,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,   129,   162,   163,   101,   140,
      39,    40,    41,    42,    43,    44,    45,    46,   102,   106,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    76,    80,    73,    84,    28,    68,    69,    70,    47,
      15,   127,   130,    17,    17,    17,    72,    16,   165,    47,
      67,    10,    47,    15,    15,    15,   115,   116,   128,    71,
      16,    16,    16,    83,    74,    73,    20,   108,   109,   110,
      47,    77,    22,    75,   104,   105,    35,    78,   103,     1,
      81,   117,   118,    82,     2,   136,    85,   131,     3,    88,
     133,   121,     4,     5,   126,   167,     6,     7,   107,   138,
     141,    17,   142,   122,     8,     9,    47,    47,     1,   123,
      47,    15,    86,     2,    83,   137,   124,     3,    16,   111,
     112,     4,     5,   113,   114,     6,     7,   138,    47,    83,
     135,    83,   132,     8,     9,   119,   120,    25,   125,    26,
      27,    28,   127,   137,   146,   147,    29,   148,   149,   170,
     161,   143,   144,   145,   154,   155,    47,   100,   164,    47,
     150,   151,   152,   153,    30,    31,   168,    32,   169,   166,
     171,   158,   159,   141,   172,   173,   177,   174,    34,   178,
     179,   175,    35,    36,    37,   183,    38,   180,   182,    87,
     181,   157,   156,   176,   185,     0,    47,    47,    47,    18,
     103,     1,    83,    19,   184,   164,     2,    20,     0,   160,
       3,    21,    47,    22,     4,     5,     0,    23,     6,     7,
       0,     0,     0,     0,     0,     0,     8,     9,    24,     0,
      25,     0,    26,    27,    28,     0,     1,     0,     1,    29,
       0,     2,     0,     2,     0,     3,     0,     3,     0,     4,
       5,     4,     5,     6,     7,     6,     7,    30,    31,     0,
      32,     8,     9,     8,     9,     0,     0,     0,     0,    10,
      33,    34,     0,     0,     0,    35,    36,    37,    18,    38,
       1,     0,    19,     0,     0,     2,    20,     0,     0,     3,
      21,     0,    22,     4,     5,     0,    23,     6,     7,     0,
       0,     0,     0,     0,    10,     8,     9,    24,     0,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    29,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,    30,    31,     0,    32,
       0,   -71,     0,     0,     0,     0,   100,   -71,    10,     0,
      34,     0,     1,     0,    35,    36,    37,     2,    38,     0,
       0,     3,     0,     0,     0,     4,     5,     0,     0,     6,
       7,     0,     0,     0,     0,     0,     0,     8,     9,     0,
       0,    25,     0,    26,    27,    28,     0,     0,     0,     0,
      29,    25,     0,    26,    27,    28,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,    30,    31,
       0,    32,     0,     0,     0,     0,     0,    79,    30,    31,
       0,    32,    34,     0,     0,     0,    35,    36,    37,     0,
      38,     0,    34,   139,     0,     0,    35,    36,    37,    25,
      38,    26,    27,    28,     0,     0,     0,     0,    29,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   134,
       0,     0,     0,     0,     0,     0,    30,    31,     0,    32,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
      34,     0,     0,     0,    35,    36,    37,     0,    38
};

static const yytype_int16 yycheck[] =
{
       0,    20,    23,    17,    34,    39,    13,    14,    15,    10,
       0,    59,    77,    13,    14,    15,    17,     0,    71,    20,
       0,    74,    23,    13,    14,    15,    42,    43,    76,    71,
      13,    14,    15,    34,    71,    49,    12,    39,    40,    41,
      41,    76,    18,    71,    62,    63,    80,    76,    49,     6,
      76,    67,    68,    80,    11,    85,    78,    78,    15,    71,
      81,    34,    19,    20,    71,   130,    23,    24,    55,    99,
     100,    71,   102,    44,    31,    32,    77,    78,     6,    45,
      81,    71,    75,    11,    85,    99,    65,    15,    71,    37,
      38,    19,    20,    60,    61,    23,    24,   127,    99,   100,
      77,   102,    71,    31,    32,    69,    70,    35,    66,    37,
      38,    39,    59,   127,   111,   112,    44,   113,   114,    79,
      77,   108,   109,   110,   119,   120,   127,    76,   128,   130,
     115,   116,   117,   118,    62,    63,    77,    65,    77,   129,
      72,   123,   124,   173,    77,    72,   167,    77,    76,   168,
     169,    72,    80,    81,    82,    77,    84,   171,   175,    41,
     173,   122,   121,   164,   183,    -1,   167,   168,   169,     4,
     171,     6,   173,     8,   178,   175,    11,    12,    -1,   125,
      15,    16,   183,    18,    19,    20,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    37,    38,    39,    -1,     6,    -1,     6,    44,
      -1,    11,    -1,    11,    -1,    15,    -1,    15,    -1,    19,
      20,    19,    20,    23,    24,    23,    24,    62,    63,    -1,
      65,    31,    32,    31,    32,    -1,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    81,    82,     4,    84,
       6,    -1,     8,    -1,    -1,    11,    12,    -1,    -1,    15,
      16,    -1,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    74,    31,    32,    33,    -1,    35,
      -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    71,    -1,    -1,    -1,    -1,    76,    77,    74,    -1,
      76,    -1,     6,    -1,    80,    81,    82,    11,    84,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    62,    63,
      -1,    65,    76,    -1,    -1,    -1,    80,    81,    82,    -1,
      84,    -1,    76,    77,    -1,    -1,    80,    81,    82,    35,
      84,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    81,    82,    -1,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    15,    19,    20,    23,    24,    31,    32,
      74,    86,    87,    88,    89,    95,   105,   106,     4,     8,
      12,    16,    18,    22,    33,    35,    37,    38,    39,    44,
      62,    63,    65,    75,    76,    80,    81,    82,    84,    95,
      96,    97,    98,    99,   100,   101,   102,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,    87,    87,
      87,    71,   104,   107,    71,    71,    97,    76,    76,    71,
     102,    76,    80,   104,   108,    78,    75,    96,    71,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      76,    93,   103,   104,    62,    63,   104,   111,    39,    40,
      41,    37,    38,    60,    61,    42,    43,    67,    68,    69,
      70,    34,    44,    45,    65,    66,    87,    59,    76,    90,
     101,   102,    71,   102,    59,    77,   108,   107,   108,    77,
      94,   108,   108,   111,   111,   111,   113,   113,   114,   114,
     115,   115,   115,   115,   116,   116,   117,   118,   120,   120,
     121,    77,    91,    92,   106,    71,    95,   101,    77,    77,
      79,    72,    77,    72,    77,    72,   104,   102,    97,    97,
     107,    94,    91,    77,    98,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    98,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   104,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   114,   114,   114,   115,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     3,     2,     2,
       2,     4,     4,     3,     2,     3,     1,     2,     3,     2,
       3,     1,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     6,     2,     5,     7,     2,     3,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       3,     1,     1,     3,     1,     1,     1,     1,     3,     2,
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
#line 76 "src/parser.y" /* yacc.c:1646  */
    { g_root = new RootNode((yyvsp[0].node)); }
#line 1528 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1534 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1540 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1546 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1552 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1558 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1564 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1570 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1576 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));; }
#line 1582 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 107 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDefinition((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1588 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 112 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1594 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 113 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper(NULL); }
#line 1600 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleArguments((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1606 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 118 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleArguments((yyvsp[0].node), NULL); }
#line 1612 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1618 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1624 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper(NULL); }
#line 1630 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleParameters((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1636 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 131 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleParameters((yyvsp[0].node), NULL); }
#line 1642 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Scope((yyvsp[-1].node)); }
#line 1648 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Scope(NULL); }
#line 1654 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1660 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultipleStatements((yyvsp[0].node), NULL); }
#line 1666 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 145 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1672 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 146 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1678 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 147 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1684 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 148 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1690 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 149 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1696 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 154 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1702 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfStatement((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1708 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 156 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1714 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1720 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ForLoop((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1726 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("RETURN", NULL); }
#line 1732 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("RETURN", (yyvsp[-1].node)); }
#line 1738 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("BREAK", NULL); }
#line 1744 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new JumpStatement("CONTINUE", NULL); }
#line 1750 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1756 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1762 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1768 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1774 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("="); }
#line 1780 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("*="); }
#line 1786 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 220 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("/="); }
#line 1792 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("%="); }
#line 1798 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("+="); }
#line 1804 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 223 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("-="); }
#line 1810 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("<<="); }
#line 1816 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator(">>="); }
#line 1822 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("&="); }
#line 1828 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("^="); }
#line 1834 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentOperator("|="); }
#line 1840 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable(*(yyvsp[0].string), "NORMAL", NULL); delete (yyvsp[0].string); }
#line 1846 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 241 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable(*(yyvsp[0].string), "POINTER", NULL); delete (yyvsp[0].string); }
#line 1852 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable(*(yyvsp[-3].string), "ARRAY", (yyvsp[-1].node) ); delete (yyvsp[-3].string); }
#line 1858 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1864 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("VOID"); }
#line 1870 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("CHAR"); }
#line 1876 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("SHORT"); }
#line 1882 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("INT"); }
#line 1888 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("LONG"); }
#line 1894 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("FLOAT"); }
#line 1900 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("DOUBLE"); }
#line 1906 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("SIGNED"); }
#line 1912 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TypeSpecifier("UNSIGNED"); }
#line 1918 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 261 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1924 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 1930 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1936 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 264 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentStatement((yyvsp[0].node), NULL, NULL); }
#line 1942 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1948 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 269 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentExpression((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1954 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 273 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1960 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IntegerConstant( (yyvsp[0].integer_constant) ); }
#line 1966 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FloatConstant( (yyvsp[0].float_constant) ); }
#line 1972 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StringLiteral(*(yyvsp[0].string)); }
#line 1978 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ParenthesisWrapper((yyvsp[-1].node)); }
#line 1984 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionCall((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1990 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1996 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "++"); }
#line 2002 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "--"); }
#line 2008 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2014 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryExpression((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2020 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("++"); }
#line 2026 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("--"); }
#line 2032 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("&"); }
#line 2038 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("+"); }
#line 2044 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("-"); }
#line 2050 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("~"); }
#line 2056 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UnaryOperator("!"); }
#line 2062 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2068 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 2074 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 2080 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "%", (yyvsp[0].node)); }
#line 2086 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2092 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 2098 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 2104 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2110 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ShiftExpression((yyvsp[-2].node), "<<", (yyvsp[0].node)); }
#line 2116 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ShiftExpression((yyvsp[-2].node), ">>", (yyvsp[0].node)); }
#line 2122 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2128 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<", (yyvsp[0].node)); }
#line 2134 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">", (yyvsp[0].node)); }
#line 2140 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 326 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<=", (yyvsp[0].node)); }
#line 2146 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">=", (yyvsp[0].node)); }
#line 2152 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2158 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "==", (yyvsp[0].node)); }
#line 2164 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "!=", (yyvsp[0].node)); }
#line 2170 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2176 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BitwiseANDExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2182 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 342 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2188 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BitwiseXORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2194 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 347 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2200 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 348 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BitwiseORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2206 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 352 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2212 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 353 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "and", (yyvsp[0].node)); }
#line 2218 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 357 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2224 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 358 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "or", (yyvsp[0].node)); }
#line 2230 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 362 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2236 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2240 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 370 "src/parser.y" /* yacc.c:1906  */


// Definition of variable (to match declaration earlier).
const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
