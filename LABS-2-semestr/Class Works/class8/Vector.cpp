#include "Vector.h"
#include "Book.h"

Vector::Vector(int s) {
    size = s;
    data = new Object * [s];
}

Vector::~Vector() {
    if (data != nullptr) delete[] data;
    data = nullptr;
}

void Vector::Add(Object* p) {
    std::cout << "Если вы хотите добавить книгу, нажмите 1" << std::endl;
    std::cout << "Если вы хотите добавить издателя, нажмите 2" << std::endl;
    int y;
    std::cin >> y;
    if (y == 1) {
        Pring* prig = new (Pring);
        prig->Input();
        p = prig;
        if (curr < size) {
            data[curr] = p;
            curr++;
        }
    }
    else {
        Book* book = new (Book);
        book->Input();
        p = book;
        if (curr < size) {
            data[curr] = p;
            curr++;
        }
    }
}

void Vector::Show() {
    if (curr == 0) { std::cout << "Вектор пуст" << std::endl; }
    Object** p = data;
    for (int i = 0; i < curr; i++) {
        (*p)->Show();
        p++;
    }
}

void Vector::Del() {
    if (curr) curr--;
}

void Vector::HandleEvent(const TEvent& event) {
    if (event.what == EvMessage) {
        Object** p = data;
        for (int i = 0; i < curr; i++) {
            (*p)->Show();
            p++;
        }
    }
}