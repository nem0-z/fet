#include <chrono>
#include <iostream>

// std::chrono
//
// std::chrono zaglavlje za rad sa vremenom.
// Dva osnovna tipa:
// *duration* tipovi (nanosekunde, milisekunde, sati i slicno)
// *time_point* tipovi (moment u vremenu, biljezi se kao duration koji je
//     protekao od neke epohe, pocetka kalendara)
//
// Potpisi templetizirani, preporucena je upotreba *auto* dedukcije tipova.

int main(int argc, char *argv[]) {

  // time_point
  // vrijeme u nanosekundama od Unix epohe (1.1.1970.).
  auto now = std::chrono::system_clock::now();

  // zelimo da izmjerimo vrijeme izvrsenja ovog dijela koda
  std::cout << "Hello, world!" << std::endl;

  // od novog time pointa oduzmemeo stari, dobijemo proteklo vrijeme
  auto finish = std::chrono::system_clock::now();
  auto elapsed = finish - now;
  std::cout << elapsed.count() << "ns" << std::endl;

  return 0;
}
