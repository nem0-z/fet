#include <functional>
#include <iostream>
#include <list>
#include <vector>

// using container = std::list<int>;
// probati koristiti vector
using container = std::vector<int>;

template <typename OutputIt>
void ispisi(OutputIt poc, OutputIt kraj) {
  while (poc != kraj) {
    std::cout << *poc << std::endl;
    ++poc;
  }
}

template <typename OutputIt, typename UnaryOperation>
OutputIt pronadji(OutputIt poc, OutputIt kraj, UnaryOperation foo) {
  while (poc != kraj) {
    if (foo(*poc)) {
      return poc;
    }
    ++poc;
  }
  return kraj;
}

int main(void) {
  container a{1, 2, 3, 4, 5};

  ispisi(a.begin(), a.end());

  int unos;
  std::cout << "Unesite broj: ";
  std::cin >> unos;
  auto x = [unos](int x) {return unos == x; };
  auto it = pronadji(a.begin(), a.end(),x);

  if (it != a.end()) {
    std::cout << "Broj se nalazi u listi!" << std::endl;
  } else {
    std::cout << "Broj se ne nalazi u listi!" << std::endl;
  }
  return 0;
}
