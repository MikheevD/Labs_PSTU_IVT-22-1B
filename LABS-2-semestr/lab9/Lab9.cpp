﻿// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
int main()
{
    int n = 0;
    system("chcp 1251 > null");
    std::string File1, File2;
    std::cin >> File1;
    std::cin >> File2;
    std::string line = " ";
    std::ifstream In1;
    std::ofstream Out2;
    In1.open(File1);
    Out2.open(File2);
    if (In1.is_open())
    {
        while (getline(In1, line))
        {
            if (Out2.is_open()) {
                Out2 << line << std::endl;
                char chars[100];
                line.copy(chars, line.length() + 1);
                for (int i = 0; i < 100; i++) {
                    if (chars[i] == 'A' || chars[i] == 'E' || chars[i] == 'I' || chars[i] == 'O' || chars[i] == 'U' ||
                        chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u') {
                        n++;
                    }

                }
            }
            else std::cout << "Error write file" << std::endl;
        }
    }
    else std::cout << "Error read file" << std::endl;
    Out2.close();
    In1.close();     // закрываем файл
    In1.open(File2);
    if (In1.is_open())
    {
        while (getline(In1, line))
        {
            std::cout << line << std::endl;
        }
    }
    std::cout << "Количество глассных в файле = " << n << std::endl;
    return 0;
}

