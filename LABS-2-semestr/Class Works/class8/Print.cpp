#include "Print.h"

Pring::Pring() {
    title = "";
    avtor = "";
}

Pring::Pring(std::string str, std::string sta) {
    title = str;
    avtor = sta;
}

Pring::Pring(const Pring& p) {
    title = p.title;
    avtor = p.avtor;
}

Pring::~Pring() {
}

Pring& Pring::operator=(const Pring& p) {
    if (this == &p) { return *this; }
    title = p.title;
    avtor = p.avtor;
    return *this;
}

void Pring::Show() {
    std::cout << "����� ����� �������� " << title << std::endl;
    std::cout << "� ����� ����� " << avtor << " " << std::endl;
}

void Pring::Input() {
    std::cout << "����� ��������� " << std::endl;
    std::cin >> title;
    std::cout << " ����� ����� " << std::endl;
    std::cin >> avtor;
}

void Pring::HandleEvent(const TEvent& event) {
    if (event.what == EvMessage) {
        switch (event.command) {
        case cmGet: std::cout << "�������� " << get_title() << std::endl; break;
        }
    }
}