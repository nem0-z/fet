#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename T>
void mySwap(T& a, T& b)
{
  auto tmp = a;
  a = b;
  b = tmp;
}

template<typename OutputIt>
void myReverse(OutputIt start, OutputIt end)
{
  auto size = 0;
  auto tmpStart = start;
  auto tmpEnd = end;
  while(tmpStart!=tmpEnd){
    size+=*tmpStart;
    ++tmpStart;
  }
  int sredina = size/2;
  --end;
  for(auto bar = 0;bar<sredina; ++bar)
  {
    mySwap(*start,*end);
    ++start;
    --end;
  }
  // for(auto i = start; i!= end; ++i){
  //   for(auto j = i; j!= end; ++j){
  //     mySwap(*i,*j);
  //   }
  //   // for(auto x = start; x!= end; ++x) std::cout<<*x<<" ";
  //   // std::cout<<std::endl;
  // }
  // --end;
  // while(start<end && start!=end)
  // {
  //   mySwap(*start,*end);
  //   ++start;
  //   --end;
  // }
}

template<typename ContType>
void ispisi(std::ostream& output, ContType cont)
{
  for(auto i = cont.begin(); i!= cont.end(); ++i)
    output<<*i<<" ";
  output<<std::endl;
}

int main(void)
{
  std::list<int> l(200000,2);
  ispisi(std::cout,l);
  std::cout<<"\n";
  myReverse(l.begin(),l.end());
  ispisi(std::cout,l);
  // std::string meho{"Mehagaa"};
  // std::cout << meho << std::endl;
  // for(auto i = 0; i<meho.size()/2; ++i)
  // {
  //   std::swap(meho[i],meho[meho.size()-1-i]);
  // }
  // std::cout << meho << std::endl;
  // auto begin = meho.begin();
  // auto end = --meho.end();
  // while(begin!=end && begin<end)
  // {
  //   std::swap(*begin,*end);
  //   ++begin;
  //   --end;
  // }
  // std::cout << meho << std::endl;

  return 0;
}
