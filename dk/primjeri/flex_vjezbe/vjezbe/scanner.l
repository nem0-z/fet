%option noyywrap 

%{

#include "token.hpp"

%}

ws       [ \t\n]
digit    [0-9]
number   {digit}+

%%

{ws}       {}
:          { return COLON; }
\".*\"     { return STRING; }
"{"        { return OPEN_BRACES; }
"}"        { return CLOSED_BRACES; }
"["        { return OPEN_BRACKET; }
"]"        { return CLOSED_BRACKET; }
","        { return COMMA; }
"false"    { return BOOLEAN; }
"true"     { return BOOLEAN; }
"null"     { return NULLJSON; }
{number}   { return NUMBER; }
.          { printf("error: %c\n", yytext[0]); }

%%

int main() {
    int t;
    while ( (t = yylex()) ) {
        Token token{t, yytext};
        std::cout << token << std::endl;
    }
}

