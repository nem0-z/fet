#include<iostream>
#include<list>
#include<iterator>
#include<map>
#include<string>
using namespace std;
template<typename Cont>
void ispisiVektor(Cont& vec)
{
    for(auto it = vec.begin(); it!= vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

void printMap(const std::map<int,std::string>& myMap){
    for (auto it = myMap.begin(); it!=myMap.end(); ++it)    
    {
        std::cout << it->second << " -> "<< it->first<< std::endl;
    }
}

int main(int argc, char const *argv[])
{
    list<int> lista{5,7,1,2,4};
    lista.sort();
    ispisiVektor(lista);
    lista.push_front(3);
    ispisiVektor(lista);
    auto it = lista.begin();
    it++;
    *it = 4;
    ispisiVektor(lista);
    auto it1 = front_inserter(lista);
    *it1 = 'a';
    ispisiVektor(lista); 
    map<int,std::string> myMap;
    std::string input;
    for (size_t i = 0; i < 5; i++)
    {   
        std::cin>>input;
        myMap[i] = input;
    }
    printMap(myMap);
    myMap[8] = "sinisa";
    printMap(myMap);   
    std::cout << myMap[3] << std::endl;
    auto foo = myMap[11];
    printMap(myMap);   
    auto potraga = myMap.find(25);
    std::cout << potraga->second << std::endl; //undefined in this case
    std::cout<<myMap.erase(30)<<std::endl;
    printMap(myMap);
    return 0;
}
