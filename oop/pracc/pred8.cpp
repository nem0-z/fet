#include <iostream>
#include <string>
using namespace std;

class Radnik{
  std::string ime;
  double plata;
  int godine;
  public:
  void povecaj_platu(double);
  void smanji_platu(double);
  std::istream& ucitaj(std::istream &);
  int godina_do_penzije(void) const;
  void ispisi_podatke(void) const;
};

std::istream& Radnik::ucitaj(std::istream & ulaz)
{
  ulaz >> ime >> plata >> godine;
  return ulaz;
}
void Radnik::povecaj_platu(double povecanje)
{
  plata += povecanje;
}
void Radnik::ispisi_podatke(void) const
{
  cout<<ime<<plata<<godine;
}

int main(int argc, char *argv[])
{
  Radnik meho;
  meho.ucitaj(cin);
  meho.povecaj_platu(200);
  meho.ispisi_podatke();

  return 0;
}
