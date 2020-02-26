%option noyywrap

%{


// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

%%

BIN 		[0-1]
OCT 		[0-7]
DEC			[0-9]
LET			[a-zA-Z_]
HEX			[a-fA-F0-9]
EXPO			[Ee][+-]?{D}+

// Float and integer suffixes
FLOATSUFFIX			(f|F|l|L)
INTSUFFIXS			(u|U|l|L)*

BINARY_INTEGER 0[bB]{BIN}*{INTSUFFIX}?
DECIMAL_INTEGER [1-9]{DEC}*{INTSUFFIX}?
OCTAL_INTEGER 0[OCT]*{INTSUFFIX}?
HEXA_INTEGER 0[xX]{HEX}*{INTSUFFIX}?

INTEGER_CONSTANT (BINARY_INTEGER|DECIMAL_INTEGER|OCTAL_INTEGER|HEXA_INTEGER)
FLOAT_CONSTANT ({DEC}+{EXPO}{FLOATSUFFIX}?|{DEC}*"."{DEC}+({EXPO})?{FLOATSUFFIX}?|{DEC}+"."{DEC}*({EXPO})?{FLOATSUFFIX}?)

IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*

NEW_LINE [\n\r]
WHITESPACE [ \t\v]+

SINGLE_LINE_COMMENT ([/][/].*)
MULTIPLE_LINE_COMMENT ([/]\*(.|{NEW_LINE})*\*[/])



%{
#include <stdio.h>
#include "y.tab.h"

void
%}

%%
"/*"			{ comment(); }

"auto"			{ return AUTO; }
"break"			{ return BREAK; }
"case"			{ return CASE; }
"char"			{ return CHAR; }
"const"			{ return CONST; }
"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"double"		{ return DOUBLE; }
"else"			{ return ELSE; }
"enum"			{ return ENUM; }
"extern"		{ return EXTERN; }
"float"			{ return FLOAT; }
"for"			{ return FOR; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"int"			{ return INT; }
"long"			{ return LONG; }
"register"		{ return REGISTER; }
"return"		{ return RETURN; }
"short"			{ return SHORT; }
"signed"		{ return SIGNED; }
"sizeof"		{ return SIZEOF; }
"static"		{ return STATIC; }
"struct"		{ return STRUCT; }
"switch"		{ return SWITCH; }
"typedef"		{ return TYPEDEF; }
"union"			{ return UNION; }
"unsigned"		{ return UNSIGNED; }
"void"			{ return VOID; }
"while"			{ return WHILE; }


"..."			{ return ELLIPSIS; }
">>="			{ return RSHIFT_ASSIGN; }
"<<="			{ return LSHIFT_ASSIGN; }
"+="			{ return ADD_ASSIGN; }
"-="			{ return SUB_ASSIGN; }
"*="			{ return MUL_ASSIGN; }
"/="			{ return DIV_ASSIGN; }
"%="			{ return MOD_ASSIGN; }
"&="			{ return AND_ASSIGN; }
"^="			{ return XOR_ASSIGN; }
"|="			{ return OR_ASSIGN; }
"="			{ return EQ_ASSIGN; }



">>"			{ return RSHIFT_OP; }
"<<"			{ return LSHIFT_OP; }
"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }
"->"			{ return PTR_OP; }
"&&"			{ return AND_OP; }
"||"			{ return OR_OP; }
"<="			{ return LE_OP; }
">="			{ return GE_OP; }
"=="			{ return EQ_OP; }
"!="			{ return NE_OP; }


";"			{ return SEMICOLON; }
("{"|"<%")		{ return L_BRACE; }
("}"|"%>")		{ return R_BRACE; }
","			{ return COMMA; }
":"			{ return COLON; }
"("			{ return L_PARATHENSIS; }
")"			{ return R_PARATHENSIS; }
("["|"<:")		{ return L_BRACKET; }
("]"|":>")		{ return R_BRACKET; }


"."			{ return DOT; }
"&"			{ return AND; }
"!"			{ return NOT; }
"~"			{ return INVERT; }
"-"			{ return MINUS }
"+"			{ return PLUS }
"*"			{ return MULT }
"/"			{ return DIV }
"%"			{ return MOD; }
"<"			{ return LT; }
">"			{ return GT; }
"^"			{ return XOR; }
"|"			{ return OR; }
"?"			{ return QUESTION; }
.			{ }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}
