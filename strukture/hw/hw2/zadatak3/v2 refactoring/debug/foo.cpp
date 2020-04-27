#include <iostream>
#include "debug.hpp"

int main(int argc, char const *argv[])
{
    std::list<Station> stations;
    auto it = findStation(stations,"Tuzla");    
    for(int i = 1; i<2000;++i)
    {
		for(int j = 1; j<13; ++j)
    EditStation(it,i,j,5.5,4.5);
    }
    return 0;
}
