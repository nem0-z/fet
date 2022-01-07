%option noyywrap 

%{

#include <vector>
#include "token.hpp"

%}

ws       [ \t\n]
digit    [0-9]
number   {digit}+

%%

{ws}       {}
"{"        { return OPEN_BRACES; }
"}"        { return CLOSED_BRACES; }
"["        { return OPEN_BRACKET; }
"]"        { return CLOSED_BRACKET; }
"("        { return OPEN_PAREN; }
")"        { return CLOSED_PAREN; }
.          {}

%%

int main() {
    int t;
    std::vector<Token> tokeni;
    while ( (t = yylex()) ) {
        tokeni.push_back(Token{t, yytext});
        std::cout << tokeni.back() << std::endl;
    }
    std::cout << "Ucitano je ukupno: " << tokeni.size() << " tokena." << std::endl;

    std::cout << std::boolalpha << "Balansirano: " << analiziraj(tokeni) << std::endl;
}

