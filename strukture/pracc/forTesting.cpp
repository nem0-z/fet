#include <iostream>
#include "StdList.hpp"

int main(int argc, const char **argv)
{
    StdList<int> lista;
    lista.print();
    lista.push_back(2);
    lista.print();
    lista.push_back(5);
    lista.push_back(7);
    lista.print();
    lista.clear();
    lista.print();
    lista.push_back(2);
    lista.print();
    lista.push_back(5);
    lista.push_back(7);
    lista.print();
    return 0;
}
