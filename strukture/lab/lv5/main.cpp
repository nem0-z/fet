#include <iostream>
#include "forwardlist.hpp"

int main(int argc, char *argv[]) {
  forward_list<int> moja_lista;

  moja_lista.push_back(10);
  std::cout << moja_lista.front() << std::endl;

  moja_lista.push_back(20);
  std::cout << moja_lista.front() << std::endl;

  if (moja_lista.size() != 0) {
    std::cout << "Broj elemenata: " << moja_lista.size() << std::endl;
    std::cout << moja_lista.front() << std::endl;
  } else {
    std::cout << "Lista je prazna!!" << std::endl;
  }

  moja_lista.push_back(30);
  std::cout << moja_lista.back() << std::endl;

  moja_lista.clear();
  std::cout << "Broj elemenata: " << moja_lista.size() << std::endl;

  std::cout << "Push front: " << std::endl;
  moja_lista.push_front(5);
  moja_lista.push_front(10);
  std::cout << moja_lista.front() << std::endl;
  std::cout << moja_lista.back() << std::endl;

  moja_lista.push_back(5);
  moja_lista.push_back(6);
  moja_lista.push_back(7);
  moja_lista.push_back(8);
  moja_lista.push_back(9);
  moja_lista.push_back(10);

  // default ctor
  forward_list<int> list1;
  // copy ctor
  forward_list<int> list2(moja_lista);
  std::cout << "Copy ctor" << std::endl;
  std::cout << list2.front() << std::endl;
  std::cout << list2.back() << std::endl;

  // move ctor
  std::cout << "Move ctor" << std::endl;
  forward_list<int> list3 = std::move(list2);
  std::cout << list3.front() << std::endl;
  std::cout << list3.back() << std::endl;

  // copy assignment
  std::cout << "Copy assignment: " << std::endl;
  auto list4 = list3;
  std::cout << list4.front() << std::endl;
  std::cout << list4.back() << std::endl;

  // move assignment
  std::cout << "Move assignment: " << std::endl;
  list2 = std::move(moja_lista);
  std::cout << list2.front() << std::endl;
  std::cout << list2.back() << std::endl;

  return 0;
}
