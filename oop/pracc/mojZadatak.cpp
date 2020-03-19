#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

// uzme listu brojeva i vektor stringova a vraca mapu
// napravi parove u mapi za svaki clan u listi/vektoru
// nek broj bude kljuc a string vrijednost
// ako su velicine liste i vektora razlicite baci out_of_range
// generic function please :) preko iteratora ofc

using namespace std;

template<typename T, typename U>
void checkSize (T brojeviStart, T brojeviEnd, U stringoviStart, U stringoviEnd)
{ 
  int sizeBrojeva=0,sizeStringova=0;
  T test1 = brojeviStart;
  U test2 = stringoviStart;
  while(test1!=brojeviEnd) 
  {
    test1++;
    sizeBrojeva++;
  }
  while(test2!=stringoviEnd) 
  {
    sizeStringova++;
    test2++;
  }
  if(sizeBrojeva!=sizeStringova) throw std::out_of_range("Konjino");
}
template <typename X, typename U, typename T>
X magic(T brojeviStart, T brojeviEnd, U stringoviStart, U stringoviEnd) {
  X mapa;
  checkSize(brojeviStart,brojeviEnd,stringoviStart,stringoviEnd);
  while (brojeviStart!=brojeviEnd)
  {

    mapa[*brojeviStart++] = *stringoviStart++;
  }
  return mapa;
}

int main(int argc, char *argv[]) {
  list<int> lista{1, 54, 8, 3, 8, 43, 74, 2};
  vector<string> vektor{"sinisa", "ciro",  "zlatan", "ajla",
                        "adil",   "hidan", "sljiva", "boris"};
  try{
  auto mapa = magic<map<int, string>>(lista.cbegin(), lista.cend(),
                                      vektor.cbegin(), vektor.cend());
  for (auto x:mapa) cout<<x.first<<"\t"<<x.second<<endl;
  }
  catch(std::out_of_range a)
  {
    std::cout << a.what() << std::endl;
  }
  return 0;
}
