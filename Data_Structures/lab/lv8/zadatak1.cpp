#include <iostream>
#include <string>

class AnnotatedString {
  std::string value;

 public:
  AnnotatedString() = default;
  AnnotatedString(const char* s) : value{s} {}

  AnnotatedString(const AnnotatedString& as) : value{as.value} {
    std::cout << "copy" << std::endl;
  }
  AnnotatedString(AnnotatedString&& as) : value{std::move(as.value)} {
    std::cout << "move" << std::endl;
  }

};

class Customer {
  AnnotatedString firstname;
  AnnotatedString lastname;
 public:
  Customer(const AnnotatedString& first, const AnnotatedString& last)
      : firstname{first}, lastname{last} {}
};

int main() {

  return 0;
}

