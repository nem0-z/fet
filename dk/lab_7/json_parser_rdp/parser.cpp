#include "parser.h"

#include <iostream>
#include <string>
#include <vector>

#include "token.hpp"

using namespace std;
/*
 * Gramatika iz fajla rules.txt
 */

Parser::Parser(std::vector<Token> const& t)
    : tokens(t), bufferLength(t.size()) {}

// start of parsing
bool Parser::parse() {
  currentIndex = 0;

  bool retval = Start();

  if (currentIndex < bufferLength) retval = false;
  return retval;
}

// first production rule
// TODO this should match json object
bool Parser::Start() {
  cout << currentIndex << " start" << endl;
  // TODO match here
  return terminal(OPENBRACES) && pairs() && terminal(CLOSEDBRACES);
  /* return false; */
  //
}

bool Parser::terminal(int t) {
  if (currentIndex >= bufferLength) return false;
  bool x = (t == tokens[currentIndex].tag);
  if (x == true) currentIndex++;
  return x;
}

bool Parser::pairs() {
  cout << currentIndex << " pairs" << endl;
  // TODO make recursive list parser here
  return pair() && pairs_tail();
  /* return false; */
  // NOTE: look at pairs_tail as well
}

bool Parser::pair() {
  cout << currentIndex << " pair" << endl;
  // TODO pair parser key : value
  return terminal(STRING) && terminal(COLON) && value();
  /* return false; */
  //
}

bool Parser::epsilon() {
  cout << currentIndex << " epsilon" << endl;
  return true;
}

bool Parser::pairs_tail() {
  cout << currentIndex << " pairs tail" << endl;
  // TODo
  auto backtrackIndex = currentIndex;
  return (terminal(COMMA) && pairs()) ||
         (currentIndex = backtrackIndex, epsilon());
  /* return false; */
  //
}

bool Parser::value() {
  cout << currentIndex << " value" << endl;
  // TODO add other values here
  auto backtrackIndex = currentIndex;
  //dodati backtracking
  return terminal(NUMBER) || terminal(STRING) || terminal(TRUE) ||
         terminal(FALSE) || terminal(NULLABLE) || array() || Start();
}

bool Parser::array() {
  return terminal(OPENBRACKET) && elements() && terminal(CLOSEDBRACKET);
}

bool Parser::elements() {
  auto backtrackIndex = currentIndex;
  return (value() && elements_tail()) || (currentIndex = backtrackIndex, epsilon());
}

bool Parser::elements_tail() {
  auto backtrackIndex = currentIndex;
  return (terminal(COMMA) && elements()) || (currentIndex = backtrackIndex, epsilon());
}
