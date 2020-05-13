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

void PostfixCalc::magic()
{
    while (operands_.size())
        operands_.pop();
}

bool PostfixCalc::isNum(const std::string &s)
{
    for (const char &c : s)
        if (c < 48 || c > 57)
            return false;
    return true;
}

bool PostfixCalc::isOperand(const char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/')
        return true;
    return false;
}

void PostfixCalc::start()
{
    try
    {
        input();
        result();
    }
    catch (const std::runtime_error &err)
    {
        std::cout << err.what();
        return;
    }
    catch (const std::string &exit)
    {
        throw exit;
    }
}

void PostfixCalc::evaluate(const char opType)
{
    if (operands_.size() >= 2)
    {
        int op1 = operands_.pop();
        int op2 = operands_.pop();
        int res = 0;
        if (opType == '+')
            res = op1 + op2;
        else if (opType == '-')
            res = op1 - op2;
        else if (opType == '/')
            res = op1 / op2;
        else if (opType == '*')
            res = op1 * op2;
        operands_.push(res);
    }
    else
        throw - 1;
}

void PostfixCalc::result()
{
    if (operands_.size() == 1)
        std::cout << "Result: " << operands_.pop() << std::endl;
    else
        std::cout << "Check Wikipedia on how to form an expression :)" << std::endl;
    magic();
}

void PostfixCalc::input()
{
    std::string expr, token;
    std::cout << "Enter expression(Q to quit): ";
    std::getline(std::cin, expr);
    std::stringstream ss(expr);
    while (ss.good())
    {
        ss >> token;
        if (isNum(token))
            operands_.push(std::stoi(token));
        else if (isOperand(token[0]))
        {
            try
            {
                evaluate(token[0]);
            }
            catch (int op)
            {
                magic();
                return;
            }
        }
        else if (token.size() == 1 && token[0] == 'Q')
        {
            std::cout << "Killing background tasks..." << std::endl;
            std::cout << "Exiting..." << std::endl; //Let me have fun cmon
            throw std::string("Out");
        }
        else
            throw std::runtime_error("Be serious.\n");
    }
}
