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
void cisti(char a) { std::cout << '\r' << std::string(a, ' ') << '\r'; }

int main() {
  while (1) {
    char a, x = 1;
    for (int i = 0; i < (a = broj_kolona()); i++) {
      cisti(a);
      std::cout << std::string(i, ' ');
      if (x == 1) {
        std::cout << '/';
        --x;
      } else if (x == 0) {
        std::cout << '-';
        --x;
      } else if (x == -1) {
        std::cout << '\\';
        --x;
      } else {
        std::cout << '|';
        x = 1;
      }
      std::cout << std::string(a - i - 1, ' ');
      pauziraj(70);
    }
    for (int i = 0; i < (a = broj_kolona()); i++) {
      cisti(a);
      std::cout << std::string(a - i - 1, ' ');
      if (x == 1) {
        std::cout << '/';
        --x;
      } else if (x == 0) {
        std::cout << '-';
        --x;
      } else if (x == -1) {
        std::cout << '\\';
        --x;
      } else {
        std::cout << '|';
        x = 1;
      }
      std::cout << std::string(i, ' ');
      pauziraj(70);
    }
  }
  return 0;
}

