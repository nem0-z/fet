#include <functional>
#include <list>
#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

namespace v11 {

template <typename ContainerType, typename UnaryOpt>
void remove_if(ContainerType& container, UnaryOpt predicate) {
  for (auto it = container.begin(); it != container.end();) {
    if (predicate(*it))
      it = container.erase(it);
    else
      ++it;
  }
}

template <typename T>
void foo(T t) {
  std::cout << "Template" << std::endl;
  t();
}

void foo(std::function<void()> f) {
  std::cout << "function" << std::endl;
  f();
}

}  // namespace v11

// TEST_CASE("Expects to remove nothing on empty vector") {
//   // std::vector<int> v;
//   // v11::remove_if(v, [](int num) { return num == 1; });
//   // CHECK_EQ(v.size(), 0);
//   v11::foo([]() { std::cout << "My lambda" << std::endl; });
// }

// TEST_CASE("Expects to remove first element in the vector") {
//   std::vector<int> v{1};
//   v11::remove_if(v, [](int num) { return num == 1; });
//   CHECK_EQ(v.size(), 0);
// }

// TEST_CASE("Expects to remove last element in list") {
//   std::list<std::string> l{"Hello", "World"};
//
//   v11::remove_if(l, [](const std::string& el) { return el == "World"; });
//
//   CHECK_EQ(l.size(), 1);
//   CHECK_EQ(*l.begin(), "Hello");
// }
//
TEST_CASE("Expects to remove all sevens in the list") {
  std::list<int> l{7, 2, 7, 1, 4, 7, 2, 8, 7, 9, 7};
  // auto it9 = l.begin();
  // std::advance(it9, 9);
  v11::remove_if(l, [](int el) { return el == 7; });
  CHECK_EQ(l.size(), 6);
  auto it = std::find(l.begin(), l.end(), 7);
  CHECK_EQ(it, l.end());

  // CHECK_EQ(*it9, 9);
}
//
// TEST_CASE("Expects to remove all sevens in the vector") {
//   std::vector<int> l{7, 2, 7, 1, 4, 7, 2, 8, 7, 9, 7};
//   v11::remove_if(l, [](int el) { return el == 7; });
//   CHECK_EQ(l.size(), 6);
//   auto it = std::find(l.begin(), l.end(), 7);
//   CHECK_EQ(it, l.end());
// }
//
// TEST_CASE("Expects to remove all digits from string") {
//   std::string str = "H3110 W0rld";
//   v11::remove_if(str, [](char a) { return std::isdigit(a); });
//   CHECK_EQ(str, "H Wrld");
// }
//
