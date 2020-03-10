%code requires{
  #include "../inc/ast.hpp"
  #include <cassert>

  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

  // extern void yyset_in(FILE* fd);
}

// Represents the value associated with any kind of AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%type <node> external_declaration function_definition declaration_expression_list
declaration_expression_list_node declarator direct_declarator arguments_list
compound_statement statement statement_list expression_statement jump_statement
iteration_statement selection_statement function_argument function_arguments
function_call_parameters_list parameters_list logical_or_arithmetic_expression
conditional_expression logical_or_expression logical_and_expression
inclusive_or_expression exclusive_or_expression and_expression equality_expression
relational_expression expression shift_expression additive_expression
multiplicative_expression unary_expression postfix_expression primary_expression
case_statement_list compound_case_statement default_statement
case_or_default_statement_list case_statement enum_declaration
enum_declaration_list_node function_declaration

%type <string> T_IDENTIFIER type_specifier unary_operator assignment_operator
%type <integer_constant> INTEGER_CONSTANT
%type <float_constant> FLOAT_CONSTANT
%type <char_string_constant> CHARACTER_CONSTANT STRING_CONSTANT

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
%token T_L_PARATHENSIS T_R_PARATHENSIS T_L_BRACKET T_R_BRACKET

//T_IDENTIFIERs and constant expressions
%token T_T_IDENTIFIER T_INT_CONST T_FLOAT_CONST T_CHAR_CONST T_STRING_CONST

%start translation_unit

%%

ROOT
  : FRAME       { g_root = new RootNode($1); }

FRAME
  : FUNCTION_DEFINITION                    { $$ = $1; }
  | FUNCTION_DECLARATION                   { $$ = $1; }
  | VARIABLE_DECLARATION T_COLON           { $$ = $1; }
  | PROGRAM FUNCTION_DEFINITION            { $$ = new Frame($1, $2); }
  | PROGRAM FUNCTION_DECLARATION           { $$ = new Frame($1, $2); }
  | PROGRAM VARIABLE_DECLARATION T_COLON   { $$ = new Frame($1, $2); }
  // | ENUM T_IDENTIFIER T_L_BRACE ENUMERATOR_LIST T_R_BRACE T_SEMICOLON { $$ = $4; }
  ;

// ENUMATOR_LIST
//   : ENUMERATOR T_COMMA ENUMERATOR { $$ = new EnumDeclarationListNode($1, $3); }
//   | ENUMERATOR                    { $$ = new EnumDeclarationListNode($1, nullptr); }
//   ;
//
// ENUMERATOR //need revision
//   : T_IDENTIFIER                                       { $$ = new EnumDeclaration(*$1, nullptr); delete $1; }
//   | T_IDENTIFIER T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION  { $$ = new EnumDeclaration(*$1, $3); delete $1; } //change ltr
//   ;

FUNCTION_DECLARATION //int foo(int i, string j);
  : TYPE_SPECIFIER DECLARATOR ARGUMENTS T_SEMICOLON  { $$ = new FunctionDeclaration(*$1, $2, $3); delete $1; }
  ;

FUNCTION_DEFINITION //int foo(int i, string j) { do this; }
  : TYPE_SPECIFIER DECLARATOR ARGUMENTS COMPOUND_STATEMENT { $$ = new FunctionDefinition(*$1, $2, $3, $4); delete $1; }
  ;

ARGUMENTS_IN_PARANTHESIS //(int i, string j) or ()
  : T_L_PARATHENSIS MULTIPLE_ARGUMENTS T_L_PARATHENSIS  { $$ = $2; }
  | T_L_PARATHENSIS T_R_PARATHENSIS                     { $$ = new Arguments(nullptr, nullptr); }
  ;

MULTIPLE_ARGUMENTS //int i, string j, or more...
  : SINGLE_ARGUMENT T_COMMA MULTIPLE_ARGUMENTS  { $$ = new MultipleArguments($1, $3); }
  | SINGLE_ARGUMENT                             { $$ = new MultipleArguments($1, nullptr); }
  ;

