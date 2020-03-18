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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

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
       0,    76,    76,    80,    81,    82,    84,    85,    86,    87,
      88,   103,   107,   112,   113,   117,   118,   122,   129,   130,
     134,   135,   139,   140,   141,   142,   143,   148,   149,   150,
     184,   185,   190,   191,   192,   193,   198,   205,   206,   207,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   234,   239,   240,   241,   246,   247,   251,   252,   253,
     255,   256,   257,   261,   262,   263,   267,   268,   272,   273,
     274,   275,   276,   277,   278,   282,   283,   284,   285,   289,
     290,   291,   295,   296,   297,   301,   302,   303,   304,   305,
     309,   310,   311,   315,   316,   320,   321,   325,   326,   330,
     331,   335,   336,   340,   347,   348,   352,   353,   357,   358,
     364,   365,   366,   367,   368,   369,   370,   371,   372
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
  "ASSIGNMENT_OPERATOR", "VARIABLE_DECLARATION", "ASSIGNMENT_STATEMENT",
  "MATH_OR_BITWISE_EXPRESSION", "PRIMARY_EXPRESSION", "POSTFIX_EXPRESSION",
  "UNARY_EXPRESSION", "UNARY_OPERATOR", "MULTIPLICATIVE_EXPRESSION",
  "ADDITIVE_EXPRESSION", "SHIFT_EXPRESSION", "RELATIONAL_EXPRESSION",
  "EQUALITY_EXPRESSION", "BITWISE_AND_EXPRESSION",
  "BITWISE_XOR_EXPRESSION", "BITWISE_OR_EXPRESSION",
  "BOOLEAN_AND_EXPRESSION", "BOOLEAN_OR_EXPRESSION",
  "CONDITIONAL_EXPRESSION", "WRAPPED_PARAMETERS", "MULTIPLE_PARAMETERS",
  "DECLARATOR", "TYPE_SPECIFIER", YY_NULLPTR
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

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     164,    20,   -67,    43,    43,    43,   -66,   -12,   -53,   -39,
     243,   -40,   -32,   315,   -15,   -67,   -67,   -67,   -10,   -67,
     -67,   -67,   -67,   -67,   383,   -67,   -67,   -67,   -67,   -67,
     -16,   243,   -67,   -67,   -67,   -67,    25,   -67,   -67,   -67,
     -67,    31,   -67,   383,    47,    18,    12,    36,    39,    64,
      61,    67,    51,    52,   -67,   160,   -12,   -67,   -67,   -67,
     -67,    43,   -67,   -47,   -67,   -67,   -67,   325,   325,   -67,
      53,   325,   -67,    49,   239,   -67,   -67,   -67,   -67,   -67,
     -67,    55,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     383,   373,   383,   -67,    77,   -67,   383,    15,   -26,   325,
      62,   -67,    63,   -67,   -67,   -67,   -67,   -67,    47,    47,
      18,    18,    12,    12,    12,    12,    36,    36,    39,    64,
      67,    67,    51,   -67,   -67,   -67,    69,    65,   -67,   -67,
      66,    73,   -12,   -67,   -67,   325,   243,   243,   383,   -67,
     -67,    91,   -67,    72,    19,   -67,   -67,   -67,   243,   -67,
     -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   111,   116,   115,   113,   114,   112,   117,   118,   110,
       0,     0,     2,     5,     4,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    72,    71,     0,    73,
      68,    69,    70,    19,     0,   108,    58,    59,    60,    22,
       0,    21,    26,    25,    24,    23,     0,    37,    38,    39,
      63,    66,    75,     0,    79,    82,    85,    90,    93,    95,
      97,    99,   101,   103,    55,    57,     0,     1,    10,     9,
       8,     6,    51,    54,    34,    35,    29,     0,     0,    32,
       0,     0,   109,     0,    57,    18,    20,    36,    64,    65,
      67,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    46,    44,    45,    41,    42,    43,    48,    49,    50,
       0,     0,     0,    62,    54,     7,     0,     0,     0,     0,
       0,    33,     0,    61,    40,    76,    77,    78,    81,    80,
      84,    83,    86,    87,    88,    89,    91,    92,    94,    96,
      98,   100,   102,    52,    53,   105,   107,     0,    56,    14,
       0,    16,     0,    11,    12,     0,     0,     0,     0,   104,
      13,     0,    17,     0,    27,    30,   106,    15,     0,    28,
      31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,    -7,   -67,   -67,   -67,   -25,   -67,    10,   109,
     -19,   -23,   -67,   -67,   -60,   -21,   -67,    28,   -13,   -31,
     -67,   -67,   -42,   -67,     5,    32,   -17,    29,    48,    46,
     -67,    27,    45,   -67,   -67,   -67,   -11,    -1,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,   128,   160,   161,    39,    40,
      41,    42,    43,    44,    45,    46,   122,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   123,   157,    91,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    76,    80,    83,    72,    71,    68,    69,    70,    65,
      15,    90,   126,    17,    17,    17,    73,   129,    74,    65,
      67,     1,    65,    15,    15,    15,     2,    28,    16,   127,
       3,    20,    75,    84,     4,     5,    77,    22,     6,     7,
      65,    16,    16,    16,    78,   163,     8,     9,    10,     1,
     135,   136,   137,    72,     2,    95,    96,   130,     3,    85,
     132,    81,     4,     5,   125,   124,     6,     7,    35,   165,
      82,    17,    97,    98,     8,     9,    65,    65,    99,   100,
      65,    15,   142,   143,   144,   145,    92,    93,    94,   154,
     156,   158,   159,    88,    89,   154,    87,     1,   105,    16,
     138,   139,     2,   101,   102,   106,     3,   153,   103,   104,
       4,     5,   107,   153,     6,     7,   108,    10,   109,    65,
      84,    84,     8,     9,   131,    65,   133,   162,    65,   140,
     141,   121,   146,   147,   150,   151,   126,   156,   164,   166,
     167,   168,   169,   170,   173,   171,   177,   174,   175,   178,
      86,   179,   149,   148,   152,     0,     0,   176,     0,   180,
       0,   172,     0,     0,    65,    65,    65,    84,    18,     0,
       1,   162,    19,     0,     0,     2,    20,    65,     0,     3,
      21,     0,    22,     4,     5,     0,    23,     6,     7,     0,
       0,     0,     0,     0,     0,     8,     9,    24,     0,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    29,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,    30,    31,     0,    32,
       0,   -54,     0,     0,     0,     0,   121,   -54,    10,    33,
      34,     0,     0,     0,    35,    36,    37,    18,    38,     1,
       0,    19,     0,     0,     2,    20,     0,     0,     3,    21,
       0,    22,     4,     5,     0,    23,     6,     7,     0,     0,
       0,     0,     0,     0,     8,     9,    24,     0,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    29,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   134,     0,
       0,     0,     0,     0,     0,    30,    31,     0,    32,     0,
       0,     0,     0,     0,     0,   121,     0,    10,     0,    34,
       0,     1,     0,    35,    36,    37,     2,    38,     0,     0,
       3,     1,     0,     0,     4,     5,     2,     0,     6,     7,
       3,     0,     0,     0,     4,     5,     8,     9,     6,     7,
      25,     0,    26,    27,    28,     0,     8,     9,     0,    29,
      25,     0,    26,    27,    28,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
      32,     0,     0,     0,     0,     0,    79,    30,    31,     0,
      32,    34,     0,     0,     0,    35,    36,    37,     0,    38,
       0,    34,     0,     0,     0,    35,    36,    37,    25,    38,
      26,    27,    28,     0,     0,     0,     0,    29,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,    30,    31,     0,    32,     0,
       0,     0,     0,     0,     0,    30,    31,     0,    32,    34,
     155,     0,     0,    35,    36,    37,     0,    38,     0,    34,
       0,     0,     0,    35,    36,    37,     0,    38
};

