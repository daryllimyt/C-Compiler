/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 64 "src/parser.tab.hpp"

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

#line 168 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
