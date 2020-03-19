#include <iostream>
#include <vector>
#include <string>

template<typename Iter,typename lambda>
void mojSort(Iter b, Iter e, lambda cmp)
{
  for(auto i = b; i!= e; ++i)
    for(auto j = i; j!= e; ++j)
     if(cmp(*j,*i)) std::swap(*i,*j);
}

int main(int argc, char *argv[])
{
  std::vector<int> v{2,6,8,1,-5,2,76,0};
  // std::string v{"sinishajebote"};
  mojSort(v.begin(),v.end(),[](int a, int b){return a<b;});
  for(const auto& x:v) std::cout<<x<<" ";
  std::cout << std::endl;
  return 0;
}
