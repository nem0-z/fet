#include<iostream>

using namespace std;

struct A{
	A(int a) {
	cout<<a<<endl;
	}
};

namespace my{
A y(5);
}

int main(void){
A x(10);
my::y = A{2};
return 0;
}
