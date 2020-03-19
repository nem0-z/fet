
#include <sys/ioctl.h>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
size_t broj_kolona() {
  winsize sz;
  ioctl(0, TIOCGWINSZ, &sz);
  return sz.ws_col;
}

void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}

int main() {
  while (1) {
    std::string pattern{"/-\\|"};

    for (auto i = 0, s = 0; i < broj_kolona(); ++i, ++s) {
      if (!(s % 4)) s = 0;
      std::cout << '\r' << std::string(i, ' ') << pattern[s] << '\r';
      pauziraj(60);
    }
    for (size_t i = broj_kolona(), s = 0; i > 0; --i, ++s) {
      if (!(s % 4)) s = 0;
      std::cout << std::string(i - 1, ' ') << pattern[s] << '\r';
      pauziraj(60);
      std::cout << std::string(broj_kolona(), ' ') << '\r';
    }
  }
  return 0;
}

