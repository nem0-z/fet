#include "queue.hpp"
#include <chrono>
#include <ctime>

class BankAccount
{
public:
    void newTransaction()
    {
        newTransaction_();
    }
    void applyTransaction()
    {
        applyTransaction_();
    }
    void pendingTransaction()
    {
        pendingTransaction_();
    }
    void discardPending()
    {
        discardPending_();
    }
    void balance()
    {
        getBalance_();
    }

private:
    class Transaction
    {
    public:
        double value_;
        std::string timeAndDate;
    };
    queue<Transaction> account_;
    double balance_ = 0;
    void newTransaction_();
    void applyTransaction_();
    void pendingTransaction_() const;
    void discardPending_();
    void getBalance_() const;
};

void retardInput();
int printMenu();

