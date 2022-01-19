%{
    #include <iostream>
    #include <string>

    extern int yylex();
    extern int yyparse();
    void yyerror(const char*);

    extern std::string current_table;
%}

%union {
    int ival;
    char *sval;
}

%token<sval> T_ID
%token<ival> T_NUM
%right ':'
%left '+' '-'
%left '*' '/'

%type<ival> expr

%start z1

%%

z1: z1 table
  |
  ;

table: tabletitle pairs;

tabletitle: '[' T_ID ']' '\n' { current_table = std::string{$2}; free($2); };

pairs: pairs pair
     |
     ;

pair: T_ID ':' expr '\n'      { std::cout << current_table << "." << std::string{$1} << ": " << $3 << std::endl; free($1); };

expr: T_NUM                   { $$ = $1; }
    | expr '+' expr           { $$ = $1 + $3; }
    | expr '-' expr           { $$ = $1 - $3; }
    | expr '*' expr           { $$ = $1 * $3; }
    | expr '/' expr           { $$ = $1 / $3; }
    | '(' expr ')'            { $$ = $2; }

%%

std::string current_table;

void yyerror(const char *err) {
    fprintf(stderr, "%s", err);
}

int main() {
    yyparse();

    return 0;
}
