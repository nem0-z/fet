%{

#include <stdio.h>
#include <stdlib.h>

#define YYSTYPE int

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

/* %union { */
/* 	int ival; */
/* 	float fval; */
/* } */

%token T_INT
%token '+' '-' '*' '/' '(' ')' 
%token '\n' T_QUIT

/* %token<ival> T_INT */
/* %token<fval> T_FLOAT */
/* %left '+' '-' */
/* %left '*' '/' */
/* %type<ival> expression */
/* %type<fval> mixed_expression */

%start calculation

%%

calculation: 
	   | calculation line
;

line: '\n'
    /* | mixed_expression '\n' { printf("\tResult: %f\n", $1);} */
    | expression '\n' { printf("\tResult: %i\n", $1); } 
    | T_QUIT '\n' { printf("bye!\n"); exit(0); }
;

/* mixed_expression: T_FLOAT                 		 { $$ = $1; } */
/* 	  | mixed_expression '+' mixed_expression	 { $$ = $1 + $3; } */
/* 	  | mixed_expression '-' mixed_expression	 { $$ = $1 - $3; } */
/* 	  | mixed_expression '*' mixed_expression { $$ = $1 * $3; } */
/* 	  | mixed_expression '/' mixed_expression	 { $$ = $1 / $3; } */
/* 	  | '(' mixed_expression ')'		 { $$ = $2; } */
/* 	  | expression '+' mixed_expression	 	 { $$ = $1 + $3; } */
/* 	  | expression '-' mixed_expression	 	 { $$ = $1 - $3; } */
/* 	  | expression '*' mixed_expression 	 { $$ = $1 * $3; } */
/* 	  | expression '/' mixed_expression	 { $$ = $1 / $3; } */
/* 	  | mixed_expression '+' expression	 	 { $$ = $1 + $3; } */
/* 	  | mixed_expression '-' expression	 	 { $$ = $1 - $3; } */
/* 	  | mixed_expression '*' expression 	 { $$ = $1 * $3; } */
/* 	  | mixed_expression '/' expression	 { $$ = $1 / $3; } */
/* ; */

expression: T_INT				{ $$ = $1; }
	  | expression '+' expression	{ $$ = $1 + $3; }
	  | expression '-' expression	{ $$ = $1 - $3; }
	  | expression '*' expression	{ $$ = $1 * $3; }
	  | expression '/' expression	{ $$ = $1 / $3; }
	  | '(' expression ')'		{ $$ = $2; }
;

%%

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
