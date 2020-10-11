#include <iostream>
using namespace std;

int main(void) {
  int array[5];  // zauzeli prostor za 5 intova
  array[0] = 10;
  std::cout << array[0] << std::endl;
  // array[10] = 50; //undefined, fino ti kaze warning
  *array = 20;  // isto kao array[0] = 20;
  std::cout << array[0] << std::endl;
  *(array + 3) = 40;  // cetvrti clan set
  for (const auto& item : array) cout << item << " ";
  cout << endl;
  int n;
  cin >> n;
  int niz[n];  // ne moze ovo iako kompajler napravi da moze
  // kompajler u sustini odvoji njemu tonu memorije za ovo jer ne moze unaprijed
  // znat koliko ce biti nase n tako da lupam za n=5, niz[20] ce raditi bez
  // problema
  return 0;
}
