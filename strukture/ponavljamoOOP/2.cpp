#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string a;
    string b{};
    string c{"foo"};
    string d = c;
    std::cout << d.size() << std::endl;
    std::cout << b+c+d << std::endl;
    std::cout << d[5] << std::endl;
    std::cout << d.at(5) << std::endl;
    return 0;
}
