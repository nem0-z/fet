#include<iostream>
int main(void)
{
  std::cout << sizeof 5. << std::endl;
  std::cout << sizeof 'a' << std::endl;
  int a=0x27;
  std::cout << a << std::endl;
  a=10+3;
  std::cout << a << std::endl;
  int b=10;
  int d=7;
  int c=d+b;
  std::cout << c << std::endl;
  //pored double ima i float za decimalne samo sto je 4 bajta umjesto 8
  d=a+4*b;
  std::cout << d << std::endl;
  a=4+4*4<<4; //prvo se pomnozi 4*4 pa se sabere sa 4 i onda shifta 4 bita ulijevo =320 
  std::cout << a << std::endl;
  const double pi=3.14;
  double x=4*pi;
  std::cout << x << std::endl;
  int u;  //uninitalized, 
  std::cout << u << std::endl;
  unsigned short z=20000;
  unsigned short y=30000;
  std::cout << sizeof z << std::endl;
  std::cout << sizeof y << std::endl;
  unsigned short o=z+y;
  std::cout << sizeof o << std::endl;
  std::cout << o << std::endl;
  int a1=2.+5+'c'; //promocija-kad prebaci nizi>visi tip podatka; sto se kaze on je promoto (5+'c') u double hahahahhaahahahhahaha
  std::cout << a1 << std::endl;
  auto a2=2.+5+'c';
  std::cout << a2 << std::endl; // ma ista stvar ko gore samo sto auto sam skonta koji je to tip podatka pa mu neces explicitly govorit koji tip podatka da koristi
  auto b1=9/2;
  std::cout << sizeof b1 << std::endl;
  std::cout << b1 << std::endl;
  int a3=2,a4=9;
  auto x1=a4/(double)a3;
  std::cout << x1 << std::endl;
  auto b3=0xA&0x4;  //bezze
  std::cout << b3 << std::endl;
  b=b+5;    //b=10 prije ovoga
  b+=5;     //same thing
  ++b;
  --b;
  b++;
  b--;    //inkrementi i dekrementi
  return 0;

}
