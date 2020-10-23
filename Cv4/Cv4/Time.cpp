#include "Time.h"
#include <string>

Time::Time()
{
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
    if (hours < 0 || hours > 23) {
        this->hours = 0;
    }
    else {
        this->hours = hours;
    }
    if (minutes < 0 || minutes > 59) {
        this->minutes = 0;
    }
    else {
        this->minutes = minutes;
    }
    if (seconds < 0 || seconds > 59) {
        this->seconds = 0;
    }
    else {
        this->seconds = seconds;
    }
}

int Time::compareTo(IComparable* obj) const
{
    Time* objectTime = dynamic_cast<Time*>(obj);
    int thisTimeInSeconds = (this->hours * 3600) + (this->minutes * 60) + this->seconds;
    int objectTimeInSeconds = (objectTime->hours * 3600) + (objectTime->minutes * 60) + objectTime->seconds;

    if (thisTimeInSeconds < objectTimeInSeconds) {
        return -1;
    }
    else if (thisTimeInSeconds > objectTimeInSeconds) {
        return 1;
    }
    else{
        return 0;
    }
    
}

string Time::toString() const
{
    string hours = to_string(this->hours);
    string minutes = to_string(this->minutes);
    string seconds = to_string(this->seconds);
    return "Time is: " + hours + ':' + minutes + ':' + seconds;
}

void Time::sortArray(IComparable** array, int arraySize)
{
    if (arraySize < 2) {
        throw "array is < 2";
    }
    Time** arrayOfTimes = (Time**)array;
    Time* temp;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (array[j]->compareTo(array[j + 1]) == 1) {
                temp = arrayOfTimes[j];
                arrayOfTimes[j] = arrayOfTimes[j + 1];
                arrayOfTimes[j + 1] = temp;
            }
        }
    }
}
