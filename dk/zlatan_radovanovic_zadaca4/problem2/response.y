%define api.value.type { char* }
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%token VERSION
%token WORD
%token NUMBER
%token STRING
%token ID
%token COLON
%token NEWLINE

%%

RESPONSE: VERSION CODE MESSAGE NEWLINE HEADERS {
       printf("%s %s\n", $2, $3);
    }
;

CODE: NUMBER {
        $$ = $1;
    }
;

MESSAGE: WORD {
       $$ = $1;
       }
;

HEADERS: HEADER {
        $$ = $1;
    }
    |HEADER NEWLINE HEADERS {
        $$ = (char *)malloc(sizeof(char)*(strlen($1)+1+strlen($3)+1));
        sprintf($$, "%s\n%s", $1, $3);
    }
    |{
        $$ = "";
    }
;

HEADER: FIELDNAME COLON STRING {
        $$ = (char *)malloc(sizeof(char)*(strlen($1)+1+strlen($3)+1));
        sprintf($$, "%s:%s", $1, $3);
    }
;

FIELDNAME: WORD {
        $$ = $1;
    }
    |ID {
        $$ = $1;
    }
;

%%

void yyerror (char const *s) {
   fprintf(stderr, "Poruka nije tacna\n");
}

int main() {
#ifdef DBGBISON
    yydebug=1;
#endif
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

    return 0;
}
