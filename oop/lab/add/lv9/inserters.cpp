#include <iostream>
#include <list>

using list_it = std::list<int>::iterator;

void ispisi(list_it poc, list_it kraj) {
  while (poc != kraj) {
    std::cout << *poc << " ";
    ++poc;
  }
  std::cout << std::endl;
}

int main(void) {
  std::list<int> a{1, 2, 3, 4, 5};

  std::cout << "Sadrzaj liste na pocetku: " << std::endl;
  ispisi(a.begin(), a.end());

  auto it1 = std::front_inserter(a);
  *it1 = 30;

  std::cout << "Sadrzaj liste nakon koristenja front_inserter: " << std::endl;
  ispisi(a.begin(), a.end());

  auto it2 = std::back_inserter(a);
  *it2 = 100;

  std::cout << "Sadrzaj liste nakon koristenja back_inserter: " << std::endl;
  ispisi(a.begin(), a.end());

  auto it3 = a.begin();
  ++it3;
  ++it3;
  auto it4 = std::inserter(a, it3);
  *it4 = -20;

  std::cout << "Sadrzaj liste nakon koristenja inserter: " << std::endl;
  ispisi(a.begin(), a.end());

  return 0;
}
