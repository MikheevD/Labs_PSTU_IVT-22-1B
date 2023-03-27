#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int knuthmorrisprattSeard(string str, string substr)
{
    int strSize, substrSize;
    strSize = str.size();
    substrSize = substr.size();

    int* pref = new int[substrSize];

    int i = 0;
    int j = -1;
    pref[0] = -1;


    while ((j >= 0) && (substr[j] != substr[i]))
    {
        j = pref[j];
    }
    i++;
    j++;
    if (substr[i] == substr[j])
    {
        pref[i] = pref[j];
    }
    else
    {
        pref[i] = j;
    }
    i = 0;
    j = 0;
    for (i = 0, j = 0; (i <= strSize - 1) && (j <= substrSize - 1); i++, j++)
    {
        while ((j >= 0) && (substr[j]) != str[i])
        {
            j = pref[j];
        }
    }
    delete[] pref;
    if (j == substrSize) { return i - j; }
    else return -1;

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputStr, searchStr;
    printf("Введит строку:>");
    cin >> inputStr;
    printf("Введите слово для поиска:>");
    cin >> searchStr;
    int idx = knuthmorrisprattSeard(inputStr, searchStr);
    if (idx == -1) { cout << "Элемента нет!"; }
    else { cout << "Номер в строке:" << idx; }
    return 0;
}
