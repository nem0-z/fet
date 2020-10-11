#include <fstream>
#include <iostream>
#include <string>
#include "stack.hpp"

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    std::cout << "Missing file name!\n" << std::endl;
    return 0;
  }
  std::string filename = argv[1];
  std::cout << "Reading file " << filename << std::endl;
  std::ifstream input{filename};

  if (!input.is_open()) {
    std::cout << "Unable to open file! " << std::endl;
    return 0;
  }

  stack<char> myStack;
  std::string myLine;
  int rows = 0;
  // int cols = 0;
  char current = 0;
  char topOfStack = -1;

  while (getline(input, myLine)) {
    std::cout << "Reading " << ++rows << ".row" << std::endl;
    const int lineSize = static_cast<int>(myLine.size());
    for (int i = 0; i < lineSize; ++i) {
      current = myLine[i];
    }
    // myStack.print();
  }

  // sredi ovo i napravi detekciju greske u fajlu, npr
  // [{,()}] kazes na kojoj liniji se desila greska i koji je karakter
  // nevalidan

  // napraviti kontrolu redoslijeda zagrada, tj da moraju ic redom velika pa
  // srednja pa mala zagrada

  // pogledati kako radi getline tj da citas liniju po liniju a ne char po
  // char

  // sto znaci napravi da radi s nekim fajlom koji ima tonu redova ovih kao
  // patterna

  return 0;
}
