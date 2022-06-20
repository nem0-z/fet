// Napisati program koji racuna sumu svih elemenata vectora brojeva (int)
// u zasebnoj niti
#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

void sum_all(int& result, vector<int> elements) {
  result = accumulate(begin(elements), end(elements), 0);
}

int main(int argc, char* argv[]) {
  const size_t elements_per_thread = 10;
  const size_t th_count = 10;
  vector<int> elements(th_count * elements_per_thread);
  iota(begin(elements), end(elements), 1);
  // int n = {1};
  // generate(begin(elements), end(elements), [&n] { return n++; });

  vector<int> partial_results(th_count);
  vector<thread> workers(th_count);
  for (auto i = 0u; i < th_count; ++i) {
    vector<int> data{begin(elements) + i * elements_per_thread,
                     begin(elements) + (i + 1) * elements_per_thread};
    workers[i] = thread{sum_all, ref(partial_results[i]), data};
  }

  for (auto& worker : workers) worker.join();

  int result = 0;
  // thread th{sum_all, ref(result), elements};
  thread th{sum_all, ref(result), partial_results};
  th.join();
  cout << "Result is: " << result << endl;
  return 0;
}
