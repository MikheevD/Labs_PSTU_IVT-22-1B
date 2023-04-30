#include "class1.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    class1 r, r1, r2;
    r.Read();
    r.Show();
    r.range(20);
    r1.Init(10.57, 9.68);
    r1.range(10);
    r2.Init(101.5, 89.54);
    r2.range(100);
    return 0;
}