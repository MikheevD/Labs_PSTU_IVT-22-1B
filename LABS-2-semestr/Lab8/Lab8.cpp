// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <windows.h>
#include <locale>// библиотека для кириллицы

struct People {
    std::string Last_First_Middle_Name;
    std::string Date_Birthday;
    float Height;
    float Mass;
};
People PeopDelete() {
    People obj;
    return obj;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float h, m = -1.f;
    People mas[100];
    {
        mas[0].Last_First_Middle_Name = "Михеев Даниил Вадимович";
        mas[0].Date_Birthday = "05.05.2000";
        mas[0].Height = 180.f;
        mas[0].Mass = 90.f;
    }
    for (int x = 0; x < 100; x++) {
        if (mas[x].Last_First_Middle_Name == "" || mas[x].Date_Birthday == "" || mas[x].Height <= 0 || mas[0].Mass <= 0)
            continue;
        std::cout << mas[x].Last_First_Middle_Name << " " << mas[x].Date_Birthday << " " << mas[x].Height << " " << mas[x].Mass << " \n";
    }
    std::cin >> h;
    std::cin >> m;
    for (int x = 0; x < 100; x++) {
        if (mas[x].Last_First_Middle_Name == "" || mas[x].Date_Birthday == "" || mas[x].Height <= h || mas[x].Mass <= m)
        {
            mas[x] = PeopDelete();
            continue;
        }
        std::cout << mas[x].Last_First_Middle_Name << " " << mas[x].Date_Birthday << " " << mas[x].Height << " " << mas[x].Mass << " \n";
    }
    return 0;

