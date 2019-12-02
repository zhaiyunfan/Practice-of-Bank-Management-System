#pragma once
#include"Date.h"

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
	double calSum(Date& date);
	bool set(Date& date, double value);
	bool reset(Date& date, double value);
};

