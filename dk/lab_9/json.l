%option noyywrap
%{

#include<stdio.h>
#include "json.tab.h"

/*
const int OPENBRACES = 10;
const int CLOSEDBRACES = 2;
const int COLON = 3;
const int COMMA = 4;
const int STRING = 5;
const int NUMBER = 8;
const int OPENBRACKET = 9;
const int CLOSEDBRACKET = 11;
const int TRUE = 12;
const int FALSE = 13;
const int NULLABLE = 14;
*/

%}

ws            [ \t\n]
letter        [a-zA-Z]
digit         [0-9]
number        {digit}+
string    ({letter}|{digit})*

%%

{ws}
{number}                      { return NUMBER; }
"null"                        { return NULLABLE; }
"true"                        { return TRUE; }
"false"                       { return FALSE;}
\"{string}\"                  { return STRING; }
.                             { return *yytext; }

%%
