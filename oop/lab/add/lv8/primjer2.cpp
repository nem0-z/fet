#include <iostream>
#include "fileA.hpp"
#include "fileB.hpp"

// Ovaj program se nece kompajlirati zbog problema sa include-anjem file-ova, tj
// fileB.hpp se include-a dva puta sto prouzrokuje gresku tipa "redefinition of
// int b"
// Jedan od nacina da se ovo izbjegne je koristenjem #pragma once
// predprocesorske direktive Drugi nacin je koristenjem #ifndef predprocesorske
// direktive

int main(void) {
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  return 0;
}
