#include "Account.h"

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

int SavingsAccount::monthTable(int year, int month)	//һ��������ֵnormalYearΪ�������µ�1���Ǹ���ĵ�(normalYear-1)��
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
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))	//��������
	{
		if (month > 2)
		{
			normalYear += 1;
		}
	}
	return normalYear;
}

int SavingsAccount::lastDateCal(int newDate)		//һ�����ڼ�����������newDate��lastDate�м���������
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
		result += (365 - monthTable(lastYear, lastMonth) - lastDay);									//���ϵ�һ��ʣ�µ�����
		result += monthTable(newYear, newMonth) + newDay;											//�������һ���Ѷȹ�������
		if ((lastYear % 400 == 0 || (lastYear % 4 == 0 && lastYear % 100 != 0)) && lastMonth <= 2)	//���һ���������ҹ����£�+1
		{
			result += 1;
			for (int i = lastYear + 1; i < newYear; i++)													//�����м���꣬����ƽ����
			{
				result += monthTable(i, 12);
				result += 31;
			}
		}
		return result;
	}
}

SavingsAccount::SavingsAccount(int inDate, int inId, double inRate)
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
	cout << "------------------------------------------" << endl;
}

bool SavingsAccount::deposit(int date, double amount)
{
	accumulation += accumulate(date);	//��������Ϣ���㲢������Ϣ��
	lastDate = date;						//���´�������
	balance += amount;					//��������
	return true;
}

bool SavingsAccount::withdraw(int date, double amount)
{
	if (amount > balance)
	{
		cout << "���������װ���������������˾ͣ�" << endl;
		return false;
	}
	accumulation += accumulate(date);	//��������Ϣ���㲢������Ϣ��
	lastDate = date;						//���´�������
	balance -= amount;					//�����ȡ��
	return true;
}

bool SavingsAccount::settle(int date)
{
	accumulation += accumulate(date);	//��������Ϣ���㲢������Ϣ��
	lastDate = date;						//���´�������
	balance += accumulation;				//����Ϣ�ص���Ϣ�������
	accumulation = 0;					//�����Ϣ��
	return true;
}

