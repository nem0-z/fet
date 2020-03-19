#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  string a = "zlatan";
    sort(a.begin()+a.size()/2,a.end());
  cout<<a;
  return 0;
}
