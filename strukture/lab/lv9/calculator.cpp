#include <iostream>

// 3 * 7 + 8 - 10

struct Node
{
    Node *leftChild;
    Node *rightChild;
    virtual int evaluate() = 0;
};

struct NumericNode : public Node
{
    int value;
    NumericNode(int v) : value{v} {}

    int evaluate() override
    {
        return value;
    }
};

struct OperationNode : public Node
{
    char operation;
    OperationNode(char c) : operation{c} {}

    int evaluate() override
    {
        if (leftChild == nullptr || rightChild == nullptr)
            throw std::runtime_error("Invalid expression.");
        if (operation == '+')
        {
            return leftChild->evaluate() + rightChild->evaluate();
        }
        else if (operation == '-')
        {
            return leftChild->evaluate() - rightChild->evaluate();
        }
        else if (operation == '/')
        {
            return leftChild->evaluate() / rightChild->evaluate();
        }
        else if (operation == '*')
        {
            return leftChild->evaluate() * rightChild->evaluate();
        }
        else
            throw std::runtime_error("Invalid operator");
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Node *a = new OperationNode('+');
    //ponovi oop stuff

    Node *root = new OperationNode('-');
    Node *operationPlus = new OperationNode('+');
    Node *number10 = new NumericNode(10);

    Node *operationMultiply = new OperationNode('*');
    Node *number8 = new NumericNode(8);

    operationPlus->leftChild = operationMultiply;
    operationPlus->rightChild = number8;

    Node *number3 = new NumericNode(3);
    Node *number7 = new NumericNode(7);

    operationMultiply->leftChild = number3;
    operationMultiply->rightChild = number7;

    root->leftChild = operationPlus;
    root->rightChild = number10;

    std::cout << root->evaluate() << std::endl;

    return 0;
}
