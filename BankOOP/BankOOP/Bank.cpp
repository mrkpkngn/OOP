#include "Bank.h"

Bank::Bank(int clientsCount, int accountsCount)
{
	_clients = new BankClient * [clientsCount] {nullptr};
	_clientsCount = 0;
	_accounts = new BankAccount * [accountsCount] {nullptr};
	_accountsCount = 0;
}

Bank::~Bank() {
	for (int i = 0; i < _clientsCount; i++) {
		if (_clients[i] != nullptr) {
			delete _clients[i];
			_clients[i] = nullptr;
		}
	}

	for (int i = 0; i < _accountsCount; i++) {
		if (_accounts[i] != nullptr) {
			delete _accounts[i];
			_accounts[i] = nullptr;
		}
	}

	delete[] _clients;
	_clients = nullptr;

	delete[] _accounts;
	_accounts = nullptr;
}

BankClient* Bank::getClient(int code) {
	for (int i = 0; i < _clientsCount; i++) {
		if (_clients[i] != nullptr && _clients[i]->getCode() == code){
			return _clients[i];
		}
	}
	return nullptr;
}

BankAccount* Bank::getAccount(int number) {
	for (int i = 0; i < _accountsCount; i++) {
		if (_accounts[i] != nullptr && _accounts[i]->getNumber() == number) {
			return _accounts[i];
		}
	}
	return nullptr;
}

BankClient* Bank::createClient(int code, string name) {
	BankClient* newClient = new BankClient(code, name);
	_clients[_clientsCount] = newClient;
	_clientsCount++;
	return newClient;
}

BankAccount* Bank::createAccount(int number, BankClient* client) {
	BankAccount* newBankAccount = new BankAccount(number, client);
	_accounts[_accountsCount] = newBankAccount;
	_accountsCount++;
	return newBankAccount;
}

BankAccount* Bank::createAccount(int number, BankClient* client, double interestRate) {
	BankAccount* newBankAccount = new BankAccount(number, client, interestRate);
	_accounts[_accountsCount] = newBankAccount;
	_accountsCount++;
	return newBankAccount;
}

BankAccount* Bank::createAccount(int number, BankClient* client, BankClient* partner) {
	BankAccount* newBankAccount = new BankAccount(number, client, partner);
	_accounts[_accountsCount] = newBankAccount;
	_accountsCount++;
	return newBankAccount;
}

BankAccount* Bank::createAccount(int number, BankClient* client, BankClient* partner, double interestRate) {
	BankAccount* newBankAccount = new BankAccount(number, client, partner, interestRate);
	_accounts[_accountsCount] = newBankAccount;
	_accountsCount++;
	return newBankAccount;
}

void Bank::addInterest() {
	for (int i = 0; i < _accountsCount; i++) {
		_accounts[i]->addInterest();
	}
}

void Bank::printBank() {
	cout << "FIO BANKA" << endl;
	for (int x = 0; x < _accountsCount; x++) {
		_accounts[x]->printAccount();
	}
}