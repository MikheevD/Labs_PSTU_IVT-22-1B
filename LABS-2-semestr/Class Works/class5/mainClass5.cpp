#include "complex.h"
#include "pair.h"
#include "Object.h"
#include "Vector.h"
#include <windows.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Vector v(5);
    pair just_another_pair;
    std::cin >> just_another_pair;
    complex this_is_another_fraction_problems_with_naming;
    std::cin >> this_is_another_fraction_problems_with_naming;
    Object* ptr = &just_another_pair;
    v.Add(ptr);
    ptr = &this_is_another_fraction_problems_with_naming;
    v.Add(ptr);
    std::cout << v;
    return 0;
}