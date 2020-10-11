#include <iostream>
#include <string>
using std::string;

int main(void) {
  string ime;

  std::cout << "unesite ime: " << std::endl;
  std::cin >> ime;
  const string poruka("Pozdrav, " + ime + "!");
  const auto duzina = poruka.size();
  const string prvaZadnja(duzina, 'x');    // okvir skroz gore
  const string drugaCetvrta(duzina, ' ');  // prazna mjestai
  std::cout << "xx" << prvaZadnja << "xx" << std::endl;
  std::cout << "x " << drugaCetvrta << " x" << std::endl;
  std::cout << "x " << poruka << " x" << std::endl;
  std::cout << "x " << drugaCetvrta << " x" << std::endl;
  std::cout << "xx" << prvaZadnja << "xx" << std::endl;

  // probaj ovo sam kod kuce bez da gledas
  // gore smo koristili auto pa nek on skonta hocel short int unsigned blabla
  return 0;
}
