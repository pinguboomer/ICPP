#pragma once
#ifndef DATE_H
#define DATE_H
#include "IComparable.h"
#include <string>

struct Date : IComparable {
private:
    int day;
    int month;
    int year;   
public:
    Date();
    Date(int day, int month, int year);
    int compareTo(IComparable* obj) const override;
    string toString() const override;
    void sortArray(IComparable** array, int arraySize);
};

#endif //DATE_H