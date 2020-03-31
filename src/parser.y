%code requires{
  #include "../include/ast.hpp"
  #include <cassert>
  #include <stdio.h>

  extern const Node *g_root;


  int yylex(void);
  void yyerror(const char *);

}


%union{
  const Node *node;
  double float_constant;
  long long int integer_constant;
  std::string *string;
}
%type <node> ROOT FRAME FUNCTION_DEFINITION FUNCTION_DECLARATION WRAPPED_ARGUMENTS DECLARATOR TYPE_SPECIFIER
SCOPE JUMP_STATEMENT MULTIPLE_STATEMENTS SINGLE_STATEMENT PRIMARY_EXPRESSION EXPRESSION VARIABLE_DECLARATION
ASSIGNMENT_STATEMENT T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION POSTFIX_EXPRESSION UNARY_EXPRESSION MULTIPLICATIVE_EXPRESSION
ADDITIVE_EXPRESSION SHIFT_EXPRESSION RELATIONAL_EXPRESSION EQUALITY_EXPRESSION BITWISE_AND_EXPRESSION BITWISE_XOR_EXPRESSION
BITWISE_OR_EXPRESSION BOOLEAN_AND_EXPRESSION BOOLEAN_OR_EXPRESSION CONDITIONAL_EXPRESSION EXPRESSION_STATEMENT
ITERATION_STATEMENT SELECTION_STATEMENT MULTIPLE_ARGUMENTS SINGLE_ARGUMENT WRAPPED_PARAMETERS MULTIPLE_PARAMETERS
ASSIGNMENT_OPERATOR UNARY_OPERATOR WRAPPED_CASE_STATEMENTS MULTIPLE_CASE_STATEMENTS ENUMERATION
SINGLE_CASE_STATEMENT MULTIPLE_ENUMERATORS SINGLE_ENUMERATOR TYPE_DEF STRUCT_DEFINITION MULTIPLE_ATTRIBUTES SINGLE_ATTRIBUTE
STRUCT_DECLARATION STRUCT_ATTRIBUTE


%type <string> T_IDENTIFIER
%type <integer_constant> T_INT_CONST
%type <float_constant> T_FLOAT_CONST
%type <string> T_STRING_CONST T_CHAR_CONST

//general
%token T_AUTO T_BREAK T_CASE T_CHAR T_CONST T_CONTINUE T_DEFAULT T_DO T_DOUBLE
%token T_ELSE T_ENUM T_EXTERN T_FLOAT T_FOR T_GOTO T_IF T_INT T_LONG T_REGISTER
%token T_RETURN T_SHORT T_SIGNED T_SIZEOF T_STATIC T_STRUCT T_SWITCH T_TYPEDEF
%token T_UNION T_UNSIGNED T_VOID T_WHILE

//arithmetic and boolean operators
%token T_AND T_NOT T_INVERT T_MINUS T_PLUS T_MULT T_DIV T_MOD
%token T_LT T_GT T_XOR T_OR T_QUESTION T_DOT T_ELLIPSIS

//assignment operators
%token T_RSHIFT_ASSIGN T_LSHIFT_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN
%token T_DIV_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN T_EQ_ASSIGN

//logical operators
%token T_RSHIFT_OP T_LSHIFT_OP T_INC_OP T_DEC_OP T_PTR_OP T_AND_OP T_OR_OP
%token T_LE_OP T_GE_OP T_EQ_OP T_NE_OP

//miscelleneous
%token T_SEMICOLON T_COMMA T_COLON T_L_BRACE T_R_BRACE
%token T_L_PARENTHESIS T_R_PARENTHESIS T_L_BRACKET T_R_BRACKET

//T_IDENTIFIERs and constant expressions
%token T_IDENTIFIER T_INT_CONST T_FLOAT_CONST T_CHAR_CONST T_STRING_CONST T_BOOL

%start ROOT

%%

ROOT
  : FRAME       { g_root = new RootNode($1); }

