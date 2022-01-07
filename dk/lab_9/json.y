%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #define YYSTYPE char*
%}

%token STRING
%token NUMBER
%token TRUE
%token FALSE
%token NULLABLE

%%
START: OBJECT { printf("Success\n"); };

OBJECT: '{' PAIRS '}';

PAIR: STRING ':' VALUE;

VALUE: NUMBER       { printf("Dummy code\n"); }
     | STRING
     | TRUE
     | FALSE
     | NULLABLE
     | OBJECT
     | ARRAY
     ;

PAIRS: PAIRS ',' PAIR
     | PAIR
     |
     ;

ARRAY: '[' VALUES ']';

VALUES: VALUES ',' VALUE
      | VALUE
      |
      ;

%%

int main() {
   printf("\n");
   yyparse();
   printf("\n");
   return 0;
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

