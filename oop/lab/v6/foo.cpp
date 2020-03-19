#include <functional>
#include <iostream>
#include <string>
#include <vector>
void ispisi(bool a) { std::cout << "fun1\n"; }
void ispisi(char a) { std::cout << "fun2\n"; }

int saberi(int a = 25, int b = 5) { return a + b; }
void izmijeni(std::vector<int>& x, std::function<int(int)> fun) {
  for (auto& a : x)
    a = fun(a);  // mora auto& da ne bi pravio kopije od ref vektora slucajno,
                 // neces nista postici
}
int main(int argc, char* argv[]) {
  int x = 5, y = 10;
  std::string s = "zlatan";
  std::cout << saberi() << "\n";
  auto saberi = [](int a, int b) { return a + b; };
  std::cout << saberi(5, 10) << "\n";
  auto foo = [x, &y](int a) mutable {  //[1]
    std::cout << a << std::endl << x << std::endl << y << std::endl;
    ++x;
  };
  // pazi sta ce biti kad uzima po kopiji ili po referenci
  // lambda moze mijenjati neku vrijednost a da izvan nje ostane ista
  // ono sto je proslijedjeno po kopiji ne mozes edit (unless mutable) [1]
  foo(5);
  std::function<void(int)> funkcija;
  funkcija = foo;  // ako ovaj foo ipak vraca nesto a specificirano je void
                   // povratno, ipak ce proc, why????, a: zavisno od kompajlera
  funkcija(30);
  std::vector<int> vect{1, 2, 3, 4, 5};
  izmijeni(vect, [](int a) { return a * 2; });
  for (auto a : vect) std::cout << a << std::endl;
  return 0;
}

