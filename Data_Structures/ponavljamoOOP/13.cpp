#include <iostream>
#include <string>

using namespace std;

struct prevoznoSredstvo {
  size_t seats{};
  double fuel{};
  double potrosnja(double);
};

struct avion : prevoznoSredstvo {
  size_t prozori{};
  string fuelV{"Kerozin xD"};
};

double prevoznoSredstvo::potrosnja(double kilometraza) {
  return fuel * 100 / kilometraza;  // this is so random but doesn't matter atm
}

void listAvijon(const avion& plane) {
  cout << plane.seats << " " << plane.fuel << " " << plane.prozori << " "
       << plane.fuelV << endl;
}

int main(void) {
  prevoznoSredstvo avdiA8;
  prevoznoSredstvo avdiA6{4, 300};
  avion A380;
  listAvijon(A380);
  auto consumption = A380.potrosnja(500);
  cout << consumption << endl;
  return 0;
}
