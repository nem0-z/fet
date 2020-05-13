#include "bankAccount.hpp"

using std::chrono::system_clock;
void BankAccount::newTransaction_()
{
    Transaction newT;
    std::cout << "Enter amount: ";
    if (std::cin >> newT.value_)
    {
        auto currentTime = system_clock::now();
        std::time_t time_ = system_clock::to_time_t(currentTime);
        newT.timeAndDate = std::move(std::ctime(&time_));
        account_.enqueue(std::move(newT));
    }
    else
        retardInput();
}

void BankAccount::applyTransaction_()
{
    try
    {
        Transaction toApply = account_.dequeue();
        balance_ += toApply.value_;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "No pending transactions" << std::endl;
    }
}

void BankAccount::pendingTransaction_() const
{
    try
    {
        Transaction pending = account_.top();
        std::cout << "---Pending transaction review---" << std::endl;
        std::cout << "Time and date: " << pending.timeAndDate;
        std::cout << "Amount: " << pending.value_ << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "No pending transactions" << std::endl;
    }
}

void BankAccount::discardPending_()
{
    try
    {
        account_.dequeue();
    }
    catch (std::runtime_error e)
    {
        std::cout << "No pending transactions" << std::endl;
    }
}

void BankAccount::getBalance_() const
{
    std::cout << "Your balance is: " << balance_ << std::endl;
    if (balance_ < 0)
        std::cout << "I am sorry for your loss :)" << std::endl;
}

void retardInput()
{
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Nice try" << std::endl;
}

int printMenu()
{
    int choice;
    const std::string decor(50, '*');
    std::cout << decor << std::endl;
    std::cout << "Actions: " << std::endl;
    std::cout << "\t1. New transaction\n"
              << "\t2. Apply transaction\n"
              << "\t3. Pending transaction\n"
              << "\t4. Discard pending transaction\n"
              << "\t5. Balance\n"
              << "\t6. Exit\n";
    std::cout << "Your choice? ";
    if (std::cin >> choice)
        return choice;
    else
        retardInput();
    return -1;
}
