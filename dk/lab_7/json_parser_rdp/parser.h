#ifndef _PARSER_
#define _PARSER_

#include "token.hpp"
#include <string>
#include <vector>

class Parser {
public:
  std::vector<Token> tokens;
  int currentIndex = 0;
  int bufferLength = 0;

  Parser(std::vector<Token> const &);
  bool parse();
  bool epsilon();
  bool terminal(int t);
  bool Start();
  bool pairs();
  bool pair();
  bool pairs_tail();
  bool value();
  bool array();
  bool elements();
  bool elements_tail();
};

#endif
