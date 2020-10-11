#include <iostream>
#include <list>
#include <vector>

namespace vjezbe12 {
template <typename Iter, typename UnaryOpt>
Iter partition(Iter begin, Iter end, UnaryOpt foo) {
  auto i = begin;
  auto j = end;
  // while (i != j) {
  //   if (j == e) --j;
  //   if (foo(*i)) {
  //     if (foo(*j)) {
  //       --j;
  //       continue;
  //     }
  //     
  //       std::swap(*i, *j);
  //       ++i;
  //       --j;
  //   } else
  //     ++i;
  // }
  for(auto i = begin; i!= end; ++i){
    for(auto j = i; j!=end ; ++j){
      if(foo(*i))std::swap(*i,*j);
    }
  }
    while(--end!=begin){
      if(!foo(*end)) return end;
      else --end;
    }
}
}  // namespace vjezbe12

int main(void) {
  std::list<int> v{2, 6, 1, 3, 7, 8, 3, 2, 15};
  auto lambda = [](int a) { return a%2==0; };
  auto k = vjezbe12::partition(v.begin(), v.end(), lambda);
  std::cout << *k << std::endl;
  for (const auto& x : v) std::cout << x << " ";
  
  return 0;
}

