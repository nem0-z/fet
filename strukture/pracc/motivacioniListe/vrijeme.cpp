#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <vector>

int main() {
  auto start_time = std::chrono::high_resolution_clock::now();

  std::list<int> lista;
  char instr;
  int num;
  while (std::cin >> instr) {
    if (instr == 'i') {
      std::cin >> num;
      if (num < lista.front())
        lista.push_front(num);
      else if (num > lista.back())
        lista.push_back(num);
    } else {
      std::cin >> instr;
      if (instr == '>')
        lista.pop_back();
      else if (instr == '<')
        lista.pop_front();
    }
  }
  int max = lista.back();
  int min = lista.front();
  int gap = max - min;
  std::cout << "Ukupan broj brojeva u listi je: " << lista.size() << std::endl;
  std::cout << "Max: " << max << std::endl;
  std::cout << "Min: " << min << std::endl;
  std::cout << "Gap: " << gap << std::endl;
  std::cout << "Nedostaju brojevi: ";
  // get this done
  auto it = lista.begin();
  for (int i = min; i <= max; ++i) {
    if (i != *it) {
      printf("%d ",i);
    } else {
      ++it;
    }
  }
  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> interval = end_time - start_time;

  std::cout << "\nUkupna duzina intervala vremena je: " << interval.count()
            << " sekundi." << std::endl;

  return 0;
}
