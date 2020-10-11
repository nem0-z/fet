#include <functional>
#include <iostream>
#include <list>

using const_list_it = std::list<int>::const_iterator;
using list_inserter = std::front_insert_iterator<std::list<int>>;

template <typename InputIt, typename OutputIt, typename Func>
void transform(InputIt begin, InputIt end, OutputIt destination, Func foo) {
  while (begin != end) {
    *destination = foo(*begin);
    ++begin;
  }
}

int main(void) {
  std::list<int> first{1, 2, 3, 4, 5};
  std::list<int> result{-1, -2};

  transform(first.cbegin(), first.cend(), std::front_inserter(result),
            [](int a) { return a * 2; });

  // Ostali nacini za pozivanje koje treba pokazati:
  transform<const_list_it, list_inserter>(first.cbegin(), first.cend(),
                                          std::front_inserter(result),
                                          [](int a) { return a * 2; });

  // Greska!
  // list_inserter je tipa front_iterator, mi smo proslijedili back_iterator
  //
  // transform<const_list_it, list_inserter>(first.cbegin(), first.cend(),
  //                                         std::back_inserter(result),
  //                                         [](int a) { return a * 2; });

  // Greska!
  // prva dva parametra moraju biti istog tipa
  //
  // transform(first.cbegin(), std::back_inserter(first),
  //           std::front_inserter(result), [](int a) { return a * 2; });

  for (auto it = result.begin(); it != result.end(); ++it)
    std::cout << *it << std::endl;
  return 0;
}
