#include <stdlib.h>

#include <cctype>
#include <iostream>
#include <string>

#define INVALID 0
#define WS 1
#define ID 2
#define INTEGER 3
#define KEYWORD 4
#define OPERATOR 5

struct Token {
  int tag;
  std::string lexeme;

  bool operator!() { return tag != 0; }
  explicit operator bool() { return tag; }
};

const char* TagToString(int tag) {
  switch (tag) {
    case WS:
      return "whitespace";
    case ID:
      return "itentifikator";
    case INTEGER:
      return "integer";
    case KEYWORD:
      return "keyword";
    case OPERATOR:
      return "operator";
  }
  return "unknown";
}

struct InputBuffer {
  std::string text;
  int lexemeBegin = 0;
  int currentPosition = 0;

  InputBuffer(std::string const& input) : text(input) {}

  char peekNext() { return text[currentPosition]; }
  char getNext() { return text[currentPosition++]; }
  bool notEmpty() const { return currentPosition < text.size(); }
  size_t consumedLength() { return currentPosition - lexemeBegin; }
  void getReady() { lexemeBegin = currentPosition; }
  std::string getLexeme() const {
    return std::string(text, lexemeBegin, currentPosition - lexemeBegin);
  }
  void backtrack() { currentPosition = lexemeBegin; }
};

// regex: \s+
Token getWs(InputBuffer& buf) {
  buf.getReady();
  while (buf.peekNext() == ' ') {
    buf.getNext();
  }
  if (buf.consumedLength()) {
    return Token{WS};
  }
  return Token{0};
}

// regex: alpha alnum*
Token getId(InputBuffer& buf) {
  buf.getReady();
  if (isalpha(buf.peekNext())) {
    buf.getNext();
    while (isalnum(buf.peekNext())) {
      buf.getNext();
    }
    return Token{ID, buf.getLexeme()};
  }
  return Token{0};
}

// regex: else
Token getElse(InputBuffer& buf) {
  buf.getReady();
  if (buf.getNext() == 'e' && buf.getNext() == 'l' && buf.getNext() == 's' &&
      buf.getNext() == 'e') {
    return Token{KEYWORD, buf.getLexeme()};
  }
  buf.backtrack();
  return Token{0};
}

// regex: if
Token getIf(InputBuffer& buf) {
  buf.getReady();
  if (buf.getNext() == 'i' && buf.getNext() == 'f') {
    return Token{KEYWORD, buf.getLexeme()};
  }
  buf.backtrack();
  return Token{0};
}

// regex: if | else
Token getKeyword(InputBuffer& buf) {
  // auto ifToken = getIf(buf);
  // if (ifToken)
  //   return ifToken;
  // else
  //   return getElse(buf);

  // We need Elvis Operator
  return (getIf(buf) ?: getElse(buf));
}

// regex: isdigit+
Token getInteger(InputBuffer& buf) {
  buf.getReady();
  while (isdigit(buf.peekNext())) {
    buf.getNext();
  }
  if (buf.consumedLength()) {
    return Token{INTEGER, buf.getLexeme()};
  }
  return Token{0};
}

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    InputBuffer buf(line);

    while (buf.notEmpty()) {
      Token t;

      if ((t = getWs(buf)).tag == WS) {
        std::cout << "Prepoznat " << TagToString(t.tag) << ": " << t.lexeme
                  << std::endl;
      } else if ((t = getInteger(buf)).tag == INTEGER) {
        std::cout << "Prepoznat " << TagToString(t.tag) << ": " << t.lexeme
                  << std::endl;
      } else if ((t = getKeyword(buf)).tag == KEYWORD) {
        std::cout << "Prepoznat " << TagToString(t.tag) << ": " << t.lexeme
                  << std::endl;
      } else if ((t = getId(buf)).tag == ID) {
        std::cout << "Prepoznat " << TagToString(t.tag) << ": " << t.lexeme
                  << std::endl;
      } else {
        std::cout << "nije poznat tag" << std::endl;
      }
    }
  }
  return 0;
}
