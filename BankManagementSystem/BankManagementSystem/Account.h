#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class SavingsAccount
{
private:
	string id;								//唯一id号，不可重复
	double accumulation;					//利息量	
	double balance;							//余额
	double rate;							//年利率		
	Date lastDate;							//上次操作时间

	static double total;					//所有帐户的总金额

	bool record(Date &date, double amount);	//存取记录
	double accumulate(Date &date);			//利息结算记录



public:

	SavingsAccount(Date &inDate, string inId, double inRate);
	void show();
	bool deposit(Date &date, double amount,string title);	//存款
	bool withdraw(Date &date, double amount,string title);	//取款
	bool settle(Date &date);								//于指定日期结算

	const string& getId()
	{
		return id;
	}
	const double getBalance()
	{
		return balance;
	}
	const double getRate()
	{
		return rate;
	}
	static const double getTotal()
	{
		return total;
	}

};