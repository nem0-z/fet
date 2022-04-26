%option noyywrap
%{
    #include "hm.tab.h"
%}

%%

"print"             { return T_PRINT; }
(int|float|double)  { yylval.sval = strdup(yytext); return T_TYPE; }
[a-zA-Z][a-zA-Z0-9]* { yylval.sval = strdup(yytext); return T_ID; }
[0-9]+              { yylval.ival = atoi(yytext); return T_NUM; }
[-+,\n]             { return *yytext; }
.                   ;

%%
