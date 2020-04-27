#include <iostream>
#include "debug.hpp"

int main(int argc, char const *argv[])
{
  std::vector<Station> stations;
  auto it = findStation(stations, "BanjaLuka");
  for (int i = -1500; i < 1500; ++i)
  {
    for (int j = 1; j < 13; ++j)
      EditStation(it, i, j, -j, j);
  }
  return 0;
}
