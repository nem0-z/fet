#include "radnici.hpp"
int main(void)
{
  Radnik radnik;
  radnik.ucitaj_radnika(std::cin);
  radnik.povecaj_platu(300);
  try
  {
  radnik.smanji_platu(10000);
  }
catch(std::domain_error x)
  {
    std::cout << x.what() << std::endl;
  }
  radnik.pokupi_radnika(std::cout);
  return 0;
}
