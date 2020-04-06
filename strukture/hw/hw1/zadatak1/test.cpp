#include <iostream>
#include "ArrayList-impl.hpp"

int main(int argc, const char **argv)
{
    ArrayList<char> list1{'T', 'e', 's', 't'};
    ArrayList<char>::const_iterator it = list1.cbegin() + 2;
    list1.insert(it, 'x');
    list1.print();
    // auto it2 = list1.find('s');
    // auto it3 = list1.find_if([](char c) { return c > 'a' && c < 'm'; });
    // list1.remove(it2);
    // list1.print();
    // list1.remove_if([](char c) { return c == 't'; });
    // list1.print();
    // list1.invert();
    // list1.print();
    return 0;
}