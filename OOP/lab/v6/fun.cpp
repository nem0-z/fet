#include "complex.hpp"
#include <iostream>
using namespace std;

void ispis(const KompleksanBroj& a)
{
  cout<<a.realni<<" + i"<<a.imaginarni<<endl;
}
void unos(KompleksanBroj& a)
{
  cout<<"Unesite realni dio: ";
  cin>>a.realni;
  cout<<"Unesite imaginarni dio: ";
  cin>>a.imaginarni;
}
KompleksanBroj saberi(const KompleksanBroj&  b1, const KompleksanBroj& b2)
{
  KompleksanBroj c;
  c.realni = b1.realni + b2.realni;
  c.imaginarni = b1.imaginarni + b2.imaginarni ; 
  return c;
}
