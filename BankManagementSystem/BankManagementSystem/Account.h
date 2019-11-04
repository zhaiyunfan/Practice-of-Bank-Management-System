#pragma once
#include<fstream>
#include<iostream>

using namespace std;

class SavingsAccount
{
private:
	int id;					//唯一id号，不可重复
	double accumulation;		//利息量	
	double balance;			//余额
	double rate;				//年利率
	int lastDate;			//

	bool record(int date, double amount);	//强制置数

	double accumulate(int date);

	int monthTable(int year, int month);
	int lastDateCal(int newDate);

public:

	SavingsAccount(int inDate, int inId, double inRate);
	void show();
	bool deposit(int date, double amount);	//存款
	bool withdraw(int date, double amount);	//取款
	bool settle(int date);					//于指定日期结算

	int getId()
	{
		return id;
	}
	double getBalance()
	{
		return balance;
	}
	double getRate()
	{
		return rate;
	}

};

