#pragma once

#ifndef DATE_H
#define DATE_H

#include <iostream>

struct Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	~Date();
	Date(int _day, int _month, int _year);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif // !DATE_H
