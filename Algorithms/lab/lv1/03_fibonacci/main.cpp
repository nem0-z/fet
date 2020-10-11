#include <chrono>
#include <cmath>
#include <iostream>

// implement a recursive function that computes the n-th fibonacci number
int fibonacci(int n) {
  if (n == 1 || n == 2) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// Ova reukrzija se izvrsava u vidu stabla
//                      fib(4)
//                    /       \
//               fib(3)        fib(2)
//              /      \      /      \
//         fib(2)    fib(1)   1        1
//          /   \         \
//         1     1         1

// implement a iterative fibonacci and measure its performance
unsigned long fibonacci_iter(unsigned long n) {
  int n0 = 0;
  int n1 = 1;
  for (int i = 0; i < n; i++) {
    auto temp = n1 + n0;
    n0 = n1;
    n1 = temp;
  }
  return n1;
}

// implement a function that computes the n-th fibonacci number using the
// general case formula
unsigned long fibonacci_gen(int n) {

  const double sqrt5 = std::sqrt(5);
  const double c1 = (1 + sqrt5) / 2;
  const double c2 = (1 - sqrt5) / 2;

  double result = (1 / sqrt5) * (std::pow(c1, n) - std::pow(c2, n));

  // Moguci gubitci u zaokruzivanju
  return std::round(result);
}

int main() {
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for recursive method: " << elapsed.count()
              << "ns" << std::endl;
  }
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci_iter(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for iterative method: " << elapsed.count()
              << "ns" << std::endl;
  }
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci_gen(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for general method: " << elapsed.count()
              << "ns" << std::endl;
  }
}
