#include <iostream>
#include "forwardlist.hpp"

int main()
{
  std::cout << "Testing push_back..." << std::endl;
  forward_list<int> list;
  list.push_back(1);
  list.push_back(3);
  list.push_back(2);
  std::cout << "Testing iterator access..." << std::endl;
  for (auto it = list.begin(); it != list.end(); ++it)
    std::cout << *it << std::endl;
  std::cout << "--------------" << std::endl;

  // ******Zadatak 1)******
  std::cout << "Testing push_front" << std::endl;
  forward_list<int> frontList;
  frontList.push_front(4);
  frontList.push_front(5);
  frontList.push_front(6);
  std::cout << "Testing iterator access..." << std::endl;
  for (auto it = frontList.begin(); it != frontList.end(); ++it)
    std::cout << *it << std::endl;
  std::cout << "--------------" << std::endl;

  std::cout << "Testing copy constructor" << std::endl;
  forward_list<int> otherList = list;
  for (auto it = otherList.begin(); it != otherList.end(); ++it)
    std::cout << *it << std::endl;
  std::cout << "Size=" << otherList.size() << std::endl;
  std::cout << "--------------" << std::endl;

  std::cout << "Testing transform: " << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });

  // ******Zadatak 3)******
  std::cout << "Testing find predicate" << std::endl;
  auto it = otherList.find(3);
  std::cout << *it << std::endl;
  std::cout << "--------------" << std::endl;

  // ******Zadatak 4)******
  std::cout << "Testing erase from middle" << std::endl;
  std::cout << "Before erase" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  otherList.erase(it);
  std::cout << "After erase" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "Size=" << otherList.size() << std::endl;
  std::cout << "--------------" << std::endl;

  std::cout << "Testing erase from begin" << std::endl;
  std::cout << "Before erase" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  otherList.erase(otherList.begin());
  std::cout << "After erase" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "Size=" << otherList.size() << std::endl;
  std::cout << "--------------" << std::endl;

  std::cout << "Testing erase last element" << std::endl;
  std::cout << "Before erase" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  otherList.erase(otherList.begin());
  std::cout << "After erase" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "Size=" << otherList.size() << std::endl;
  std::cout << "--------------" << std::endl;

  // ******Zadatak 5)******
  std::cout << "Testing splice at end" << std::endl;
  otherList.push_back(9);
  otherList.push_back(9);
  otherList.push_back(9);
  std::cout << "Before splice" << std::endl;
  list.transform([](int a) { std::cout << a << std::endl; });
  list.splice(list.end(), otherList);
  std::cout << "After splice" << std::endl;
  list.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "Other list after splice" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "--------------" << std::endl;

  std::cout << "Testing splice at begin" << std::endl;
  std::cout << "Before splice" << std::endl;
  list.transform([](int a) { std::cout << a << std::endl; });
  otherList.push_back(9);
  otherList.push_back(9);
  otherList.push_back(9);
  list.splice(list.begin(), otherList);
  std::cout << "After splice" << std::endl;
  list.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "Other list after splice" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "--------------" << std::endl;

  std::cout << "Testing splice in the middle" << std::endl;
  otherList.push_back(9);
  otherList.push_back(9);
  otherList.push_back(9);
  list.splice(list.find(3), otherList);
  std::cout << "After splice" << std::endl;
  list.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "Other list after splice" << std::endl;
  otherList.transform([](int a) { std::cout << a << std::endl; });
  std::cout << "--------------" << std::endl;
}