SINGLE_ARGUMENT //int i
  : TYPE_SPECIFIER DECLARATOR         { DeclarationExpressionListNode* node =
                                        new DeclarationExpressionListNode($2, nullptr, nullptr);
                                        $$ = new DeclarationExpressionList(*$1, node);
                                        delete $1; } //check later
  ;

COMPOUND_STATEMENT //scope {do smth;}
  : T_L_BRACE MULTI_STATEMENTS T_R_BRACE { $$ = new CompoundStatement($2); }
  | T_L_BRACE T_R_BRACE                { $$ = new CompoundStatement(nullptr); }
  ;

MULTI_STATEMENTS //each line inside a scope
  : SINGLE_STATEMENT MULTI_STATEMENTS { $$ = new StatementListNode($1, $2); }
  | SINGLE_STATEMENT                { $$ = new StatementListNode($1, nullptr); }
  ;

/* Possible statements. */
SINGLE_STATEMENT
  : COMPOUND_STATEMENT   { $$ = $1; }
  | EXPRESSION_STATEMENT { $$ = $1; }
  | JUMP_STATEMENT       { $$ = $1; }
  | ITERATION_STATEMENT  { $$ = $1; }
  | SELECTION_STATEMENT  { $$ = $1; }
  ;

SELECTION_STATEMENT //if(expr){do smth;} else{do smth else;}  || switch(expr) {case x: do smth; break; case y: do smth; break; ...}
  : T_IF T_L_PARATHENSIS EXPRESSION T_R_PARATHENSIS SINGLE_STATEMENT                          { $$ = new IfStatement($3, $5, nullptr); }
  | T_IF T_L_PARATHENSIS EXPRESSION T_R_PARATHENSIS SINGLE_STATEMENT T_ELSE SINGLE_STATEMENT    { $$ = new IfStatement($3, $5, $7); }
  | T_SWITCH T_L_PARATHENSIS EXPRESSION T_R_PARATHENSIS CASE_STATEMENTS               { $$ = new SwitchStatement($3, $5); }
  ;

CASE_STATEMENTS //{case x: do smth; break; case y: do smth; break; ...}
  : T_L_BRACE MULTIPLE_CASE_DEFAULT T_R_BRACE          { $$ = $2; }
  | T_L_BRACE MULTIPLE_CASE_STATEMENTS T_R_BRACE                { $$ = $2; }
  | T_L_BRACE T_R_BRACE                                         { $$ = new CaseStatementListNode(nullptr, nullptr); }
  ;

MULTIPLE_CASE_DEFAULT //default can happen in any order
  : SINGLE_CASE_STATEMENT MULTIPLE_CASE_DEFAULT  { $$ = new CaseStatementListNode($1, $2); }
  | DEFAULT_STATEMENT MULTIPLE_CASE_STATEMENTS  { $$ = new CaseStatementListNode($1, $2); }
  | DEFAULT_STATEMENT                           { $$ = new CaseStatementListNode($1, nullptr); }
  ;

MULTIPLE_CASE_STATEMENTS //purely case statements (no default)
  : SINGLE_CASE_STATEMENT MULTIPLE_CASE_STATEMENTS { $$ = new CaseStatementListNode($1, $2); }
  | SINGLE_CASE_STATEMENT                          { $$ = new CaseStatementListNode($1, nullptr); }
  ;


SINGLE_CASE_STATEMENT //case x: do smth;
  : T_CASE EXPRESSION T_COLON MULTI_STATEMENTS      { $$ = new SingleCaseStatement($2, $4); }
  | T_CASE EXPRESSION T_COLON                       { $$ = new CaseStatement($2, nullptr); }
  ;

DEFAULT_STATEMENT //default: {do smth;}
  : T_DEFAULT T_COLON MULTIPLE_STATEMENTS           { $$ = new DefaultStatement($3); }
  | T_DEFAULT T_COLON                               { $$ = new DefaultStatement(nullptr); }
  ;

