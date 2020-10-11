#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, const char** argv) {
    vector<int> vec{3,5,2,1};
    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i] << std::endl;
    // }
    // for(const auto& item:vec)
            // std::cout << item << std::endl;
    std::sort(vec.begin(),vec.end());
    // int x;
    // while(std::cin>>x){
    //     vec.push_back(x);
    // }
    for(const auto& item:vec)
            std::cout << item << std::endl;
    // std::cout << vec.size() << std::endl;
    // std::cout << vec.at(6) << std::endl;
    std::cout << vec[6] << std::endl;


    return 0;
}
