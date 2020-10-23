#pragma once
#ifndef TIME_H
#define TIME_H

#include "IComparable.h"

struct Time : public IComparable {
private:
    int seconds;
    int minutes;
    int hours;
public:
    Time();
    Time(int hours, int minutes, int seconds);
    int compareTo(IComparable* obj) const override;
    string toString() const override;
    void sortArray(IComparable** array, int arraySize);
};

#endif //TIME_H