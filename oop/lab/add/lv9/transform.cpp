#include <functional>
#include <iostream>
#include <list>

using const_list_it = std::list<int>::const_iterator;
using list_inserter = std::front_insert_iterator<std::list<int>>;

void transform(const_list_it begin, const_list_it end, list_inserter destination, 
               std::function<int(int)> foo) {
  while (begin != end) {
    *destination = foo(*begin);
    ++begin;
  }
}

int main(void) {
  std::list<int> first{1, 2, 3, 4, 5};
  std::list<int> result{-1,-2};

  transform(first.cbegin(), first.cend(), std::front_inserter(result),
            [](int a) { return a * 2; });

  for(auto it = result.begin(); it != result.end(); ++it)
    std::cout << *it << std::endl;
  return 0;
}
