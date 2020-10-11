#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

typedef vector<double> kontejner;

double median(kontejner lista) {
  sort(begin(lista), end(lista));
  typedef decltype(lista.size()) vec_velicina;
  vec_velicina br_elemenata = lista.size();
  vec_velicina sredina = br_elemenata / 2;
  double rezultat = (br_elemenata % 2 == 0)
                        ? (lista[sredina] + lista[sredina - 1]) / 2
                        : lista[sredina];
  return rezultat;
}

double unos_elemenata_i_racun_prosjeka(kontejner& lista) {
  std::cout << "Unesite elemente u listu: " << std::endl;
  double x;
  double suma = 0.;
  while (cin >> x) {
    lista.push_back(x);
    suma += x;
  }
  if (!lista.size()) {
    cin.clear();
    throw string{"Prazan kontejner!"};
  }

    return suma / lista.size();
}

void ispis_elemenata(const kontejner& lista) {
  for (const auto& e : lista) cout << e << " ";
  cout << endl;
}

int main() {
  kontejner lista1;
  bool test=true;
  while(test)
  {
  try {
    auto p = unos_elemenata_i_racun_prosjeka(lista1);
    auto m = median(lista1);
    cout << "Prosjecna vrijednost:\t" << p << endl;
    cout << "Arit. sredina:\t" << m << endl;
    test = false;
  } catch (const string& e) {
    std::cout << "Greska: " << e << std::endl;
  }
  }
  return 0;
}

