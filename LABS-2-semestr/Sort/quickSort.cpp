﻿#include <iostream>
using namespace std;


int partition(int list[], int start, int pivot)
{
	int i = start;
	while (i < pivot)
	{
		if (list[i] > list[pivot] && i == pivot - 1)
		{
			swap(list[i], list[pivot]);
			pivot--;
		}

		else if (list[i] > list[pivot])
		{
			swap(list[pivot - 1], list[pivot]);
			swap(list[i], list[pivot]);
			pivot--;
		}

		else i++;
	}
	return pivot;
}

void quickSort(int list[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(list, start, end);

		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
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
	quickSort(list, 0, size - 1);
	cout << "\n\nВыходной массив ... \n";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t";

	}
}