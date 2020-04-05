#include <iostream>
#include <vector>
#include <cstring>
#include "PjancList.hpp"
#include "ForwardList.hpp"
#include "ArrayList.hpp"

using namespace std;

int main(int argc, const char **argv)
{
    // vector<int> vec{2, 5, 3, 7, 1, 2, 5, 7};
    // auto it1 = vec.begin();
    // auto it2 = vec.end();
    // cout << it2 - it1;
    // auto cit1 = vec.cbegin();
    // auto cit2 = vec.cend();
    // cout << cit2 - it1;
    // while (it1 != cit2) //so they can be compared
    // {
    //     cout << *it1++ << " ";
    // }
    // it1 = it2;
    // cit1 = cit2;
    // *it1 = 5;
    // char arr[] = "Test string";
    // memset(arr, 500, 4);
    // printf("\n%s\n", arr);

    PjancList<int> pjancList{2, 5, 7, 1, 2, 5};
    pjancList.print();
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.push_back(4);
    pjancList.print(); //invalid writes ofc

    return 0;
}