//started here today
ITERATION_STATEMENT // while(){do smth;} || for(expr){do smth;}
  : T_WHILE T_L_PARATHENSIS EXPRESSION T_R_PARATHENSIS SINGLE_STATEMENT                                             { $$ = new WhileStatement($3, $5); }
  | T_FOR T_L_PARATHENSIS EXPRESSION_STATEMENT  EXPRESSION_STATEMENT EXPRESSION T_R_PARATHENSIS SINGLE_STATEMENT  { $$ = new ForStatement($3, $4, $5, $7); }
  | T_FOR T_L_PARATHENSIS EXPRESSION_STATEMENT  EXPRESSION_STATEMENT T_R_PARATHENSIS SINGLE_STATEMENT             { $$ = new ForStatement($3, $4, nullptr, $6); }
  ;

JUMP_STATEMENT //return; || return x; || break; || continue;
  : T_RETURN T_SEMICOLON            { $$ = new JumpStatement("return", NULL); }
  | T_RETURN EXPRESSION T_SEMICOLON { $$ = new JumpStatement("return", $2); }
  | T_BREAK T_SEMICOLON             { $$ = new JumpStatement("break", NULL); }
  | T_CONTINUE T_SEMICOLON          { $$ = new JumpStatement("continue", NULL); }
  ;

EXPRESSION_STATEMENT
  : T_SEMICOLON            { $$ = new EmptyExpression(); }
  | EXPRESSION T_SEMICOLON { $$ = $1; }
  ;

/* Every simple expression. Could be an assignment, a declaration, a function call
 * etc..
 * Only assignment and declaration for now. */
EXPRESSION
  : VARIABLE_ASSIGNMENT       { $$ = $1; }
  | logical_or_arithmetic_expression  { $$ = $1; }
  ;


ASSIGNMENT_OPERATOR
  : T_EQ_ASSIGN    { $$ = new std::string("="); }
  | T_MUL_ASSIGN   { $$ = new std::string("*="); }
  | T_DIV_ASSIGN   { $$ = new std::string("/="); }
  | T_MOD_ASSIGN   { $$ = new std::string("%="); }
  | T_ADD_ASSIGN   { $$ = new std::string("+="); }
  | T_SUB_ASSIGN   { $$ = new std::string("-="); }
  | T_LEFT_ASSIGN  { $$ = new std::string("<<="); }
  | T_RIGHT_ASSIGN { $$ = new std::string(">>="); }
  | T_AND_ASSIGN   { $$ = new std::string("&="); }
  | T_XOR_ASSIGN   { $$ = new std::string("^="); }
  | T_OR_ASSIGN    { $$ = new std::string("|="); }
  ;

/* Declaration expressions are like
 *                  VARIABLE_DECLARATION
 *                  /                   \
 *           TYPE_SPECIFIER             ASSIGNMENT_STATEMENT
 *                                      /          |           \
 *                               Variable      Rhs(nullptr)    Nextnode(nullptr)
 */

VARIABLE_DECLARATION //int a = 2, b = 5
  : TYPE_SPECIFIER ASSIGNMENT_STATEMENT         { $$ = new VariableDeclaration(*$1, $2); delete $1; }
  ;

ASSIGNMENT_STATEMENT //a = 2, b = 5 ;
  : DECLARATOR T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION T_COMMA ASSIGNMENT_STATEMENT  { $$ = new AssignmentStatement($1, $3, $5); }
  | DECLARATOR T_EQ_ASSIGN ASSIGNMENT_STATEMENT                                     { $$ = new AssignmentStatement($1, nullptr, $3); }
  | DECLARATOR T_EQ_ASSIGN MATH_OR_BITWISE_EXPRESSION                               { $$ = new AssignmentStatement($1, $3, nullptr); }
  | DECLARATOR                                                                      { $$ = new AssignmentStatement($1, nullptr, nullptr); }
  ;


MATH_OR_BITWISE_EXPRESSION
  : CONDITIONAL_EXPRESSION  { $$ = $1; }
  | DECLARATOR ASSIGNMENT_OPERATOR MATH_OR_BITWISE_EXPRESSION { $$ = new AssignmentExpression($1, *$2, $3); }
  ;

