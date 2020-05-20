#include <iostream>
#include <string>
#include <vector>

// staircase problem
// na koliko nacine se moguce popeti uz n stepenica
// moguce je zakoraciti na jednu ili na dvije stepenice
//

int staircase_r(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  // moze zakoracit jednu ili dvije

  return staircase_r(n - 1) + staircase_r(n - 2);
  // broj nacina ako smo na zadnjoj stepenici ili na predzadnjoj
}

// int lookup_table[1000];
// int staircase_mem(int n) {
//   if (lookup_table[n] != 0) {
//     // znaci da je vec izracunato
//     return lookup_table[n];
//   }
//   if (n == 1) {
//     lookup_table[n] = 1;
//     return 1;
//   }
//   if (n == 2) {
//     lookup_table[n] = 2;
//     return 2;
//   }
//
//   lookup_table[n] = staircase_mem(n - 1) + staircase_mem(n - 2);
//   return lookup_table[n];
// }
// ovo je sve fino al koristi globalnu varijablu i ogranicen niz = not good

int staircase_mem_impl(int n, std::vector<int>& lookup_table) {
  if (lookup_table[n] != 0) {
    // znaci da je vec izracunato
    return lookup_table[n];
  }
  if (n == 1) {
    lookup_table[n] = 1;
    return 1;
  }
  if (n == 2) {
    lookup_table[n] = 2;
    return 2;
  }

  lookup_table[n] = staircase_mem_impl(n - 1, lookup_table) +
                    staircase_mem_impl(n - 2, lookup_table);
  return lookup_table[n];
}

int staircase_mem(int n) {
  std::vector<int> lookup_table;
  lookup_table.resize(n + 1);
  // ovo nam osigura da mozemo gore
  // indeksirati vektor bez problema
  return staircase_mem_impl(n, lookup_table);
}

int staircase_dp(int n) {
  std::vector<int> table;
  table.resize(n + 1);

  table[1] = 1;
  table[2] = 2;
  // spremanje baznih slucajeva

  for (int i = 3; i <= n; ++i) table[i] = table[i - 1] + table[i - 2];
  // idemo od 3 jer 1-2 imamo izracunato kao bazne slucajeve

  return table[n];
}

int main(void) {
  std::cout << "Rekurzivno: " << staircase_r(5) << std::endl;
  std::cout << "Memoizacija: " << staircase_mem(5) << std::endl;
  std::cout << "Memoizacija(bolja xD): " << staircase_mem(5) << std::endl;
  std::cout << "DP: " << staircase_dp(5) << std::endl;
  return 0;
}
