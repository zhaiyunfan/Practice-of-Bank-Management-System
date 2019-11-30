#include "Account.h"

Account::Account(Date& date, string id)
{
	cout << date.getDateStr() << "\t";
	Account::id = id;
	balance = 0;
}

bool Account::record(Date& date, double amount, string title)
{
	balance += amount;
	total += amount;
	cout << date.getDateStr() << "\t" << id << "\t" << amount << "\t" << balance << "\t" << title << endl;
	return true;
}

bool Account::show()
{
	cout << id << "\tBalance: " << balance;
	return true;
}
double Account::total = 0;
