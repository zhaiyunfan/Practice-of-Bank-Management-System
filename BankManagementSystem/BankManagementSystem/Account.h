#pragma once
#include<fstream>
#include<iostream>

using namespace std;

class SavingsAccount
{
private:
	int id;					//Ψһid�ţ������ظ�
	double accumulation;		//��Ϣ��	
	double balance;			//���
	double rate;				//������
	int lastDate;			//

	bool record(int date, double amount);	//ǿ������

	double accumulate(int date);

	int monthTable(int year, int month);
	int lastDateCal(int newDate);

public:

	SavingsAccount(int inDate, int inId, double inRate);
	void show();
	bool deposit(int date, double amount);	//���
	bool withdraw(int date, double amount);	//ȡ��
	bool settle(int date);					//��ָ�����ڽ���

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

