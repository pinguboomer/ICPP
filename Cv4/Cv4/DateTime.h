#pragma once
#ifndef DATETIME_H
#define DATETIME_H
#include "IComparable.h"
#include "Time.h"
#include "Date.h"

struct DateTime : IComparable {
private:
    Date date;
    Time time;
public:
    DateTime(Date* date, Time* time);
    int compareTo(IComparable* obj) const override;
    string toString() const override;
    void sortArray(IComparable** array, int arraySize);
};

#endif //DATETIME_H