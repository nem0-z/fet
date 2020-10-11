#include "bankAccount.hpp"

int main(int argc, char const *argv[])
{
    BankAccount account;
    int choice = -1;
    while (choice != 6)
    {
        choice = printMenu();
        if (choice == 1)
            account.newTransaction();
        else if (choice == 2)
            account.applyTransaction();
        else if (choice == 3)
            account.pendingTransaction();
        else if (choice == 4)
            account.discardPending();
        else if (choice == 5)
            account.balance();
    }
    return 0;
}
