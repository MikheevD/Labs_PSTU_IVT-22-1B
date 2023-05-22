#include "Time.h"
#include "iostream"
#include "fstream"
#include "string"
#include "WordFile.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Time t1;
    std::cin >> t1;
    std::cout << t1 << std::endl;
    Time t2;
    t2 = t1;
    std::cout << t2 << std::endl;
    Time t3;
    int k, c, n;
    Time t_example;
    do {
        std::cout << "1.������� ����" << std::endl;
        std::cout << "2. ����������� ����" << std::endl;
        std::cout << "3. ������� ������ �� �����" << std::endl;
        std::cout << "4. �������� ������ � ����" << std::endl;
        std::cout << "5. �������� ������ � �����" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cin >> c;
        char filename[30];
        switch (c) {
        case 1:
            std::cout << "��� �����?" << std::endl;
            std::cin >> filename;
            k = make_file(filename);
            if (k < 0) std::cout << "�� ������� ������� ����" << std::endl;
            break;
        case 2:
            std::cout << "��� �����?" << std::endl;
            std::cin >> filename;
            k = print_file(filename);
            if (k == 0) std::cout << "������ ����" << std::endl;
            if (k < 0) std::cout << "�� ������� ������� ����" << std::endl;
            break;
        case 3:
            std::cout << "��� �����?" << std::endl;
            std::cin >> filename;
            std::cout << "N �������?" << std::endl;
            std::cin >> n;
            k = del_file(filename, n);
            if (k < 0) std::cout << "�� ������� ��������� ����" << std::endl;
            break;
        case 4:
            std::cout << "��� �����?" << std::endl;
            std::cin >> filename;
            std::cout << "N �������?" << std::endl;
            std::cin >> n;
            std::cout << "����� �����" << std::endl;
            std::cin >> t_example;
            k = add_file(filename, n, t_example);
            if (k < 0) std::cout << "�� ������� ��������� ����" << std::endl;
            if (k == 0) k = add_end(filename, t_example);
            break;
        case 5:
            std::cout << "��� �����?" << std::endl;
            std::cin >> filename;
            std::cout << "N �������?" << std::endl;
            std::cin >> n;
            std::cout << "����� �����" << std::endl;
            std::cin >> t_example;
            k = change_file(filename, n, t_example);
            if (k < 0) std::cout << "�� ������� ��������� ����" << std::endl;
            if (k == 0) std::cout << "����� ������ ���" << std::endl;
            break;
        }
    } while (c != 0);

    return 0;
}