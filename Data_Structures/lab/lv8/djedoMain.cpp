#include <iostream>
#include "djedoQueue.hpp"

int main(void)
{
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  std::cout << "Top: " << q.top() << std::endl;
  q.pop();
  std::cout << "Top: " << q.top() << std::endl;
  q.pop();
  std::cout << "Top: " << q.top() << std::endl;
  q.pop();
  std::cout << q.empty() << std::endl;
  return 0;
}
