// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;

    cout << "\nПожалуйста, введите количество элементов: ";
    int arrSize;
    cin >> arrSize;
    int* arr_1 = new int[arrSize];
    cout << endl;
    srand(time(NULL));
    for (int i = 0; i < arrSize; ++i)
    {
        arr_1[i] = 10 + rand() % 90;
        cout << arr_1[i] << " ";
    }
    cout << endl;
    cout << "\nвведите индекс элемента для удаления\n";
    int deleteKey;
    cin >> deleteKey;
    cout << endl;
    --arrSize;
    int* arr_2 = new int[arrSize];
    for (int i = 0, j = 0; i < arrSize; ++i, ++j)
    {
        if (j != deleteKey)
        {
            arr_2[i] = arr_1[j];
        }

        else
        {
            ++j;
            arr_2[i] = arr_1[j];
        }
        cout << arr_2[i] << " ";
    }
    cout << "\n\nПожалуйста, выберите местоположение элемента\n"
        "который вы хотите вставить в новый массив:\n";
    int choice = 0;
    cin >> choice;
    int insertAfter = -2;
    int insertBefore = -2;
    switch (choice)
    {
    case 1: cout << "\nПожалуйста, введите индекс, после которого вы хотите\n"
        "чтобы удалить элемент из массива: ";
        cin >> insertAfter;
        break;
    case 2: cout << "\nПожалуйста, введите индекс, перед которым вы хотите\n"
        "чтобы удалить элемент из массива: ";
        cin >> insertBefore;
        break;
    }
    ++insertAfter;
    --insertBefore;
    cout << "\nПожалуйста, введите значение элемента\n"
        ", который вы хотите вставить в массив: ";
    int insertValue;
    cin >> insertValue;
    cout << endl;
    ++arrSize;
    for (int i = 0, j = 0; i < arrSize; ++i, ++j)
    {
        if (i == insertAfter || i == insertBefore)
        {
            arr_1[i] = insertValue;
            --j;
        }
        else
        {
            arr_1[i] = arr_2[j];
        }
        cout << arr_1[i] << " ";
    }
    delete[] arr_1;
    delete[] arr_2;
    return 0;


