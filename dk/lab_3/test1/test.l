%option noyywrap
%{
#include <iostream>
int brojC,brojR,brojL,brojBrojeva,brojID;
%}
alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
id          ({alpha}|_)({alnum})*

%%

\n          { brojL++; brojC++;}
{alpha}+   { brojR++; brojC += yyleng; }
{id}        { brojID++; brojC += yyleng;}
{digit}+     { brojBrojeva++; brojC += yyleng; }
.           { brojC++; }

%%

/* int main() { */
/*   yylex(); */
/*   std::cout << "Broj rijeci: " << brojR */
/*             << ", broj karaktera: " << brojC */
/*             << ", broj linija: " << brojL */
/*             << ", broj brojeva: " << brojBrojeva */
/*             << ", broj ideva: " << brojID */
/*             << std::endl; */
/* } */
