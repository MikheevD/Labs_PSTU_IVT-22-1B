﻿// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
void merge(int list[], int start, int end, int mid);

void mergeSort(int list[], int start, int end)
{
	int mid;
	if (start < end) {

		mid = (start + end) / 2;
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, end, mid);
	}
}

void merge(int list[], int start, int end, int mid)
{
	int mergedList[100];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;

	while (i <= mid && j <= end) {
		if (list[i] < list[j]) {
			mergedList[k] = list[i];
			k++;
			i++;
		}
		else {
			mergedList[k] = list[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		mergedList[k] = list[i];
		k++;
		i++;
	}

	while (j <= end) {
		mergedList[k] = list[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {
		list[i] = mergedList[i];
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
	mergeSort(list, 0, size - 1);
	cout << "\n\nВыходной массив ... \n";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t";
	}
}
