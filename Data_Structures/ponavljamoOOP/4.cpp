#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

namespace MyNamespace
{
    int inMyNamespace = 5;
}

std::istream& popuniVektor(std::istream& stream, vector<int>& vec){
    int input;
    while(stream>>input){
        vec.push_back(input);
    }
    return stream;
}
std::ostream& ispisiVektor(std::ostream& stream, const vector<int>& vec){
    for(const auto& item:vec){
        stream<<item<<" ";
        stream<<endl;
    }
    return stream;
}

void sortitrajVektor(vector<int>& vec, std::function<bool(int,int)> kriterij){
    std::sort(vec.begin(),vec.end(),kriterij);
}

int main(int argc, char const *argv[])
{
    // typedef int sinisa;
    // sinisa a = 5;
    // std::cout << a << std::endl;
    // decltype(a) x = 'a'; 
    // std::cout << x << std::endl;
    // x==97?a=7:a=4;
    // std::cout << a << std::endl;
    int& foo = MyNamespace::inMyNamespace;
    foo = 10;
    std::cout << MyNamespace::inMyNamespace << std::endl;
    // const int& bar = foo;
    // int k{14};
    // bar = k;
    vector<int> vec{};
    popuniVektor(std::cin,vec);
    auto sortIt = [](int a,int b){
        return a>b;
    };
    sortitrajVektor(vec,sortIt);
    ispisiVektor(std::cout,vec);
    return 0;
}
