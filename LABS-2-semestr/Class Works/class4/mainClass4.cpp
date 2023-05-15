#include "complex.h"
#include "pair.h"
#include <windows.h>

void f1(pair& p) {
    p.setFirst(10);
    std::cout << p;
}

pair f2() {
    complex frac(5, 2);
    return frac;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    pair p1;
    std::cin >> p1;
    std::cout << p1;
    pair p2(2, 1);
    std::cout << p2;
    p1 = p2;
    std::cout << p2;
    complex f;
    std::cin >> f;
    std::cout << f;
    f1(f);
    p1 = f2();
    std::cout << p1;
    return 0;
}