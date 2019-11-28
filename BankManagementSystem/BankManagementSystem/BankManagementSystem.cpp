#include "Account.h"
#include <iostream>

using namespace std;

//int main()
//{
//
//	//建立几个账户
//	string id0 = "21325302";
//	string id1 = "58320212";
//	SavingsAccount sa0(19970324, id0, 0.015);
//	SavingsAccount sa1(19740324, id1, 0.015);
//
//
//
//	//几笔账目
//
//	sa0.deposit(19740324, 5000);
//	sa1.deposit(19990324, 10000);
//	sa0.deposit(20190324, 5500);
//	sa1.withdraw(20190324, 4000);
//
//
//
//	//开户后第90天到了银行的计息日，结算所有账户的年息
//
//	sa0.settle(20190324);
//	sa1.settle(20190324);
//	cout << SavingsAccount::getTotal() << endl;
//
//
//	//输出各个账户信息
//
//	sa0.show(); cout << endl;
//	sa1.show(); cout << endl;
//
//
//	return 0;
//
//}
int main() {

	Date date(2008, 11, 1);//起始日期

	//建立几个账户

	SavingsAccount* accounts[2];

	accounts[0] = new SavingsAccount(date, string("S3755217"), 0.015);

	accounts[1] = new SavingsAccount(date, string("02342342"), 0.015);


	const int n = 2;

	//11月份的几笔账目
	date.dateChange(2008, 11, 5);
	accounts[0]->deposit(date, 5000);

	date.dateChange(2008, 11, 25);
	accounts[1]->deposit(date, 10000);

	//12月份的几笔账目
	date.dateChange(2008, 12, 5);
	accounts[0]->deposit(date, 5500);

	date.dateChange(2008, 12, 20);
	accounts[1]->withdraw(date, 4000);



	//结算所有账户并输出各个账户信息

	cout << endl;

	date.dateChange(2009, 1, 1);
	for (int i = 0; i < n; i++) 
	{
		accounts[i]->settle(date);
		accounts[i]->show();
		cout << endl;
	}

	cout << "Total: " << SavingsAccount::getTotal() << endl;

	return 0;

}