#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Date.h"
#include"Account.h"
using namespace std;

class SavingsAccount :public Account
{
private:
	Accumulator acc;						//�ۼ���
	double rate;							//������		
public:

	SavingsAccount(Date& inDate, string inId, double inRate);
	bool deposit(Date& date, double amount, string title);	//���
	bool withdraw(Date& date, double amount, string title);	//ȡ��
	bool settle(Date& date);								//��ָ�����ڽ���
	bool show();

	const double getRate() const
	{
		return rate;
	}
	

};