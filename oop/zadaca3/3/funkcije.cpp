#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include "Baza.hpp"
#include "Radnik.hpp"


std::istream& BazaRadnika::ucitaj(std::istream& ulaz) {
  Radnik r;
  while(true)
  {
  try{
  while (ulaz >> r.ime >> r.plata >> r.brGodina) {
  for (auto it = baza.begin(); it != baza.end(); ++it)
  {
    if(r.ime == (*it).ime) throw std::domain_error("Error!Postojeci korisnik!");
  }
  baza.push_back(r);
  }
  break;
  }
  catch(std::domain_error x)
  {
    std::cout<<x.what()<<std::endl;
    ulaz.clear();
  }
}
  return ulaz;
}

std::ostream& BazaRadnika::ispisi(std::ostream& izlaz) {
  for (auto it = baza.begin(); it != baza.end(); ++it)
    izlaz << (*it).ime << " " << (*it).plata << " " << (*it).brGodina << std::endl;
  return izlaz;
}
double BazaRadnika::prosjekPlata() const {
  double sum = 0;
  for (auto it = baza.begin(); it != baza.end(); ++it) sum += (*it).plata;
  return sum / baza.size();
}
double BazaRadnika::prosjekGodina() const {
  double sum = 0;
  for (auto it = baza.begin(); it != baza.end(); ++it) sum += (*it).brGodina;
  return sum / baza.size();
}
bool BazaRadnika::izbrisi_radnika(std::string x) {
  for (auto it = baza.begin(); it != baza.end(); ++it)
    if ((*it).ime == x) {
      baza.erase(it);
      return 1;
    }
  return 0;
}
