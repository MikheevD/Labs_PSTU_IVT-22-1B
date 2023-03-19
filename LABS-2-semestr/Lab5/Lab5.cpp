// Pro1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
double summa(double array[50][50], int m, int i, int j);
bool proverka(double array[50][50], int n, int m);
//-------------------------------------------------------
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double array[50][50] = { 0 };
	int n = 0, m = 0;
	bool otvet = 0;
	cout << "Введите количество строк" << endl;
	cin >> n;
	if (n > 50 || n < 2) {
		cout << "Размер матрицы неуместен" << endl;
		return 0;
	}
	cout << "Введите количество столбцов" << endl;
	cin >> m;
	if (m > 50 || m < 2) {
		cout << "Размер матрицы неуместен" << endl;
		return 0;
	}
	cout << "Введите  элементы матрицы" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
			cin >> array[i][k];
		cout << endl;
	}
	otvet = proverka(array, n, m);
	if (otvet == true)
		cout << "Матрица ортонормированная";
	else cout << "Матрица не ортонормированная";
	return 0;
}
bool proverka(double array[50][50], int n, int m)
{
	int i = 0, j = 0;
	double s = 0;
	for (i = 0; i < n; i++) {
		j = i;
		s = summa(array, m, i, j);
		if (s != 1)
			return false;
		for (j = i + 1; j < n; j++) {
			s = summa(array, m, i, j);
			if (s != 0)
				return false;
		}
	}
	return true;
}
double summa(double array[50][50], int m, int i, int j)
{
	double s = 0;
	for (int k = 0; k < m; k++)
		s += array[i][k] * array[j][k];
	return s;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
