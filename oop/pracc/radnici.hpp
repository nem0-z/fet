#pragma once
#include <string>
#include <iostream>
//sortira radnike po plati preko fje
//poveca platu radniku
//smanji platu randiku
//ucita radnika
//vrati godine do penzije od radnika
extern const int godine_za_penziju;

class Radnik{

  private:
  std::string ime;
  double plata;
  int godine;


  public:
  bool po_plati(const Radnik&, const Radnik&);
  double povecaj_platu(double);
  double smanji_platu(double);
  
  std::istream& ucitaj_radnika(std::istream&);
  std::ostream& pokupi_radnika(std::ostream&);
  int do_penzije(void) const;

};










