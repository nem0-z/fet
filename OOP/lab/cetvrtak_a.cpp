/*
Napisati program prema sljedećim specifikacijama:
-Pri pokretanju, program očekuje unos cijelih brojeva od korisnika. Unos se vrši
kroz funkciju insert, čiji je dio implementiran, ali je potrebno dodati
validaciju unosa. Ako korisnik ne unese nijedan broj, funkcija treba baciti
iznimku sa porukom “Prazan unos”, koja se treba ispisati na mjestu tretiranja
iznimke. -Napisati funkciju none_of koja kao parametre uzima dva iteratora te
lambda izraz koji definiše neki uslov. Funkcija vraća vrijednost true samo ako
nijedan od elemenata iz kolekcije ograničene proslijeđenim iteratorima ne
zadovoljava dati uslov.
- Lambda izraz koji će se proslijediti kao argument funkciji none_of treba
provjeriti da li je vrijednost parametra veća od ukupnog broja elemenata u
kolekciji.
- U funkciji main, pozvati funkciju za unos, definisati prethodno opisani lambda
izraz te pozvati funkciju none_of. U ovisnosti od povratne vrijednosti funkcije
ispisati odgovarajuću poruku (sadržaj string-a all ili one). Obavezno tretirati
iznimke.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <string>
template<typename ContainerType>
void insert(ContainerType& cont)
{
  int input;
  while(std::cin>>input)
  {
    cont.push_back(input);
  }
  if(!cont.size()) throw std::domain_error("Prazan unos!\n");
}

bool none_of(std::vector<int>::iterator start, std::vector<int>::iterator end,
    std::function<bool(int)> lambda)
{
    while(start!=end)
    {
      if(lambda(*start++)) return false;
    }
    return true;
}

int main(void)
{
  std::vector<int> vec{};
  const std::string all = "1";
  const std::string one = "0";
  try
  {
  insert(vec);
  auto lambda = [vec](int a){
    return a>vec.size();
  };
  auto x = none_of(vec.begin(),vec.end(),lambda);
  if (x) std::cout << all << std::endl;
  else std::cout << one << std::endl;
  }
  catch(std::domain_error x)
  {
    std::cout << x.what() << std::endl;
  }
  return 0;
}
