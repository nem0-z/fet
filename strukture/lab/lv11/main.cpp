#include <iostream>
#include "map.hpp"

int main(void)
{
  mapa<int, std::string> m;
  m.add(15, "Petnaest");
  m.add(20, "Dvadeset");
  m.add(10, "Deset");
  m.print();
  m.erase(10);
  m.print();
  return 0;
}
