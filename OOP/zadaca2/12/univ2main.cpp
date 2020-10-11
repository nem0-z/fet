#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include "univ2.hpp"

int main(void) {
  std::vector<Student> vektorStudenata;
  std::list<Predmet> listaPredmeta;
  while (1) {
    int menu = -1;
    std::cout << "#####MAIN MENU#####\n1.Unos predmeta\n2.Unos studenta"
                 "\n3.Edit studenta\n4.Ispis studenta\n5.Exit\n";
    std::cout << "Vas izbor: ";
    std::cin >> menu;
    if (menu == 1) {
      unosPredmeta(listaPredmeta);
    } else if (menu == 2) {
      unosStudenta(vektorStudenata, listaPredmeta);
    } else if (menu == 3) {
      editStudenta(vektorStudenata, listaPredmeta);
    } else if (menu == 4) {
      printStudenta(vektorStudenata,listaPredmeta);
    } else if (menu == 5) {
      std::cout << "Cao cao!";
      return 1;
    } else {
      std::cout << "Error! Pogresan unos";
    }
  }
  return 0;
}
