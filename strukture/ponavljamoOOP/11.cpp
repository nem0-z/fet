#include<iostream>
#include<string>

using namespace std;

struct A{
    A(){std::cout << "Default" << std::endl;}
    A(const A&){std::cout << "Copy" << std::endl;}
    A(A&&){std::cout << "Move" << std::endl;}
    A& operator=(const A& other){std::cout << "Copy=" << std::endl;
    return *this;}
    A& operator=(A&& other){std::cout << "Move=" << std::endl;
    return *this;}
    ~A(){std::cout << "A dtor" << std::endl;}
};

int main(int argc, char const *argv[])
{
    // A x;
    // A y;
    // x = y;
    // y = A{x};
    A* niz = new A[10];   
    delete [] niz;
    return 0;
}
