%{
#include "token.h"
%}

ws       [ \t\n]     
number   [0-9]
word     [a-zA-Z]+ 

%%

exit        { return 1; }
{word}      { return WORD; }
{number}+   { return NUMBER;}
{ws}        ;   // zanemarujemo
.           ;   // catch all 

%%

int print_token(int t) {
  switch (t) {
    case 1:
      printf("WORD");
      break;
    case 2:
      printf("INTEGER");
      break;
  }
}

int main() {
  int token;
  while (token = yylex()) {
    print_token(token);
    printf("%s\n", yytext);
  }
}
