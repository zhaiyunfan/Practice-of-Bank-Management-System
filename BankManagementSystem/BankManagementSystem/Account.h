#pragma once
#include<fstream>
#include<iostream>

using namespace std;

class SavingsAccount
{
private:
	int id;
	double accumulation;
	double balance;
	double rate;
	int lastDate;

	bool record(int date, double amount);

	double accumulate(int date);

	int monthTable(int year, int month);
	int lastDateCal(int newDate);

public:

	SavingsAccount(int inDate, int inId, double inRate);
	void show();
	bool deposit(int date, double amount);	//´æ¿î
	bool withdraw(int date, double amount);	//È¡¿î
	bool settle(int date);

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

