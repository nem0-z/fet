#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main(void) {
  std::string rijec;
  int pocetakSatro;
  std::cout << "Unesi svoje ime" << std::endl;
  std::cin >> rijec;
  pocetakSatro = rijec.find_first_of("aAeEiIoOuU") + 1;
  std::cout << "Tvoje ime na satrovackom je: " << std::endl;
  for (int i = pocetakSatro; i < rijec.size(); ++i) std::cout << rijec[i];
  for (int i = 0; i < pocetakSatro; i++) std::cout << rijec[i];
  return 0;
}
