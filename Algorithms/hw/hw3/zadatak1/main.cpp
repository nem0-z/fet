#include <iostream>
#include <vector>

int ar(int n) {
  if (n == 0) return 2;
  if (n == 1) return 4;
  if (n == 2) return 12;
  return 3 * ar(n - 3) + 2 * ar(n - 2) + ar(n - 3);
}
int am_impl(int n, std::vector<int>& lookupTable) {
  if (lookupTable[n] != -1) return lookupTable[n];
  if (n == 0)
    lookupTable[n] = 2;
  else if (n == 1)
    lookupTable[n] = 4;
  else if (n == 2)
    lookupTable[n] = 12;
  else
    lookupTable[n] = 3 * am_impl(n - 3, lookupTable) +
                     2 * am_impl(n - 2, lookupTable) +
                     am_impl(n - 3, lookupTable);
  return lookupTable[n];
}

int am(int n) {
  std::vector<int> lookupTable;
  lookupTable.resize(n + 1);
  for (auto& x : lookupTable) x = -1;
  return am_impl(n, lookupTable);
}
int ad(int n) {
  std::vector<int> lookupTable;
  lookupTable.resize(n + 1);
  for (int& x : lookupTable) x = -1;
  lookupTable[0] = 2;
  lookupTable[1] = 4;
  lookupTable[2] = 12;
  for (int i = 3; i <= n; ++i)
    lookupTable[i] =
        3 * lookupTable[i - 3] + 2 * lookupTable[i - 2] + lookupTable[i - 3];
  return lookupTable[n];
}

int main(void) {
  std::cout << ar(25) << std::endl;
  std::cout << am(25) << std::endl;
  std::cout << ad(25) << std::endl;
  return 0;
}

