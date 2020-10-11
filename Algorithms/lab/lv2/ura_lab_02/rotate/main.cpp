#include <algorithm>
#include <iostream>
#include <vector>

// uslov je poredat iteratora first <= n_first <= last
template <typename ForwardIt>
ForwardIt moj_rotate(ForwardIt first, ForwardIt n_first, ForwardIt last) {
  if (first == n_first) return last;
  if (n_first == last) return first;

  ForwardIt whereIsFirstNow = first;

  while(n_first != last){
    if(whereIsFirstNow == first) whereIsFirstNow = n_first;
    //cuva nam poziciju prvog 
    std::swap(*first,*n_first);
    first++;
    n_first++;
  }
  moj_rotate(first,whereIsFirstNow,last);
  //ovo smo odradili jer bez ovog nam se poremeti poredak ovih vamo desno
  //pa ga ovako vracamo
  return first;
}

int main() {
  std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto print = [&numbers]() {
    for (auto n : numbers) std::cout << n << ' ';
    std::cout << std::endl;
  };

  print();
  moj_rotate(numbers.begin(), numbers.begin() + 3, numbers.end()-1);
  print();

  return 0;
}
