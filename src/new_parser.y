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
  : PROGRAM       { g_root = new RootNode($1); }
  | ROOT PROGRAM  { g_root = new RootNode($2); }
  ;

PROGRAM
  : FUNCTION_DEFINITION                                               { $$ = $1; }
  | FUNCTION_DECLARATION                                              { $$ = $1; }
  | DECLARATION_EXPRESSION_LIST T_COLON                               { $$ = $1; }
  | ENUM T_IDENTIFIER T_L_BRACE ENUMERATOR_LIST T_R_BRACE T_SEMICOLON { $$ = $4; }
  ;

ENUMATOR_LIST
  : ENUMERATOR T_COMMA ENUMERATOR { $$ = new EnumDeclarationListNode($1, $3); }
  | ENUMERATOR                    { $$ = new EnumDeclarationListNode($1, nullptr); }
  ;

ENUMERATOR //need revision
  : T_IDENTIFIER                                       { $$ = new EnumDeclaration(*$1, nullptr); delete $1; }
  | T_IDENTIFIER T_EQ_ASSIGN logical_or_arithmetic_expression  { $$ = new EnumDeclaration(*$1, $3); delete $1; } //change ltr
  ;

FUNCTION_DECLARATION //int foo(int i, string j);
  : TYPE_SPECIFIER DECLARATOR ARGUMENTS ';'  { $$ = new FunctionDeclaration(*$1, $2, $3); delete $1; }
  ;

FUNCTION_DEFINITION //int foo(int i, string j) { do this; }
  : TYPE_SPECIFIER DECLARATOR ARGUMENTS COMPOUND_STATEMENT { $$ = new FunctionDefinition(*$1, $2, $3, $4); delete $1; }
  ;

ARGUMENTS //(int i, string j) or ()
  : T_L_PARATHENSIS MULTIPLE_ARGUMENTS T_L_PARATHENSIS      { $$ = $2; }
  | T_L_PARATHENSIS T_R_PARATHENSIS                     { $$ = new ArgumentNode(nullptr, nullptr); }
  ;

MULTIPLE_ARGUMENTS //int i, string j, or more...
  : SINGLE_ARGUMENT T_COMMA MULTIPLE_ARGUMENTS { $$ = new ArgumentListNode($1, $3); }
  | SINGLE_ARGUMENT                        { $$ = new ArgumentListNode($1, nullptr); }
  ;

SINGLE_ARGUMENT //int i
  : TYPE_SPECIFIER DECLARATOR         { DeclarationExpressionListNode* node =
                                        new DeclarationExpressionListNode($2, nullptr, nullptr);
                                        $$ = new DeclarationExpressionList(*$1, node);
                                        delete $1; } //check later
  ;

COMPOUND_STATEMENT //scope {do smth;}
  : T_L_BRACE STATEMENT_LIST T_R_BRACE { $$ = new CompoundStatement($2); }
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
 *                  VARIABLE_ASSIGNMENT
 *                  /                   \
 *           TYPE_SPECIFIER             DECLARATIVE_EXPRESSION
 *                                      /          |           \
 *                               Variable      Rhs(nullptr)    Nextnode(nullptr)
 */

VARIABLE_ASSIGNMENT //int a = 2, b = 5
  : TYPE_SPECIFIER ASSIGNMENT_STATEMENT         { $$ = new DeclarationExpressionList(*$1, $2); delete $1; }
  ;

ASSIGNMENT_STATEMENT //a = 2, b = 5 ;
  : DECLARATOR '=' LOGICAL_OR_ARITHMETIC_EXPRESSION ',' ASSIGNMENT_STATEMENT    { $$ = new DeclarationExpressionListNode($1, $3, $5); }
  | DECLARATOR ',' ASSIGNMENT_EXPRESSION                                         { $$ = new DeclarationExpressionListNode($1, nullptr, $3); }
  | DECLARATOR '=' LOGICAL_OR_ARITHMETIC_EXPRESSION                              { $$ = new DeclarationExpressionListNode($1, $3, nullptr); }
  | DECLARATOR                                                                   { $$ = new DeclarationExpressionListNode($1, nullptr, nullptr); }
  ;

/* Logical or arithmetic expressions are like
 * var_name +
 */
logical_or_arithmetic_expression
  : conditional_expression  { $$ = $1; }
  | declarator assignment_operator logical_or_arithmetic_expression { $$ = new AssignmentExpression($1, *$2, $3); }
  ;

/* ============== BEGIN Arithmetic and logical expressions ordereing */
primary_expression
  : declarator                                { $$ = $1; }
  | INTEGER_CONSTANT                          { $$ = new IntegerConstant( $1 ); }
  /*| FLOAT_CONSTANT
  | CHARACTER_CONSTANT
  | STRING_CONSTANT */
  | '(' logical_or_arithmetic_expression ')'  { $$ = $2; }
  | T_IDENTIFIER function_call_parameters_list  { $$ = new FunctionCall(*$1, $2); delete $1; }
  ;

postfix_expression
  : primary_expression         { $$ = $1; }
  | postfix_expression INC_OP  { $$ = new PostfixExpression($1, "++"); }
  | postfix_expression DEC_OP  { $$ = new PostfixExpression($1, "--"); }
  ;

