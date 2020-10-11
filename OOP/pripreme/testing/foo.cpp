#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

template<class T>
auto foo(T a, T b) -> bool
{
  std::cout << 1 << std::endl;
}
void foo( std::string a)
{
  std::cout << 2 << std::endl;
}

// void foo(double a)
// {
//   std::cout << 3 << std::endl;
// }

template<class ajla, class zlatan>
void sinisa(ajla begin, ajla end, zlatan value)
{
  int cnt = 0;
  auto i = begin;
  auto j = --end;
  while(i!=j)
  {
    if(*begin == value) ++cnt;
    ++i;
  }
  int test = 0;
  while(i!=j)
  {
    if(test == cnt) break;
    auto found = std::find(i,j,value);
    if(*found == *j) --j;
    else {
      std::swap(*found,*j);
      i = found;
      ++test;
  }
  }

}

int main(void)
{
  std::vector<int> v{1,8,7,3,5,3};
  sinisa(v.begin(),v.end(),3);
  for(const auto&x:v) std::cout<<x<<" ";
  return 0;
}
