#include <iostream>


using namespace std;


void merge(int arr[], int begin, int mid, int end) {
    int left = mid - begin + 1;
    int right = end - mid;
    int* lArr = new int[left];
    int* rArr = new int[right];
    for (int i = 0; i < left; i++) {
        lArr[i] = arr[begin + i];
    }
    for (int i = 0; i < right; i++) {
        rArr[i] = arr[mid + i + 1];
    }
    int left_ind = 0;
    int merge_ind = begin;
    int right_ind = 0;
    while (left_ind < left && right_ind < right) {
        if (lArr[left_ind] <= rArr[right_ind]) {
            arr[merge_ind] = lArr[left_ind];
            left_ind++;
        }
        else {
            arr[merge_ind] = rArr[right_ind];
            right_ind++;
        }
        merge_ind++;
    }
    while (left_ind < left) {
        arr[merge_ind] = lArr[left_ind];
        merge_ind++;
        left_ind++;
    }
    while (right_ind < right) {
        arr[merge_ind] = rArr[right_ind];
        right_ind++;
        merge_ind++;
    }
    delete[] lArr;
    delete[] rArr;
}

void mergeSortII(int arr[], int n, int end)
{
    if (n >= end) { return; }
    int mid = n + (end - n) / 2;
    mergeSortII(arr, n, mid);
    mergeSortII(arr, mid + 1, end);
    merge(arr, n, mid, end);
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
        arr[i] = rand() % 100; printf("%d ", arr[i]);
    }
    mergeSortII(arr, 0, n - 1);
    cout << "\n\nВыходной массив ... \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}