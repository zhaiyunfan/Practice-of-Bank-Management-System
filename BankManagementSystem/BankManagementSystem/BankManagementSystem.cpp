#include "Account.h"
#include <iostream>

using namespace std;

int main()
{

	//建立几个账户
	string id0 = "21325302";
	string id1 = "58320212";
	SavingsAccount sa0(19970324, id0, 0.015);
	SavingsAccount sa1(19740324, id1, 0.015);



	//几笔账目

	sa0.deposit(19740324, 5000);
	sa1.deposit(19990324, 10000);
	sa0.deposit(20190324, 5500);
	sa1.withdraw(20190324, 4000);



	//开户后第90天到了银行的计息日，结算所有账户的年息

	sa0.settle(20190324);
	sa1.settle(20190324);
	cout << SavingsAccount::getTotal() << endl;


	//输出各个账户信息

	sa0.show(); cout << endl;
	sa1.show(); cout << endl;


	return 0;

}