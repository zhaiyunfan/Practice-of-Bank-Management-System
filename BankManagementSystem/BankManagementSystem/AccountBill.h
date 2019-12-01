#pragma once
#include"Date.h"
#include<string>
#include"Account.h"
using namespace std;
class AccountBill
{
private:
	Date date;				//����
	const Account* account;	//�˻�
	double amount;			//���
	double balance;			//���
	std::string title;		//����
public:
	//���캯��
	AccountBill(const Date& date, const Account* account, double amount, double balance, const string& title);
	bool show() ;	//�����ǰ��¼
	string getId()
	{
		return account->getId();
	}
};

