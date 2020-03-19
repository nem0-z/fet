#include <iostream>
#include <iterator>
#include <list>

std::list<int> sort(std::list<int>::const_iterator a, std::list<int>::const_iterator b) {
  //dovoljno je const_iterator jer se koristi samo za
  //citanje vrijednosti na koje pokazuje i pomjeranje po listi iz main()
  std::list<int> lista;
  std::list<int> tmp;
  for (auto at = a; at != b; ++at) {
    if ((*at) % 2) lista.push_back(*at);
    else tmp.push_back(*at);
  }
  lista.splice(std::end(lista),tmp);
  return lista;
}
int main(void) {
  int x;
  std::list<int> numbers;
  while (std::cin >> x) numbers.push_back(x);
  numbers = sort(std::begin(numbers), std::end(numbers));
  for (auto e : numbers) std::cout << e << " ";
  return 0;
}
