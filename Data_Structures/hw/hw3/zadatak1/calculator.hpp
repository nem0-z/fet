#pragma once
#include "stack.hpp"
#include <sstream>
#include <vector>
#include <string>

class PostfixCalc
{
public:
    void start();

private:
    stack<int> operands_;
    void input();
    void evaluate(const char);
    void result();
    void magic();
    bool isNum(const std::string &);
    bool isOperand(const char);
};

