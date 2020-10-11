#include <iostream>
#include "test.hpp"
#include <iterator>
#include <list>
 

struct test{
  int clanskiBroj;
  std:: string ime;
};

int main(void){
  // test foo;
  std::vector<int> vec{5,3,76,2,1};
  // std::cout<<vec.size();
  // vector<int>::const_iterator it;
  // it = vec.end(); //kao ovde nema nista
  // auto x = back_inserter(vec);
  // auto y = inserter(vec,begin(vec));
  // *x = 10;
  // *y = 20;
  auto x = vec.begin()+2;
  auto test = vec.erase(vec.begin()+1);
  *test = 4;
  for(auto a:vec) std::cout<<a;
  *x = 5;
  for(auto a:vec) std::cout<<a;
  // cout<<vec.size();
}
