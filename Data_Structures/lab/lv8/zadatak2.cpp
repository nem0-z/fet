#include <iostream>
#include <string>
#include <fstream>

#include "stack.hpp"

int main(int argc, char *argv[]) {


  std::cout << "Argumenti main fukcije" << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << std::endl;
  }

  std::string filename = argv[1];

  std::cout << "Opening file " << filename << std::endl;
  std::ifstream ulaz{filename};

  if (!ulaz.is_open()) {
    std::cout << "File ne postoji." << std::endl;
    return 0;
  }

  Stack<char> zagrade;

  char c;
  while (ulaz >> c) {
    if (c == '{' || c == '[' || c == '(') {
      std::cout << "Push: " << c << std::endl;
      zagrade.push(c);
    } else if (c == '}') {
      if (zagrade.top() == '{') {
        std::cout << "Pop: " << c << std::endl;
        zagrade.pop();
      } else
        break;
    } else if (c == ']') {
      if (zagrade.top() == '[') {
        std::cout << "Pop: " << c << std::endl;
        zagrade.pop();
      } else
        break;

    } else if (c == ')') {
      if (zagrade.top() == '(') {
        std::cout << "Pop: " << c << std::endl;
        zagrade.pop();
      } else
        break;
    }
  }

  if (zagrade.empty()) {
    std::cout << "Ispravno formatiranje." << std::endl;
  } else {
    std::cout << "Neispravno formatiranje." << std::endl;
  }
  ulaz.close();

  return 0;
}
