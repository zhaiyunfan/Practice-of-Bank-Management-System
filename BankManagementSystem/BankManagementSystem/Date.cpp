#include "Date.h"

int Date::distanceCal(Date& newDate)	//一个日期计算器，返回newDate与lastDate中间间隔的天数
{
	int result = 0;
	int yearLong = 0;

	if ((newDate.year - this->year) > 0)
	{
		yearLong = newDate.year - this->year;
	}
	else
	{
		yearLong = 0;
	}
	if (yearLong == 0)
	{
		int newDayNumber = monthTable(newDate.year, newDate.month) + newDate.day;
		int lastDayNumber = monthTable(this->year, this->month) + this->day;
		result = newDayNumber - lastDayNumber;
		return result;
	}
	else
	{
		result += (monthTable(this->year, 12) + 31 - monthTable(this->year, this->month) - this->day);								//加上第一年剩下的日子
		result += monthTable(newDate.year, newDate.month) + newDate.day;											//加上最后一年已度过的日子
		if ((newDate.year % 400 == 0 || (newDate.year % 4 == 0 && newDate.year % 100 != 0)) && newDate.month <= 2)	//最后一年是闰年且过二月，+1
		{
			result += 1;
			for (int i = this->year + 1; i < newDate.year; i++)														//加上中间的年，计算平闰年
			{
				result += monthTable(i, 12);
				result += 31;
			}
		}
		return result;
	}
	return -1;
}

string Date::getDateStr()					//返回格式化的日期字符串
{
	string result;
	string sig = "-";
	result.append(to_string(year));
	result.append(sig);
	result.append(to_string(month));
	result.append(sig);
	result.append(to_string(day));
	return result;
}

int Date::monthTable(int year, int month)	//一个表，返回值normalYear为所给年月的1日是该年的第(normalYear-1)天
{
	int normalYear = 0;
	switch (month)
	{
	case 12:
		normalYear += 30;
	case 11:
		normalYear += 31;
	case 10:
		normalYear += 30;
	case 9:
		normalYear += 31;
	case 8:
		normalYear += 31;
	case 7:
		normalYear += 30;
	case 6:
		normalYear += 31;
	case 5:
		normalYear += 30;
	case 4:
		normalYear += 31;
	case 3:
		normalYear += 28;
	case 2:
		normalYear += 31;
	case 1:
		normalYear += 0;
	default:
		break;
	}
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))	//处理闰年
	{
		if (month > 2)
		{
			normalYear += 1;
		}
	}
	return normalYear;
}

bool Date::dateChange(int y, int m, int d)
{
	if (year < y || year == y && month < m || year == y && month == m && day < d)
	{
		year = y;
		month = m;
		day = d;
		return true;
	}
	else
	{
		return false;
	}
}
