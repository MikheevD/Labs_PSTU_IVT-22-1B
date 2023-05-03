#include <windows.h>
#include <iostream>
#include "class3.h"

using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Time t(34, 59);
    Time t1(53, 43);
    Time t2(00, 34);
    t.Show();
    t1.Show();
    t = t + t2;
    t.Show();
    return 0;
}