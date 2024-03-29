﻿// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void countSort(int arr[], int size)
{
    int* output = new int[size];
    int* count;
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max) { max = arr[i]; }
    }

    count = new int[max + 1];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i]; //in-place сортировку делаем
    }

    delete[] count;
    delete[] output;

}


int main()
{
    setlocale(0, "Russian");
    int n;
    srand(time(NULL));
    int arr[100];
    printf("Введите размер массива:>");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; printf("%d ", arr[i]);
    }
    countSort(arr, n);
    cout << "\n\nВыходной массив ... \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}