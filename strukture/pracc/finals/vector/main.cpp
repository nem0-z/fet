#include <iostream>
#include "vec.hpp"

int main(int argc, char const *argv[])
{
    vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    vec.print();
    vec.pop_front().pop_front().pop_front();
    vec.print();
    vec.insert(3, 14);
    vec.print();
    vec.insert(0, 20);
    vec.insert(vec.size(), 35);
    vec.print();
    vec.invert();
    vec.print();
    std::cout << vec.find(140) << std::endl;
    vector<int>::iterator it = vec.begin();
    std::cout << *it << std::endl;
    vector<int>::iterator it1 = vec.end();
    it1 = it1 - 1;
    std::cout << *it1 << std::endl;
    vector<int> vec2(vec);
    // vec2.print();
    vec.erase(vec.begin() + 2);
    vec.print();
    vec2.print();
    return 0;
}
