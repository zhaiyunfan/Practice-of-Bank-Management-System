#include "AccountBill.h"

AccountBill::AccountBill(const Date& date, const Account* account, double amount, double balance, const std::string& title)
{
	this->date = date;
	this->account = account;
	this->amount = amount;
	this->balance = balance;
	this->title = title;

}

bool AccountBill::show()
{
	cout <<date.getDateStr()<< "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << title << endl;
	return true;
}
