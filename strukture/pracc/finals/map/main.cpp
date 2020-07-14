#include <iostream>
#include "map.hpp"

int main(int argc, const char **argv)
{
    map<int, std::string> mapa;
    mapa.insert({5, "Sinisa"});
    mapa.insert(std::make_pair(3, "boris"));
    std::string s = "bake";
    int a = 11;
    mapa.insert({a, s});
    mapa.print();
    std::cout << mapa.find(11) << std::endl;
    std::cout << mapa[14] << std::endl;
    std::cout << mapa.find(11) << std::endl;
    mapa[16] = "test";
    std::cout << mapa.find(14) << std::endl;
    std::cout << mapa.find(16) << std::endl;
    mapa.print();
    mapa.erase(3);
    mapa.erase(11);
    mapa.print();
    // mapa.erase(14);
    mapa.erase(5);
    mapa.erase(14);
    mapa.erase(16);
    mapa.print();
    return 0;
}