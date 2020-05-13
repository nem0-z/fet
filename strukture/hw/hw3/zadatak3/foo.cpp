#include <iostream>
#include "queue.hpp"

int main(void)
{
  queue<int> q(10);
  for(int i = 0; i < 10; ++i)
    q.push(i);
  for(int i = 0; i < 10; ++i)
   std::cout <<  q.pop();
  return 0;
}
