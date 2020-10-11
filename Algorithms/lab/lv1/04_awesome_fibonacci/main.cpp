#include <chrono>
#include <iostream>

using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

// O(n) fibonacci implementation
cpp_int fibonacci1(cpp_int n) {
  cpp_int n0 = 0;
  cpp_int n1 = 1;
  for (cpp_int i = 1; i < n; i++) {
    auto temp = n1;
    n1 = n1 + n0;
    n0 = temp;
  }
  return n1;
}

/**************************************************************************************************/

struct matrix2x2 {
  cpp_int array[4];
};

matrix2x2 operator*(const matrix2x2& lhs, const matrix2x2& rhs) {
  return {lhs.array[0] * rhs.array[0] + lhs.array[1] * rhs.array[2],
          lhs.array[0] * rhs.array[1] + lhs.array[1] * rhs.array[3],
          lhs.array[2] * rhs.array[0] + lhs.array[3] * rhs.array[2],
          lhs.array[2] * rhs.array[1] + lhs.array[3] * rhs.array[3]};
}

int odd(int n) { return n & 1; }

int half(int n) { return n >> 1; }

matrix2x2 power(matrix2x2 x, int n) {
  if (n == 1) return x;

  matrix2x2 result = power(x * x, half(n));
  if (odd(n)) result = x * result;
  return result;
}

// matrica oblika
// [ 1  1 ]
// [ 1  0 ]
const matrix2x2 fibonacci_matrix{cpp_int{1}, cpp_int{1}, cpp_int{1},
                                 cpp_int{0}};

cpp_int fibonacci(int n) {
  if (n == 0) return cpp_int{0};
  if (n == 1) return cpp_int{1};

  matrix2x2 result = power(fibonacci_matrix, n - 1);
  return result.array[0];
}

int main() {
  // {
  //   cpp_int x = fibonacci(1);
  //   cout << x << endl;
  // }
  // {
  //   cpp_int x = fibonacci(2);
  //   cout << x << endl;
  // }
  // {
  //   cpp_int x = fibonacci(3);
  //   cout << x << endl;
  // }
  // {
  //   cpp_int x = fibonacci(4);
  //   cout << x << endl;
  // }
  // {
  //   cpp_int x = fibonacci(5);
  //   cout << x << endl;
  // }
  // {
  //   cpp_int x = fibonacci(6);
  //   cout << x << endl;
  // }
  // {
  //   cpp_int x = fibonacci(7);
  //   cout << x << endl;
  // }
  //
  // {
  //   auto now = std::chrono::steady_clock::now();
  //   auto r = fibonacci1(500000);
  //   auto elapsed = std::chrono::steady_clock::now() - now;
  //   std::cout << "Fibonacci of 500000, regular way is: " << r << std::endl;
  //   std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  //   std::cout << "Elapsed time: "
  //             << std::chrono::duration_cast<std::chrono::duration<double>>(
  //                    elapsed)
  //                    .count()
  //             << "s" << std::endl;
  // }

  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci(500000);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 500000, power of matrix way is: " << r
              << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
    std::cout << "Elapsed time: "
              << std::chrono::duration_cast<std::chrono::duration<double>>(
                     elapsed)
                     .count()
              << "s" << std::endl;
  }
}
