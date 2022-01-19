%option noyywrap
%{
    #include "z1.tab.h"
%}

id              [a-zA-Z_][a-zA-Z_0-9]*
num             [0-9]+

%%

{id}                { yylval.sval = strdup(yytext); return T_ID; }
{num}               { yylval.ival = atoi(yytext); return T_NUM; }
[-+*/:\[\]\n()]     { return *yytext; }
[ \t]+              { ; }
.                   { exit(0); }

%%
