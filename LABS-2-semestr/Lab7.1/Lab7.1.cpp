// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <windows.h>
#include <locale>// библиотека для кириллицы
int Method(int num1, int num2) {
    return num1 * num2;
}
double Method(double num1, double num2, double num3, double num4) {
    return (num1 * num2) + (num3 * num4);
}
int main()
{
    setlocale(LC_ALL, "");
    int num1, num2 = 0;
    std::cout << "Введите два элемента для метода a1/a2:";
    std::cin >> num1;
    std::cin >> num2;
    std::cout << Method(num1, num2) << "\n";
    double numX, numY, numZ, numV = 0.;
    std::cout << "Введите три элемента для метода (a*b)+(c*d):";
    std::cin >> numX;
    std::cin >> numY;
    std::cin >> numZ;
    std::cin >> numV;
    std::cout << Method(numX, numY, numZ, numV) << "\n";
    return 0;
}
