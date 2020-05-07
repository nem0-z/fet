#include <iostream>
#include <chrono>

// Implementirati rekurzivnu funkciju koja racuna sumu
// pretpostaviti da racunar zna samo operacije inkrement/dekrement
int sum(int a, int b) {
  if (b == 0) return a;
  else return sum(a + 1, b - 1);
}

// analiza toka/stacka
// sum(5, 3)
// sum(6, 2)
// sum(7, 1)
// sum(8, 0)
// 8

// O(n)
int multiply(int a, int b) {
  if (b == 1) return a;
  else return a + multiply(a, b - 1);
}

// analiza toka/stacka
// multiply(5, 4)
// 5 + multiply(5, 3)
// 5 + 5 + multiply(5, 2)
// 5 + 5 + 5 + multiply(5, 1)
// 5 + 5 + 5 + 5
// 5 + 5 + 10
// 5 + 15
// 20


int half(int n) {
  return n >> 1;
}

// O(log(n))
int fast_multiply(int a, int b) {
  if (b == 1) return a;
  auto result = fast_multiply(a + a, half(b));
  if (b & 1) result = a + result;
  return result;
}

// O(log(n))
int fast_power(int x, int n) {
  if (n == 1) return x;
  auto result = fast_power(x * x, half(n));
  if (n & 1) result = x * result;
  return result;
}

int main() {
  std::cout << "5 + 3 = "    << sum(5, 3) << std::endl;
  std::cout << "10 + 100 = " << sum(10, 100) << std::endl;

  {
    auto now = std::chrono::system_clock::now();
    auto result = multiply(400, 300);
    auto finish = std::chrono::system_clock::now();
    std::cout << "400 * 300 = " << result << std::endl;
    auto elapsed = finish - now;
    std::cout << "multiply time " << elapsed.count() << "ns" << std::endl;
  }


  std::cout << "20 * 200 = "   << multiply(20, 200) << std::endl;
  
  {
    auto now = std::chrono::system_clock::now();
    auto result = fast_multiply(400, 300);
    auto finish = std::chrono::system_clock::now();
    std::cout << "400 * 300 = " << result << std::endl;
    auto elapsed = finish - now;
    std::cout << "fast_multiply time " << elapsed.count() << "ns" << std::endl;
  }

  std::cout << "20 * 200 = "   << fast_multiply(20, 200) << std::endl;

  
  std::cout << "4 ^ 3 = " << fast_power(4, 3) << std::endl;
  std::cout << "2 ^ 10 = "   << fast_power(2, 10) << std::endl;
}
