#include <iostream>
#include "ForwardList.hpp"

int main(int argc, const char **argv)
{

    std::cout << "Push back:" << std::endl;
    ForwardList<int> list1;
    list1.push_back(2).push_back(4).push_back(6);
    list1.print();

    std::cout << "Pop back:" << std::endl;
    list1.pop_back();
    list1.print();

    std::cout << "Push front:" << std::endl;
    list1.push_front(100).push_front(200).push_front(300);
    list1.print();

    std::cout << "Pop front:" << std::endl;
    list1.pop_front().pop_front();
    list1.print();

    std::cout << "Insert:" << std::endl;
    list1.insert(1, 25).insert(1, -50);
    list1.print();

    // std::cout << "Invert:" << std::endl;
    // list1.invert();
    // list1.print();   //do this with double-linked list, this is hard and way too slow :)

    std::cout << "Find:" << std::endl;
    auto result1 = list1.find(20000);
    std::cout << "Result1: " << result1 << std::endl;
    auto result2 = list1.find(-50);
    std::cout << "Result2: " << result2 << std::endl;

    std::cout << "Replace:" << std::endl;
    list1.replace(25, 0);
    list1.print();

    // for (auto it = list1.begin(); it != list1.end(); ++it)
    //   std::cout << *it << " ";
    // std::cout << '\n';

    // const int loopCtr = 5;
    // ForwardList<int> lista;
    // for (int i = 0; i < loopCtr; ++i)
    //     lista.push_back(5);
    // lista.print();

    // ForwardList<int> list2 = ForwardList<int>{};
    // for (int i = 0; i < loopCtr; ++i)
    //     list2.push_back(i);
    // list2.print();

    // list2 = lista;
    // // list2 = std::move(lista);
    // list2.print();

    // std::cout << lista.size() << std::endl;
    // std::cout << list2.size() << std::endl;

    return 0;
}