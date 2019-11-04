#include"Account.h"

bool SavingsAccount::record(int date, double amount)
{
	lastDate = date;
	balance = amount;
	return false;
}

double SavingsAccount::accumulate(int date)
{
	int distance = lastDateCal(date);
	double profit = distance * balance * rate / 365;
	return profit;
}

int SavingsAccount::monthTable(int year, int month)	//一个表，返回值normalYear为所给年月的1日是该年的第(normalYear-1)天
{
	int normalYear = 0;
	switch (month)
	{
	case 12:
		normalYear += 30;
	case 11:
		normalYear += 31;
	case 10:
		normalYear += 30;
	case 9:
		normalYear += 31;
	case 8:
		normalYear += 31;
	case 7:
		normalYear += 30;
	case 6:
		normalYear += 31;
	case 5:
		normalYear += 30;
	case 4:
		normalYear += 31;
	case 3:
		normalYear += 28;
	case 2:
		normalYear += 31;
	case 1:
		normalYear += 0;
	default:
		break;
	}
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))	//处理闰年
	{
		if (month > 2)
		{
			normalYear += 1;
		}
	}
	return normalYear;
}

int SavingsAccount::lastDateCal(int newDate)		//一个日期计算器，返回newDate与lastDate中间间隔的天数
{
	int tmpLastPart = 0;
	int tmpNewPart = 0;

	int lastYear = lastDate / 10000;
	int newYear = newDate / 10000;

	tmpLastPart = lastDate % 10000;
	tmpNewPart = newDate % 10000;

	int lastMonth = tmpLastPart / 100;
	int newMonth = tmpNewPart / 100;

	int lastDay = lastDate % 100;
	int newDay = newDate % 100;

	int yearLong = 0;
	int result = 0;

	if ((newYear - lastYear) > 0)
	{
		yearLong = newYear - lastYear;
	}
	else
	{
		yearLong = 0;
	}

	if (yearLong == 0)
	{
		int lastDayNumber = monthTable(lastYear, lastMonth) + lastDay;
		int newDayNumber = monthTable(newYear, newMonth) + newDay;
		result = newDayNumber - lastDayNumber;
		return result;
	}
	else
	{
		result += (365 - monthTable(lastYear, lastMonth) - lastDay);									//加上第一年剩下的日子
		result += monthTable(newYear, newMonth) + newDay;											//加上最后一年已度过的日子
		if ((lastYear % 400 == 0 || (lastYear % 4 == 0 && lastYear % 100 != 0)) && lastMonth <= 2)	//最后一年是闰年且过二月，+1
		{
			result += 1;
			for (int i = lastYear + 1; i < newYear; i++)													//加上中间的年，计算平闰年
			{
				result += monthTable(i, 12);
				result += 31;
			}
		}
		return result;
	}
}

SavingsAccount::SavingsAccount(int inDate, string& inId, double inRate)
{
	lastDate = inDate;
	id = inId;
	rate = inRate;
	balance = 0;
	accumulation = 0;
	cout << "#" << id << " is created" << endl;
}

void SavingsAccount::show()
{
	cout << "------------------------------------------" << endl;
	cout << "id:" << id << endl;
	cout << "accumulation:" << accumulation << endl;
	cout << "balance:" << balance << endl;
	cout << "total:" << total << endl;
	cout << "------------------------------------------" << endl;
}

bool SavingsAccount::deposit(int date, double amount)
{
	accumulation += accumulate(date);	//将现有利息结算并存入利息池
	lastDate = date;						//更新存入日期
	balance += amount;					//向余额存入
	total += amount;
	return true;
}

bool SavingsAccount::withdraw(int date, double amount)
{
	if (amount > balance)
	{
		cout << "几粒花生米啊？把你醉成这样了就？" << endl;
		return false;
	}
	accumulation += accumulate(date);	//将现有利息结算并存入利息池
	lastDate = date;						//更新存入日期
	balance -= amount;					//从余额取出
	total -= amount;
	return true;
}

bool SavingsAccount::settle(int date)
{
	accumulation += accumulate(date);	//将现有利息结算并存入利息池
	lastDate = date;						//更新存入日期
	balance += accumulation;				//将利息池的利息存入余额
	total += accumulation;
	accumulation = 0;					//清空利息池
	return true;
}

double SavingsAccount::total = 0;