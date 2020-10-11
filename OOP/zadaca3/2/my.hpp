#pragma once
#include <algorithm>
#include <iostream>

namespace my {

auto predicate = [](auto a, auto b) { return a < b; };
template <class Iterator, class UnaryOpt = decltype(predicate)>
void sort(Iterator start, Iterator end, UnaryOpt foo = predicate) {
  for (auto i = start; i != end; ++i)
    for (auto j = i; j != end; ++j) {
      if (!foo(*i, *j)) {
        std::swap(*i, *j);
      }
    }
}
}  // namespace my
