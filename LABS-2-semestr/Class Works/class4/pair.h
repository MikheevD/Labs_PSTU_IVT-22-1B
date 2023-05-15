#ifndef MAIN_CPP_PAIR_H
#define MAIN_CPP_PAIR_H
#include "iostream"

class pair {
    int first;
    int second;
public:
    pair();
    pair(int f, int s);
    pair(const pair& p);
    ~pair();
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }
    void operator=(const pair& );
    friend std::istream& operator>>(std::istream& in, pair& p);
    friend std::ostream& operator<<(std::ostream& out, pair& p);
    pair operator+(const pair& );
};

#endif //MAIN_CPP_PAIR_H