unary_expression
  : postfix_expression               { $$ = $1; }
  | INC_OP unary_expression          { $$ = new UnaryExpression("++", $2); }
  | DEC_OP unary_expression          { $$ = new UnaryExpression("--", $2); }
  | unary_operator unary_expression  { $$ = new UnaryExpression(*$1, $2); delete $1; }
  ;

unary_operator
  : '&'  { $$ = new std::string("&"); }
  | '+'  { $$ = new std::string("+"); }
  | '-'  { $$ = new std::string("-"); }
  | '~'  { $$ = new std::string("~"); }
  | '!'  { $$ = new std::string("!"); }
  ;

multiplicative_expression
  : unary_expression                                { $$ = $1; }
  | multiplicative_expression '*' unary_expression  { $$ = new MultiplicativeExpression($1, "*", $3); }
  | multiplicative_expression '/' unary_expression  { $$ = new MultiplicativeExpression($1, "/", $3); }
  | multiplicative_expression '%' unary_expression  { $$ = new MultiplicativeExpression($1, "%", $3); }
  ;

additive_expression
  : multiplicative_expression                          { $$ = $1; }
  | additive_expression '+' multiplicative_expression  { $$ = new AdditiveExpression($1, "+", $3); }
  | additive_expression '-' multiplicative_expression  { $$ = new AdditiveExpression($1, "-", $3); }
  ;

shift_expression
  : additive_expression                            { $$ = $1; }
  | shift_expression LEFT_OP additive_expression   { $$ = new ShiftExpression($1, "<<", $3); }
  | shift_expression RIGHT_OP additive_expression  { $$ = new ShiftExpression($1, ">>", $3); }
  ;

relational_expression
  : shift_expression                              { $$ = $1; }
  | relational_expression '<' shift_expression    { $$ = new RelationalExpression($1, "<", $3); }
  | relational_expression '>' shift_expression    { $$ = new RelationalExpression($1, ">", $3); }
  | relational_expression LE_OP shift_expression  { $$ = new RelationalExpression($1, "<=", $3); }
  | relational_expression GE_OP shift_expression  { $$ = new RelationalExpression($1, ">=", $3); }
  ;

equality_expression
  : relational_expression                            { $$ = $1; }
  | equality_expression EQ_OP relational_expression  { $$ = new EqualityExpression($1, "==", $3); }
  | equality_expression NE_OP relational_expression  { $$ = new EqualityExpression($1, "!=", $3); }
  ;

and_expression
  : equality_expression                     { $$ = $1; }
  | and_expression '&' equality_expression  { $$ = new AndExpression($1, $3); }
  ;

exclusive_or_expression
  : and_expression                              { $$ = $1; }
  | exclusive_or_expression '^' and_expression  { $$ = new ExclusiveOrExpression($1, $3); }
  ;

inclusive_or_expression
  : exclusive_or_expression                              { $$ = $1; }
  | inclusive_or_expression '|' exclusive_or_expression  { $$ = new InclusiveOrExpression($1, $3); }
  ;

logical_and_expression
  : inclusive_or_expression                                { $$ = $1; }
  | logical_and_expression AND_OP inclusive_or_expression  { $$ = new LogicalAndExpression($1, $3); }
  ;

logical_or_expression
  : logical_and_expression                              { $$ = $1; }
  | logical_or_expression OR_OP logical_and_expression  { $$ = new LogicalOrExpression($1, $3); }
  ;

conditional_expression
  : logical_or_expression                                            { $$ = $1; }
  | logical_or_expression '?' expression ':' conditional_expression  { $$ = new ConditionalExpression($1, $3, $5); }
	;

/* ============== END Arithmetic and logical expressions ordering */

function_call_parameters_list
  : '(' parameters_list ')'  { $$ = $2; }
	| '(' ')'                  { $$ = new ParametersListNode(nullptr, nullptr); }
  ;

parameters_list
  : logical_or_arithmetic_expression ',' parameters_list { $$ = new ParametersListNode($1, $3); }
  | logical_or_arithmetic_expression                     { $$ = new ParametersListNode($1, nullptr); }
  ;

/* Declarator for a variable. Only direct name allowed, no pointers.*/
declarator
  : direct_declarator { $$ = $1; }
  | '*' T_IDENTIFIER    {$$ = new Variable(*$2, "pointer", nullptr); delete $2; }
  ;

/* Only simple types allowed, e.g. int, float or defined types.
 * No arrays or struct allowed. */
direct_declarator
  : T_IDENTIFIER                                           { $$ = new Variable( *$1, "normal", nullptr); delete $1; }
  | T_IDENTIFIER '[' logical_or_arithmetic_expression ']'  { $$ = new Variable( *$1, "array", $3 ); delete $1; }
  ;

/* Only INT allowed for now. */
type_specifier
  : INT           { $$ = new std::string("int"); }
  | UNSIGNED      { $$ = new std::string("int"); }
  | UNSIGNED INT  { $$ = new std::string("int"); }
  | VOID          { $$ = new std::string("void"); }
  ;

%%

// Definition of variable (to match declaration earlier).
std::vector<const Node*> ast_roots;

std::vector<const Node*> parseAST() {
  yyparse();
  return ast_roots;
}
