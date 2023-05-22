#include "Book.h"

Book::Book() :Pring() {
    pages = 0;
    publisher = "";

}

Book::Book(std::string str, std::string sta, int p, std::string publ) : Pring(str, sta) {
    pages = p;
    publisher = publ;
}

Book::Book(const Book& book) {
    title = book.title;
    avtor = book.avtor;
    pages = book.pages;
    publisher = book.publisher;

}

Book& Book::operator=(const Book& book) {
    if (&book == this) { return *this; }
    title = book.title;
    avtor = book.avtor;
    pages = book.pages;
    publisher = book.publisher;
    return *this;
}

void Book::Show() {
    std::cout << "����� ����� �������� " << title << std::endl;
    std::cout << "� ����� ����� " << avtor << " " << std::endl;
    std::cout << "���������� ������� �����" << pages << " " << std::endl;
    std::cout << "����������� ����� ����� �������� " << publisher << " " << std::endl;
}

void Book::Input() {
    std::cout << "����� ����� �������� " << std::endl;
    std::cin >> title;
    std::cout << "����� �����  " << std::endl;
    std::cin >> avtor;
    std::cout << "���������� ������� " << std::endl;
    std::cin >> pages;
    std::cout << "������������ ����� " << std::endl;
    std::cin >> publisher;
}