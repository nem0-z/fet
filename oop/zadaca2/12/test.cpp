#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

struct Student
{ string indeks;
  string ime;
};

vector<Student>::iterator find(vector<Student>& vect,string indeks)
{
  for (auto it = vect.begin(); it!= vect.end(); ++it)
  {
      if((*it).indeks == indeks) return it;
  }
  return vect.end();
}
int main(int argc, char *argv[])
{
  vector<Student> vektor;
  Student s1{"18117","zlatan"};
  Student s2{"18118","zlatana"};
  Student s3{"18119","sinkuli"};
  vektor.push_back(s1);
  vektor.push_back(s2);
  vektor.push_back(s3);
  auto tmp = find(vektor,"18200");
  cout<<(*tmp).indeks;
  return 0;
}
