#include  <iostream>
using namespace std;

int shellSort(int list[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = list[i];
			int j;
			for (j = i; j >= gap && list[j - gap] > temp; j -= gap)
				list[j] = list[j - gap];
			list[j] = temp;
		}
	}
	return 0;
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
	shellSort(list, size);
	cout << "\n\nВыходной массив ... \n";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t";

	}
}