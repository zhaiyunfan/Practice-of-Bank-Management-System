#include"SavingsAccount.h"

SavingsAccount::SavingsAccount(Date& inDate, string inId, double inRate):Account(inDate, inId),rate(inRate), acc(inDate, 0)
{
	cout << "#" << inId << " is created" << endl;
}


bool SavingsAccount::deposit(Date& date, double amount, string title)
{
	record(date, amount,title);				//更新存入日期并向余额存入
	acc.set(date, getBalance());
	return true;
}

bool SavingsAccount::withdraw(Date& date, double amount, string title)
{
	if (amount > getBalance())
	{
		cout << "几粒花生米啊？把你醉成这样了就？/n余额不足！" << endl;
		return false;
	}
	record(date, -amount, title);				//更新存入日期并从余额取出
	acc.set(date, getBalance());
	return true;
}

bool SavingsAccount::settle(Date& date)
{
	double inteset = 0;
	inteset += acc.cal(date) * rate / 365;
	record(date, inteset,"settle");			//更新存入日期并将利息池的利息存入余额
	acc.reset(date,getBalance());				//清空利息池
	return true;
}

bool SavingsAccount::show()
{
	cout << "SavingsAccount" << "\t";
	Account::show();
	return true;
}