static const yytype_int16 yycheck[] =
{
       0,    20,    23,    34,    17,    71,    13,    14,    15,    10,
       0,    53,    59,    13,    14,    15,    17,    77,    71,    20,
       0,     6,    23,    13,    14,    15,    11,    39,     0,    76,
      15,    12,    71,    34,    19,    20,    76,    18,    23,    24,
      41,    13,    14,    15,    76,    71,    31,    32,    74,     6,
      92,    93,    94,    66,    11,    37,    38,    78,    15,    75,
      81,    76,    19,    20,    71,    66,    23,    24,    80,   129,
      80,    71,    60,    61,    31,    32,    77,    78,    42,    43,
      81,    71,    99,   100,   101,   102,    39,    40,    41,   120,
     121,   122,    77,    62,    63,   126,    71,     6,    34,    71,
      95,    96,    11,    67,    68,    44,    15,   120,    69,    70,
      19,    20,    45,   126,    23,    24,    65,    74,    66,   120,
     121,   122,    31,    32,    71,   126,    77,   127,   129,    97,
      98,    76,   103,   104,   107,   108,    59,   168,   128,    77,
      77,    72,    77,    77,   165,    72,   171,   166,   167,    77,
      41,   174,   106,   105,   109,    -1,    -1,   168,    -1,   178,
      -1,   162,    -1,    -1,   165,   166,   167,   168,     4,    -1,
       6,   171,     8,    -1,    -1,    11,    12,   178,    -1,    15,
      16,    -1,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,    35,
      -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    71,    -1,    -1,    -1,    -1,    76,    77,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    82,     4,    84,     6,
      -1,     8,    -1,    -1,    11,    12,    -1,    -1,    15,    16,
      -1,    18,    19,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    -1,    35,    -1,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    74,    -1,    76,
      -1,     6,    -1,    80,    81,    82,    11,    84,    -1,    -1,
      15,     6,    -1,    -1,    19,    20,    11,    -1,    23,    24,
      15,    -1,    -1,    -1,    19,    20,    31,    32,    23,    24,
      35,    -1,    37,    38,    39,    -1,    31,    32,    -1,    44,
      35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    71,    62,    63,    -1,
      65,    76,    -1,    -1,    -1,    80,    81,    82,    -1,    84,
      -1,    76,    -1,    -1,    -1,    80,    81,    82,    35,    84,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    35,    -1,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,    76,
      77,    -1,    -1,    80,    81,    82,    -1,    84,    -1,    76,
      -1,    -1,    -1,    80,    81,    82,    -1,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    11,    15,    19,    20,    23,    24,    31,    32,
      74,    86,    87,    88,    89,    93,   102,   123,     4,     8,
      12,    16,    18,    22,    33,    35,    37,    38,    39,    44,
      62,    63,    65,    75,    76,    80,    81,    82,    84,    93,
      94,    95,    96,    97,    98,    99,   100,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   122,   123,     0,    87,    87,
      87,    71,   103,   122,    71,    71,    95,    76,    76,    71,
     100,    76,    80,   104,   122,    75,    94,    71,    62,    63,
     107,   122,    39,    40,    41,    37,    38,    60,    61,    42,
      43,    67,    68,    69,    70,    34,    44,    45,    65,    66,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    76,   101,   120,   122,    87,    59,    76,    90,    99,
     100,    71,   100,    77,    59,   107,   107,   107,   109,   109,
     110,   110,   111,   111,   111,   111,   112,   112,   113,   114,
     116,   116,   117,   103,   104,    77,   104,   121,   104,    77,
      91,    92,   123,    71,    93,    99,    77,    77,    72,    77,
      77,    72,   122,   100,    95,    95,   121,    91,    77,    96,
      95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    95,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    98,    98,    98,    99,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   103,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   106,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     3,     2,     2,
       2,     4,     4,     3,     2,     3,     1,     2,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     5,     6,     2,
       5,     7,     2,     3,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     3,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 76 "src/parser.y"
                { g_root = new RootNode((yyvsp[0].node)); }
#line 1620 "src/parser.tab.cpp"
    break;

  case 3:
#line 80 "src/parser.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 1626 "src/parser.tab.cpp"
    break;

  case 4:
#line 81 "src/parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1632 "src/parser.tab.cpp"
    break;

  case 5:
#line 82 "src/parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1638 "src/parser.tab.cpp"
    break;

  case 6:
#line 84 "src/parser.y"
                                     { (yyval.node) = (yyvsp[-1].node); }
#line 1644 "src/parser.tab.cpp"
    break;

  case 7:
#line 85 "src/parser.y"
                                           { (yyval.node) = new Frame((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1650 "src/parser.tab.cpp"
    break;

  case 8:
#line 86 "src/parser.y"
                                           { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1656 "src/parser.tab.cpp"
    break;

  case 9:
#line 87 "src/parser.y"
                                      { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1662 "src/parser.tab.cpp"
    break;

  case 10:
#line 88 "src/parser.y"
                                     { (yyval.node) = new Frame((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1668 "src/parser.tab.cpp"
    break;

  case 11:
#line 103 "src/parser.y"
                                                             { (yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));; }
#line 1674 "src/parser.tab.cpp"
    break;

  case 12:
#line 107 "src/parser.y"
                                                      { (yyval.node) = new FunctionDefinition((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1680 "src/parser.tab.cpp"
    break;

  case 13:
#line 112 "src/parser.y"
                                                        { (yyval.node) = new WrappedArguments((yyvsp[-1].node), NULL); }
#line 1686 "src/parser.tab.cpp"
    break;

  case 14:
#line 113 "src/parser.y"
                                                        { (yyval.node) = new WrappedArguments(NULL, NULL); }
#line 1692 "src/parser.tab.cpp"
    break;

  case 15:
#line 117 "src/parser.y"
                                                { (yyval.node) = new MultipleArguments((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1698 "src/parser.tab.cpp"
    break;

  case 16:
#line 118 "src/parser.y"
                                                { (yyval.node) = new MultipleArguments((yyvsp[0].node), NULL); }
#line 1704 "src/parser.tab.cpp"
    break;

  case 17:
#line 122 "src/parser.y"
                                { (yyval.node) = new VariableDeclaration(NULL, (yyvsp[0].node)); }
#line 1710 "src/parser.tab.cpp"
    break;

  case 18:
#line 129 "src/parser.y"
                                            { (yyval.node) = new Scope((yyvsp[-1].node)); }
#line 1716 "src/parser.tab.cpp"
    break;

  case 19:
#line 130 "src/parser.y"
                                       { (yyval.node) = new Scope(NULL); }
#line 1722 "src/parser.tab.cpp"
    break;

  case 20:
#line 134 "src/parser.y"
                                         { (yyval.node) = new MultipleStatements((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1728 "src/parser.tab.cpp"
    break;

  case 21:
#line 135 "src/parser.y"
                                    { (yyval.node) = new MultipleStatements((yyvsp[0].node), NULL); }
#line 1734 "src/parser.tab.cpp"
    break;

  case 22:
#line 139 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1740 "src/parser.tab.cpp"
    break;

  case 23:
#line 140 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1746 "src/parser.tab.cpp"
    break;

  case 24:
#line 141 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1752 "src/parser.tab.cpp"
    break;

  case 25:
#line 142 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1758 "src/parser.tab.cpp"
    break;

  case 26:
#line 143 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1764 "src/parser.tab.cpp"
    break;

  case 27:
#line 148 "src/parser.y"
                                                                                                  { (yyval.node) = new IfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1770 "src/parser.tab.cpp"
    break;

  case 28:
#line 149 "src/parser.y"
                                                                                           { (yyval.node) = new IfStatement((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1776 "src/parser.tab.cpp"
    break;

  case 29:
#line 150 "src/parser.y"
                                                                                                         { (yyval.node) = (yyvsp[0].node); }
#line 1782 "src/parser.tab.cpp"
    break;

  case 30:
#line 184 "src/parser.y"
                                                                                                                    { (yyval.node) = new WhileLoop((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1788 "src/parser.tab.cpp"
    break;

  case 31:
#line 185 "src/parser.y"
                                                                                                                 { (yyval.node) = new ForLoop((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1794 "src/parser.tab.cpp"
    break;

  case 32:
#line 190 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("return", NULL); }
#line 1800 "src/parser.tab.cpp"
    break;

  case 33:
#line 191 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("return", (yyvsp[-1].node)); }
#line 1806 "src/parser.tab.cpp"
    break;

  case 34:
#line 192 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("break", NULL); }
#line 1812 "src/parser.tab.cpp"
    break;

  case 35:
#line 193 "src/parser.y"
                                    { (yyval.node) = new JumpStatement("continue", NULL); }
#line 1818 "src/parser.tab.cpp"
    break;

  case 36:
#line 198 "src/parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1824 "src/parser.tab.cpp"
    break;

  case 37:
#line 205 "src/parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1830 "src/parser.tab.cpp"
    break;

  case 38:
#line 206 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1836 "src/parser.tab.cpp"
    break;

  case 39:
#line 207 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1842 "src/parser.tab.cpp"
    break;

  case 40:
#line 212 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("="); }
#line 1848 "src/parser.tab.cpp"
    break;

  case 41:
#line 213 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("*="); }
#line 1854 "src/parser.tab.cpp"
    break;

  case 42:
#line 214 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("/="); }
#line 1860 "src/parser.tab.cpp"
    break;

  case 43:
#line 215 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("%="); }
#line 1866 "src/parser.tab.cpp"
    break;

  case 44:
#line 216 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("+="); }
#line 1872 "src/parser.tab.cpp"
    break;

  case 45:
#line 217 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("-="); }
#line 1878 "src/parser.tab.cpp"
    break;

  case 46:
#line 218 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("<<="); }
#line 1884 "src/parser.tab.cpp"
    break;

  case 47:
#line 219 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator(">>="); }
#line 1890 "src/parser.tab.cpp"
    break;

  case 48:
#line 220 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("&="); }
#line 1896 "src/parser.tab.cpp"
    break;

  case 49:
#line 221 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("^="); }
#line 1902 "src/parser.tab.cpp"
    break;

  case 50:
#line 222 "src/parser.y"
                        { (yyval.node) = new AssignmentOperator("|="); }
#line 1908 "src/parser.tab.cpp"
    break;

  case 51:
#line 234 "src/parser.y"
                                                { (yyval.node) = new VariableDeclaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1914 "src/parser.tab.cpp"
    break;

  case 52:
#line 239 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 1920 "src/parser.tab.cpp"
    break;

  case 53:
#line 240 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1926 "src/parser.tab.cpp"
    break;

  case 54:
#line 241 "src/parser.y"
                                                                                    { (yyval.node) = new AssignmentStatement((yyvsp[0].node), NULL, NULL); }
#line 1932 "src/parser.tab.cpp"
    break;

  case 55:
#line 246 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1938 "src/parser.tab.cpp"
    break;

  case 56:
#line 247 "src/parser.y"
                                                              { (yyval.node) = new AssignmentExpression((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1944 "src/parser.tab.cpp"
    break;

  case 57:
#line 251 "src/parser.y"
                                              { (yyval.node) = (yyvsp[0].node); }
#line 1950 "src/parser.tab.cpp"
    break;

  case 58:
#line 252 "src/parser.y"
                                         { (yyval.node) = new IntegerConstant( (yyvsp[0].integer_constant) ); }
#line 1956 "src/parser.tab.cpp"
    break;

  case 59:
#line 253 "src/parser.y"
                                          { (yyval.node) = new FloatConstant( (yyvsp[0].float_constant) ); }
#line 1962 "src/parser.tab.cpp"
    break;

  case 60:
#line 255 "src/parser.y"
                                         { (yyval.node) = new StringLiteral(*(yyvsp[0].string)); }
#line 1968 "src/parser.tab.cpp"
    break;

  case 61:
#line 256 "src/parser.y"
                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1974 "src/parser.tab.cpp"
    break;

  case 62:
#line 257 "src/parser.y"
                                   { (yyval.node) = new FunctionCall((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1980 "src/parser.tab.cpp"
    break;

  case 63:
#line 261 "src/parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1986 "src/parser.tab.cpp"
    break;

  case 64:
#line 262 "src/parser.y"
                                 { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "++"); }
#line 1992 "src/parser.tab.cpp"
    break;

  case 65:
#line 263 "src/parser.y"
                                 { (yyval.node) = new PostfixExpression((yyvsp[-1].node), "--"); }
#line 1998 "src/parser.tab.cpp"
    break;

  case 66:
#line 267 "src/parser.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 2004 "src/parser.tab.cpp"
    break;

  case 67:
#line 268 "src/parser.y"
                                     { (yyval.node) = new UnaryExpression((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2010 "src/parser.tab.cpp"
    break;

  case 68:
#line 272 "src/parser.y"
                { (yyval.node) = new UnaryOperator("++"); }
#line 2016 "src/parser.tab.cpp"
    break;

  case 69:
#line 273 "src/parser.y"
                { (yyval.node) = new UnaryOperator("--"); }
#line 2022 "src/parser.tab.cpp"
    break;

  case 70:
#line 274 "src/parser.y"
                { (yyval.node) = new UnaryOperator("&"); }
#line 2028 "src/parser.tab.cpp"
    break;

  case 71:
#line 275 "src/parser.y"
                { (yyval.node) = new UnaryOperator("+"); }
#line 2034 "src/parser.tab.cpp"
    break;

  case 72:
#line 276 "src/parser.y"
                { (yyval.node) = new UnaryOperator("-"); }
#line 2040 "src/parser.tab.cpp"
    break;

  case 73:
#line 277 "src/parser.y"
                { (yyval.node) = new UnaryOperator("~"); }
#line 2046 "src/parser.tab.cpp"
    break;

  case 74:
#line 278 "src/parser.y"
                { (yyval.node) = new UnaryOperator("!"); }
#line 2052 "src/parser.tab.cpp"
    break;

  case 75:
#line 282 "src/parser.y"
                                                    { (yyval.node) = (yyvsp[0].node); }
#line 2058 "src/parser.tab.cpp"
    break;

  case 76:
#line 283 "src/parser.y"
                                                       { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 2064 "src/parser.tab.cpp"
    break;

  case 77:
#line 284 "src/parser.y"
                                                      { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 2070 "src/parser.tab.cpp"
    break;

  case 78:
#line 285 "src/parser.y"
                                                      { (yyval.node) = new MultiplicativeExpression((yyvsp[-2].node), "%", (yyvsp[0].node)); }
#line 2076 "src/parser.tab.cpp"
    break;

  case 79:
#line 289 "src/parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 2082 "src/parser.tab.cpp"
    break;

  case 80:
#line 290 "src/parser.y"
                                                          { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 2088 "src/parser.tab.cpp"
    break;

  case 81:
#line 291 "src/parser.y"
                                                           { (yyval.node) = new AdditiveExpression((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 2094 "src/parser.tab.cpp"
    break;

  case 82:
#line 295 "src/parser.y"
                                                   { (yyval.node) = (yyvsp[0].node); }
#line 2100 "src/parser.tab.cpp"
    break;

  case 83:
#line 296 "src/parser.y"
                                                       { (yyval.node) = new ShiftExpression((yyvsp[-2].node), "<<", (yyvsp[0].node)); }
#line 2106 "src/parser.tab.cpp"
    break;

  case 84:
#line 297 "src/parser.y"
                                                      { (yyval.node) = new ShiftExpression((yyvsp[-2].node), ">>", (yyvsp[0].node)); }
#line 2112 "src/parser.tab.cpp"
    break;

  case 85:
#line 301 "src/parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2118 "src/parser.tab.cpp"
    break;

  case 86:
#line 302 "src/parser.y"
                                                   { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<", (yyvsp[0].node)); }
#line 2124 "src/parser.tab.cpp"
    break;

  case 87:
#line 303 "src/parser.y"
                                                   { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">", (yyvsp[0].node)); }
#line 2130 "src/parser.tab.cpp"
    break;

  case 88:
#line 304 "src/parser.y"
                                                    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), "<=", (yyvsp[0].node)); }
#line 2136 "src/parser.tab.cpp"
    break;

  case 89:
#line 305 "src/parser.y"
                                                    { (yyval.node) = new RelationalExpression((yyvsp[-2].node), ">=", (yyvsp[0].node)); }
#line 2142 "src/parser.tab.cpp"
    break;

  case 90:
#line 309 "src/parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 2148 "src/parser.tab.cpp"
    break;

  case 91:
#line 310 "src/parser.y"
                                                       { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "==", (yyvsp[0].node)); }
#line 2154 "src/parser.tab.cpp"
    break;

  case 92:
#line 311 "src/parser.y"
                                                       { (yyval.node) = new EqualityExpression((yyvsp[-2].node), "!=", (yyvsp[0].node)); }
#line 2160 "src/parser.tab.cpp"
    break;

  case 93:
#line 315 "src/parser.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 2166 "src/parser.tab.cpp"
    break;

  case 94:
#line 316 "src/parser.y"
                                                      { (yyval.node) = new BitwiseANDExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2172 "src/parser.tab.cpp"
    break;

  case 95:
#line 320 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2178 "src/parser.tab.cpp"
    break;

  case 96:
#line 321 "src/parser.y"
                                                         { (yyval.node) = new BitwiseXORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2184 "src/parser.tab.cpp"
    break;

  case 97:
#line 325 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2190 "src/parser.tab.cpp"
    break;

  case 98:
#line 326 "src/parser.y"
                                                      { (yyval.node) = new BitwiseORExpression((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2196 "src/parser.tab.cpp"
    break;

  case 99:
#line 330 "src/parser.y"
                                                         { (yyval.node) = (yyvsp[0].node); }
#line 2202 "src/parser.tab.cpp"
    break;

  case 100:
#line 331 "src/parser.y"
                                                           { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "and", (yyvsp[0].node)); }
#line 2208 "src/parser.tab.cpp"
    break;

  case 101:
#line 335 "src/parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2214 "src/parser.tab.cpp"
    break;

  case 102:
#line 336 "src/parser.y"
                                                          { (yyval.node) = new BooleanExpression((yyvsp[-2].node), "or", (yyvsp[0].node)); }
#line 2220 "src/parser.tab.cpp"
    break;

  case 103:
#line 340 "src/parser.y"
                                                                     { (yyval.node) = (yyvsp[0].node); }
#line 2226 "src/parser.tab.cpp"
    break;

  case 104:
#line 347 "src/parser.y"
                                                         { (yyval.node) = new WrappedParameters((yyvsp[-1].node), NULL); }
#line 2232 "src/parser.tab.cpp"
    break;

  case 105:
#line 348 "src/parser.y"
                                                          { (yyval.node) = new WrappedParameters(NULL, NULL); }
#line 2238 "src/parser.tab.cpp"
    break;

  case 106:
#line 352 "src/parser.y"
                                                           { (yyval.node) = new MultipleParameters((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2244 "src/parser.tab.cpp"
    break;

  case 107:
#line 353 "src/parser.y"
                                                      { (yyval.node) = new MultipleParameters((yyvsp[0].node), NULL); }
#line 2250 "src/parser.tab.cpp"
    break;

  case 108:
#line 357 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[0].string), "normal", NULL); delete (yyvsp[0].string); }
#line 2256 "src/parser.tab.cpp"
    break;

  case 109:
#line 358 "src/parser.y"
                                                                     { (yyval.node) = new Variable(*(yyvsp[0].string), "pointer", NULL); delete (yyvsp[0].string); }
#line 2262 "src/parser.tab.cpp"
    break;

  case 110:
#line 364 "src/parser.y"
               { (yyval.node) = new TypeSpecifier("void"); }
#line 2268 "src/parser.tab.cpp"
    break;

  case 111:
#line 365 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("char"); }
#line 2274 "src/parser.tab.cpp"
    break;

  case 112:
#line 366 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("short"); }
#line 2280 "src/parser.tab.cpp"
    break;

  case 113:
#line 367 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("int"); }
#line 2286 "src/parser.tab.cpp"
    break;

  case 114:
#line 368 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("long"); }
#line 2292 "src/parser.tab.cpp"
    break;

  case 115:
#line 369 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("float"); }
#line 2298 "src/parser.tab.cpp"
    break;

  case 116:
#line 370 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("double"); }
#line 2304 "src/parser.tab.cpp"
    break;

  case 117:
#line 371 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("signed int"); }
#line 2310 "src/parser.tab.cpp"
    break;

  case 118:
#line 372 "src/parser.y"
                     { (yyval.node) = new TypeSpecifier("unsigned int"); }
#line 2316 "src/parser.tab.cpp"
    break;


#line 2320 "src/parser.tab.cpp"

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
#line 375 "src/parser.y"


// Definition of variable (to match declaration earlier).
const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
