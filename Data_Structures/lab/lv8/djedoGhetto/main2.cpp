#include <iostream>
#include <vector>

struct Student {
  std::vector<int> ocjene{};
  std::string ime;
  std::string prezime;

  Student() { std::cout << "ctor" << std::endl; }
  Student(const Student&) { std::cout << "copy ctor" << std::endl; }
  Student(Student&&) { std::cout << "move ctor" << std::endl; }
  Student& operator=(const Student&) {
    std::cout << "copy operator =" << std::endl;
    return *this;
  }
  Student& operator=(Student&&) {
    std::cout << "move operator =" << std::endl;
    return *this;
  }
  ~Student() { std::cout << "dtor" << std::endl; }
};

int main(void) { 
  // std::vector<Student> studenti(10);
  std::vector<Student> studenti;
  studenti.reserve(5);

    int a;
    Student s;
    while(std::cin >> a){
      s.ocjene.push_back(a);
    }
    studenti.push_back(s);
  return 0; 
}
