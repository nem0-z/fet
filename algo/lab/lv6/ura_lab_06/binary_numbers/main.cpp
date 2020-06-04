#include <iostream>
#include <string>

// Printati sve binarne brojeve koji imaju samo dvije jedinice u svom zapisu
// duzine n.

// O(n)
// int broj_jedinica(std::string& binary) {
//   int count = 0;
//   for (auto b : binary) {
//     if (b == '1') count++;
//   }
//   return count;
// }

void print_binary(std::string& binary, int n, int broj_jedinica) {
  if (n == 0 && broj_jedinica == 2) {
    std::cout << binary << std::endl;
  }
  if (n == 0) {
    return;
  }

  binary.push_back('0');
  print_binary(binary, n - 1, broj_jedinica);
  binary.pop_back();

  if (broj_jedinica < 2) {
    binary.push_back('1');
    print_binary(binary, n - 1, broj_jedinica + 1);
    binary.pop_back();
  }
}

int main() {
  std::string bin;
  int n = 8;
  print_binary(bin, 8, 0);
}
