#include <list>
#include <string>
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Napisati program koji uzima iteratore na početak i kraj nekog range-a te
// vrijednost koju korisnik traži. Ukoliko se vrijednost nalazi unutar range-a,
// nazad vratiti iterator na pronađeni element, u suprotnom vratiti kraj
// proslijeđene sekvence.

namespace v11 {

    template<typename Iter,typename Key>
    Iter find(Iter start, Iter end, Key match)
    {
        while(start!=end)
        {
          if (*start == match) return start;
          ++start;
        }
        return end;
    }

}  // namespace v11

TEST_CASE("Expects to return end on empty vector") {
  std::vector<int> v;
  auto it = v11::find(v.begin(), v.end(), 10);
  CHECK_EQ(it, v.end());
}

TEST_CASE("Expects to return iterator to only element in container") {
  std::vector<double> v{1.};
  auto it = v11::find(v.begin(), v.end(), 1.);
  CHECK_EQ(it, v.begin());
}
//
TEST_CASE("Expects to return iterator to first element in container") {
  std::list<int> l{7, 5};
  auto it = v11::find(l.begin(), l.end(), 7);
  CHECK_EQ(it, l.begin());
}

TEST_CASE("Expects to return end when only one element in container") {
  std::vector<int> v{1};
  auto it = v11::find(v.begin(), v.end(), 7);
  CHECK_EQ(it, v.end());
}
//
TEST_CASE("Expects to return iterator to second element in container") {
  std::vector<int> v{7, 2};
  auto it = v11::find(v.begin(), v.end(), 2);
  CHECK_EQ(it, v.end() - 1);
}

TEST_CASE("Expects to find element in the middle of container") {
  std::list<std::string> l{"this", "is",    "an",  "exercise",
                           "with", "lists", "and", "templates"};
  auto it = v11::find(l.begin(), l.end(), "exercise");
  auto exerciseIt = l.begin();
  std::advance(exerciseIt, 3);
  CHECK_EQ(it, exerciseIt);
  auto it2 = v11::find(l.begin(), l.end(), "asd");
  CHECK_EQ(it2, l.end());
}
