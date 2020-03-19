#include<iostream>
#include<string>
#include<vector>
#include<iterator>


// void foo(int){
//     std::cout << "1" << std::endl;
// }
// void foo(double){
//     std::cout << "2" << std::endl;
// }
// void foo(char){
//     std::cout << "3" << std::endl;
// }
// void foo(std::string){
//     std::cout << "4" << std::endl;
// }
auto foo(char a = 'a', double b = 4){
    return a+b;
}
// auto foo(std::string x = "default", double b); //default argument always on far right

void ispisiVektor(const std::vector<int>& vec)
{
    for(auto it = vec.begin(); it!= vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

int main(int argc, const char** argv) {
    // foo(false);
    // foo('a');
    // foo(5);
    // foo("a");
    std::cout << foo() << std::endl;
    std::vector<int> vec{5,2,1,42,1,4,1};
    std::vector<int>::iterator iter = vec.begin();
    ++iter;++iter;
    std::cout << *iter << std::endl;
    // decltype(*iter) l = 4; //can this be compiled or no?
    ispisiVektor(vec);
    return 0;
}