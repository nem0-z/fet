#include <iostream>
#include "niz.hpp"

int main(void){
	MojNiz<int> numbers;
  for(int i = 1; i < 7; ++i){
    numbers.push_back(i);
  }
  numbers.erase(numbers.begin()+2,numbers.begin()+3);
  for (auto it = numbers.begin(); it < numbers.end(); ++it) {
    std::cout << *it << std::endl;
  }
	return 0;
}
