#pragma once
#include<string>
#include "SavingsAccount.h"
#include "CreditAccount.h"
using namespace std;

string getBillStr(Date &date,const double amount,const string &title,const Account*p) 
{
	string bill;
	bill.append(date.getDateStr());
	bill.append(string("\t"));
	bill.append(string("deposit"));
	bill.append(string("\t"));
	bill.append(to_string(amount));
	bill.append(string("\t"));
	bill.append(to_string(p->getBalance()));
	bill.append(string("\t"));
	bill.append(title);
	return bill;
}