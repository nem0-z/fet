#include <iostream>
#include "StdList.hpp"
// #include <list>

// void print(const std::list<int> &lista)
// {
//     auto it = lista.begin();
//     while (it != lista.end())
//     {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << std::endl;
// }

int main(int argc, const char **argv)
{
    StdList<int> lista;
    lista.push_back(5);
    lista.push_back(7);
    lista.push_back(3);
    lista.push_back(9);
    // lista.print();
    // StdList<int> toAdd;
    // toAdd.push_back(1);
    // toAdd.push_back(1);
    // toAdd.push_back(1);
    // std::cout << "Before splice:" << std::endl;
    // lista.print();
    // toAdd.print();
    // auto it = lista.end();
    // --it;
    // lista.splice(it, toAdd);
    // std::cout << "After splicing before element " << *it << std::endl;
    // lista.print();
    // toAdd.print();
    // auto pred = [&](int num) { std::cout << "Lambda: " << num << std::endl; };
    // lista.transform(pred);
    // lista.print();
    // auto pred1 = [](int num) { return num == 5; };
    // StdList<int>::iterator iter = lista.find(pred1);
    // std::cout << *iter << std::endl;
    // StdList<int>::iterator iter1 = lista.find(5);
    // std::cout << *iter1 << std::endl;
    // while (iter1 != nullptr)
    // {
    //     std::cout << *iter1 << " ";
    //     ++iter1;
    // }
    // std::cout << std::endl;
    // std::cout << "Before erasing:" << std::endl;
    // lista.print();
    // auto iter2 = lista.find(7);
    // lista.erase(iter2);
    // std::cout << "After erasing:" << std::endl;
    // lista.print();
    auto it = lista.begin();
    ++it;
    ++it;
    lista.insert(it, 14);
    lista.print();
    lista.insert(lista.end(), 10);
    lista.print();

    return 0;
}
