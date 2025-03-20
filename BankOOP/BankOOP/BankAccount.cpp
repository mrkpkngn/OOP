#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount(int number, BankClient* client)
{
	_number = number;
	_balance = 0;
	_interestRate = 0;
	_client = client;
	_partner = nullptr;
}

BankAccount::BankAccount(int number, BankClient* client, double interestRate)
{
	_number = number;
	_balance = 0;
	_interestRate = interestRate;
	_client = client;
	_partner = nullptr;
}

BankAccount::BankAccount(int number, BankClient* client, BankClient* partner)
{
	_number = number;
	_balance = 0;
	_interestRate = 0;
	_client = client;
	_partner = partner;
}

BankAccount::BankAccount(int number, BankClient* client, BankClient* partner, double interestRate)
{
	_number = number;
	_balance = 0;
	_interestRate = interestRate;
	_client = client;
	_partner = partner;
}

int BankAccount::getNumber()
{
	return _number;
}

double BankAccount::getBalance()
{
	return _balance;
}

double BankAccount::getInterestRate()
{
	return _interestRate;
}

BankClient* BankAccount::getOwner()
{
	return _client;
}

BankClient* BankAccount::getPartner()
{
	return _partner;
}

bool BankAccount::canWithdraw(double balance)
{
	return _balance >= balance;
}

void BankAccount::deposit(double amount)
{
	_balance += amount;
}

bool BankAccount::Withdraw(double amount)
{
	if (canWithdraw(amount))
	{
		_balance -= amount;
		return true;
	}
	return false;
}

void BankAccount::addInterest()
{
	_balance += _balance * _interestRate / 100;
}

void BankAccount::printAccount() {
	cout << "\n";
	cout << "Account Number:\t\t" << _number << endl;
	cout << "Account Owner:\t\t" << _client->getName() << endl;
	if (_partner != nullptr) {
		cout << "Account Partner:\t" << _partner->getName() << endl;
	}
	cout << "Account Balance:\t" << _balance << endl;
	cout << "Account IR:\t\t" << _interestRate<< endl;
	cout << "\n";
}