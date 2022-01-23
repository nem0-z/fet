%{
#include <stdio.h>
#include <vector>
#include <iostream>
#include "expression_tree.hpp"
#include "environment.hpp"

int yylex();
void yyerror(Environment& env, const char* s);
%}

%union {
  int num;
  char* str;
  std::vector<ExpressionNode*>* exprs;
  std::vector<std::string>* ids;
  ExpressionNode* node;
}

%start START

%token<num> NUMBER
%token IF
%token ELSE
%token WHILE
%token PRINT
%token EQUAL
%token NONEQUAL
%token RETURN
%token<str> ID

%right '='
%left '+' '-'
%left '*' '/'

%type<node> STMT
%type<node> EXPR
%type<exprs> STMT_LIST
%type<exprs> EXPR_LIST
%type<ids> ID_LIST

%parse-param {Environment& env}

%%

START: /* epsilon */
     | START STMT   { $2->evaluate(env); }
     ;

STMT: EXPR ';'                               { $$ = $1; }
    | PRINT EXPR ';'                         { $$ = new PrintNode($2); }
    | IF '(' EXPR ')' STMT                   { $$ = new IfNode($3, $5); }
    | IF '(' EXPR ')' STMT ELSE STMT         { $$ = new IfElseNode($3, $5, $7); }
    | WHILE '(' EXPR ')' '{' STMT_LIST '}'                  { $$ = new WhileNode($3, *$6); }
    | ID '(' ID_LIST ')' '{' STMT_LIST RETURN EXPR ';' '}'  { $$ = new FunctionDefinitionNode($1, *$3, *$6, $8); }
    ;

ID_LIST: ID_LIST ',' ID   { $$ = $1; $$->push_back($3); }
       | ID               { $$ = new std::vector<std::string>(); $$->push_back($1); }
       ;

EXPR: NUMBER { $$ = new NumberNode($1); };
    | EXPR '+' EXPR         { $$ = new PlusNode($1, $3); }
    | EXPR '-' EXPR         { $$ = new MinusNode($1, $3); }
    | EXPR '*' EXPR         { $$ = new MultiplyNode($1, $3); }
    | EXPR '/' EXPR         { $$ = new DivideNode($1, $3); }
    | EXPR EQUAL EXPR       { $$ = new EqualityNode($1, $3); }
    | EXPR NONEQUAL EXPR    { $$ = new InEqualityNode($1, $3); }
    | EXPR '<' EXPR         { $$ = new LessThanNode($1, $3); }
    | EXPR '>' EXPR         { $$ = new GreaterThanNode($1, $3); }
    | ID                    { $$ = new VariableNode($1); }
    | ID '=' EXPR           { $$ = new AssignmentNode($1, $3); }
    | ID '(' EXPR_LIST ')'  { $$ = new FunctionCallNode($1, *$3); }
    | '(' EXPR ')'          { $$ = $2; }
    ;

STMT_LIST: ';'                { $$ = $$; }
         | STMT_LIST STMT     { $$ = $1; $$->push_back($2); }
         | /*epsilon*/        { $$ = new std::vector<ExpressionNode*>(); }
         ;

EXPR_LIST: EXPR_LIST ',' EXPR   { $$ = $1; $$->push_back($3); }
       | EXPR               { $$ = new std::vector<ExpressionNode*>(); $$->push_back($1); }
       ;

%%

int main() {
  /* yydebug = 1; */
  Environment env;
  yyparse(env);
}

// An optional but friendlier yyerror function...
void yyerror(Environment& env, const char *s) {
  extern int yylineno;  // defined and maintained in lex
  extern char *yytext;  // defined and maintained in lex
  fprintf(stderr, "Error: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
}
