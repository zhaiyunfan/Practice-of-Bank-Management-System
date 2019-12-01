#pragma once
#include<string>
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "AccountBill.h"
#include "AccoutException.h"
#include <vector>
#include <map>
#include <utility>
#include<fstream>
#include<sstream>
#include <stdexcept>

using namespace std;

bool fileLoad(Date&date,ifstream& inPut, map<string, Account*>& accounts, multimap<Date, AccountBill>& myBill)
{
	Account* p = NULL;
	map<string, Account*>::iterator iter;

	stringstream s;
	string command;
	string line;
	while (!inPut.eof())
	{
		getline(inPut, command);
		if (command == "a")
		{
			string id, key;
			int type;
			getline(inPut, line);
			s << line;
			s >> type;
			s.clear();
			getline(inPut, line);
			getline(inPut, id);
			getline(inPut, key);
			if (type == 1)
			{
				double sRate;
				getline(inPut, line);
				s << line;
				s >> sRate;
				s.clear();
				accounts.insert(pair<string, Account*>(id, new SavingsAccount(date, id, key, sRate)));
			}
			else if (type == 2)
			{
				double mylimit, myrate, myfee;
				getline(inPut, line);
				s << line;
				s >> mylimit;
				s.clear();
				getline(inPut, line);
				s << line;
				s >> myrate;
				s.clear();
				getline(inPut, line);
				s << line;
				s >> myfee;
				s.clear();
				accounts.insert(pair<string, Account*>(id, new CreditAccount(date, id, key, mylimit, myrate, myfee)));
			}
			else
			{
				cout << "#" << id << "loading error!" << endl;
				return false;
			}
		}
		else if (command == "d" || command == "w")
		{
			string id, title;
			double amount, balance;
			getline(inPut, line);
			getline(inPut, id);
			getline(inPut, line);
			s << line;
			s >> amount;
			s.clear();
			getline(inPut, line);
			s << line;
			s >> balance;
			s.clear();
			getline(inPut, title);

			iter = accounts.find(id);
			p = iter->second;

			if (command == "d")
			{
				p->deposit(date, amount, title);
			}
			else
			{
				p->withdraw(date, amount, title);
			}
			myBill.insert(pair<Date, AccountBill>(date, AccountBill(date, p, amount, p->getBalance(), title)));
		}
		else if (command == "n")
		{
			if (date.getMonth() == 12)
			{
				date.dateChange(date.getYear() + 1, 1, 1);
				cout << "now is" << date.getDateStr() << endl;
				for (auto& it : accounts)
				{
					it.second->settle(date);
				}

			}
			else
			{
				date.dateChange(date.getYear(), date.getMonth() + 1, 1);
				cout << "now is" << date.getDateStr() << endl;
				for (auto& it : accounts)
				{
					it.second->settle(date);
				}
			}
		}
		else if (command == "c")
		{
			int myDay;
			getline(inPut, line);
			s << line;
			s >> myDay;
			s.clear();
			date.dateChange(date.getYear(), date.getMonth(), myDay);
			cout << "now is" << date.getDateStr() << endl;
		}
	}
	return true;
}