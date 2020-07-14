#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

int main(int argc, char *argv[]) {
  char input;
  std::unordered_map<std::string, std::vector<int>> mapa;
  std::stack<std::string> pretrage;
  while (true) {
    std::cout << "Vas izbor: ";
    std::cin >> input;
    if (input == 'l') {
      std::ifstream file("story.txt");
      std::string token;
      int i = 0;
      while (file >> token) {
        mapa[token].push_back(++i);
      }
    } else if (input == 'q') {
      break;
    } else if (input == 's') {
      if (!pretrage.empty()) {
        std::cout << "Zadnja trazena pretraga: " << std::endl;
        std::cout << pretrage.top() << std::endl;
      }

    } else if (input == 'f') {
      std::cout << "Rijec koju trazis: ";
      std::string token;
      std::cin >> token;
      auto pozicije = mapa.find(token);
      if (pozicije == mapa.end()) {
        std::cout << "Nema te rijeci" << std::endl;
      } else {
        std::string info;
        info += "Trazili ste rijec " + pozicije->first +
                " i ona je na pozicijama : ";
        std::cout << "Pozicije te rijeci:" << std::endl;
        for (auto pozicija : pozicije->second) {
          std::cout << pozicija << " ";
          info += std::to_string(pozicija) + ",";
        }
        std::cout << std::endl;
        pretrage.push(info);
      }
    } else {
      std::cout << "bad input" << std::endl;
    }
  }
  return 0;
}
