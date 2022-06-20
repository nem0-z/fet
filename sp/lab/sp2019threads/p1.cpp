#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void foo(std::vector<int> brojevi) {
  std::cout << "Thread se izvrsava." << std::endl;
  for(const auto& el : brojevi)
    std::cout << el << std::endl;
}

int main(int argc, char *argv[])
{
  vector<int> brojevi{1,2,4,5,10};
  std::thread t{foo, brojevi}; //joinable -> doing smth
  t.join(); //unjoinable -> ne smijem ga ubit tj cekam
  return 0;
}
