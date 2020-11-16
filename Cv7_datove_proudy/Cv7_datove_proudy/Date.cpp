#include "Date.h"

Date::Date()
{
}

Date::~Date()
{
}

Date::Date(int _day, int _month, int _year)
{
    this->_day = _day;
    this->_month = _month;
    this->_year = _year;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    return os << date._day << "-" << date._month << "-" << date._year;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    char ch;
    is >> date._day >> ch >> date._month >> ch >> date._year;
    return is;
}
