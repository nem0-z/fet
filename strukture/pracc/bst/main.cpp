#include <iostream>
#include "bst.hpp"

int main(int argc, char const *argv[])
{
    BST<int> b;
    b.insert(5);
    b.insert(7);
    b.insert(20);
    b.insert(3);
    b.insert(2);
    b.print();
    return 0;
}
