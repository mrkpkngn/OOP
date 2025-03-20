#pragma once
#include <iostream>
#include "BankClient.h"
using namespace std;

class BankAccount
{
private:
	int _number;
	double _balance;
	double _interestRate;

	BankClient* _client;
	BankClient* _partner;

public:
	BankAccount(int number, BankClient* client);
	BankAccount(int number, BankClient* client, double interestRate);
	BankAccount(int number, BankClient* client, BankClient* partner);
	BankAccount(int number, BankClient* client, BankClient* partner, double interestRate);



	int getNumber();
	double getBalance();
	double getInterestRate();
	BankClient* getOwner();
	BankClient* getPartner();
	bool canWithdraw(double balance);

	void deposit(double amount);
	bool Withdraw(double amount);
	void addInterest();
	
	void printAccount();
};

