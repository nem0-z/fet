#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

int main(void) {
  vector<int> brojevi;
  brojevi.push_back(23);
  brojevi.push_back(21);
  // std::cout << brojevi.size() << std::endl;
  // std::cout << brojevi.at(1) << std::endl;
  for (int i = 0; i < brojevi.size(); i++) {
    std::cout << brojevi.at(i) << std::endl;
  }
  vector<int> brojevi1{2, 5, 10};
  for (int i = 0; i < brojevi1.size(); i++) {
    std::cout << brojevi1.at(i) << std::endl;
  }
  // vektor.size(), vektor.push_back() vektor.at()
  // vektor.empty() - vraca bool
  // vektor.front() vektor.back() - prvi/zadnji clan vektora
  // vektor.erase() - brise sve logically
  // vektor.pop_back() - brise zadnji element
  for (int item : brojevi) {
    std::cout << item << std::endl;
  }  // primjer for each petlje

  // unosi brojeve u vektor dok ne unese ctrl+D
  int broj;
  vector<int> kontejner;
  std::cout << "Unesi brojeve, ctrl+D za prekid" << std::endl;
  while (std::cin >> broj) {
    kontejner.push_back(broj);
  }

  for (int i = 0; i < kontejner.size(); i++) {
    std::cout << "Vrijednost " << i << "."
              << " elementa je " << kontejner[i] << std::endl;
  }

  std::sort(kontejner.begin(), kontejner.end()); //sortiraj

  for (int i = 0; i < kontejner.size(); i++) {
    std::cout << "Vrijednost " << i << "."
              << " elementa je " << kontejner[i] << std::endl;
  }

  std::random_shuffle(kontejner.begin(), kontejner.end()); //random shuffle

  for (int i = 0; i < kontejner.size(); i++) {
    std::cout << "Vrijednost " << i << "."
              << " elementa je " << kontejner[i] << std::endl;
  }
  return 0;
}
