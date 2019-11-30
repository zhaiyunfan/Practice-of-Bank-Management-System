#pragma once
#include"Date.h"
//²ßÂÔÄ£Ê½
class Accumulator
{
private:
	Date lastDate;
	double value;
	double sum;
public:
	Accumulator(Date& date, double value)
	{
		lastDate = date;
		this->value = value;
		sum = 0;
	}
	double cal(Date& date);
	bool set(Date& date, double value);
	bool reset(Date& date, double value);
};

