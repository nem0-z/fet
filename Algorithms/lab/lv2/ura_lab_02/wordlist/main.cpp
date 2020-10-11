#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std::chrono;

// TODO to prepare the vector for data analysis
// you may need the following std algorithms
// std::binary_search
// std::sort
// std::unique
// std::vector::erase

int main() {
  std::vector<std::string> words;
  std::ifstream fin{"shakespeare.txt"};
  std::string input;
  while (fin >> input) {
    words.push_back(input);
  }
  std::sort(words.begin(), words.end());
  std::cout << "loading " << words.size() << " words..." << std::endl;
  auto it = std::unique(words.begin(), words.end());
  words.erase(it, words.end());
  std::cout << "loading " << words.size() << " words..." << std::endl;

  std::cout << "Loading the file has finished." << std::endl;
  std::cout << "Enter word:" << std::endl;

  while (std::cin >> input) {
    std::cout << "Word: " << input << std::endl;

    auto now = std::chrono::system_clock::now();
    // benchmark
    auto found = std::binary_search(words.begin(), words.end(), input);
    // auto found = it != words.end();
    //
    auto elapsed = std::chrono::system_clock::now() - now;

    if (found) {
      std::cout << "Words exists in dictionary" << std::endl;
    } else {
      std::cout << "Words does not exists in dictionary" << std::endl;
    }
    std::cout << "Duration: " << elapsed.count() << " ns" << std::endl;
    std::cout << "Duration: " << duration_cast<milliseconds>(elapsed).count()
              << " ms" << std::endl;
  }
}
