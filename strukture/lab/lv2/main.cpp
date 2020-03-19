#include <algorithm>
#include <iostream>
#include <vector>
#include "niz.hpp"

template <typename T>
using Niz = MojNiz<T>;

int main(int argc, char* argv[]) {
  Niz<int> numbers;

  for (int i = 0; i < 10; i++) {
    numbers.push_back(i);
  }

  // PART 1
  std::cout << "*** PART 1 ***" << std::endl;
  for (auto it = numbers.begin(); it < numbers.end(); ++it) {
    std::cout << *it << std::endl;
  }
  //
  // PART 2
  std::cout << "*** PART 2 ***" << std::endl;
  Niz<int> numbers2;
  numbers2.resize(numbers.size());
  auto source = numbers.begin();
  auto source_end = numbers.end();
  auto destination = numbers2.begin();
  while (source != source_end) {
    *destination++ = *source++;
  }
  for (auto it = numbers2.begin(); it < numbers2.end(); ++it) {
    std::cout << *it << std::endl;
  }

  // prije 0 1 2 3 4 5 6 7 8 9
  // PART 3
  std::cout << "*** PART 3 ***" << std::endl;
  std::partition(numbers2.begin(), numbers2.end(),
                 [](auto element) { return element % 2 == 0; });
  for (auto& element : numbers2) {
    std::cout << element << std::endl;
  }
  // for each petlja koristi iteratore, znaci da bi to uopste koristili
  // moramo implementirati makar begin i end i da iteratori budu atleast forward
  // poslije npr 2 6 4 0 8 5 7 9 3 1 -> relativni poredak moze biti narusen

  // prije 0 1 2 3 4 5 6 7 8 9
  // PART 4
  std::cout << "*** PART 4 ***" << std::endl;
  auto numbers3 = numbers;
  std::stable_partition(numbers3.begin(), numbers3.end(),
                        [](auto element) { return element % 2 == 0; });
  for (auto& element : numbers3) {
    std::cout << element << std::endl;
  }
  // poslije 0 2 4 6 8 1 3 5 7 9 -> cuva relativni poredak

  // PART 5
  std::cout << "*** PART 5 ***" << std::endl;
  auto to_delete = numbers.begin() + 4;
  numbers.erase(to_delete);
  for (auto& element : numbers) {
    std::cout << element << std::endl;
  }
  std::cout << '\n' << std::endl;
  numbers.erase(numbers.begin() + 2, numbers.begin() + 4);
  for (auto& element : numbers) {
    std::cout << element << std::endl;
  }

  return 0;
}
