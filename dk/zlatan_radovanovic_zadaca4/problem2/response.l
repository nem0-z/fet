%option noyywrap
%{
    #include<stdio.h>
    #include "response.tab.h"
    char *strclone(char *str);
%}

num                                     [0-9]+(\.[0-9]{1,2})?
letter                                  [a-zA-Z]
letternum                               [a-zA-Z0-9\-]
word                                    {letter}+
id                                      {letter}{letternum}*
string                                  \"[^"]*\"

%%

HTTP\/{num}                             { yylval = strclone(yytext); return VERSION; }
{word}                                  { yylval = strclone(yytext); return WORD; }
{id}                                    { yylval = strclone(yytext); return ID; }
{string}                                { yylval = strclone(yytext); return STRING; }
{num}                                   { yylval = strclone(yytext); return NUMBER; }
"\n"                                    { return NEWLINE; }
":"                                     { return COLON; }
[ \t\n]+                                       ;
. {
    printf("Unexpected: %c\nExiting...\n", *yytext);
    exit(0);
}

%%

char *strclone(char *str) {
    int len = strlen(str);
    char *clone = (char *)malloc(sizeof(char)*(len+1));
    strcpy(clone,str);
    return clone;
}
