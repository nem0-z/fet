%option noyywrap
%{
#include <stdio.h>
#include "calc.tab.h"
%}

letter                  [a-zA-Z]

%%

"exit"		    { return T_QUIT;}
"quit"		    { return T_QUIT;}
[ \t]	        ; // ignore all whitespace
[0-9]+		    { yylval = atoi(yytext); return T_INT;}
{letter}        { yylval = *yytext; return T_ID; }
\n		        { return T_NEWLINE;}
[-+*/()=]       { return *yytext; }

%%
