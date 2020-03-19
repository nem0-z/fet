#include <iostream>
#include <vector>
#include <list>
//zamijeni vrijednosti od pocetka do kraja iteratora sa def value f-je
using namespace std;

template<class InputIt>
void myReplace(InputIt start, InputIt end, const int def = 10)
{
  while(start!=end)
  {
    *start++ = def;
  }
}

int main(int argc, char *argv[])
{
  list<int> lista{5,8,2,7,8,2,6};
  cout<<"Before replace:"<<endl;
  auto it = lista.begin();
  while(it!=lista.end()){
    cout<<*it++<<" ";
  }
  cout<<endl;
  myReplace(lista.begin(),++lista.begin());
  cout<<"After replace:"<<endl;
  auto it1 = lista.begin();
  while(it1!=lista.end()){
    cout<<*it1++<<" ";
  }
  cout<<endl;
  return 0;
}