FRAME
  : SCOPE                                   { $$ = $1; }
  | ENUMERATION                             { $$ = $1; }
  | FUNCTION_DEFINITION                     { $$ = $1; }
  | FUNCTION_DECLARATION                    { $$ = $1; }
  | TYPE_DEF 								{ $$ = $1; }
  | STRUCT_DEFINITION                       { $$ = $1; }
  | VARIABLE_DECLARATION T_SEMICOLON        { $$ = $1; }
  | STRUCT_DEFINITION FRAME                 { $$ = new Frame($1, $2); }
  | VARIABLE_DECLARATION T_SEMICOLON FRAME  { $$ = new Frame($1, $3); }
  | SCOPE FRAME                             { $$ = new Frame($1, $2); }
  | FUNCTION_DEFINITION FRAME               { $$ = new Frame($1, $2); }
  | FUNCTION_DECLARATION FRAME              { $$ = new Frame($1, $2); }
  | ENUMERATION FRAME                       { $$ = new Frame($1, $2); }
  | TYPE_DEF FRAME							{ $$ = new Frame($1, $2); }
  ;

FUNCTION_DECLARATION //int foo(int i, string j);
  : TYPE_SPECIFIER DECLARATOR WRAPPED_ARGUMENTS T_SEMICOLON  	{ $$ = new FunctionDeclaration($1, $2, $3);; }


FUNCTION_DEFINITION //int foo(int i, string j) { do this; }
  : TYPE_SPECIFIER DECLARATOR WRAPPED_ARGUMENTS SCOPE 			{ $$ = new FunctionDefinition($1, $2, $3, $4); }



WRAPPED_ARGUMENTS //(int i, string j) or ()
  : T_L_PARENTHESIS MULTIPLE_ARGUMENTS T_R_PARENTHESIS  		{ $$ = new ParenthesisWrapper($2); }
  | T_L_PARENTHESIS T_R_PARENTHESIS                     		{ $$ = new ParenthesisWrapper(NULL); }
  ;

MULTIPLE_ARGUMENTS //int i, string j, or more...
  : SINGLE_ARGUMENT T_COMMA MULTIPLE_ARGUMENTS  				{ $$ = new MultipleArguments($1, $3); }
  | SINGLE_ARGUMENT                             				{ $$ = new MultipleArguments($1, NULL); }
  ;

SINGLE_ARGUMENT //int i
  : TYPE_SPECIFIER DECLARATOR   								{ $$ = new VariableDeclaration($1, $2); }

WRAPPED_PARAMETERS // (int i = 5, double j)
: T_L_PARENTHESIS MULTIPLE_PARAMETERS T_R_PARENTHESIS  			{ $$ = new ParenthesisWrapper($2); }
| T_L_PARENTHESIS T_R_PARENTHESIS                 				{ $$ = new ParenthesisWrapper(NULL); }
;

MULTIPLE_PARAMETERS //int i = 5, double j
  : MATH_OR_BITWISE_EXPRESSION T_COMMA MULTIPLE_PARAMETERS 		{ $$ = new MultipleParameters($1, $3); }
  | MATH_OR_BITWISE_EXPRESSION                        			{ $$ = new MultipleParameters($1, NULL); }
  ;

SCOPE //scope {do smth;}
  : T_L_BRACE MULTIPLE_STATEMENTS T_R_BRACE					 	{ $$ = new Scope($2); }
  | T_L_BRACE T_R_BRACE                							{ $$ = new Scope(NULL); }
  ;

MULTIPLE_STATEMENTS //multiple lines inside a scope
  : SINGLE_STATEMENT MULTIPLE_STATEMENTS 						{ $$ = new MultipleStatements($1, $2); }
  | SINGLE_STATEMENT                							{ $$ = new MultipleStatements($1, NULL); }
  ;

SINGLE_STATEMENT//each line inside a scope
  : SCOPE                 { $$ = $1; }
  | EXPRESSION_STATEMENT  { $$ = $1; }
  | JUMP_STATEMENT        { $$ = $1; }
  | ITERATION_STATEMENT   { $$ = $1; }
  | SELECTION_STATEMENT   { $$ = $1; }
  | ENUMERATION           { $$ = $1; }
  | TYPE_DEF			  { $$ = $1; }
  | STRUCT_DEFINITION     { $$ = $1; }
  | STRUCT_DECLARATION    { $$ = $1; }
  ;


