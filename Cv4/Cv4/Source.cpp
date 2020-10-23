#include "Time.h"
#include "Date.h"
#include "DateTime.h"

int main() {
    Time** times = new Time * [5];
    Date** dates = new Date * [5];
    DateTime** dateTimes = new DateTime * [5];

    for (int i = 0; i < 5; i++) {
        times[i] = new Time(rand() % 23, rand() % 59, rand() % 59);
        dates[i] = new Date((rand() % 31) + 1, (rand() % 12) + 1, (rand() % 150) + 1900);
        dateTimes[i] = new DateTime(dates[i], times[i]);
    }

    for (int i = 0; i < 5; i++) {
        cout << dateTimes[i]->toString() << endl;
    }
    cout << "Sorted: "<< endl;
    dateTimes[0]->sortArray((IComparable**)dateTimes, 5);
    for (int i = 0; i < 5; i++) {
        cout << dateTimes[i]->toString() << endl;
    }
    delete[] times;
    delete[] dates;
    delete[] dateTimes;
}