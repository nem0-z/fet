#include <algorithm>
#include <iostream>

namespace algo {

// Returns true if pred returns true for all the elements in the range
// [first,last) or if the range is empty, and false otherwise.
template <typename InputIt, typename UnaryOpt>
bool all_of(InputIt start, InputIt end, UnaryOpt predicate) {
  while (start != end) {
    if (!predicate(*start++)) return false;
  }
  return true;
}
// Returns true if pred returns true for any of the elements in the range
// [first,last), and false otherwise.
template <typename InputIt, typename UnaryOpt>
bool any_of(InputIt start, InputIt end, UnaryOpt predicate) {
  while (start != end) {
    if (predicate(*start++)) return true;
  }
  return false;
}

// Applies function fn to each of the elements in the range [first,last).
template <typename InputIt, typename UnaryOpt>
UnaryOpt for_each(InputIt start, InputIt end, UnaryOpt predicate) {
  while (start != end) {
    predicate(*start++);
  }
  return std::move(predicate);  // since c++11
}

// Returns an iterator to the first element in the range [first,last) that
// compares equal to val. If no such element is found, the function returns
// last.
template <typename InputIt, typename T>
InputIt find(InputIt start, InputIt end, const T& val) {
  while (start != end) {
    if (*start++ == val) return start;
  }
  return end;
}

// Searches the range [first,last) for the first occurrence of two consecutive
// elements that match, and returns an iterator to the first of these two
// elements, or last if no such pair is found.
template <typename ForwardIt, typename BinaryOpt>
ForwardIt adjacent_find(ForwardIt start, ForwardIt end, BinaryOpt predicate) {
  while (start != end) {
    ForwardIt next = start++;
    if (predicate(*start, *next)) return --start;
    ++start;
  }
  return end;
}

// Returns the number of elements in the range [first,last) that compare equal
// to val.
template <typename InputIt, typename T>
T count(InputIt start, InputIt end, const T& val) {
  size_t ret = 0;
  while (start != end) {
    if (*start++ == val) ++ret;
  }
  return ret;
}

// Compares the elements in the range [first1,last1) with those in the range
// beginning at first2, and returns the first element of both sequences that
// does not match.
template <typename InputIt1, typename InputIt2>
std::pair<InputIt1, InputIt2> mismatch(InputIt1 start1, InputIt1 end1,
                                       InputIt2 start2) {
  while (start1 != end1) {
    if (*start1 != *start2) return std::make_pair(start1, start2);
    ++start1;
    ++start2;
  }
}

// Copies the elements in the range [first,last) into the range beginning at
// result.
template <typename InputIt, typename OutputIt>
OutputIt copy(InputIt start, InputIt end, OutputIt result) {
  while (start != end) *result++ = *start++;
  return result;
}

// Moves the elements in the range [first,last) into the range beginning at
// result.
template <typename InputIt, typename OutputIt>
OutputIt move(InputIt start, InputIt end, OutputIt result) {
  while (start != end) *result++ = std::move(*start++);
  return result;
}

// Moves the elements in the range [first,last) starting from the end into the
// range terminating at result.
template <typename BidirectionalIt1, typename BidirectionalIt2>
BidirectionalIt2 move_backward(BidirectionalIt1 start, BidirectionalIt1 end,
                               BidirectionalIt2 result) {
  while (end != start) *(--result) = std::move(*(--end));
  return result;
}

// Exchange values of A and B
template <typename T>
void swap(T& A, T& B) {
  T c = std::move(B);
  B = std::move(A);
  A = std::move(c);
}

// Applies op to each of the elements in the range [first1,last1) and stores the
// value returned by each operation in the range that begins at result.
template <typename InputIt, typename OutputIt, typename UnaryOpt>
OutputIt transform(InputIt start, InputIt end, OutputIt result,
                   UnaryOpt predicate) {
  while (start != end) {
    *result++ = predicate(*start++);
  }
  return result;
}

// Assigns new_value to all the elements in the range [first,last) that compare
// equal to old_value.
template <typename ForwardIt, typename T>
void replace(ForwardIt start, ForwardIt end, const T& old_val,
             const T& new_val) {
  while (start != end) {
    if (*start == old_val) *start = new_val;
    ++start;
  }
}

// Transforms the range [first,last) into a range with all the elements for
// which pred returns true removed, and returns an iterator to the new end of
// that range.
template <typename ForwardIt, typename UnaryOpt>
ForwardIt remove_if(ForwardIt start, ForwardIt end, UnaryOpt predicate) {
  ForwardIt result = start;
  while (start != end) {
    if (!predicate(*start)) {
      *result = std::move(*start);
      ++result;
    }
    ++start;
  }
  return result;
}

// Removes all but the first element from every consecutive group of equivalent
// elements in the range [first,last).
template <typename ForwardIt>
ForwardIt unique(ForwardIt start, ForwardIt end) {
  ForwardIt result = start;
  while (++start != end) {
    if (*result != *start) *(++result) = *start;
  }
  return ++result;
}

// Reverse
template <typename BidirectionalIt>
void reverse(BidirectionalIt start, BidirectionalIt end) {
  while (start != end && start != --end) {
    algo::swap(*start++, *end);
  }
}

// Shit partition implementation
template <typename BidirectionalIt, typename UnaryOpt>
void partition(BidirectionalIt start, BidirectionalIt end, UnaryOpt predicate) {
  --end;
  for (BidirectionalIt dummy = start; start != end;) {
    dummy = std::find_if(start, end, predicate);
    algo::swap(*dummy, *(start++));
  }
}
template <typename BidirectionalIt, typename UnaryOpt>
void partitionRight(BidirectionalIt start, BidirectionalIt end,
                    UnaryOpt predicate) {
  --end;
  for (BidirectionalIt dummy = start; start != end;) {
    dummy = std::find_if(start, end, predicate);
    algo::swap(*dummy, *(end--));
  }
}

// Returns true if the range [first,last) is sorted into ascending order.
template<typename InputIt>
bool is_sorted(InputIt start, InputIt end)
{
  InputIt next = start;
  while(++next!=end)
  {
    if(*next<*start++) return false;
  }
  return true;
}
}  // namespace algo

