#include "words.hpp"

void TextAnalyser::getFile(const std::string &filename) {
  std::ifstream input(filename);
  std::string token;
  if (input.is_open())
    mapInput(input, token);
  else
    std::cout << "File not found" << std::endl;
}
void TextAnalyser::printFile() const {
  for (auto it = words_.begin(); it != words_.end(); ++it) {
    std::cout << "Rijec je " << it->first << " i nalazi se na pozicijama: \n";
    printPositions(it->second);
  }
}

void TextAnalyser::mapInput(std::ifstream &input, std::string &token) {
  while (input >> token) words_[token].push_back(pos_++);
}
void TextAnalyser::printPositions(const std::vector<int> &positions) const {
  for (const auto &item : positions) std::cout << item << " ";
  std::cout << std::endl;
}
