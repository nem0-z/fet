#include <limits.h>
#include <iostream>
#include <vector>

int fr(int n) {
  if (n < 1) return INT_MIN;  // error
  if (n == 1 || n == 2) return 1;
  if (n == 3) return 2;
  if (n == 4) return 4;
  return fr(n - 1) + fr(n - 3) + fr(n - 4);
}
int fm_impl(int n, std::vector<int>& lookupTable) {
  if (lookupTable[n] != -1) return lookupTable[n];
  if (n == 1 || n == 2)
    lookupTable[n] = 1;
  else if (n == 3)
    lookupTable[n] = 2;
  else if (n == 4)
    lookupTable[n] = 4;
  else
    lookupTable[n] = fm_impl(n - 1, lookupTable) + fm_impl(n - 3, lookupTable) +
                     fm_impl(n - 4, lookupTable);
  return lookupTable[n];
}
int fm(int n) {
  if (n < 1) return INT_MIN;  // error
  std::vector<int> lookupTable;
  lookupTable.resize(n + 1);
  for (auto& x : lookupTable) x = -1;
  return fm_impl(n, lookupTable);
}

int fd(int n) {
  if (n < 1) return INT_MIN;  // error
  std::vector<int> lookupTable;
  lookupTable.resize(n + 1);
  lookupTable[1] = 1;
  lookupTable[2] = 1;
  lookupTable[3] = 2;
  lookupTable[4] = 4;
  for (int i = 5; i <= n; ++i)
    lookupTable[i] =
        lookupTable[i - 1] + lookupTable[i - 3] + lookupTable[i - 4];
  return lookupTable[n];
}

int main(void) {
  std::cout << fr(17) << std::endl;
  std::cout << fm(17) << std::endl;
  std::cout << fd(17) << std::endl;
  return 0;
}
