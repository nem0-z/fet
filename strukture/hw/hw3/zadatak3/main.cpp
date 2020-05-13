#include "queue.hpp"

int main(int argc, const char **argv)
{
    //Print samo ispisuje stanje reda kad su u pitanju size capacity te indeksi
    queue<double> s(5);
    s.print();
    try
    {
        int i = 15;
        while (i--)
        {
            s.push(i);
            std::cout << "Adding: " << i << std::endl;
        }
    }
    catch (...)
    {
        std::cout << "I jumped here because I reached my max capacity" << std::endl;
    }
    s.print();
    std::cout << "Popping: " << s.pop() << std::endl;
    std::cout << "Popping: " << s.pop() << std::endl;
    s.print();
    s.push(20.45);
    std::cout << "Adding: 20.45" << std::endl;
    s.push(21.45);
    std::cout << "Adding: 21.45\n"
              << std::endl;
    s.print();
    queue<double> x = std::move(s);
    std::cout << "Move constructor" << std::endl;
    std::cout << "New queue: " << std::endl;
    x.print();
    std::cout << "Old queue: " << std::endl;
    s.print();
    return 0;
}