#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void ispis(int x){
  std::cout << x << std::endl;
}
int kvadrat(const int& x){
  return x*x;
}

int main(int argc, char* argv[]) {
  using namespace std;
  int a = 5;
  int& b = a;
  b = 10;  // napravili referencu na a i promijenili vrijednost u a preko b ref
  const int& c = b;
  b = 20;  // napravio const, nju ne mozes mijenjat ali ono na sta ona
           // referencira mozes np
  ispis(c);
  cout<<kvadrat(c)<<endl;
  // "time ./a.out" pokrene a.out i ispise koliko mu je vremena trebalo za exec
  
  return 0;
}
