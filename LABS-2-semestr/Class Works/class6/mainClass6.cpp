#include "vector.h"
#include "iostream"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Vector v1(4);
    std::cout << v1 << std::endl;
    std::cin >> v1;
    std::cout << v1 << std::endl;
    v1[1] = 168;
    std::cout << v1 << std::endl;
    Vector v2(8);
    std::cout << v2 << std::endl;
    v2 = v1;
    std::cout << v2 << std::endl;
    Vector v3(8);
    v3 = v2 * 5;
    std::cout << v3 << std::endl;
    std::cout << "Длина первого вектора " << v1() << std::endl;
    std::cout << *(v1.first()) << std::endl;
    Iterator i = v1.first();
    -- i;
    std::cout << *i << std::endl;
    for (i = v1.last(); i != v1.first(); --i) std::cout << *i << std::endl;
};