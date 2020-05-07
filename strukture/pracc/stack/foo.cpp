#include <iostream>
#include "ArrayStack.hpp"
#include "ListStack.hpp"

using namespace std;

int main(void)
{
  ListStack<int> s; 
  s.push(2);
  s.push(3);
  s.push(4);
  int num = 0;
  s.push(num);
  // s.push(num+1);
  // s.push(num);
  // s.push(num+10);
  // s.push(num-4);
  // s.push(num=35);
  s.print();
  // std::cout << s.top() << std::endl;
  s.pop();
  s.pop();
  s.print();
  cout << s.size() << endl;
  // std::cout << s.top() << std::endl;

  return 0;
}
