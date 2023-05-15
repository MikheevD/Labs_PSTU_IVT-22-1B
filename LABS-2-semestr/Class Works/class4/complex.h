#ifndef MAIN_CPP_MONEY_H
#define MAIN_CPP_MONEY_H
#include "pair.h"

class complex : public pair {
    //first is numerator, second is denominator
public:
    complex();
    complex(int, int);
    complex(const complex&);
    ~complex();
    int get_numerator() const { return getFirst(); }
    int get_denominator() const { return getSecond(); }
    void set_numerator(int num) { setFirst(num); }
    void set_denominator(int den) { setSecond(den); }
    void operator=(const complex& frac);
    friend std::istream& operator>>(std::istream& in, complex& frac);
    friend std::ostream& operator<<(std::ostream& out, complex& frac);   
    complex operator*(const complex& frac);
    complex operator-(const complex& frac);
};

#endif //MAIN_CPP_FRACTION_H