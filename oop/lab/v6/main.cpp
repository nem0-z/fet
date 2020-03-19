#include <iostream>
#include <stdexcept>  //out_of_range, invalid_argument - neki od exceptiona
#include <vector>
#include "complex.hpp"
int main(int argc, char *argv[]) {
  using namespace std;
  // try {
  //   throw 5;
  //   cout << "test";
  // } catch (int a) {
  //   cout << a << endl;
  // }
  KompleksanBroj prvi,drugi;
  unos(prvi);
  unos(drugi);
  cout<<(saberi(prvi,drugi)).realni<<" + i"<<(saberi(prvi,drugi)).imaginarni<<endl;
  return 0;

  //napisi da unese dva kompleksna broja pa da ih sabere DZ
}
