#pragma once
#include <iostream>
#include <string>
using namespace std;

class BankClient
{
private:
	int _code;
	string _name;
public:
	BankClient(int code, string name);
	int getCode();
	string getName();
};

