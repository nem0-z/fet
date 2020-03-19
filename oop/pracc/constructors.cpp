#include <iostream>
#include <string>
using namespace std;

class Student {
  public:
  std::string ime = "boris";
  int broj;

  public:
  Student() { cout << "Default" << endl; }
  Student(const Student& foo) : broj{foo.broj} { cout << "Copy" << endl; }
  Student& operator=(const Student& foo) {
    ime = foo.ime;
    broj = foo.broj;
    cout << "Operator=" << endl;
    return *this;
  }
  ~Student() { cout << "Destructor from " << ime << endl; }
  Student(int x) : ime{"Sinisha"}, broj{x} { cout << "ledara" << endl; }
};

int main(void) {
  // Student s1{10};
  // Student s2{s1};
  // cout<<s2.ime<<endl<<s2.broj<<endl;
  // Student s3;
  // s3 = s2;
  // cout<<s3.ime<<endl<<s3.broj<<endl;
  // s2 = s1;
  Student s3(6);
  // cout << s3.ime << endl << s3.broj << endl;
  s3 = 10;
  // cout << s3.ime << endl << s3.broj << endl;
  return 0;
}
