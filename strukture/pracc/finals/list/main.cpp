#include <iostream>
#include "list.hpp"

int main(int argc, char const *argv[])
{
    list<double> lista;
    lista.emplace_back(5.5);
    lista.emplace_back(7.5);
    lista.emplace_back(3.5);
    lista.emplace_front(1);
    lista.print();
    auto it = lista.begin();
    std::cout << *it << std::endl;
    auto it2 = lista.end();
    --it2;
    std::cout << *it2 << std::endl;
    ++it2;
    ++it2;
    ++it2;
    ++it2;
    --it;
    --it;
    --it;
    lista.print();
    auto it3 = lista.end();
    // --it3;
    lista.erase(it3);
    lista.print();
    auto it5 = lista.begin();
    ++it5;
    ++it5;
    ++it5;
    lista.insert(it5, 20.48);
    lista.print();
    auto lambda = [](double a) { return a == 5.5; };
    auto found = lista.find_if(lambda);
    lista.insert(found, 40);
    lista.print();
    return 0;
}
