#include <map>
#include <iostream>

int main(int argc, char* argv[]) {
  std::map<std::string, std::string> a{{"foo", "s"}, {"xbar", "e"}};

  a["bb"] = "q";

  a["bb"] = "r";


  for (const auto& el : a) {
    std::cout << el.first << ":" << el.second << std::endl;
  }

  return 0;
}