ENUMERATION
  : T_ENUM T_IDENTIFIER T_L_BRACE MULTIPLE_ENUMERATORS T_R_BRACE T_SEMICOLON 							{ $$ = new Enumeration(*$2, NULL, $4); delete $2; }
  | T_ENUM T_IDENTIFIER T_COLON TYPE_SPECIFIER T_L_BRACE MULTIPLE_ENUMERATORS T_R_BRACE T_SEMICOLON 	{ $$ = new Enumeration(*$2, $4, $6); delete $2; }
  ;

MULTIPLE_ENUMERATORS
  : SINGLE_ENUMERATOR T_COMMA MULTIPLE_ENUMERATORS 		{ $$ = new MultipleEnumerators($1, $3); }
  | SINGLE_ENUMERATOR                    				{ $$ = new MultipleEnumerators($1, NULL); }
  ;

SINGLE_ENUMERATOR
  : T_IDENTIFIER                                       	 { $$ = new SingleEnumerator(*$1, NULL); delete $1; }
  | T_IDENTIFIER T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION  { $$ = new SingleEnumerator(*$1, $3); delete $1; }
  ;

SELECTION_STATEMENT //if(expr){do smth;} else{do smth else;}  || switch(expr) {case x: do smth; break; case y: do smth; break; ...}
  : T_IF T_L_PARENTHESIS EXPRESSION T_R_PARENTHESIS SINGLE_STATEMENT                              	{ $$ = new IfStatement($3, $5, NULL); }
  | T_IF T_L_PARENTHESIS EXPRESSION T_R_PARENTHESIS SINGLE_STATEMENT SELECTION_STATEMENT   			{ $$ = new IfStatement($3, $5, $6); }
  | T_ELSE SINGLE_STATEMENT                                                                         { $$ = $2; }
  | T_SWITCH T_L_PARENTHESIS EXPRESSION T_R_PARENTHESIS WRAPPED_CASE_STATEMENTS               		{ $$ = new SwitchStatement($3, $5); }
  | T_SWITCH T_L_PARENTHESIS EXPRESSION T_R_PARENTHESIS SINGLE_STATEMENT               				{ $$ = new SwitchStatement($3, $5); }
  ;

WRAPPED_CASE_STATEMENTS //{case x: do smth; break; case y: do smth; break; ...}
  : T_L_BRACE MULTIPLE_CASE_STATEMENTS T_R_BRACE       { $$ = $2; }



MULTIPLE_CASE_STATEMENTS //purely case statements (no default)
  : SINGLE_CASE_STATEMENT MULTIPLE_CASE_STATEMENTS 		{ $$ = new MultipleCaseStatements($1, $2); }
  | SINGLE_CASE_STATEMENT 							 	{ $$ = new MultipleCaseStatements($1, NULL); }
  ;


SINGLE_CASE_STATEMENT //case x: do smth;
  : T_CASE EXPRESSION T_COLON MULTIPLE_STATEMENTS   	{ $$ = new SingleCaseStatement($2, $4); }
  | T_CASE EXPRESSION T_COLON    						{ $$ = new SingleCaseStatement($2, NULL); }
  | T_DEFAULT T_COLON MULTIPLE_STATEMENTS               { $$ = new DefaultStatement($3); }
  | T_DEFAULT T_COLON                    				{ $$ = new DefaultStatement(NULL); }
  | SINGLE_STATEMENT                                    { $$ = $1; }
  ;


ITERATION_STATEMENT // while(){do smth;} || for(expr){do smth;}
	: T_WHILE T_L_PARENTHESIS EXPRESSION T_R_PARENTHESIS SINGLE_STATEMENT                                           { $$ = new WhileLoop($3, $5, 0); }
 	| T_DO SINGLE_STATEMENT T_WHILE T_L_PARENTHESIS EXPRESSION T_R_PARENTHESIS T_SEMICOLON                          { $$ = new WhileLoop($5, $2, 1); }
	| T_FOR T_L_PARENTHESIS EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION T_R_PARENTHESIS SINGLE_STATEMENT  	{ $$ = new ForLoop($3, $4, $5, $7); }
	| T_FOR T_L_PARENTHESIS EXPRESSION_STATEMENT EXPRESSION_STATEMENT T_R_PARENTHESIS SINGLE_STATEMENT  			{ $$ = new ForLoop($3, $4, NULL, $6); }
  ;

