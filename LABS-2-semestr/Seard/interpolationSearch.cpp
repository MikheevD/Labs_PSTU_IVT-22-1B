interpolationSear// 

#include <iostream>

using namespace std;


void insertionSort(int arr[], int listLength)
{
    for (int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}
int interpolationSearch(int arr[], int begin, int end, int x)
{
    int i;
    if (begin <= end && x >= arr[begin] && x <= arr[end]) {

        i = begin + (((double)(end - begin) / (arr[end] - arr[begin])) * (x - arr[begin]));
        if (arr[i] == x)
            return i;
        if (arr[i] < x)
            return interpolationSearch(arr, i + 1, end, x);
        if (arr[i] > x)
            return interpolationSearch(arr, begin, i - 1, x);
    }
    return -1;
}
int main()
{
    setlocale(0, "Russian");
    srand(time(NULL));
    int n;
    int arr[100];
    printf("Введите размер массива:>");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
    cout << "\n\nМассив отсортирован ... \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    int x;
    cout << endl;
    printf("Введите число для поиска:>");
    cin >> x;
    int index = interpolationSearch(arr, 0, n - 1, x);
    if (index != -1)
        cout << "Элемент присутствует в индексе:" << index;
    else
        cout << "Элемент отсутствует в массиве.";
    return 0;
}ch