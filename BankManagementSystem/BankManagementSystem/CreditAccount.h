#pragma once
#include "Account.h"
class CreditAccount :public Account
{
private:
	Accumulator acc;
	double creditLimit;
	double rate;
	double annualFee;
public:
	CreditAccount(Date& inDate, string inId, double inLimit,double inRate,double inFee);
	bool deposit(Date& date, double amount, string title);	//存款
	bool withdraw(Date& date, double amount, string title);	//取款
	bool settle(Date& date);								//于指定日期结算

	const double getRate()
	{
		return rate;
	}
	const double getCreditLimit()
	{
		return creditLimit;
	}
	const double getAnnualFee()
	{
		return annualFee;
	}

	bool show();
};

