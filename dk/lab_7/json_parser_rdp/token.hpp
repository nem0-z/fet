#ifndef _TOKEN_
#define _TOKEN_

#include <iostream>
#include <string>

const int OPENBRACES = 10;
const int CLOSEDBRACES = 2;
const int COLON = 3;
const int COMMA = 4;
const int STRING = 5;
const int NUMBER = 8;
const int OPENBRACKET = 9;
const int CLOSEDBRACKET = 11;
const int TRUE = 12;
const int FALSE = 13;
const int NULLABLE = 14;

class Token {
  public:
  int tag;
  std::string lexeme;

  Token(int i = 0, std::string const& s = "") : tag(i), lexeme(s) {}
  Token& operator=(Token const& t) {
    tag = t.tag;
    lexeme = t.lexeme;
    return *this;
  }
  void print() const {
    std::cout << "<" << tag << ", " << lexeme << ">" << std::endl;
  }
};

#endif
