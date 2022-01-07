%{

int numOfNewLines = 0;
int numOfWords = 0;
int numOfCharacters = 0;

%}

%%

[ \t]      { numOfCharacters++; };
[\n]       { numOfNewLines++; numOfCharacters++; }
[a-zA-Z]+  { numOfWords++; numOfCharacters += yyleng; }

%%

int main() {

  yylex();

  printf("%d\n", numOfNewLines);
  printf("%d\n", numOfWords);
  printf("%d\n", numOfCharacters);
  
}
