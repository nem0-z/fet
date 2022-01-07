%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "calc.tab.h"

%}

/* {number}+\.{number}+ 	{ yylval.fval = atof(yytext); return T_FLOAT; } */
/* {number}+             { yylval.ival = atoi(yytext); return T_INT;} */

number                [0-9]

%%

[ \t]	                ; // ignore all whitespace
[-+*/\n*()]           { return *yytext; }
{number}+             { yylval = atoi(yytext); return T_INT;}
"exit"	            	{ return T_QUIT; }
"quit"	            	{ return T_QUIT; }

%%
