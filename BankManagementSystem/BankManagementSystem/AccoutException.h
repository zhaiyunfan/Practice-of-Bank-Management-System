#pragma once
#include <stdexcept>
#include"Account.h"
using namespace std;

class AccoutException :public runtime_error
{
private:
	string msg;
	Account* p;
public:
	AccoutException(string msg, Account* p) :runtime_error(msg)
	{
		this->msg = msg;
		this->p = p;
	}
	void show()
	{
		cout << msg <<" in"<< endl;
		cout << p->getId() << endl;
	}

};

