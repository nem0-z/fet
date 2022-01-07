%{
#include <iostream>
#include <string>
#include "header.hpp"

extern "C" int yywrap();
static int tableCount;
%}

digit                       [0-9]
ip                          ({digit}{1,3}\.){3}{digit}{1,3}

%%

[ \t\n]*                    {;}
true                        {return BOOLEAN;}
false                       {return BOOLEAN;}
title                       {return TITLE;}
"="                         {return EQUAL;}
{ip}                        {return IP;}
\"[^\"]*\"                  {return STRING;}
[a-zA-Z_][a-zA-Z_0-9]*      {return ID;}
[0-9]+                      {return NUM;}
\[.*\]                      {++tableCount; return TABLE;}
.                           {;}

%%

int yywrap() {
    return 1;
}

int main() {
    int token;
    std::string tag;

    while ((token = yylex())) {
        tag = mapTagToString(token);
        if (tag.empty())
            return -1;
        std::cout << "<" << tag << ", " << yytext << ">" << std::endl;
    }

    std::cout << "Datoteka sadrzi " << tableCount << " tabele." << std::endl;
}
