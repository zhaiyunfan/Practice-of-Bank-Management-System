#include"BankManagementSystem.h"

using namespace std;

int main() 
{
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);

	int oOri = 0;
	ofstream outPut;	
	ifstream inPut;

	Date date(2008, 11, 1);//起始日期

	map<string,Account*> accounts;
	map<string, Account*>::iterator iter;
	multimap<Date, AccountBill>myBill;

	cout << "Welcome to Bank-Management-System" << endl;
	cout << "do you want to load last saving?" << endl;
	cout << "1 YES,0 NO" << endl;
	cin >> oOri;
	if (oOri == 1)
	{
		inPut.open("file.txt", ios::in);
		fileLoad(date, inPut, accounts, myBill);
		inPut.close();
	}
	outPut.open("file.txt", ios::app | ios::out);
	cout << "Next is the operating instructions:" << endl;

	char command;
	string commandDeal;
	bool isLoginin = false;
	Account* p = NULL;
	double myAmount;
	string id, key, title;
	do
	{		
		if (isLoginin)
		{
			cout << "(d)deposit (w)withdraw (s)show (q)query (c)change day (n)next month (o)logout" << endl;
			try
			{				
				cin >> command;
				getline(cin, commandDeal);
				if (commandDeal.size() > 1)
				{
					throw runtime_error("command size error");
				}
			}
			catch (const std::exception& )
			{
				cout << "command size overflow" << endl;
				continue;
			}
			
			switch (command)
			{
			case 'd':
			{
				cout << "press amount and title" << endl;
				try
				{
					cin >> myAmount;
					if (myAmount <= 0)
					{
						throw AccoutException("deposit wrong",p);
					}
				}
				catch (AccoutException& error)
				{
					error.show();
					cout << "should enter positive number" << endl;
					continue;
				}				
				getchar();
				getline(cin, title);
				if (p->deposit(date, myAmount, title))
				{
					myBill.insert(pair<Date, AccountBill>(date, AccountBill(date, p, myAmount, p->getBalance(), title)));
					outPut << command << "\n" << date.getDateStr() << "\n" << id << "\n" << fixed << myAmount << "\n" << p->getBalance() << "\n" << title << endl;
				}
				break;
			}
			case'w':
			{
				cout << "press amount and title" << endl;
				try
				{
					cin >> myAmount;
					if (myAmount <= 0)
					{
						throw AccoutException("withdraw wrong",p);
					}
				}
				catch (AccoutException& error)
				{
					error.show();
					cout << "should enter positive number" << endl;
					continue;
				}
				getchar();
				getline(cin, title);
				if (p->withdraw(date, myAmount, title))
				{
					myBill.insert(pair<Date, AccountBill>(date, AccountBill(date, p, -myAmount, p->getBalance(), title)));
					outPut << command << "\n" << date.getDateStr() << "\n" << id << "\n" << fixed << -myAmount << "\n" << p->getBalance() << "\n" << title << endl;
				}
				break;
			}
			case's':
			{
				p->show();
				break;
			}
			case'q':
			{
				cout << "press date number:" << endl;
				int num;
				try
				{
					cin >> commandDeal;
					if (commandDeal.size() > 1 || commandDeal == " ")
					{
						throw runtime_error("command size overflow");
					}
					num = commandDeal[0] - '0';
				}
				catch (const std::exception&)
				{
					cout << "command size overflow" << endl;
					continue;
				}
				switch (num)
				{
				case 1:
				{
					cout << "press a date:" << endl;
					try
					{
						auto billIter = myBill.equal_range(Date::read());
						if (billIter.first != end(myBill))
						{
							for (auto pr = billIter.first; pr != billIter.second; ++pr)
							{
								if ((pr->second).getId() == p->getId())
								{
									(pr->second).show();
								}
							}
						}
						break;
					}
					catch (AccoutException& error)
					{
						error.show();
						cout << "date enter wrong,please enter a legal 20xx-xx-xx date" << endl;
						continue;
					}					
				}
				case 2:
				{
					cout << "press two date,smaller one and bigger one:" << endl;
					try
					{
						auto iter1 = myBill.lower_bound(Date::read());
						auto iter2 = myBill.upper_bound(Date::read());
						if (iter1 != end(myBill))
						{
							for (auto iter = iter1; iter != iter2; ++iter)
							{
								if ((iter->second).getId() == p->getId())
								{
									(iter->second).show();
								}
							}
						}
						break;
					}
					catch (AccoutException& error)
					{
						error.show();
						cout << "date enter wrong,please enter two legal 20xx-xx-xx date" << endl;
						continue;
					}					
				}				
				default:
					cout << "wrong commnd, return to menu!" << endl;
					break;
				}
				break;
			}
			case'c':
			{
				cout << "press goal day:";
				int myDay;
				cin >> myDay;	
				try
				{
					if (myDay > (date.monthTable(date.getYear(), date.getMonth() + 1) - date.monthTable(date.getYear(), date.getMonth())))
					{
						throw out_of_range("day out of range");
					}
				}
				catch (const std::exception&)
				{
					cout << "date enter wrong,please enter two legal date" << endl;
					continue;
				}
				if (!date.dateChange(date.getYear(), date.getMonth(), myDay))
				{
					cout << "can not return to previous day!" << endl;
					break;
				}
				cout << "now is" << date.getDateStr() << endl;
				outPut << command << "\n" << myDay << endl;
				break;
			}
			case'n':
			{
				if (date.getMonth() == 12)
				{
					if (!date.dateChange(date.getYear() + 1, 1, 1))
					{
						cout << "can not return to previous day!" << endl;
					}
					else
					{
						cout << "now is" << date.getDateStr() << endl;
						for (auto& it : accounts) 
						{
							it.second->settle(date);
						}
						outPut << command << endl;
					}
				}
				else
				{
					if (!date.dateChange(date.getYear(), date.getMonth() + 1, 1))
					{
						cout << "can not return to previous day!" << endl;
					}
					else
					{
						cout << "now is" << date.getDateStr() << endl;
						for (auto& it : accounts)
						{
							it.second->settle(date);
						}
						outPut << command << endl;
					}
				}
				break;
			}
			case'o':
			{
				p = NULL;
				isLoginin = false;
				cout << "logout successful!" << endl;
				break;
			}
			default: 
			{
				cout << "wrong commnd,return to menu!" << endl;
				break; 
			}
			}
		}
		else
		{
			cout << "(a)add account (l)login (e)exit" << endl;
			try
			{
				cin >> command;
				getline(cin, commandDeal);
				if (commandDeal.size() > 1)
				{
					throw overflow_error("command size error");
				}
			}
			catch (const std::exception& )
			{				
				cout << "command size overflow" << endl;
				continue;
			}			
			switch (command)
			{
			case 'a':
				cout << "please press id and key:" << endl;
				cin >> id >> key;
				iter = accounts.find(id);
				if (iter != accounts.end())
				{
					cout << "already created!return to menu!" << endl;
				}
				else
				{
					cout << "which type of Account?" << endl << "1.SavingsAccount\t2.CreditAccount" << endl;
					int type;
					try
					{
						cin >> commandDeal;
						if (commandDeal.size() > 1 || commandDeal == " ")
						{
							throw runtime_error("command size overflow");
						}
						type = commandDeal[0] - '0';
					}
					catch (const std::exception&)
					{
						cout << "command size overflow" << endl;
						continue;
					}
					
					switch (type)
					{
					case 1:
						cout << "press rate:" << endl;
						double sRate;
						cin >> sRate;
						accounts.insert(pair<string, Account*>(id, new SavingsAccount(date, id, key, sRate)));
						outPut << command << "\n" << type << "\n" << date.getDateStr() << "\n" << id << "\n" << key << "\n" << sRate << endl;
						break;
					case 2:
						cout << "press creditLimit rate fee:" << endl;
						double mylimit, myrate, myfee;
						cin >> mylimit >> myrate >> myfee;
						accounts.insert(pair<string, Account*>(id, new CreditAccount(date, id, key, mylimit, myrate, myfee)));
						outPut << command << "\n" << type << "\n" << date.getDateStr() << "\n" << id << "\n" << key << "\n" << mylimit << "\n" << myrate << "\n" << myfee << endl;
						break;
					default:
						cout << "wrong commnd,return to menu!" << endl;
						break;
					}					
				}
				break;
			case 'l':
				cout << "please press id and key:" << endl;
				cin >> id >> key;
				iter = accounts.find(id);
				if (iter != accounts.end())
				{
					if((iter->second)->keyCheck(key))
					{
						cout << "login successfully!return to menu!" << endl;
						isLoginin = true;
						p = iter->second;
					}
					else
					{
						cout << "wrong key!Do not Find this account!return to menu!" << endl;
					}
				}
				else
				{
					cout << "wrong id!Do not Find this account!return to menu!" << endl;
				}
				break;
			case'e':
				cout << "goodbye!" << endl << "system close!" << endl;
				outPut.close();
				break;
			default:
				cout << "wrong commnd,return to menu!" << endl;
				break;
			}
		}
		cin.clear();
		cin.sync();
	} while (command != 'e');
	return 0;
}