#pragma once
#include<string>
#include<iostream>
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
	string getDateStr();					//返回格式化的日期字符串，用于日期打印等处
	
	int getYear()  const
	{
		return year;
	}
	int getMonth() const
	{
		return month;
	}
	int getDay() const
	{
		return day;
	}
	static Date read();
	bool dateChange(int y, int m, int d);
	bool operator<(const Date d)const;
};

