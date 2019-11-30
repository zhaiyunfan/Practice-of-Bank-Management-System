#include "CreditAccount.h"


CreditAccount::CreditAccount(Date& inDate, string inId, double inLimit,double inRate,double inFee) :Account(inDate, inId), acc(inDate, 0), creditLimit(inLimit),rate(inRate),annualFee(inFee)
{
	cout <<"Credit Account"<< "#" << inId << " is created" << endl;
}

bool CreditAccount::deposit(Date& date, double amount, string title)
{
	record(date, amount, title);
	acc.set(date, getDebt());
	return true;
}

bool CreditAccount::withdraw(Date& date, double amount, string title)
{
	if (getBalance() - amount < -creditLimit)
	{
		cout << "余额不足且信用额度不足" << endl;
		return false;
	}
	else 
	{
		record(date, -amount, title);
		acc.set(date, getDebt());
	}

	return true;
}

bool CreditAccount::settle(Date& date)
{
	double interest = rate * acc.calSum(date);
	record(date, interest, "settle");
	acc.reset(date, getDebt());
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
