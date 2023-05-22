#include "vector.h"
#include "error.h"
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
        catch (error e) 
        { e.what(); };
        return 0;
}
