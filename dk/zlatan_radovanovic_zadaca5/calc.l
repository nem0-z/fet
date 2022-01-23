%option noyywrap

%{

#include <stdio.h>
#define YY_DECL extern "C" int yylex()
#include "calc.tab.h"

void yyerror(const char*);

%}

id                  [a-zA-Z_][a-zA-Z_0-9]*
number              [0-9]+(\.[0-9]*)?

%%

[ \t]	                                ; // ignore all whitespace
\"[^\"]*\"                              { yylval.sval = strndup(yytext+1, strlen(yytext)-2); return T_STR; }
"exit"	            	                { return T_EXIT; }
"print"                                 { return T_PRINT; }
"cos"                                   { return T_COS; }
"sin"                                   { return T_SIN; }
"cosdeg"                                { return T_COSDEG; }
"sindeg"                                { return T_SINDEG; }
{number} 	                            { yylval.fval = atof(yytext); return T_NUM; }
{id}                                    { yylval.sval = strdup(yytext); return T_ID; }
[-+=*/&(){}\[\]\n,]                     { return *yytext; }

%%
