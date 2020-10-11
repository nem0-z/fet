#include <iostream>
#include <vector>

int main(void)
{
  //unese dva vektora i pise uredjene parove
  std::vector<int> prviSkup;
  std::vector<int> drugiSkup;
  int unos;
  std::cout << "Unesi prvi skup clanova: " << std::endl;
  while(std::cin>>unos)
  {
    prviSkup.push_back(unos);
  }
  std::cin.clear();
  std::cout << "Unesi drugi skup clanova: " << std::endl;
  while(std::cin>>unos){
    drugiSkup.push_back(unos);
  }
  std::cin.clear();
  std::cout << "Uredjeni parovi su: " << std::endl;

  for (int i = 0; i < prviSkup.size(); i++) {
    for (int j = 0; j < drugiSkup.size(); j++) {
      std::cout << prviSkup[i]<<","<<drugiSkup[j]<< std::endl;
    }
    
  }
  return 0;
}