JUMP_STATEMENT //return; || return x; || break; || continue;
  : T_RETURN T_SEMICOLON            { $$ = new JumpStatement("RETURN", NULL); }
  | T_RETURN EXPRESSION T_SEMICOLON { $$ = new JumpStatement("RETURN", $2); }
  | T_BREAK T_SEMICOLON             { $$ = new JumpStatement("BREAK", NULL); }
  | T_CONTINUE T_SEMICOLON          { $$ = new JumpStatement("CONTINUE", NULL); }
  ;

EXPRESSION_STATEMENT
  : T_SEMICOLON            { $$ = NULL; }
  | EXPRESSION T_SEMICOLON { $$ = $1; }
  ;


EXPRESSION
  : VARIABLE_DECLARATION       	{ $$ = $1; }
  | ASSIGNMENT_STATEMENT        { $$ = $1; }
  | MATH_OR_BITWISE_EXPRESSION  { $$ = $1; }
  ;


ASSIGNMENT_OPERATOR
  : T_MUL_ASSIGN        { $$ = new AssignmentOperator("*="); }
  | T_DIV_ASSIGN        { $$ = new AssignmentOperator("/="); }
  | T_MOD_ASSIGN        { $$ = new AssignmentOperator("%="); }
  | T_ADD_ASSIGN        { $$ = new AssignmentOperator("+="); }
  | T_SUB_ASSIGN        { $$ = new AssignmentOperator("-="); }
  | T_LSHIFT_ASSIGN     { $$ = new AssignmentOperator("<<="); }
  | T_RSHIFT_ASSIGN     { $$ = new AssignmentOperator(">>="); }
  | T_AND_ASSIGN        { $$ = new AssignmentOperator("&="); }
  | T_XOR_ASSIGN        { $$ = new AssignmentOperator("^="); }
  | T_OR_ASSIGN         { $$ = new AssignmentOperator("|="); }
  ;

DECLARATOR //a || *a || a[1]
  : STRUCT_ATTRIBUTE                                                 { $$ = $1; }
  | T_IDENTIFIER                                                     { $$ = new Variable(*$1, "NORMAL", NULL); delete $1; }
  | T_MULT T_IDENTIFIER                                              { $$ = new Variable(*$2, "POINTER", NULL); delete $2; }
  | T_IDENTIFIER T_L_BRACKET MATH_OR_BITWISE_EXPRESSION T_R_BRACKET  { $$ = new Variable(*$1, "ARRAY", $3 ); delete $1; }
  ;

VARIABLE_DECLARATION //int a = 2, b = 5
  : TYPE_SPECIFIER ASSIGNMENT_STATEMENT         					 { $$ = new VariableDeclaration($1, $2); }


TYPE_DEF
	: T_TYPEDEF TYPE_SPECIFIER T_IDENTIFIER	T_SEMICOLON			{ $$ = new TypeDef(*$3, $2); delete $3;}

TYPE_SPECIFIER
  	: T_VOID   		{ $$ = new TypeSpecifier("VOID"); }
	| T_CHAR     	{ $$ = new TypeSpecifier("CHAR"); }
	| T_SHORT   	{ $$ = new TypeSpecifier("SHORT"); }
	| T_INT     	{ $$ = new TypeSpecifier("INT"); }
	| T_LONG     	{ $$ = new TypeSpecifier("LONG"); }
	| T_FLOAT    	{ $$ = new TypeSpecifier("FLOAT"); }
	| T_DOUBLE   	{ $$ = new TypeSpecifier("DOUBLE"); }
	| T_SIGNED   	{ $$ = new TypeSpecifier("SIGNED"); }
	| T_UNSIGNED 	{ $$ = new TypeSpecifier("UNSIGNED"); }
	| T_BOOL 		{ $$ = new TypeSpecifier("BOOL"); }
	| T_IDENTIFIER 	{ $$ = new CustomType(*$1); delete $1;}
  ;

STRUCT_DEFINITION
  	: T_STRUCT T_IDENTIFIER T_L_BRACE MULTIPLE_ATTRIBUTES T_R_BRACE T_SEMICOLON 	{ $$ = new StructDefinition(*$2, $4);}

