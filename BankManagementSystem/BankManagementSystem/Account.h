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
	double balance;
	static double total;
public:
	Account(Date& date, string id);
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
	bool show();
};

