#include <iostream>
#include <string>
#include <vector>
#include "Radnik.hpp"
#include "Baza.hpp"

int main(void) {
  BazaRadnika b1;
  b1.ucitaj(std::cin);
  if (b1.izbrisi_radnika("Adil")) {
    std::cout << "Adil izbrisan" << std::endl;
  } else {
    std::cout << "Brisanje nije moguce!" << std::endl;
  }
  std::cout << "U bazi su: " << std::endl;
  b1.ispisi(std::cout);
  std::cout << "Prosjek plata iznosi: " << b1.prosjekPlata() << std::endl;
  std::cout << "Prosjek godina iznosi: " << b1.prosjekGodina() << std::endl;
  return 0;
}
