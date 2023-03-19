// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;

void bubbleSort(int list[], int listLength)
{
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
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
	bubbleSort(list, size);
	cout << "\n\nВыходной массив ... \n";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t";

	}
}