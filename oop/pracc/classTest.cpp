#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

extern const int a = 50;

class Student {
  string ime, prezime;
  int ocjena, godine,a;
  public:
  Student() {
    a = 10;
    ime = "sinisa";
    prezime = "markovic";
    ocjena = 10;
    godine = -5;
    if(godine < 0) cout<<1;
  }
  Student(string a, int b)
  {
    ime  = "ajla";
    prezime = "gl";
    ocjena = b;
    godine = b;
  }
  explicit Student (int a)
  {
    ime = "boli te briga";
    prezime = "glupane";
    ocjena = a;
    godine = 333;
  }
  void print() {
    cout << ime << endl << prezime << endl << ocjena << endl << godine << endl;
  }
};

int main(void) {
  Student student;
  student.print();
  // Student student1("test",5);
  // student1.print();
  Student student2(5);
  student2.print();
  Student student3 = student2;
  Student student4{student2};
  vector<Student> vec;
  vec.push_back(student);
  vec.push_back(student2);
  vec.push_back(student3);
  vec.push_back(student4);
  std::sort(vec.begin(),vec.end(),[](const auto& a, const auto& b){
      return a.ime<b.ime;});
  return 0;
}
