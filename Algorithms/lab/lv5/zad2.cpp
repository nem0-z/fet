#include <iostream>
#include <map>
#include <vector>

// student krene u radnju sa nekim iznosom novca n i napravi
// racun od m KM. od kasirke zatrazi da mu vrati kusur sa sto manje novcanica.
// za kusur se koriste apoeni od 10,5,2 i 1 KM. napisati program koji racuna
// najmanji broj novcanica koje student dobije kao kusur.

const int apoeni[] = {10, 5, 2, 1};

int broj_novcanica(int kusur) {
  // prvi nacin ako je broj negativan, vratiti natrag ogroman pozitivan broj
  // i ovo rjesenje se nece uzet u obzir

  // if (kusur < 0) {
  //   return 1000000;
  // }

  if (kusur == 0) return 0;  // ovo je ono kad nemamo kusura znaci taman na 0

  int min = 100000;
  for (auto a : apoeni) {
    // drugi nacin obezbijediti da se nece pozvati fja sa negativnim brojem
    if (kusur >= a) min = std::min(broj_novcanica(kusur - a), min);
  }
  return min + 1;  // dont get this
}

int lookup_table[200000];
int broj_novcanica_m(int kusur) {
  if (kusur == 0) return 0;  // ovo je ono kad nemamo kusura znaci taman na 0
  if (lookup_table[kusur] != 0) return lookup_table[kusur];

  int min = broj_novcanica_m(kusur - 1);
  for (auto a : apoeni) {
    if (kusur >= a) min = std::min(broj_novcanica_m(kusur - a), min);
  }
  lookup_table[kusur] = min + 1;
  return min + 1;
}

int broj_novcanica_dp(int kusur) {
  std::vector<int> table;
  table.resize(kusur + 1);

  table[0] = 0;

  for (int i = 1; i <= kusur; ++i) {
    int min = table[i - 1];
    for (auto a : apoeni) {
      if (kusur >= a) min = std::min(table[i - a], min);
    }
    table[i] = min + 1;
  }
  return table[kusur];
}

int main(void) {
  int kusur;
  std::cout << "Unesite kusur: ";
  std::cin >> kusur;
  std::cout << broj_novcanica_dp(kusur) << std::endl;
  return 0;
}
