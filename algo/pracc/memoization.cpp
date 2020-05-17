#include <limits.h>
#include <algorithm>
#include <chrono>
#include <iostream>

typedef unsigned long long ull;

ull rfib(int n) {
  if (n < 2) return n;
  return rfib(n - 2) + rfib(n - 1);
}

ull mfib(int n) {
  static ull M[100] = {0};
  if (n < 2) return n;
  if (M[n] == 0) M[n] = mfib(n - 2) + mfib(n - 1);
  return M[n];
}

ull rfact(int n) {
  if (n < 2) return n;
  return n * rfact(n - 1);
}

ull mfact(int n) {
  static ull M[100] = {0};
  if (n < 2) return n;
  if (M[n] == 0) M[n] = n * mfact(n - 1);
  return M[n];
}

int main(void) {
  auto now = std::chrono::system_clock::now();
  std::cout << "Without memoization: " << rfact(55) << std::endl;
  auto finish = std::chrono::system_clock::now();
  auto elapsed = finish - now;
  std::cout << elapsed.count() << "ns" << std::endl;

  now = std::chrono::system_clock::now();
  std::cout << "Using memoization: " << mfact(55) << std::endl;
  finish = std::chrono::system_clock::now();
  elapsed = finish - now;
  std::cout << elapsed.count() << "ns" << std::endl;
}
