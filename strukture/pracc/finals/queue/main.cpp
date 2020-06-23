#include <iostream>
#include "queue.hpp"

int main(int argc, char *argv[])
{
  queue<int> q;
  q.enqueue(5);
  q.enqueue(18);
  q.enqueue(3);
  q.enqueue(20);
  std::cout << q.front() << std::endl;
  // std::cout << q.size() << std::endl;
  q.dequeue();
  std::cout << q.front() << std::endl;
  // std::cout << q.size() << std::endl;
  return 0;
}
