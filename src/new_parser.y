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
  : SCOPE                   { g_root = new RootNode($1); }
  | translation_unit SCOPE  { g_root = new RootNode($2); }
  ;

/* [OK] A single top level declaration. */
SCOPE
  : FUNCTION_DEFINITION                                                          { $$ = $1; }
  | FUNCTION_DECLARATION                                                         { $$ = $1; }
  | DECLARATION_EXPRESSION_LIST T_COLON                                          { $$ = $1; }
  | ENUM T_IDENTIFIER T_L_BRACE ENUMERATOR_LIST T_R_BRACE T_SEMICOLON { $$ = $4; }  //CHECK
  ;

ENUMATOR_LIST
  : ENUMERATOR T_COMMA ENUMERATOR { $$ = new EnumDeclarationListNode($1, $3); }
  | ENUMERATOR                    { $$ = new EnumDeclarationListNode($1, nullptr); }
  ;

ENUMERATOR
  : T_IDENTIFIER                                       { $$ = new EnumDeclaration(*$1, nullptr); delete $1; }
  | T_IDENTIFIER '=' logical_or_arithmetic_expression  { $$ = new EnumDeclaration(*$1, $3); delete $1; }
  ;

function_declaration
  : type_specifier declarator arguments_list ';'  { $$ = new FunctionDeclaration(*$1, $2, $3); delete $1; }
  ;

function_definition
  : type_specifier declarator arguments_list compound_statement { $$ = new FunctionDefinition(*$1, $2, $3, $4); delete $1; }
  ;

/* Only accept no arguments. */
arguments_list
  : '(' ')'                     { $$ = new ArgumentListNode(nullptr, nullptr); }
  | '(' function_arguments ')'  { $$ = $2; }
  ;

function_arguments
  : function_argument ',' function_arguments { $$ = new ArgumentListNode($1, $3); }
  | function_argument                        { $$ = new ArgumentListNode($1, nullptr); }
  ;

function_argument
  : type_specifier declarator         { DeclarationExpressionListNode* node =
                                        new DeclarationExpressionListNode($2, nullptr, nullptr);
                                        $$ = new DeclarationExpressionList(*$1, node);
                                        delete $1; }
  ;

/* Sequence of statements. */
compound_statement
  : '{' statement_list '}' { $$ = new CompoundStatement($2); }
  | '{' '}'                { $$ = new CompoundStatement(nullptr); }
  ;

/* [OK] One or more statements. */
statement_list
  : statement statement_list { $$ = new StatementListNode($1, $2); }
  | statement                { $$ = new StatementListNode($1, nullptr); }
  ;

/* Possible statements. */
statement
  : compound_statement   { $$ = $1; }
  | expression_statement { $$ = $1; }
  | jump_statement       { $$ = $1; }
  | iteration_statement  { $$ = $1; }
  | selection_statement  { $$ = $1; }
  ;

/* Note. This creates a shift reduce conflict, but since Yacc resolves the confilct
 * by matching the longest subsequence, hence we have the desired behaviour. */
selection_statement
  : IF '(' expression ')' statement                   { $$ = new IfStatement($3, $5, nullptr); }
  | IF '(' expression ')' statement ELSE statement    { $$ = new IfStatement($3, $5, $7); }
  | SWITCH '(' expression ')' compound_case_statement { $$ = new SwitchStatement($3, $5); }
  ;

case_or_default_statement_list
  : case_statement case_or_default_statement_list   { $$ = new CaseStatementListNode($1, $2); }
  | default_statement case_statement_list           { $$ = new CaseStatementListNode($1, $2); }
  | default_statement                               { $$ = new CaseStatementListNode($1, nullptr); }
  ;

case_statement_list
  : case_statement case_statement_list              { $$ = new CaseStatementListNode($1, $2); }
  | case_statement                                  { $$ = new CaseStatementListNode($1, nullptr); }
  ;

compound_case_statement
  : '{' case_or_default_statement_list '}'          { $$ = $2; }
  | '{' case_statement_list '}'                     { $$ = $2; }
  | '{' '}'                                         { $$ = new CaseStatementListNode(nullptr, nullptr); }
  ;

case_statement
  : CASE expression ':' statement_list              { $$ = new CaseStatement($2, $4); }
  | CASE expression ':'                             { $$ = new CaseStatement($2, nullptr); }
  ;

default_statement
  : DEFAULT ':' statement_list                      { $$ = new DefaultStatement($3); }
  | DEFAULT ':'                                     { $$ = new DefaultStatement(nullptr); }
  ;

iteration_statement
  : WHILE '(' expression ')' statement                                          { $$ = new WhileStatement($3, $5); }
  | FOR '(' expression_statement  expression_statement expression ')' statement { $$ = new ForStatement($3, $4, $5, $7); }
  | FOR '(' expression_statement  expression_statement ')' statement            { $$ = new ForStatement($3, $4, nullptr, $6); }
  ;

jump_statement
  : RETURN ';'            { $$ = new ReturnStatement(nullptr); }
  | RETURN expression ';' { $$ = new ReturnStatement($2); }
  | BREAK ';'             { $$ = new BreakStatement(); }
  | CONTINUE ';'          { $$ = new ContinueStatement(); }
  ;

/* [OK] Expression. */
expression_statement
  : ';'            { $$ = new EmptyExpression(); }
  | expression ';' { $$ = $1; }
  ;

/* Every simple expression. Could be an assignment, a declaration, a function call
 * etc..
 * Only assignment and declaration for now. */
expression
  : declaration_expression_list       { $$ = $1; }
  | logical_or_arithmetic_expression  { $$ = $1; }
  ;


assignment_operator
  : '='          { $$ = new std::string("="); }
  | MUL_ASSIGN   { $$ = new std::string("*="); }
  | DIV_ASSIGN   { $$ = new std::string("/="); }
  | MOD_ASSIGN   { $$ = new std::string("%="); }
  | ADD_ASSIGN   { $$ = new std::string("+="); }
  | SUB_ASSIGN   { $$ = new std::string("-="); }
  | LEFT_ASSIGN  { $$ = new std::string("<<="); }
  | RIGHT_ASSIGN { $$ = new std::string(">>="); }
  | AND_ASSIGN   { $$ = new std::string("&="); }
  | XOR_ASSIGN   { $$ = new std::string("^="); }
  | OR_ASSIGN    { $$ = new std::string("|="); }
  ;

/* Declaration expressions are like
 *              DeclarationExpressionList
 *                  /                 \
 *           TypeSpecifier          DeclarationExpressionListNode
 *                                      /          |           \
 *                               Variable      Rhs(nullptr)    Nextnode(nullptr)
 */

declaration_expression_list
  : type_specifier declaration_expression_list_node         { $$ = new DeclarationExpressionList(*$1, $2); delete $1; }
  ;

declaration_expression_list_node
  : declarator '=' logical_or_arithmetic_expression ',' declaration_expression_list_node    { $$ = new DeclarationExpressionListNode($1, $3, $5); }
  | declarator ',' declaration_expression_list_node                                         { $$ = new DeclarationExpressionListNode($1, nullptr, $3); }
  | declarator '=' logical_or_arithmetic_expression                                         { $$ = new DeclarationExpressionListNode($1, $3, nullptr); }
  | declarator                                                                              { $$ = new DeclarationExpressionListNode($1, nullptr, nullptr); }
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
