#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Date.h"
#include"Account.h"
using namespace std;

class SavingsAccount :public Account
{
private:
	Accumulator acc;						//累加器
	double rate;							//年利率		
public:

	SavingsAccount(Date& inDate, string inId, double inRate);
	bool deposit(Date& date, double amount, string title);	//存款
	bool withdraw(Date& date, double amount, string title);	//取款
	bool settle(Date& date);								//于指定日期结算
	bool show();

	const double getRate() const
	{
		return rate;
	}
	

};