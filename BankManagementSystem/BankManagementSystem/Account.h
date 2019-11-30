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
	string& getId()
	{
		return id;
	}
	double getBalance()
	{
		return balance;
	}
	static double getTotal()
	{
		return total;
	}
	bool show();
};

