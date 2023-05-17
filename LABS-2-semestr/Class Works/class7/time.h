#ifndef MAIN_CPP_TIME_H
#define MAIN_CPP_TIME_H

#include "iostream"

class Time {
    int seconds;
    int minutes;
public:
    Time();

    Time(int, int);

    Time(const Time& t);

    ~Time();

    Time& operator=(const Time& t);

    Time& operator+(const Time& t);

    Time& operator+(int);

    friend std::istream& operator>>(std::istream& in, Time& t);
    friend std::ostream& operator<<(std::ostream& out, Time& t);
};

#endif //MAIN_CPP_TIME_H
