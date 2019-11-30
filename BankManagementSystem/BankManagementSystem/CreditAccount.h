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
	bool deposit(Date& date, double amount, string title);	//���
	bool withdraw(Date& date, double amount, string title);	//ȡ��
	bool settle(Date& date);								//��ָ�����ڽ���

	const double getRate() const
	{
		return rate;
	}
	const double getCreditLimit() const
	{
		return creditLimit;
	}
	const double getAnnualFee() const
	{
		return annualFee;
	}

	bool show();
};

