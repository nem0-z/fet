#include <iostream>
#include "calculator.hpp"

int main(int argc, char const *argv[])
{
    PostfixCalc calculator;
    std::cout << "---RPN calculator---" << std::endl;
    while (true)
    {
        try
        {
            calculator.start();
        }
        catch (const std::string &e)
        {
            return 1;
        }
    }
    return 0;
}
