// 

#include <iostream>
using namespace std;

int  linearSearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}


int main(void)
{
	setlocale(0, "Russian");
	srand(time(NULL));
	int n, x;
	int arr[100];
	printf("Введите размер массива:>");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100; printf("%d ", arr[i]);
	}
	cout << endl; printf("Введите число:>");
	scanf_s("%d", &x);
	int index = linearSearch(arr, n, x);
	(index == -1)
		? cout << "Элемент отсутствует в массиве."
		: cout << " Элемент присутствует в индексе: " << index;
	return 0;
}
