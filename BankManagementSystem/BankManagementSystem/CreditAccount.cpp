#include "CreditAccount.h"


CreditAccount::CreditAccount(Date& inDate, string inId,string inKey, double inLimit,double inRate,double inFee) :Account(inDate, inId,inKey), acc(inDate, 0), creditLimit(inLimit),rate(inRate),annualFee(inFee)
{
	if (inLimit < 0 || inRate < 0 || inFee < 0)
	{
		throw out_of_range("negative enter");
	}
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
		cout << "别借了别借了，还的上吗您？\n余额不足且信用额度不足，请先偿还借款" << endl;
		return false;
	}
	else 
	{
		record(date, -amount, title);
		acc.set(date, getDebt());
		return true;
	}	
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
