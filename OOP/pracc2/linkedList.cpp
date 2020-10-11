#include <iostream>

class Node{
  public:
  int value;
  Node* next;
};

int main(void)
{
  Node* start = nullptr; 
  for(auto i = 0; i < 3; ++i)
  {
  Node* ptr = new Node;
  ptr->value = 5;
  ptr->next = nullptr;
  start = ptr;
  }
  auto ptrMove = start;
  while(ptrMove!=nullptr)
  {
    std::cout<<ptrMove->value;
    ptrMove = ptrMove->next;
  }


  return 0;
}

