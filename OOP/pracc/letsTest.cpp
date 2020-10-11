#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
int foo(int a) { return a + 5; }

int main(void) {
  using namespace std;
  string x(10, 'c');
  try {
    cout << x.size() << endl;
    const int a = 20;
    auto b = a;
    cout << b;

  } catch (...) {
    cout << 1;
  }
  function<char(double)> f;
  f = foo;
  auto res = f('a');
  cout << endl << res << endl;

  struct klasa {
    string ime;
    string prezime;
    int brGodina;
  };

  klasa a;
  a.ime = "boris";
  a.brGodina = 7;

  cout << a.ime << endl << a.brGodina << endl;
  string a1;
  getline(cin,a1);
  cout<<a1;
  return 0;
}
