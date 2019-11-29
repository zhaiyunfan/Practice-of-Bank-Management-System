#include"Account.h"

bool SavingsAccount::record(Date &date, double amount)
{
	accumulation += accumulate(date);	//将现有利息结算并存入利息池
	lastDate = date;					//更新存取日期
	balance += amount;					//更新余额
	total += amount;					//更新总额
	return true;
}

double SavingsAccount::accumulate(Date &date)
{
	int distance = lastDate.distanceCal(date);
	double profit = distance * balance * rate / 365;
	return profit;
}


SavingsAccount::SavingsAccount(Date &inDate, string inId, double inRate)
{
	lastDate = inDate;
	id = inId;
	rate = inRate;
	balance = 0;
	accumulation = 0;
	cout << "#" << id << " is created" << endl;
}

void SavingsAccount::show()				//打印单独用户信息
{
	cout << "------------------------------------------" << endl;
	cout << "id:" << id << endl;
	cout << "accumulation:" << accumulation << endl;
	cout << "balance:" << balance << endl;
	cout << "------------------------------------------" << endl;
}

bool SavingsAccount::deposit(Date &date, double amount,string title)
{
	record(date, amount);				//更新存入日期并向余额存入
	cout << date.getDateStr() << "\t" << id << "\t" << amount << "\t" << balance << "\t" << title << endl;
	return true;
}

bool SavingsAccount::withdraw(Date &date, double amount,string title)
{
	if (amount > balance)
	{
		cout << "几粒花生米啊？把你醉成这样了就？/n余额不足！" << endl;
		return false;
	}
	record(date, -amount);				//更新存入日期并从余额取出
	cout << date.getDateStr() << "\t" << id << "\t" << -amount << "\t" << balance << "\t" << title << endl;
	return true;
}

bool SavingsAccount::settle(Date &date)
{
	record(date, accumulation);			//更新存入日期并将利息池的利息存入余额
	accumulation = 0;					//清空利息池
	return true;
}

double SavingsAccount::total = 0;