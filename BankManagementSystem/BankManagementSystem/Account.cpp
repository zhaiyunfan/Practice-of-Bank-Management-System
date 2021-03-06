﻿#include "Account.h"

Account::Account(const Date& date, string id,string key)
{
	Account::id = id;
	Account::key = key;
	balance = 0;
}

bool Account::record(Date& date, double amount, string title)
{
	balance += amount;
	total += amount;
	cout << date.getDateStr() << "\t" << id << "\t" << amount << "\t" << balance << "\t" << title << endl;
	return true;
}

bool Account::keyCheck(string& inKey) const
{
	if (key == inKey)
	{
		return true;
	}
	else
	{
		return false;

	}
}

bool Account::show()
{
	cout << id << "\tBalance: " << balance;
	return true;
}
double Account::total = 0;
