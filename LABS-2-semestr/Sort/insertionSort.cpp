﻿// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;


void insertionSort(int list[], int listLength)
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			swap(list[j], list[j + 1]);
			cout << "\ndid";
			j--;
		}
	}
}

int main()
{
	setlocale(0, "Russian");
	int size;
	srand(time(NULL));
	int list[100];
	printf("Введите размер массива:>");
	scanf_s("%d", &size);
	for (int i = 0; i < size; i++) {
		list[i] = rand() % 1000; printf("%d ", list[i]);
	}
	insertionSort(list, size);
	cout << "\n\nВыходной массив ... \n";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t";

	}
}