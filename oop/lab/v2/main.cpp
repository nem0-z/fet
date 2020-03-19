#include <iostream>
namespace s1 {
int a = 10;
namespace s2 {
int b = 20;
}
}  // namespace s1
int a = 50;
using namespace std;
int main(void) {
  bool t = true;
  int e;
  std::cout << sizeof t << std::endl;
  auto y = 5;  // moze i da kazes auto x=5l ili 5i 5d 5ui 5ul (tipovi podataka)
  std::cout << sizeof y << std::endl;
  int i = 5, j = 10;
  auto x = 2 + (++i) + (j++);
  cout << x << i << j << std::endl;
  std::cout << s1::a;
  std::cout << s1::s2::b;
  int a = 30;
  std::cout << a << std::endl;
  std::cout << s1::s2::b << std::endl;
  std::cout << ::a << std::endl;
  cout << "varijabla a je: al ona globalna odozgo: " << ::a << endl;
  // std::cout << "unesi neki broj druze" << std::endl;
  // cin >> e;
  // std::cout << "korisnik je udario: " << e << std::endl;
  if (true) {
    int a = 35;  // kompajler ce prvo trazit varijablu u svom bloku, pa onda
                 // iznad pa onda globalnu
    std::cout << "svaka ti cast legendo izvrsio se if" << a << std::endl;
  } else {
    std::cout << "svaka ti cast legendo izvrsio se else" << std::endl;
  }
  std::cout << "unesi neki broj" << std::endl;
  cin >> e;
  bool z = e % 2;
  if (z)
    std::cout << "broj je neparan" << std::endl;
  else
    std::cout << "broj je paran legendo" << std::endl;
  if((a%2)==0&&(a%3)==0)
  
std::cout << "svaka cast djeljiv je i sa 2 i sa 3" << std::endl;
  auto o=6+8/3*2;
  cout<<o;

  return 0;

}
