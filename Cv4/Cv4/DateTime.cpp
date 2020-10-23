#include "DateTime.h"

DateTime::DateTime(Date* date, Time* time)
{
    this->date = *date;
    this->time = *time;
}

int DateTime::compareTo(IComparable* obj) const
{
    DateTime* ojectDateTime = dynamic_cast<DateTime*>(obj);
    int compareDate = this->date.compareTo((Date*)&ojectDateTime->date);
    int compareTime = this->time.compareTo((Time*)&ojectDateTime->time);

    if (compareDate == 0 && compareTime == 0) {
        return 0;
    }
    else if (compareDate == 1 || (compareDate == 0 && compareTime == 1)) {
        return 1;
    }
    else if (compareDate == -1 || (compareDate == 0 && compareTime == -1)) {
        return -1;
    }
   
}

string DateTime::toString() const
{
    return this->date.toString() + ", " + this->time.toString();
}

void DateTime::sortArray(IComparable** array, int arraySize)
{
    if (arraySize < 2) {
        throw "array is < 2";
    }
    DateTime** arrayOfDateTimes = (DateTime**)array;
    DateTime* temp;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (array[j]->compareTo(array[j + 1]) == 1) {
                temp = arrayOfDateTimes[j];
                arrayOfDateTimes[j] = arrayOfDateTimes[j + 1];
                arrayOfDateTimes[j + 1] = temp;
            }
        }
    }
}
