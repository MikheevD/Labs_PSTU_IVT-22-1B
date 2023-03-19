// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;

void PrintArr(int mas[], int N) {
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int max_degree(int arr[], int N) {
    int max = arr[0], deg = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) max = arr[i];
    }
    while (max > 0) {
        deg++;
        max /= N;
    }
    return deg;
}

void bucketSort(int arr[], int n) {
    int buckets[10][100];
    int counter[10];
    int k, l, d = 1;
    int max = max_degree(arr, n);
    for (int m = 0; m < max; m++) {
        for (int i = 0; i < n; i++) counter[i] = 0;
        for (int i = 0; i < n; i++) {
            k = (arr[i] / d) % n;
            buckets[k][counter[k]] = arr[i];
            counter[k]++;
        }
        l = 0;
        for (int i = 0; i < n; i++) {
            for (k = 0; k < counter[i]; k++) {
                arr[l] = buckets[i][k];
                l++;
            }
        }
        d *= n;
    }
}

int main()
{
    setlocale(0, "Russian");
    int size;
    srand(time(NULL));
    int arr[100];
    printf("Введите размер массива:>");
    scanf_s("%d", &size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; printf("%d ", arr[i]);
    }
    bucketSort(arr, size);
    cout << "\n\nВыходной массив ... \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";

    }
}