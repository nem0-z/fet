%{
#include <stdio.h>
#include "calc.tab.h"
%}

%%

[ \t]	; // ignore all whitespace
[0-9]+		{ yylval = atoi(yytext); return T_INT;}
\n		{return T_NEWLINE;}
[-+*/()]        { return *yytext; }
"exit"		{return T_QUIT;}
"quit"		{return T_QUIT;}

%%
