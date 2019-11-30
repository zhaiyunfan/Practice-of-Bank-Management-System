#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <iostream>

using namespace std;

int main() {

	Date date(2008, 11, 1);//起始日期

	//建立几个账户

	Account* accounts[4];

	accounts[0] = new SavingsAccount(date, string("S3755217"), 0.015);
	accounts[1] = new SavingsAccount(date, string("02342342"), 0.015);

	accounts[2] = new CreditAccount(date, string("蒋澳然"), 2000, 0.015, 100);
	accounts[3] = new CreditAccount(date, string("蔡成龙"), 200, 0.015, 100);


	const int n = 4;

	//11月份的几笔账目
	date.dateChange(2008, 11, 5);
	accounts[0]->deposit(date, 5000, "salary");
	accounts[2]->deposit(date, 50000, "salary");
	accounts[3]->withdraw(date, 500, "do something");

	date.dateChange(2008, 11, 25);
	accounts[1]->deposit(date, 10000, "sell stock 0323");
	accounts[3]->withdraw(date, 200, "do something");
	//12月份的几笔账目
	date.dateChange(2008, 12, 5);
	accounts[0]->deposit(date, 5500, "salary");

	date.dateChange(2008, 12, 20);
	accounts[1]->withdraw(date, 4000, "buy a laptop");



	//结算所有账户并输出各个账户信息



	date.dateChange(2009, 1, 1);
	for (int i = 0; i < n; i++) 
	{
		accounts[i]->settle(date);
		accounts[i]->show();
	}

	cout << "Total: " << SavingsAccount::getTotal() << endl;

	return 0;

}