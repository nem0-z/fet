#include <iostream>
#include <map>

std::map<int, std::string> prvih10() {
  std::map<int, std::string> result;
  using map_element = std::pair<int, std::string>;
  result.insert(map_element(1, "jedan"));
  result.insert(map_element(2, "dva"));
  result.insert(map_element(3, "tri"));
  result.insert(map_element(4, "cetiri"));
  result.insert(map_element(5, "pet"));
  result.insert(map_element(6, "sest"));
  result.insert(map_element(7, "sedam"));
  result.insert(map_element(8, "osam"));
  result.insert(map_element(9, "devet"));
  result.insert(map_element(10, "deset"));
  return result;
}

int main() {
  auto prvih10Map = prvih10();

  std::cout << "Unesite broj: ";
  int num;

  while (std::cin >> num) {
    if (!(prvih10Map.count(num))){
      std::cout<<"Broj "<<num<<" se ne nalazi u mapi" << std::endl;
      std::cout<<"Unesite broj: ";
    }
    else
    {
    std::cout << "Odgovarajuci string : " << prvih10Map[num]
              << std::endl;
    std::cout << "Unesite broj: ";
    }
  }

  std::cout << std::endl << "Svi elementi mape: " << std::endl;
  for (const auto& el : prvih10Map) { 
    std::cout << el.first << " --> " << el.second << std::endl;
  }
  return 0;
}
