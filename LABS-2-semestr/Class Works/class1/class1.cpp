#include "class1.h"

void class1::Init(double f, double s) {
    double first = f;
    double second = s;
}

void class1::Read() {
    std::cin >> first;
    std::cin >> second;
}


void class1::range(unsigned int n) {
    double number = n;
    if (!second) {
        std::cout << "����� ��������� �����������" << std::endl;
    }
    else {

        std::cout << (number <= first) << " �������� ��������� ����� first  " << std::endl;
        std::cout << (number >= second) << " �������� ��������� ����� second" << std::endl;

    }
}
