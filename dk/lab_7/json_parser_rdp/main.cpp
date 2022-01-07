#include <iostream>
#include <vector>

// generisan u Makefile-u
#include "lex.yy.h"
#include "parser.h"
#include "token.hpp"


int main(void) {
  std::vector<Token> tokens;
  int yytoken;
  while ((yytoken = yylex())) {
    tokens.push_back(Token(yytoken, yytext));
  }

  for (const auto &token : tokens) {
    token.print();
  }

  // TODO uncomment this
  Parser p(tokens);
  if (p.parse())
    std::cout << "Uneseni string je ispravan." << std::endl;
  else
    std::cout << "Uneseni string nije ispravan." << std::endl;

  return 0;
}
