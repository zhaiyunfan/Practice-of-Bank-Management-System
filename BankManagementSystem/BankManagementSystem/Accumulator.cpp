#include "Accumulator.h"

double Accumulator::calSum(Date& date)
{
	return sum + value * lastDate.distanceCal(date);
}

bool Accumulator::set(Date& date, double value)
{
	sum = calSum(date);
	lastDate = date;
	this->value = value;
	return true;
}

bool Accumulator::reset(Date& date, double value)
{
	lastDate = date;
	this->value = value;
	sum = 0;
	return true;
}
