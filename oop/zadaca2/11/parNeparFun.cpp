#include <functional>
#include <iostream>
#include <list>
#include <vector>

std::list<int> sort(std::list<int>::const_iterator a,
                    std::list<int>::const_iterator b,
                    std::function<bool(int)> x) {
  std::list<int> lista;
  std::list<int> tmp;
  for (auto at = a; at != b; ++at) {
    if (x(*at))
      lista.push_back(*at);
    else
      tmp.push_back(*at);
  }
  lista.splice(std::end(lista), tmp);
  return lista;
}
int main(void) {
  std::list<int> nums{15, 20, 25, -10, -75, 100, -255, 430, 200};
  try {
    auto result = sort(nums.cbegin(), nums.cend(), [](int num) {
      if (num > 0)
        return num > 0;
      else
        throw 1;
    });
    for (auto num : result) {
      std::cout << num << ' ';
    }
  } catch (int a) {
    for (auto num : nums) std::cout << num << ' ';
    return a;
  }
  std::cout << std::endl;
  return 0;
}
