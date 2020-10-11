#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  // korisnik unosi rijeci, nakon toga ispises mu prosjek duzine rijeci
  // ispisi rijeci ispod prosjeka i rijeci iznad prosjeka tih duzina
  std::vector<std::string> rijeci;
  double suma = 0, prosjek;
  std::string unos;
  while (std::cin >> unos) {
    rijeci.push_back(unos);
    suma += unos.size();
  }

  prosjek = suma / rijeci.size();
  std::cout << prosjek << std::endl;
  std::cout << "rijeci duzine ispod prosjeka su" << std::endl;
  for (int i = 0; i < rijeci.size(); i++) {
    if ((rijeci.at(i).size()) < prosjek) std::cout << rijeci.at(i) << std::endl;
  }
  std::cout << "rijeci duzine iznad prosjeka su" << std::endl;
  for (int i = 0; i < rijeci.size(); i++) {
    if ((rijeci.at(i).size()) >= prosjek)
      std::cout << rijeci.at(i) << std::endl;

  }
    return 0;
}
