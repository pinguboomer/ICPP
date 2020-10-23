#include "Date.h"

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2020;
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    if (month > 12 || month <= 0) {
        this->month = 1;
    }
    else {
        this->month = month;
    }
    this->year = year;
}

int Date::compareTo(IComparable* obj) const
{
    Date* objectDate = dynamic_cast<Date*>(obj);
    int thisDateInDays = (this->year * 365) + (this->month * 30) + this->day;
    int objectDateInDays = (objectDate->year * 365) + (objectDate->month * 30) + objectDate->day;

    if (thisDateInDays < objectDateInDays) {
        return -1;
    }
    else if (thisDateInDays > objectDateInDays) {
        return 1;
    }
    else {
        return 0;
    }
    
}

string Date::toString() const
{
    string year = to_string(this->year);
    string month = to_string(this->month);
    string day = to_string(this->day);

    return "Date is: " + day + '-' + month + '-' + year;
}

void Date::sortArray(IComparable** array, int arraySize)
{
    if (arraySize < 2) {
        throw "array is < 2";
    }
    Date** arrayOfDates = (Date**)array;
    Date* temp;
        for (int i = 0; i < arraySize; i++) {
            for (int j = 0; j < arraySize - i - 1; ++j) {
                if (array[j]->compareTo(array[j + 1]) == 1) {
                    temp = arrayOfDates[j];
                    arrayOfDates[j] = arrayOfDates[j + 1];
                    arrayOfDates[j + 1] = temp;
                }
        }
    }
}
