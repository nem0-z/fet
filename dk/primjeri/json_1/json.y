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

PAIRS : PAIRS ',' PAIR
      | PAIR
      | 
      ;

VALUE: STRING { puts("string"); }
     | NUMBER { puts("number"); }
     | TRUE { puts("true"); } 
     | FALSE { puts("false"); }
     | NULLABLE { puts("null"); }
     | OBJECT
     | ARRAY
     ;

ARRAY : '[' ELEMENTS ']';

ELEMENTS : ELEMENTS ',' VALUE
         | VALUE
         |
         ;

%%

int main()
{
   printf("\n");
   yyparse();
   printf("\n");
   return 0;
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

