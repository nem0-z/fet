#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
double unosPodatakaIRacunanjeProsjeka(vector<double>& kont) {
  double suma = 0, n = 0;
  cout << "Enter values: ";
  for (double unos; cin >> unos; n++) {
    kont.push_back(unos);
    suma += unos;
  }
if (kont.size() == 0){
  cin.clear();
  cin.ignore(10000,'\n');
  return unosPodatakaIRacunanjeProsjeka(kont);
}

  // if (kont.size() == 0){
    // throw 1;
  // }
  else
    return suma / n;
}

double median(vector<double>& kont) {
  sort(begin(kont), end(kont));
  int sredinaKontejnera = kont.size() / 2;
  if (!(kont.size() % 2))
    return (kont[sredinaKontejnera] + kont[sredinaKontejnera - 1]) / 2;
  else
    return kont[sredinaKontejnera];
}
int main(void) {
  vector<double> kont;
  // try {
    double p = unosPodatakaIRacunanjeProsjeka(kont);
    double m = median(kont);
    cout << "Average: " << p << endl << "Median: " << m << endl;
  // } catch (int e) {
    // cout<<e;
  // }

  return 0;
}
