#include <iostream>
#include <string>
template<typename T, typename U>
struct par{
  T first;
  U second;
  
  struct S{};
};

template<typename T>
struct par<T,std::string>{
  T first;
  std::string second;

  void printString() const {
    std::cout << second << std::endl;
  }
};

template<>
struct par<int,double>{
  public:
    int first;
    double second;

    void printZbir() const {
      std::cout << first+second << std::endl;
    }
};


template<typename T, typename U>
void foo(){
  std::cout << "Dohvatam S" << std::endl;
  typename par<T,U>::S s;
}

int main() {
    par<int, short> p; 
    p.first = 1;
    p.second = 9000;
    std::cout << "First: " << p.first << " Second: " << p.second << std::endl;

    par<int, std::string> p2{1, std::string{"abcde"}};
    p2.printString();

    par<int, double> p3{1, 9.};
    p3.printZbir();

    foo<int,short>();

}
