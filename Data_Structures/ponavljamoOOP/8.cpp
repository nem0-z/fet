#include<iostream>
#include<vector>

using namespace std;

template<typename InputIt, typename OutputIt>
void myCopy(InputIt start1,InputIt end1,OutputIt start2){
    while(start1!=end1){
        *start2++ = *start1++;
    }
}

template<typename Container>
void output(const Container& cont){
    for(const auto& x:cont)
    cout<<x<<" ";
    cout<<endl;
}

template<typename T, typename U>
void foo(T a,U b){
    std::cout << a+b << std::endl;
}

template<typename A>
void overload(A a){

}

template<typename B>
void overload(B b){

}

int main(int argc, char const *argv[])
{
    vector<int> vec1{2,4,6,7};
    vector<double> vec2( 5 );
    myCopy(vec1.begin(),vec1.end(),vec2.begin());
    output(vec1);
    output(vec2);
    myCopy(vec2.begin(),vec2.end(),back_inserter(vec1));
    output(vec1);
    output(vec2);
    foo(2,(int)2.5);
    foo<int,double>(2,'a');
    overload(4); //what happens?
    return 0;
}