PRIMARY_EXPRESSION //a || 1 || a+1
  : DECLARATOR                                { $$ = $1; }
  | INTEGER_CONSTANT                          { $$ = new IntegerConstant( $1 ); }
  /*| FLOAT_CONSTANT
  | CHARACTER_CONSTANT
  | STRING_CONSTANT */
  | '(' MATH_OR_BITWISE_EXPRESSION ')'  { $$ = $2; }
  | T_IDENTIFIER function_call_parameters_list  { $$ = new FunctionCall(*$1, $2); delete $1; } //change ltr
  ;

POSTFIX_EXPRESSION // a++
  : PRIMARY_EXPRESSION         { $$ = $1; }
  | POSTFIX_EXPRESSION T_INC_OP  { $$ = new PostfixExpression($1, "++"); }
  | POSTFIX_EXPRESSION T_DEC_OP  { $$ = new PostfixExpression($1, "--"); }
  ;

UNARY_EXPRESSION //++a
  : POSTFIX_EXPRESSION               { $$ = $1; }
  | T_INC_OP UNARY_EXPRESSION          { $$ = new UnaryExpression("++", $2); }
  | T_DEC_OP UNARY_EXPRESSION          { $$ = new UnaryExpression("--", $2); }
  | UNARY_OPERATOR UNARY_EXPRESSION  { $$ = new UnaryExpression(*$1, $2); delete $1; }
  ;

UNARY_OPERATOR
  : T_AND_OP  { $$ = new std::string("&"); }
  | T_PLUS  { $$ = new std::string("+"); }
  | T_MINUS  { $$ = new std::string("-"); }
  | T_XOR  { $$ = new std::string("~"); }
  | T_NOT  { $$ = new std::string("!"); }
  ;

MULTIPLICATIVE_EXPRESSION //a * b || a / b || a % b
  : UNARY_EXPRESSION                                { $$ = $1; }
  | MULTIPLICATIVE_EXPRESSION T_MULT UNARY_EXPRESSION  { $$ = new MultiplicativeExpression($1, "*", $3); }
  | MULTIPLICATIVE_EXPRESSION T_DIV UNARY_EXPRESSION  { $$ = new MultiplicativeExpression($1, "/", $3); }
  | MULTIPLICATIVE_EXPRESSION T_MOD UNARY_EXPRESSION  { $$ = new MultiplicativeExpression($1, "%", $3); }
  ;

ADDITIVE_EXPRESSION //a + b || a - b
  : MULTIPLICATIVE_EXPRESSION                          { $$ = $1; }
  | ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION  { $$ = new AdditiveExpression($1, "+", $3); }
  | ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION  { $$ = new AdditiveExpression($1, "-", $3); }
  ;

SHIFT_EXPRESSION //a < 5 || b > 5
  : ADDITIVE_EXPRESSION                            { $$ = $1; }
  | SHIFT_EXPRESSION T_LSHIFT_OP ADDITIVE_EXPRESSION   { $$ = new ShiftExpression($1, "<<", $3); }
  | SHIFT_EXPRESSION T_RSHIFT_OP ADDITIVE_EXPRESSION  { $$ = new ShiftExpression($1, ">>", $3); }
  ;

RELATIONAL_EXPRESSION
  : SHIFT_EXPRESSION                              { $$ = $1; }
  | RELATIONAL_EXPRESSION T_LT SHIFT_EXPRESSION    { $$ = new RelationalExpression($1, "<", $3); }
  | RELATIONAL_EXPRESSION T_GT SHIFT_EXPRESSION    { $$ = new RelationalExpression($1, ">", $3); }
  | RELATIONAL_EXPRESSION T_LE_OP SHIFT_EXPRESSION  { $$ = new RelationalExpression($1, "<=", $3); }
  | RELATIONAL_EXPRESSION T_GE_OP SHIFT_EXPRESSION  { $$ = new RelationalExpression($1, ">=", $3); }
  ;