STRUCT_DECLARATION
  	: T_STRUCT TYPE_SPECIFIER T_IDENTIFIER T_SEMICOLON 								{ $$ = new StructDeclaration($2, *$3);}

STRUCT_ATTRIBUTE
    : T_IDENTIFIER T_DOT T_IDENTIFIER 												{ $$ = new StructAttribute(*$1, *$3); delete $1;delete $3; }

MULTIPLE_ATTRIBUTES
	: SINGLE_ATTRIBUTE MULTIPLE_ATTRIBUTES											{ $$ = new MultipleAttributes($1, $2); }
	| SINGLE_ATTRIBUTE																{ $$ = new MultipleAttributes($1, NULL); }
  ;

SINGLE_ATTRIBUTE
	: TYPE_SPECIFIER T_IDENTIFIER T_SEMICOLON										{ $$ = new SingleAttribute($1, *$2);}


ASSIGNMENT_STATEMENT //a = 2, b = 5 || a = b || a = b = c = 9 || a
  : DECLARATOR T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION T_COMMA ASSIGNMENT_STATEMENT  { $$ = new AssignmentStatement($1, $3, $5); }
  | DECLARATOR T_EQ_ASSIGN ASSIGNMENT_STATEMENT                                     { $$ = new AssignmentStatement($1, NULL, $3); }
  | DECLARATOR T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION                               { $$ = new AssignmentStatement($1, $3, NULL); }
  | DECLARATOR                                                                      { $$ = new AssignmentStatement($1, NULL, NULL); }
  ;

MATH_OR_BITWISE_EXPRESSION
  : CONDITIONAL_EXPRESSION  { $$ = $1; }
  | DECLARATOR ASSIGNMENT_OPERATOR MATH_OR_BITWISE_EXPRESSION 						{ $$ = new AssignmentExpression($1, $2, $3); }
  ;

PRIMARY_EXPRESSION //a || 1 || a+1
  : DECLARATOR                         							       		{ $$ = $1; }
  | T_INT_CONST                        									  	{ $$ = new IntegerConstant( $1 ); }
  | T_FLOAT_CONST                         									{ $$ = new FloatConstant( $1 ); }
  | T_CHAR_CONST                        									{ $$ = new CharConstant( *$1 ); }
  | T_STRING_CONST                       									{ $$ = new StringLiteral(*$1); }
  | T_L_PARENTHESIS MATH_OR_BITWISE_EXPRESSION T_R_PARENTHESIS  			{ $$ = new ParenthesisWrapper($2); }
  | DECLARATOR WRAPPED_PARAMETERS  											{ $$ = new FunctionCall($1, $2); }
  | T_SIZEOF T_L_PARENTHESIS TYPE_SPECIFIER T_R_PARENTHESIS 				{ $$ = new SizeOf($3); }
  | T_SIZEOF T_L_PARENTHESIS DECLARATOR T_R_PARENTHESIS 					{ $$ = new SizeOf($3); }
  ;

POSTFIX_EXPRESSION // a++
  : PRIMARY_EXPRESSION         			{ $$ = $1; }
  | POSTFIX_EXPRESSION T_INC_OP  		{ $$ = new PostfixExpression($1, "++"); }
  | POSTFIX_EXPRESSION T_DEC_OP  		{ $$ = new PostfixExpression($1, "--"); }
  ;

UNARY_EXPRESSION //++a
  : POSTFIX_EXPRESSION               	{ $$ = $1; }
  | UNARY_OPERATOR UNARY_EXPRESSION  	{ $$ = new UnaryExpression($1, $2); }
  ;

UNARY_OPERATOR
  : T_INC_OP    { $$ = new UnaryOperator("++"); }
  | T_DEC_OP    { $$ = new UnaryOperator("--"); }
  | T_AND    	{ $$ = new UnaryOperator("&"); }
  | T_PLUS      { $$ = new UnaryOperator("+"); }
  | T_MINUS     { $$ = new UnaryOperator("-"); }
  | T_INVERT    { $$ = new UnaryOperator("~"); }
  | T_NOT       { $$ = new UnaryOperator("!"); }
  ;

