#include <iostream>
#include <vector>
#include "Lista.hpp"

int main(int argc, char* argv[]) {
  V12::Lista<int> lista1;
  std::cout << "Ispisivanje prazne liste: " << std::endl;
  lista1.print();

  std::cout << "\nDodavanje 5 na kraj liste" << std::endl;
  lista1.push_back(5);
  lista1.print();

  std::cout << "\nDodavanje 10 na kraj liste" << std::endl;
  lista1.push_back(10);
  lista1.print();

  std::cout << "\nDodavanje 17 na kraj liste" << std::endl;
  lista1.push_back(17);
  lista1.print();

  std::cout << "Copy iz vektora" << std::endl;
  std::vector<double> s{1,2,3,4,5,100};
  lista1 = s;
  lista1.print();

  // std::cout << "Operator + sa vektorom" << std::endl;
  // auto lista2 = lista1 + s;
  // std::cout << "Rezultat:" << std::endl;
  // lista2.print();
  

}
