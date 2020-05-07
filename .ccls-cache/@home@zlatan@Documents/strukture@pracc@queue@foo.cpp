#include <iostream>
#include "ArrayQueue.hpp"
#include "ListQueue.hpp"

using namespace std;

int main(void)
{
  ListQueue<int> s; 
  s.push(2);
  s.push(3);
  s.print();
  s.push(4);
  int num = 5;
  s.push(num);
  s.push(num+1);
  // s.push(num);
  s.push(num+2);
  s.push(num+3);
  s.push(num+4);
  s.print();
  // // std::cout << s.top() << std::endl;
  s.pop();
  s.pop();
  s.print();
  s.push(num);
  s.push(num);
  // s.push(num);
  s.print();
  ListQueue<int> d = s;
  d.print();

  // cout << s.size() << endl;
  // std::cout << s.top() << std::endl;

  return 0;
}
