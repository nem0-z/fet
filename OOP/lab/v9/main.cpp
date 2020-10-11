#include "student.hpp"

void Student::dodajOcjenu(std::string predmet, int ocjena)
{
  if (ocjena<6||ocjena>10) throw std::invalid_argument("Ne moze");
  ocjene_[predmet].push_back(ocjena);
}

void Student::ispisiOcjene() const {
  std::cout << ime_ <<"   "<< prezime_ <<std::endl;
  for(auto it = ocjene_.begin(); it!= ocjene_.end(); ++it)
  {
    auto x = (*it).second;
      std::cout << (*it).first<<"   ";
      for (auto item:x) std::cout<<item<<" ";
  }
}

int main(void)
{
  Student s1;
  Student s2("Zlatan","Radovanovic");
  try{
  s2.dodajOcjenu("Elektronika",7);
  s2.dodajOcjenu("Elektronika", 9);
  // s2.dodajOcjenu("Elektronika", 4);
  s2.ispisiOcjene();
  }
  catch(std::invalid_argument c)
  {
  std::cout << c.what() << std::endl;
  return 1;
  }
  return 0;
}


C x {};
C x;
C x();
C(C());

