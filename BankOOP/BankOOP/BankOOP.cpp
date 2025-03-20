#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

int main()
{
    Bank* FioBanka = new Bank(20 ,15);

    string names[20] = {
        "Alice", "Bob", "Charlie", "David", "Emma",
        "Frank", "Grace", "Henry", "Ivy", "Jack",
        "Katherine", "Liam", "Mia", "Noah", "Olivia",
        "Peter", "Quinn", "Ryan", "Sophia", "Thomas"
    };

    int currentNumberOfAccounts = 0;

    for (int i = 0; i < 20; i++) {
        FioBanka->createClient(i, names[i]);
    }

    for (int i = 0; i < 10; i++) {
        FioBanka->createAccount(currentNumberOfAccounts, FioBanka->getClient(i), 20);
        currentNumberOfAccounts++;
    }

    int x = 13;

    for (int i = 10; i < 13; i++) {
        FioBanka->createAccount(currentNumberOfAccounts, FioBanka->getClient(i), FioBanka->getClient(x));
        currentNumberOfAccounts++;
        x++;
    }

    for (int y = 13; y < 15; y++) {
        FioBanka->createAccount(currentNumberOfAccounts, FioBanka->getClient(y), FioBanka->getClient(x), 10);
        currentNumberOfAccounts++;
        x++;
    }

    double currAmount = 100;
    for (int z = 0; z < 15; z++) {
        FioBanka->getAccount(z)->deposit(currAmount);
        currAmount += 100;
    }

    FioBanka->printBank();

    cout << "---------------------------- INTEREST ADDED --------------------------------" << endl;

    FioBanka->addInterest();

    FioBanka->printBank();

    cout << "---------------------------- CAN WITHDRAW? --------------------------------" << endl;
    FioBanka->getAccount(4)->printAccount();
    cout << "Can Withdraw 100?: " << FioBanka->getAccount(4)->canWithdraw(100) << endl;
    cout<< "Can Withdraw 1000?: " << FioBanka->getAccount(4)->canWithdraw(1000) << endl;

    cout << "---------------------------- WITHDRAWAL OF 100 --------------------------------" << endl;
    FioBanka->getAccount(4)->Withdraw(100);
    FioBanka->getAccount(4)->printAccount();
}
