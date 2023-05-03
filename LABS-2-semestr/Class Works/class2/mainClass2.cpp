#include <iostream>
#include <windows.h>
#include "class2.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float mantissa;
    int order;
    string repres;
    cout << "Введите число" << endl;
    cin >> mantissa;
    cin >> order;
    cin >> repres;
    Namber nambr0;
    Namber nambr1(mantissa, order, repres);
    Namber nambr2(nambr1);
    cout << nambr0.get_mantissa() << " " << nambr0.get_order() << " " << nambr0.get_repres() << endl;
    cout << nambr1.get_mantissa() << " " << nambr1.get_order() << " " << nambr1.get_repres() << endl;
    cout << nambr2.get_mantissa() << " " << nambr2.get_order() << " " << nambr2.get_repres() << endl;
    nambr0.set_Mantissa(16.23);
    nambr0.set_Order(2);
    nambr0.set_Repres("число ");
    cout << nambr0.get_mantissa() << " " << nambr0.get_order() << " " << nambr0.get_repres() << endl;
    nambr0.show();
    nambr1.show();
    nambr2.show();
    return 0;
}