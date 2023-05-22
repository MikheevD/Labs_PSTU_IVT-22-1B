#include "Book.h"
#include "Vector.h"
#include "Dialog.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto* prig1 = new Pring();
    prig1->Input();
    prig1->Show();
    auto* book1 = new Book();
    book1->Input();
    book1->Show();

    auto* prig2 = new Pring();
    prig2->Input();
    auto* book2 = new Book();
    book2->Input();
    Vector v(10);
    Object* p = prig2;
    v.Add(p);
    p = book2;
    v.Add(p);
    v.Show();
    v.Del();
    std::cout << "Размер вектора равен " << v() << std::endl;
    Dialog d;
    d.EndExec();
    return 0;
}