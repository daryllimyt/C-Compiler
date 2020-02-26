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
INTSUFFIX			(u|U|l|L)*

ESC    [abfnrtv\'\"\?\\]

BINARY_INTEGER 0[bB]{BIN}*{INTSUFFIX}?
DECIMAL_INTEGER [1-9]{DEC}*{INTSUFFIX}?
OCTAL_INTEGER 0[OCT]*{INTSUFFIX}?
HEXA_INTEGER 0[xX]{HEX}*{INTSUFFIX}?

// INTEGER_CONSTANT (BINARY_INTEGER|DECIMAL_INTEGER|OCTAL_INTEGER|HEXA_INTEGER)
FLOAT_CONSTANT ({DEC}+{EXPO}{FLOATSUFFIX}?|{DEC}*"."{DEC}+({EXPO})?{FLOATSUFFIX}?|{DEC}+"."{DEC}*({EXPO})?{FLOATSUFFIX}?)

CHAR_CONSTANT  [L]?\'(?:\\({ESC}|{O}{1,3}|x{HEX}+)|[^\\'])+\'
STRING_CONSTANT [L]?\"(?:\\({ESC}|{OCT}{1,3}|x[{DEC}|{LET}]+)|[^\\"])*\"


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
"."			{ return DOT; }
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
","			{ return COMMA; }
":"			{ return COLON; }
("{"|"<%")		{ return L_BRACE; }
("}"|"%>")		{ return R_BRACE; }
"("			{ return L_PARATHENSIS; }
")"			{ return R_PARATHENSIS; }
("["|"<:")		{ return L_BRACKET; }
("]"|":>")		{ return R_BRACKET; }

BINARY_INTEGER {yylval.number = std::stoi(yytext, nullptr, 2); return INT_CONST;}
OCTAL_INTEGER {yylval.number = std::stoi(yytext, nullptr, 8); return INT_CONST;}
DECIMAL_INTEGER {yylval.number = std::stoi(yytext, nullptr, 10); return INT_CONST;}
HEXA_INTEGER {yylval.number = std::stoi(yytext, nullptr, 16); return INT_CONST;}

FLOAT_CONSTANT {yylval.number = std::atof(yytext); return FLOAT_CONST}

CHAR_CONSTANT {yylval.text = new std::string(yytext); return CHAR_CONSTANT};
STRING_CONSTANT {yylval.text = new std::string(yytext); return STRING_CONSTANT};


IDENTIFIER {yyval.text = new std::string(yytext); return IDENTIFIER}

NEW_LINE {line_number++;}

.			{ }

%%

yywrap()
{
	return(1);
}