MULTIPLICATIVE_EXPRESSION //a * b || a / b || a % b
  : UNARY_EXPRESSION                                	{ $$ = $1; }
  | MULTIPLICATIVE_EXPRESSION T_MULT UNARY_EXPRESSION  	{ $$ = new MultiplicativeExpression($1, "*", $3); }
  | MULTIPLICATIVE_EXPRESSION T_DIV UNARY_EXPRESSION  	{ $$ = new MultiplicativeExpression($1, "/", $3); }
  | MULTIPLICATIVE_EXPRESSION T_MOD UNARY_EXPRESSION  	{ $$ = new MultiplicativeExpression($1, "%", $3); }
  ;

ADDITIVE_EXPRESSION //a + b || a - b
  : MULTIPLICATIVE_EXPRESSION                          		{ $$ = $1; }
  | ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION  	{ $$ = new AdditiveExpression($1, "+", $3); }
  | ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION  	{ $$ = new AdditiveExpression($1, "-", $3); }
  ;

SHIFT_EXPRESSION //a << 5 || b >> 5
  : ADDITIVE_EXPRESSION                            		{ $$ = $1; }
  | SHIFT_EXPRESSION T_LSHIFT_OP ADDITIVE_EXPRESSION   	{ $$ = new ShiftExpression($1, "<<", $3); }
  | SHIFT_EXPRESSION T_RSHIFT_OP ADDITIVE_EXPRESSION  	{ $$ = new ShiftExpression($1, ">>", $3); }
  ;
//i < 5
RELATIONAL_EXPRESSION
  : SHIFT_EXPRESSION                              	{ $$ = $1; }
  | RELATIONAL_EXPRESSION T_LT SHIFT_EXPRESSION    	{ $$ = new RelationalExpression($1, "<", $3); }
  | RELATIONAL_EXPRESSION T_GT SHIFT_EXPRESSION    	{ $$ = new RelationalExpression($1, ">", $3); }
  | RELATIONAL_EXPRESSION T_LE_OP SHIFT_EXPRESSION  { $$ = new RelationalExpression($1, "<=", $3); }
  | RELATIONAL_EXPRESSION T_GE_OP SHIFT_EXPRESSION  { $$ = new RelationalExpression($1, ">=", $3); }
  ;

EQUALITY_EXPRESSION
  : RELATIONAL_EXPRESSION                            	{ $$ = $1; }
  | EQUALITY_EXPRESSION T_EQ_OP RELATIONAL_EXPRESSION  	{ $$ = new EqualityExpression($1, "==", $3); }
  | EQUALITY_EXPRESSION T_NE_OP RELATIONAL_EXPRESSION  	{ $$ = new EqualityExpression($1, "!=", $3); }
  ;

BITWISE_AND_EXPRESSION
  : EQUALITY_EXPRESSION                     			{ $$ = $1; }
  | BITWISE_AND_EXPRESSION T_AND EQUALITY_EXPRESSION  	{ $$ = new BitwiseANDExpression($1, $3); }
  ;

BITWISE_XOR_EXPRESSION
  : BITWISE_AND_EXPRESSION                              	{ $$ = $1; }
  | BITWISE_XOR_EXPRESSION T_XOR BITWISE_AND_EXPRESSION  	{ $$ = new BitwiseXORExpression($1, $3); }
  ;

BITWISE_OR_EXPRESSION
  : BITWISE_XOR_EXPRESSION                              { $$ = $1; }
  | BITWISE_OR_EXPRESSION T_OR BITWISE_OR_EXPRESSION  	{ $$ = new BitwiseORExpression($1, $3); }
  ;

BOOLEAN_AND_EXPRESSION
  : BITWISE_OR_EXPRESSION                                	{ $$ = $1; }
  | BOOLEAN_AND_EXPRESSION T_AND_OP BITWISE_OR_EXPRESSION  	{ $$ = new BooleanExpression($1, "and", $3); }
  ;

BOOLEAN_OR_EXPRESSION
  : BOOLEAN_AND_EXPRESSION                              	{ $$ = $1; }
  | BOOLEAN_OR_EXPRESSION T_OR_OP BOOLEAN_AND_EXPRESSION  	{ $$ = new BooleanExpression($1, "or", $3); }
  ;

CONDITIONAL_EXPRESSION
  : BOOLEAN_OR_EXPRESSION                                   { $$ = $1; }



%%

const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
