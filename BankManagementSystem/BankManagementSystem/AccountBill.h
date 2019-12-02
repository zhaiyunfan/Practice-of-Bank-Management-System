#pragma once
#include"Date.h"
#include<string>
#include"Account.h"
using namespace std;
class AccountBill
{
private:
	Date date;				//日期
	const Account* account;	//账户
	double amount;			//金额
	double balance;			//余额
	string title;			//描述
public:
	//构造函数
	AccountBill(const Date& date, const Account* account, const double amount, const double balance, const string& title);
	bool show() ;	//输出当前记录
	string getId()
	{
		return account->getId();
	}
	double getAmount()
	{
		return amount;
	}
};

