#include <iostream>
#include <vector>
#include <list>

namespace metode{
template<class InputIt, class UnaryOpt>
void mySort(InputIt start, InputIt end, UnaryOpt cmp)
{
  for(auto i = start; i!= end; ++i)
    for(auto j = i; j!= end; ++j)
      if(!cmp(*i,*j)) std::swap(*i,*j);
}

template<class ContType,class Key>
void erase(ContType& cont,Key test)
{
  for(auto it = cont.begin(); it!= cont.end();)
    if(*it == test) it = cont.erase(it);
    else ++it;
}


}

int main(int argc, char *argv[])
{
  std::list<int> v{5,2,6,2,7,2};
  // metode::mySort(v.begin(),v.end(),[](auto a, auto b){return a<b;});
  metode::erase(v,2);
  for(const auto& x:v) std::cout << x << std::endl;
  return 0;
}
