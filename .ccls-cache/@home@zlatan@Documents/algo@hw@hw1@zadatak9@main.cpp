#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

namespace zadatak9 {
template <typename T>
bool binarySearch(const std::vector<T>& vec, int lo, int hi, T match) {
  int mid = (hi + lo) / 2;
  // DEBUG
  // sleep(1);
  // std::cout << "Lo: " << lo << std::endl;
  // std::cout << "Mid: " << mid << std::endl;
  // std::cout << "Hi: " << hi << std::endl;
  if (match == vec[lo] || match == vec[hi] || match == vec[mid])
    return true;
  else if (lo > hi)
    return false;
  else if (match < vec[mid])
    return binarySearch(vec, lo, mid - 1, match);
  else
    return binarySearch(vec, mid + 1, hi, match);
  return false;
}

template <typename ForwardIter>
ForwardIter unique(ForwardIter begin, ForwardIter end) {
  if (begin == end) return end;
  auto tmpBegin = begin;
  while (begin != end) {
    ++begin;
    if (!(*tmpBegin == *begin) && ++tmpBegin != begin) {
      *tmpBegin = std::move(*begin);
    }
  }
  return ++tmpBegin;
}
}  // namespace zadatak9

int main(void) {
  std::vector<std::string> words;
  std::ifstream input{"shakespeare.txt"};
  if (!input.is_open()) throw std::invalid_argument("File not found.");
  std::string token;
  int i = 0;
  while (input >> token) {
    words.push_back(token);
  }
  std::sort(words.begin(), words.end());
  auto it = zadatak9::unique(words.begin(), words.end());
  words.erase(it, words.end());
  std::cout << words.size() << std::endl;
  std::string toFind;
  while (true) {
    std::cout << "Enter word: ";
    std::cin >> toFind;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    bool flag = zadatak9::binarySearch(words, 0, words.size() - 1, toFind);
    if (flag)
      std::cout << "Word found!" << std::endl;
    else
      std::cout << "Word not found!" << std::endl;
  }
  // std::vector<int> a{-1023, -23, -2, -1, 0,   2,   7,
  //                    9,     11,  16, 90, 120, 250, 1500};
  // while (true) {
  //   int num;
  //   std::cin >> num;
  //   std::cout << binarySearch(a, 0, a.size()-1, num) << std::endl;
  // }
  return 0;
}
