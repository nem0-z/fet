#include <iostream>
#include <string>

using std::string;

void ispisiText() { std::cout << "Hello world" << std::endl; }

void ispisiJednuVarijablu(int a) { std::cout << "a = " << a << std::endl; }

void ispisiTextIVarijablu(string text, double varijabla) {
  std::cout << text << varijabla << std::endl;
}

int dohvatiBroj() {
  int unos;
  std::cout << "Unesite broj: ";
  std::cin >> unos;
  return unos;
}

void izmjeniKopiju(int x) {
  x *= 2;
  std::cout << "U funkciji x = " << x << std::endl;
  return;
}

void izmjeniReferencu(int& x) {
  x *= 2;
  std::cout << "U funkciji x = " << x << std::endl;
  return;
}

int main(void) {
  ispisiText();
  ispisiJednuVarijablu(20);

  string text = "Vrijednost je: ";
  double x = 100.23;
  ispisiTextIVarijablu(text, x);

  auto var = dohvatiBroj();
  std::cout << "Korisnik je unio: " << var << std::endl;

  int var2 = 50;

  izmjeniKopiju(var2);
  std::cout << "Nakon poziva funkcije izmjeniKopiju(), var2 = " << var2
            << std::endl;

  izmjeniReferencu(var2);
  std::cout << "Nakon poziva funkcije izmjeniReferencu(), var2 = " << var2
            << std::endl;

  return 0;
}
