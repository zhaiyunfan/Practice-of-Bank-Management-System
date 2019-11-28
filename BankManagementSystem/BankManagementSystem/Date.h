#pragma once
class Date
{
private:
	int year, month, day;
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
	int monthTable(int year, int month);
	bool dateChange(int y, int m, int d);
};

