%{

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

int vars[UCHAR_MAX] = {};
%}

%token T_INT
%token T_NEWLINE T_QUIT
%token T_ID

%precedence '='
%left '+' '-'
%left '*' '/'

%start calculation

%%

calculation: calculation line
           |
           ;

line: T_NEWLINE
    | expression T_NEWLINE { printf("%i\n", $1); }
    | T_QUIT T_NEWLINE { printf("bye!\n"); exit(0); }
;

expression: T_INT			        { $$ = $1; }
      | T_ID                        { $$ = vars[$1]; }
      | T_ID '=' expression         { $$ = $3; vars[$1] = $3; }
	  | expression '+' expression	{ $$ = $1 + $3; }
	  | expression '-' expression	{ $$ = $1 - $3; }
	  | expression '*' expression	{ $$ = $1 * $3; }
	  | expression '/' expression	{ $$ = $1 / $3; }
	  | '(' expression ')'          { $$ = $2; }
;

%%

int main() {
#ifdef DBGBISON
    yydebug = 1;
#endif
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));
        return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
