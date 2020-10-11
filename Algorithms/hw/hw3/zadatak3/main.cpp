#include <algorithm>
#include <iostream>
#include <vector>

const int cijene[] = {10, 5, 4, 2, 3, 1};
const int trajanja[] = {40, 18, 35, 2, 4, 10};
void knapsack(int novac) {
  int maxTrajanje = 0;
  using ratio = std::pair<double, int>;
  // double vrijednost -> odnos trajanje/cijena
  // int vrijednost -> tip voznje
  std::vector<ratio> ratios;
  std::vector<int> tipoviVoznje;
  for (int i = 0; i < sizeof(cijene) / sizeof(int); ++i) {
    ratios.push_back(std::make_pair((double)trajanja[i] / cijene[i], i));
  }
  std::sort(ratios.begin(), ratios.end(), [](const ratio& r1, const ratio& r2) {
    return r1.first > r2.first;
  });
  for (const auto& r : ratios) {
    int tipVoznje = r.second;
    if (novac - cijene[tipVoznje] >= 0) {
      maxTrajanje += trajanja[tipVoznje];
      tipoviVoznje.push_back(tipVoznje + 1);
      novac -= cijene[tipVoznje];
    }
  }
  std::cout << "Najbolje je odabrati tipove voznje: ";
  for (int t : tipoviVoznje) {
    std::cout << t << " ";
  }
  std::cout << std::endl;
  std::cout << "Maksimalno trajanje iznosi: " << maxTrajanje << " minuta"
            << std::endl;
}

int knapsackDP(int novac) {
  int velicina = sizeof(cijene) / sizeof(int);
  int dp[velicina + 1][novac + 1];

  for (int i = 0; i <= velicina; ++i) {
    for (int j = 0; j <= novac; ++j) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (cijene[i - 1] <= j)
        dp[i][j] = std::max(dp[i - 1][j],
                            dp[i - 1][j - cijene[i - 1]] + trajanja[i - 1]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[velicina][novac];
}

int main(void) {
  // knapsack(15);
  // std::cout << knapsackDP(15);
  return 0;
}
