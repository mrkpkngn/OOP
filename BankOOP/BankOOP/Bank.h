#pragma once
#include <iostream>
#include "BankAccount.h"
using namespace std;
class Bank
{
private:
	BankClient** _clients;
	int _clientsCount;

	BankAccount** _accounts;
	int _accountsCount;

public:
	Bank(int clientsCount, int accountsCount);
	~Bank();

	BankClient* getClient(int code);
	BankAccount* getAccount(int number);

	BankClient* createClient(int code, string name);
	BankAccount* createAccount(int number, BankClient* client);
	BankAccount* createAccount(int number, BankClient* client, double interestRate);
	BankAccount* createAccount(int number, BankClient* client, BankClient* partner);
	BankAccount* createAccount(int number, BankClient* client, BankClient* partner, double interestRate);
	void addInterest();

	void printBank();
};

