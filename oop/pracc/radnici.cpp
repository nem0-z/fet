#include "radnici.hpp"

const int godine_za_penziju = 65;

bool Radnik::po_plati(const Radnik& a, const Radnik& b)
{
  return a.plata<b.plata;
}

double Radnik::povecaj_platu(double povecanje)
{
  plata+=povecanje;
  return plata;
}

double Radnik::smanji_platu(double smanjenje)
{
  if(smanjenje>plata) throw std::domain_error("Dje ces mu vise smanjivat!");
  else
  {
  plata-=smanjenje;
  return plata;
  }
}

std::istream& Radnik::ucitaj_radnika(std::istream& ulaz)
{
  ulaz >> ime >> plata >> godine;
  return ulaz;
}

int Radnik::do_penzije(void) const 
{
  return godine_za_penziju - godine;
}
  std::ostream& Radnik::pokupi_radnika(std::ostream& izlaz)
{
  izlaz<<ime<<std::endl<<plata<<std::endl<<godine<<std::endl<<do_penzije();
  return izlaz;
}