EQUALITY_EXPRESSION
  : RELATIONAL_EXPRESSION                            { $$ = $1; }
  | EQUALITY_EXPRESSION T_EQ_OP RELATIONAL_EXPRESSION  { $$ = new EqualityExpression($1, "==", $3); }
  | EQUALITY_EXPRESSION T_NE_OP RELATIONAL_EXPRESSION  { $$ = new EqualityExpression($1, "!=", $3); }
  ;

BITWISE_AND_EXPRESSION
  : EQUALITY_EXPRESSION                     { $$ = $1; }
  | BITWISE_AND_EXPRESSION T_AND EQUALITY_EXPRESSION  { $$ = new AndExpression($1, $3); }
  ;

BITWISE_XOR_EXPRESSION
  : BITWISE_AND_EXPRESSION                              { $$ = $1; }
  | BITWISE_XOR_EXPRESSION T_XOR BITWISE_AND_EXPRESSION  { $$ = new ExclusiveOrExpression($1, $3); }
  ;

BITWISE_OR_EXPRESSION
  : BITWISE_XOR_EXPRESSION                              { $$ = $1; }
  | BITWISE_OR_EXPRESSION T_OR_OP BITWISE_OR_EXPRESSION  { $$ = new InclusiveOrExpression($1, $3); }
  ;

BOOLEAN_AND_EXPRESSION
  : BITWISE_OR_EXPRESSION                                { $$ = $1; }
  | BOOLEAN_AND_EXPRESSION T_AND_OP BITWISE_OR_EXPRESSION  { $$ = new LogicalAndExpression($1, $3); }
  ;

BOOLEAN_OR_EXPRESSION
  : BOOLEAN_AND_EXPRESSION                              { $$ = $1; }
  | BOOLEAN_OR_EXPRESSION T_OR_OP BOOLEAN_AND_EXPRESSION  { $$ = new LogicalOrExpression($1, $3); }
  ;

CONDITIONAL_EXPRESSION
  : BOOLEAN_OR_EXPRESSION                                            { $$ = $1; }
  | BOOLEAN_OR_EXPRESSION T_QUESTION EXPRESSION T_COLON CONDITIONAL_EXPRESSION  { $$ = new ConditionalExpression($1, $3, $5); }
	;

/* ============== END Arithmetic and logical expressions ordering */

function_call_parameters_list // (int i = 5, double j)
  : '(' parameters_list ')'  { $$ = $2; }
	| '(' ')'                  { $$ = new ParametersListNode(nullptr, nullptr); }
  ;

parameters_list //int i = 5, double j
  : MATH_OR_BITWISE_EXPRESSION ',' parameters_list { $$ = new ParametersListNode($1, $3); }
  | MATH_OR_BITWISE_EXPRESSION                     { $$ = new ParametersListNode($1, nullptr); }
  ;

DECLARATOR //a || *a || a[1]
  : T_IDENTIFIER                                                     { $$ = new Variable(*$1, "normal", nullptr); delete $1; }
  | '*' T_IDENTIFIER                                                 { $$ = new Variable(*$2, "pointer", nullptr); delete $2; }
  | T_IDENTIFIER T_L_BRACKET MATH_OR_BITWISE_EXPRESSION T_L_BRACKET  { $$ = new Variable(*$1, "array", $3 ); delete $1; }
  ;


TYPE_SPECIFIER
  : T_VOID     { $$ = new std::string("void"); }
	| T_CHAR     { $$ = new std::string("char"); }
	| T_SHORT    { $$ = new std::string("short"); }
	| T_INT      { $$ = new std::string("int"); }
	| T_LONG     { $$ = new std::string("long"); }
	| T_FLOAT    { $$ = new std::string("float"); }
	| T_DOUBLE   { $$ = new std::string("double"); }
	| T_SIGNED   { $$ = new std::string("signed int"); }
	| T_UNSIGNED { $$ = new std::string("unsigned int"); }
  ;

%%

// Definition of variable (to match declaration earlier).
const Node *g_root;
const Node *parseAST() {
  yyparse();
  return g_root;
}
