#pragma once
#include<string>
using namespace std;
class Date
{
private:
	int year, month, day;
	int monthTable(int year, int month);
public:
	Date()
	{
		year = 2000;
		month = 3;
		day = 24;
	}
	Date(int y, int m, int d) 
	{
		year = y;
		month = m;
		day = d;
	}
	int distanceCal(Date& newDate);
	string getDateStr();
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	bool dateChange(int y, int m, int d);
};

