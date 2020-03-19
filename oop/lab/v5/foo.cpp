#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int printMenu() {
  cin.clear();
  int unos;
  cout << "################\n1 - Unos\n2 - Ispis\n3 - Sortiraj najmanje"
          "\n4 - Sortiraj najvece\n5 - Prosjek\n0 - Izlaz"
          "\nVas unos: ";
  cin >> unos;
  return unos;
}

void input(vector<double>& cont) {
  cout << "Unesite vrijednosti: ";
  for (double unos; cin >> unos;) cont.push_back(unos);
  cin.clear();
  cin.ignore(1000, '\n');
}
void output(const vector<double>& cont) {
  cout << "Elementi vaseg vektora su: ";
  for (auto e : cont) cout << e << " ";
  cout << endl;
}
void sortMin(vector<double> cont) { 
  if (cont.size() >= 3) {
    cout << "Tri najmanje vrijednosti su: ";
    sort(cont.begin(), cont.end());
    for (auto i = 0; i < 3; ++i) cout << cont[i] << " ";
    cout << endl;
  } else
    cout << "Necu ti ovo ni sortirati lol" << endl;
}
void sortMax(vector<double> cont) {
  if (cont.size() >= 3) {
    cout << "Tri najvece vrijednosti su: ";
    sort(cont.begin(), cont.end(), [](int a, int b) { return a > b; });
    for (auto i = 0; i < 3; ++i) cout << cont[i] << " ";
    cout << endl;
  } else
    cout << "Necu ti ovo ni sortirati lol" << endl;
}
void avg(const vector<double>& cont) {
  double suma=0;
  for (auto e:cont) suma+=e;
  cout<< "Prosjek niza je: "<<suma/cont.size()<<endl;
}
int main(void) {
  vector<double> cont;
  while (1) {
    int unos = printMenu();
    if (unos == 1)
      input(cont);
    else if (unos == 2)
      output(cont);
    else if (unos == 3)
      sortMin(cont);
    else if (unos == 4)
      sortMax(cont);
    else if (unos == 5)
      avg(cont);
    else {
      cout << "Dovidjenja";
      return 1;
    }
  }
  return 0;
}
