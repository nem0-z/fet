#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
template <typename Iter>
void rikverc(Iter begin, Iter end) {
  auto size = 0, tmp = begin;
  while (tmp != end) {
    ++size;
    ++tmp;
  }
  auto middle = size / 2;
  std::cout << middle << std::endl;
  --end;
  for (auto i = 0; i < middle; ++i) {
    std::swap(*begin++, *end--);
  }
}

template <typename ContType, typename Output>
Output& printaj(ContType& cont, Output& output) {
  for (const auto& item : cont) output << item << " ";
  output<<'\n';
  return output;
}

int main(void) {
  // std::vector<int> v{5, 1, 2, 7, 8, 3, 2};
  // printaj(v,std::cout);
  // rikverc(v.begin(),v.end());
  // printaj(v,std::cout);
  // std::list<int> l{5, 8, 2, 1, 2, 2, 10};
  // printaj(l,std::cout);
  // rikverc(l.begin(),l.end());
  // printaj(l,std::cout);
  std::map<int, char> map;
  map[1] = 'a';
  map[2] = 'b';
  map[3] = 'c';
  for(auto it = map.begin(); it!= map.end(); ++it)
  {
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }
  std::reverse(map.begin(),map.end());
  for(auto it = map.begin(); it!= map.end(); ++it)
  {
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }

  return 0;
}
