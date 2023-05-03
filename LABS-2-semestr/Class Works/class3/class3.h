#ifndef MAIN_CPP_CLASS3_H
#define MAIN_CPP_CLASS3_H

#include "iostream"

class Time {
    int seconds;
    int minutes;
public:
    Time();

    Time(int m, int s);

    Time(Time& t);

    ~Time() {/*std::cout << "destruct this time:" << minutes << ":" << seconds << std::endl;*/ };

    int get_minutes() { return minutes; }

    int get_seconds() { return seconds; }

    void set_minutes(int m) { minutes = m; }

    void set_seconds(int s) { seconds = s; }

    Time& operator=(Time& t);

    bool operator==(Time& t) { return minutes == t.minutes && seconds != t.seconds; };

    Time& operator+(Time& t);

    void Show() { std::cout << "Время составляет" << minutes << ":" << seconds << std::endl; };
};

#endif //MAIN_CPP_CLASS3_H