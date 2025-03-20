#include "BankClient.h"

BankClient::BankClient(int code, string name)
{
	_code = code;
	_name = name;
}

int BankClient::getCode()
{
	return _code;
}

string BankClient::getName()
{
	return _name;
}