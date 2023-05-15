#include "complex.h"
#include "iostream"

complex::complex(void) :pair() {}

complex::complex(int num, int denom) : pair(num, denom) {}

complex::complex(const complex& frac) : pair(frac) {}

complex::~complex() { std::cout << " " << getFirst() << " " << getSecond() << std::endl; }

complex complex::operator*(const complex& frac) {
    complex new_p;
    new_p.set_numerator(get_numerator() * frac.get_numerator() - get_denominator() * frac.get_denominator());
    new_p.set_denominator(get_denominator() * frac.get_numerator() + get_numerator() * frac.get_denominator());
    return new_p;
}
complex complex::operator-(const complex& frac) {
    complex new_p;
    new_p.set_numerator(get_numerator() - frac.get_numerator());
    new_p.set_denominator(get_denominator() - frac.get_denominator());
    return new_p;
}
std::istream& operator>>(std::istream& in, complex& frac) {
    int a, b;
    in >> a >> b;
    frac.set_numerator(a);
    frac.set_denominator(b);
    return in;
}

std::ostream& operator<<(std::ostream& out, complex& frac) {
    std::cout << frac.get_numerator() << " " << frac.get_denominator();
    return out;
}
