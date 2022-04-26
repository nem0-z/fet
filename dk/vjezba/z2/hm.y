%{
    #include <iostream>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    void yyerror(const char *);
%}

%union {
    int ival;
    char *sval;
}

%token T_PRINT
%token<ival> T_NUM
%token<sval> T_TYPE T_ID
%type<ival> expr

%right ','
%left '+' '-'

%start prog

%%

prog: prog line '\n'
    | %empty
    ;

line: T_PRINT printlist
    | T_TYPE mark1 idlist
    ;

mark1: %empty { $<sval>$ = $<sval>0; }

idlist: idlist ',' T_ID { printf("%s: %s\n", $3, $<sval>0); }
    | T_ID    { printf("%s: %s\n", $1, $<sval>0); }
    ;

printlist: printlist ',' expr  { std::cout << $3 << std::endl; }
    | expr     { std::cout << $1 << std::endl; }
    ;

expr: T_NUM         { $$ = $1; }
    | expr '+' expr { $$ = $1 + $3; }
    ;

%%

void yyerror(const char *err) {
    fprintf(stderr, "%s", err);
}

int main() {
    yyparse();
    std::cout << "Isprinto sam nesto" << std::endl;
}
