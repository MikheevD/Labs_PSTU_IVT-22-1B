#include "vector.h"
#include <Windows.h>

int main() {
    try {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        Vector x(5);
        Vector y;
        cout << x;
        cout << " ¬ведите N" << endl;
        int i;
        cin >> i;
        cout << x[i] << endl;
        cout << y;
        --x;
        cout << x;
        --x;
        cout << x;
        --x;
    }
    catch (int) {
        cout << "ќшибка" << endl;
        return 0;
    };
}
