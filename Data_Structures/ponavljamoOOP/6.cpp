#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

void ispisi(const vector<int>& vec){
    for(const auto& item:vec)
    cout<<item<<" ";
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int> vec{5,1,2,6,2,1,5,7};
    auto it = back_inserter(vec);
    *it = 7;
    ispisi(vec);
    // auto it1 = front_inserter(vec);
    // *it = 4; //ne moze na vektor
    auto it2 = inserter(vec,vec.begin()+3);
    *it2 = 14;
    ispisi(vec);
    // *it = 4; //even though it doesn't cause crash here we should avoid this because after
    //changing size of vector, all of its previous iterators are in an undefined state
    // ispisi(vec);
    auto it3 = vec.begin() + 2;
    auto it4 = vec.end() - 3;
    auto it5 = vec.erase(it3,it4);
    ispisi(vec);
    *it5 = 33;
    ispisi(vec);
    return 0;
}
