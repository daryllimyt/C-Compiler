%option noyywrap

%{
#include "parser.tab.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>


// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
int line_number = 1; // for debugging

%}



BIN 		[0-1]
OCT 		[0-7]
DEC			[0-9]
LET			[a-zA-Z_]
HEX			[a-fA-F0-9]
EXPO		[Ee][+-]?{DEC}+

FLOATSUFFIX		(f|F|l|L)
INTSUFFIX			(u|U|l|L)*

ESC    	[abfnrtv\'\"\?\\]

BINARY_INTEGER 	0[bB]{BIN}*{INTSUFFIX}?
DECIMAL_INTEGER [1-9]{DEC}*{INTSUFFIX}?
OCTAL_INTEGER 	0[OCT]*{INTSUFFIX}?
HEXA_INTEGER 		0[xX]{HEX}*{INTSUFFIX}?

INTEGER_CONSTANT 	(BINARY_INTEGER|DECIMAL_INTEGER|OCTAL_INTEGER|HEXA_INTEGER)
FLOAT_CONSTANT 		({DEC}+{EXPO}{FLOATSUFFIX}?|{DEC}*"."{DEC}+({EXPO})?{FLOATSUFFIX}?|{DEC}+"."{DEC}*({EXPO})?{FLOATSUFFIX}?)

CHAR_CONSTANT  	[L]?\'(?:\\({ESC}|{OCT}{1,3}|x{HEX}+)|[^\\'])+\'
STRING_CONSTANT [L]?\"(?:\\({ESC}|{OCT}{1,3}|x[{DEC}|{LET}]+)|[^\\"])*\"


IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*

NEW_LINE 		[\n\r]
WHITESPACE 	[ \t\v]+

SINGLE_LINE_COMMENT 	([/][/].*)
MULTIPLE_LINE_COMMENT ([/]\*(.|{NEW_LINE})*\*[/])

%%

"auto"			{ return T_AUTO; }
"break"			{ return T_BREAK; }
"case"			{ return T_CASE; }
"char"			{ return T_CHAR; }
"const"			{ return T_CONST; }
"continue"	{ return T_CONTINUE; }
"default"		{ return T_DEFAULT; }
"do"				{ return T_DO; }
"double"		{ return T_DOUBLE; }
"else"			{ return T_ELSE; }
"enum"			{ return T_ENUM; }
"extern"		{ return T_EXTERN; }
"float"			{ return T_FLOAT; }
"for"				{ return T_FOR; }
"goto"			{ return T_GOTO; }
"if"				{ return T_IF; }
"int"				{ return T_INT; }
"long"			{ return T_LONG; }
"register"	{ return T_REGISTER; }
"return"		{ return T_RETURN; }
"short"			{ return T_SHORT; }
"signed"		{ return T_SIGNED; }
"sizeof"		{ return T_SIZEOF; }
"static"		{ return T_STATIC; }
"struct"		{ return T_STRUCT; }
"switch"		{ return T_SWITCH; }
"typedef"		{ return T_TYPEDEF; }
"union"			{ return T_UNION; }
"unsigned"	{ return T_UNSIGNED; }
"void"			{ return T_VOID; }
"while"			{ return T_WHILE; }


"&"					{ return T_AND; }
"!"					{ return T_NOT; }
"~"					{ return T_INVERT; }
"-"					{ return T_MINUS }
"+"					{ return T_PLUS }
"*"					{ return T_MULT }
"/"					{ return T_DIV }
"%"					{ return T_MOD; }
"<"					{ return T_LT; }
">"					{ return T_GT; }
"^"					{ return T_XOR; }
"|"					{ return T_OR; }
"?"					{ return T_QUESTION; }
"."					{ return T_DOT; }
"..."				{ return T_ELLIPSIS; }




">>="				{ return T_RSHIFT_ASSIGN; }
"<<="				{ return T_LSHIFT_ASSIGN; }
"+="				{ return T_ADD_ASSIGN; }
"-="				{ return T_SUB_ASSIGN; }
"*="				{ return T_MUL_ASSIGN; }
"/="				{ return T_DIV_ASSIGN; }
"%="				{ return T_MOD_ASSIGN; }
"&="				{ return T_AND_ASSIGN; }
"^="				{ return T_XOR_ASSIGN; }
"|="				{ return T_OR_ASSIGN; }
"="					{ return T_EQ_ASSIGN; }



">>"				{ return T_RSHIFT_OP; }
"<<"				{ return T_LSHIFT_OP; }
"++"				{ return T_INC_OP; }
"--"				{ return T_DEC_OP; }
"->"				{ return T_PTR_OP; }
"&&"				{ return T_AND_OP; }
"||"				{ return T_OR_OP; }
"<="				{ return T_LE_OP; }
">="				{ return T_GE_OP; }
"=="				{ return T_EQ_OP; }
"!="				{ return T_NE_OP; }


";"					{ return T_SEMICOLON; }
","					{ return T_COMMA; }
":"					{ return T_COLON; }
("{"|"<%")	{ return T_L_BRACE; }
("}"|"%>")	{ return T_R_BRACE; }
"("					{ return T_L_PARENTHENSIS; }
")"					{ return T_R_PARENTHENSIS; }
("["|"<:")	{ return T_L_BRACKET; }
("]"|":>")	{ return T_R_BRACKET; }

{BINARY_INTEGER} 	{yylval.number = std::stoi(yytext, nullptr, 2); return T_INT_CONST;}
{OCTAL_INTEGER} 	{yylval.number = std::stoi(yytext, nullptr, 8); return T_INT_CONST;}
{DECIMAL_INTEGER} {yylval.number = std::stoi(yytext, nullptr, 10); return T_INT_CONST;}
{HEXA_INTEGER} 		{yylval.number = std::stoi(yytext, nullptr, 16); return T_INT_CONST;}

{FLOAT_CONSTANT} 	{yylval.number = std::atof(yytext); return T_FLOAT_CONST}

{CHAR_CONSTANT} 	{yylval.text = new std::string(yytext); return T_CHAR_CONST};
{STRING_CONSTANT} {yylval.text = new std::string(yytext); return T_STRING_CONST};


{IDENTIFIER} 			{yyval.text = new std::string(yytext); return T_IDENTIFIER}

{NEW_LINE} 				{line_number++;}

.			{ }

%%

void yyerror (char const *s)
{
   /* if s is unrecognised, print error */
  fprintf (stderr, "Parse error : %s\n", s);
  std::cerr << " Syntax/lex error found at line: " << line_number << std::endl;
  std::cerr << "Last accepted token: " << yytext << std::endl;

  exit(1);
}
