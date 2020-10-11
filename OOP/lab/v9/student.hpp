#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
class Student {
  private:
  std::string ime_;
  std::string prezime_;
  std::map<std::string,std::vector<int>> ocjene_;

  public:
  Student() = default;
  Student(std::string ime, std::string prezime) : 
    ime_{ime}, prezime_{prezime} {}
  void dodajOcjenu(std::string,int); 
  void ispisiOcjene() const;

};


