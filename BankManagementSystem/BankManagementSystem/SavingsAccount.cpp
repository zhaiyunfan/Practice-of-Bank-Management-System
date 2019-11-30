#include"SavingsAccount.h"

SavingsAccount::SavingsAccount(Date& inDate, string inId, double inRate):Account(inDate, inId),rate(inRate), acc(inDate, 0)
{
	cout << "#" << inId << " is created" << endl;
}


bool SavingsAccount::deposit(Date& date, double amount, string title)
{
	record(date, amount,title);				//���´������ڲ���������
	acc.set(date, getBalance());
	return true;
}

bool SavingsAccount::withdraw(Date& date, double amount, string title)
{
	if (amount > getBalance())
	{
		cout << "���������װ���������������˾ͣ�/n���㣡" << endl;
		return false;
	}
	record(date, -amount, title);				//���´������ڲ������ȡ��
	acc.set(date, getBalance());
	return true;
}

bool SavingsAccount::settle(Date& date)
{
	double inteset = 0;
	inteset += acc.cal(date) * rate / 365;
	record(date, inteset,"settle");			//���´������ڲ�����Ϣ�ص���Ϣ�������
	acc.reset(date,getBalance());				//�����Ϣ��
	return true;
}

bool SavingsAccount::show()
{
	cout << "SavingsAccount" << "\t";
	Account::show();
	return true;
}
