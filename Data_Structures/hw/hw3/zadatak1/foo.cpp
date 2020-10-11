#include "stack.hpp"

int main(int argc, const char **argv)
{
    stack<int> s;
    std::cout << s.size() << std::endl;
    s.push(2);
    s.push(2);
    s.push(2);
    std::cout << s.size() << std::endl;
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    return 0;
}