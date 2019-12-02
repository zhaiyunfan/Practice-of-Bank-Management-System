#pragma once
#include<string>
#include<iostream>
#include"Date.h"
#include"Accumulator.h"
using namespace std;

class Account
{
private:
	string id;		
	string key;
	double balance;
	static double total;
public:
	Account(const Date& date, string id, string key);
	bool record(Date& date, double amount, string title);
	const string& getId() const
	{
		return id;
	}
	double getBalance() const
	{
		return balance;
	}
	static double getTotal()
	{
		return total;
	}

	bool keyCheck(string& inKey)const;
	bool virtual show();
	bool virtual deposit(Date& date, double amount, string title) = 0;	//存款
	bool virtual withdraw(Date& date, double amount, string title) = 0;	//取款
	bool virtual settle(Date& date) = 0;											//结算
};

