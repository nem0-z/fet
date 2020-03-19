#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename InputIt1, typename InputIt2>
bool jednako(InputIt1 start1, InputIt1 end1, InputIt2 start2) {
  while (start1 != end1)
    if (*start1++ != *start2++) return false;
  return true;
}
