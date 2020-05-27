#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class TextAnalyser {
  public:
  void getFile(const std::string &filename = "story.txt");
  void printFile() const;

  private:
  std::map<std::string, std::vector<int>> words_;
  int pos_ = 0;
  void mapInput(std::ifstream &, std::string &);
  void printPositions(const std::vector<int> &) const;
};
