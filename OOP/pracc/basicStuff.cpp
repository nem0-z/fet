//preko fje prolazi kroz sortirani vektor(descending) i racuna njihovu ukupnu razliku
//ukoliko je razlika na kraju <0 baci out of range, ako je ==0 baci invalid argument
//ako je parna vrati razliku+2 ako je neparna vrati razliku -2

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>

using std::vector; using std::out_of_range; using std::invalid_argument;
int fun(vector<int>& vect)
{
  auto it1=vect.begin();
  auto it2=vect.end();
  int razlika=*it1;
  while(it1!=it2)
  {
   razlika-=*++it1; 
  }
  if (razlika<0) throw out_of_range("Out of range");
  if(razlika == 0) throw invalid_argument("Invalid argument");
  if(razlika%2) return razlika-2;
  else return razlika+2;
}

int main(int argc, char *argv[])
{
  vector<int> vect;
  for(int unos;std::cin>>unos;)
    vect.push_back(unos);
  sort(vect.begin(),vect.end(),[](int a, int b){
      return a>b;
      });
  try{
  auto razlika = fun(vect);
  std::cout << razlika << std::endl;
  }
  catch(out_of_range a)
  {
    std::cout << a.what() << std::endl;
    return 1;
  }
  catch(invalid_argument a)
  {
    std::cout << a.what() << std::endl;
    return 2;
  }

  return 0;
}
