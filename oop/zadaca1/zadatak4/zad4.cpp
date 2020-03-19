
#include <sys/ioctl.h>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
size_t broj_kolona() {
  winsize sz;
  ioctl(0, TIOCGWINSZ, &sz);
  return sz.ws_col;
}

void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}
void printaj(std::vector<double> const& kontejner) {
  static char x = '=';
  for (int i = 0; i < kontejner.size(); ++i) {
    std::cout << std::string(kontejner[i], x);
    pauziraj(700);
  }
  x == '=' ? x = ' ' : x = '=';
}

void unosGranica(std::vector<double> &kontejner) {
  double g1, g2, g3, g4;
  std::cout << "Enter limits: " << std::endl;
  std::cin >> g1 >> g2 >> g3 >> g4;
  std::cin.clear();
  if ((g1 + g2 + g3 + g4) == 100) {
    kontejner.push_back(g1 / 100 * broj_kolona() );
    kontejner.push_back(g2 / 100 * broj_kolona() );
    kontejner.push_back(g3 / 100 * broj_kolona() );
    kontejner.push_back(g4 / 100 * broj_kolona() - 1);
  } else {
    std::cout << "Limits should not exceed value of 100! " << std::endl;
    exit(0);
  }
}

int main() {
  std::vector<double> kontejner;
  unosGranica(kontejner);
  while (1) {
    std::cout << "[";
    printaj(kontejner);
    std::cout << "]\r[";
    pauziraj(300);
    printaj(kontejner);
    std::cout << "]\r";
    pauziraj(700);
  }
  return 0;
}
