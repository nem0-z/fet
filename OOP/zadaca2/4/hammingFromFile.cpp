#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::string;
int hamming(const string& s1, const string& s2) {
  short hamming = 0;
  for (auto i = 0; i < s2.size(); ++i) {
    if ((s1[i] == (s2[i] + 32) || (s1[i] == (s2[i] - 32)))) continue;
    if (s1[i] != s2[i]) ++hamming;
  }
  return hamming;
}

void keyHamming(const std::vector<string>& dictionary,
                std::vector<string>& cont) {
  string key;
  std::cout << "Insert a word: ";
  std::cin >> key;
  for (auto i = 0; i < dictionary.size(); ++i) {
    if ((dictionary[i]).size() == key.size())
      if ((hamming(dictionary[i], key)) < 2) cont.push_back(dictionary[i]);
  }
  if (!(cont.size())) {
    std::cout << "Couldn't find words with distance less than 2! " << std::endl;
    throw 1;
  }
  auto criteria = [&key](string s1, string s2) {
    return hamming(s1, key) < hamming(s2, key);
  };
  std::cout << "Result: " << std::endl;
  std::sort(cont.begin(), cont.end(), criteria);
  for (auto e : cont) std::cout << e << std::endl;
}

int main(void) {
  std::ifstream dictionaryFile("words.txt");
  std::vector<string> dictionary;
  std::vector<string> cont;
  string word;
  while (dictionaryFile >> word) dictionary.push_back(std::move(word));
  try {
    keyHamming(dictionary, cont);
  } catch (int i) {
    return i;
  }
  return 0;
}
