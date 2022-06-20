// Napisati program koji racuna sumu svih elemenata vectora brojeva (int)
// koristeci veci broj niti, na nacin da se problem podijeli u onoliko
// sub-problema koliko ima niti, pri cemu svaka nit racuna sumu
// jednog dijela pocetnog vektora, a rezultat  smjesta u odgovarajuci
// element vektora medjurezultata. Konacna suma se dobija kao suma svih
// medjurezultata.
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <numeric>
#include <thread>
#include <type_traits>
#include <vector>

using namespace std;
mutex mtx;

void sum_all(int &result, vector<int> elements) {
  // for (const auto& el : elements) {
  //   lock_guard<mutex> lg{mtx};
  //   result += el;
  // }
  // result += accumulate(begin(elements), end(elements), 0);

  // alternativno (i mnogo bolje jer sve trpamo u lokalnu varijablu -> no race
  // i onda samo guardamo sabiranje sa resultom):
  int tmp = accumulate(begin(elements), end(elements), 0);
  lock_guard<mutex> lg{mtx};
  result += tmp;
}

int main(int argc, char *argv[]) {
  const size_t elements_per_thread = 1000;
  const size_t th_count = 100;
  vector<int> elements(th_count * elements_per_thread);
  iota(begin(elements), end(elements), 1);
  // int n = {1};
  // generate(begin(elements), end(elements), [&n] { return n++; });

  int result = 0;
  // vector<int> partial_results(th_count);
  vector<thread> workers(th_count);
  for (auto i = 0u; i < th_count; ++i) {
    vector<int> data{begin(elements) + i * elements_per_thread,
                     begin(elements) + (i + 1) * elements_per_thread};
    // workers[i] = thread{sum_all, ref(partial_results[i]), std::move(data)};
    workers[i] = thread{sum_all, ref(result), std::move(data)};
  }

  for (auto &worker : workers)
    worker.join();

  // thread th{sum_all, ref(result), partial_results};
  // th.join();
  cout << "ijEEEeeeEEEeeeEEEj: " << result << endl;
  return 0;
}
