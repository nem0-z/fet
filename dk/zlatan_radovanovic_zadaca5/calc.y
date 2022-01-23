%{

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <cstring>
#include <cmath>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE* yyin;
void yyerror(const char* s);

extern std::map<std::string, double> vars;
const double PI = 3.14159265;
%}

%union {
    double fval;
    char *sval;
}

%token T_EXIT T_PRINT T_COS T_SIN T_COSDEG T_SINDEG
%token<sval> T_ID
%token<sval> T_STR
%token<fval> T_NUM

%right '=' '&'
%left '+' '-'
%left '*' '/'

%type<fval> expression
%type<fval> trigonometry
%type<fval> num_or_var
%type<sval> mixed_expression

%start calculation

%%

calculation: calculation line '\n'
    | %empty
    ;

line: %empty
    | T_PRINT mixed_expressions
    | expression
    | T_EXIT        { printf("bye!\n"); exit(0); }

expression: T_NUM               { $$ = $1; }
    | T_ID                      { $$ = vars[$1]; free($1); }
    | trigonometry              { $$ = $1; }
    | T_ID '=' expression       { $$ = $3; vars[$1] = $3; free($1); }
    | '-' expression            { $$ = -$2; }
    | expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { $$ = $1 / $3; }
    | '(' expression ')'        { $$ = $2; }
    | '[' expression ']'        { $$ = $2; }
    | '{' expression '}'        { $$ = $2; }
    ;

trigonometry: T_SIN num_or_var       { $$ = std::sin($2); }
    | T_SIN '(' expression ')'       { $$ = std::sin($3); }
    | T_COS  num_or_var              { $$ = std::cos($2); }
    | T_COS '(' expression ')'       { $$ = std::cos($3); }
    | T_SINDEG  num_or_var           { $$ = std::sin($2 * PI / 180); }
    | T_SINDEG '(' expression ')'    { $$ = std::sin($3 * PI / 180); }
    | T_COSDEG  num_or_var           { $$ = std::cos($2 * PI / 180); }
    | T_COSDEG '(' expression ')'    { $$ = std::cos($3 * PI / 180); }
    ;

num_or_var: T_NUM                   { $$ = $1; }
    | T_ID                          { $$ = vars[$1]; free($1); }

mixed_expressions: mixed_expression { printf("%s\n", $1); } ',' mixed_expressions
     | mixed_expression { printf("%s\n", $1); }
     | %empty
     ;

mixed_expression: expression { $$ = (char *)malloc(sizeof(char)*15); sprintf($$, "%f", $1); }
     | T_STR { $$ = (char *)malloc(sizeof(char)*(strlen($1)+1)); sprintf($$, "%s", $1); free($1); }
     | mixed_expression '&' mixed_expression { $$ = (char *)malloc(sizeof(char)*(strlen($1)+strlen($3)+1)); sprintf($$, "%s%s", $1, $3); }
     ;

%%

std::map<std::string, double> vars;

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
