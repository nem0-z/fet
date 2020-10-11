#include <functional>
#include <iostream>
#include <list>
#include <vector>

template <typename InputIt, typename OutputIt, typename Func>
void transform(InputIt begin, InputIt end, OutputIt destination, Func foo) {
  while (begin != end) *destination = foo(*begin++);
}

template <class OutputIt>
void ispisi(OutputIt start, OutputIt end) {
  while (start != end) std::cout << *start++ << std::endl;
}

int main(int argc, char *argv[]) {
  std::list<int> lista{1, 2, 3, 4, 5};
  std::vector<int> vektor{6, 7, 8, 9, 10};
  std::list<int> result{-1, -2};
  auto pred = [](int x) { return x * 2; };
  transform(lista.cbegin(), lista.cend(),
                                            std::back_inserter(result), pred);
  ispisi(result.begin(), result.end());

  return 0;
}
