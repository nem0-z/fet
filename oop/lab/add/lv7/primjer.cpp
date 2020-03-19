#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int meni() {
  std::cout << "1 - Unos temperatura" << std::endl;
  std::cout << "2 - Ispis temperatura" << std::endl;
  std::cout << "3 - Ispis 3 najmanje temperature" << std::endl;
  std::cout << "4 - Ispis 3 najvece temperature" << std::endl;
  std::cout << "5 - Ispis prosjecne temperature" << std::endl;
  std::cout << "0 - Izlaz" << std::endl;

  int unos;
  std::cout << "Vas odabir: ";
  std::cin >> unos;
  return unos;
}

// Prvi nacin je bio:
// vector<double> unesi_temperature(){
//   vector<double> rezultat;
//   double unos;
//   std::cout << "Unesite temperature, Ctrl + D za prekid:" << std::endl;
//   while(std::cin >> unos){
//     rezultat.push_back(unos);
//   }
//   std::cin.clear();
//   return rezultat;
// }

void unesi_temperature(vector<double>& rezultat) {
  double unos;
  std::cout << "Unesite temperature, Ctrl + D za prekid:" << std::endl;
  while (std::cin >> unos) {
    rezultat.push_back(unos);
  }
  std::cin.clear();
}

void ispisi_temperature(const vector<double>& temperature) {
  for (auto item : temperature) {
    std::cout << item << std::endl;
  }
}

// Ukoliko funkciju napisemo da prima vector<double> po referenci, mijenjamo
// vector koji se nalazi u main-u. To znaci da ce naredni ispis biti sortiran.
//
// Ukoliko je zahtjev da ispis bude u redoslijedu kako je vrsen unos, onda je
// jedini nacin za to raditi po kopiji. U tom slucaj use vector iz funkcije main
// kopira u funkciju ispisi_tri_najmanje i sortira se kopija unutar funkcije dok
// originalna vrijednost ostaje nepromjenjena.
void ispisi_tri_najmanje(vector<double>& temperature) {
  sort(temperature.begin(), temperature.end());
  auto kraj = temperature.size() >= 3 ? 2 : temperature.size() - 1;
  for (int i = 0; i <= kraj; ++i) {
    std::cout << temperature[i] << std::endl;
  }
}

int main(void) {
  vector<double> temperature;

  while (true) {
    int izbor = meni();
    if (izbor == 1) {
      // prvi nacin je bio:
      // temperature = unesi_temperature();
      unesi_temperature(temperature);
    } else if (izbor == 2) {
      ispisi_temperature(temperature);
    } else if (izbor == 3) {
      ispisi_tri_najmanje(temperature);
    } else if (izbor == 4) {
      // TODO:
      // ispisi_tri_najvece();
    } else if (izbor == 5) {
      // TODO
      // ispisi_prosjecnu_temperaturu();
    } else if (izbor == 0) {
      std::cout << "Dovidjenja!" << std::endl;
      break;
    } else {
      std::cout << "Pogresan unos!" << std::endl;
    }
  }
  return 0;
}
