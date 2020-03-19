#include<iostream>
#include<string>

using std::string;
namespace my{
    int a = 6;
    double b = 7;
}

int main(int argc, const char** argv) {
    using namespace my;
    // int a = 5;
    // double b = 4;
    std::cout << a << std::endl;
    // for (char input;std::cin>>input;)
    // {
    //     std::cout << input << std::endl;
    // }
    // std::cin.clear();
    // std::cin.ignore();
    char input;
    while(std::cin>>input){
        std::cout << input << std::endl;
    }
    return 0;
}
