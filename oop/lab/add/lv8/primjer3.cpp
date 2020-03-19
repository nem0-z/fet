#include <functional>
#include <iostream>
#include <vector>

using std::function;
using std::vector;

void izmjeni(vector<int>& vec, function<int(int)> foo) {
  for (int i = 0; i < vec.size(); ++i) {
    vec[i] = foo(vec[i]);
  }
}

int main(void) {
  vector<int> a{1, 2, 3, 4, 5};
  function<int(int)> operacija = [](int a) { return a * 2; };

  izmjeni(a, operacija);

  // drugi nacin za poziv je:
  // izmjeni(a, [](int a) { return a * 2; });

  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << std::endl;
  }
  return 0;
}
