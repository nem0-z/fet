#include <iostream>
#include <list>
#include <functional>

using list_it = std::list<int>::iterator;

void ispisi(list_it poc, list_it kraj) {
  while (poc != kraj) {
    std::cout << *poc << std::endl;
    ++poc;
  }
}

list_it pronadji(list_it poc, list_it kraj, std::function<bool(int)> foo) {
  while (poc != kraj) {
    if (foo(*poc)) {
      return poc;
    }
    ++poc;
  }
  return kraj;
}

int main(void) {
  std::list<int> a{1, 2, 3, 4, 5};

  ispisi(a.begin(), a.end());

  int unos;
  std::cout << "Unesite broj: ";
  std::cin >> unos;

  auto it = pronadji(a.begin(), a.end(), [unos](int x) { return unos == x; });

  if (it != a.end()) {
    std::cout << "Broj se nalazi u listi!" << std::endl;
  } else {
    std::cout << "Broj se ne nalazi u listi!" << std::endl;
  }
  return 0;
}
