#pragma once
#include <string>
#include <vector>
#include "Radnik.hpp"

class BazaRadnika {
  std::vector<Radnik> baza;

  public:
  std::istream& ucitaj(std::istream&);
  std::ostream& ispisi(std::ostream&);
  double prosjekPlata() const;
  double prosjekGodina() const;
  bool izbrisi_radnika(std::string);
};
