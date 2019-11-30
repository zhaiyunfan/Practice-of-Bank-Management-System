#include "CreditAccount.h"


CreditAccount::CreditAccount(Date& inDate, string inId, double inLimit,double inRate,double inFee) :Account(inDate, inId), acc(inDate, 0), creditLimit(inLimit),rate(inRate),annualFee(inFee)
{
	cout << "#" << inId << " is created" << endl;
}

bool CreditAccount::deposit(Date& date, double amount, string title)
{
	if (getBalance() >= 0)
	{
		record(date, amount, title);
	}
	else
	{
		record(date, amount, title);
		acc.set(date, getBalance());
	}
	return true;
}

bool CreditAccount::withdraw(Date& date, double amount, string title)
{
	if (getBalance() - amount < -creditLimit)
	{
		cout << "余额不足且信用额度不足" << endl;
		return false;
	}
	else if (getBalance() - amount >= -creditLimit && getBalance() - amount < 0)
	{
		record(date, -amount, title);
		acc.set(date, getBalance());
	}
	else
	{
		record(date, -amount, title);
	}

	return true;
}

bool CreditAccount::settle(Date& date)
{
	double interest = rate * acc.cal(date);
	record(date, interest, "settle");
	acc.reset(date, (getBalance() >= 0 ? 0 : getBalance()));
	if (date.getMonth() == 1)
	{
		record(date, -annualFee, "Annual Fee");
	}
	return true;
}

bool CreditAccount::show()
{
	cout << "CreditAccount" << "\t";
	Account::show();
	cout << "\tAvailable credit:" << (getBalance() >= 0 ? creditLimit : (creditLimit + getBalance())) << endl;
	return true;
}
