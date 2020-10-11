#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int foo(4);
    int bar(6);
    int* p = &foo;
    std::cout << p << std::endl;
    const int* l = &foo;
    std::cout << l << std::endl;
    l = &bar;
    std::cout << *l << std::endl;
    int* const k = &foo;
    std::cout << *k << std::endl;
    *k = 7;
    std::cout << foo << std::endl;
    double array[10];
    for (size_t i = 0; i < sizeof(array)/sizeof(double); i++)
    {
        array[i] = i;
    }
    for (size_t i = 0; i < sizeof(array)/sizeof(double); i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<'\n';
    vector<int> vec(array,array+10); //one of vector constructors
    cout<<"sinisa";   
    return 0;
}



