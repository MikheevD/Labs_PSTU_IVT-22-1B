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
        std::cout << "1.Создать файл" << std::endl;
        std::cout << "2. Распечатать файл" << std::endl;
        std::cout << "3. Удалить запись из файла" << std::endl;
        std::cout << "4. Добавить запись в файл" << std::endl;
        std::cout << "5. Изменить запись в файле" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cin >> c;
        char filename[30];
        switch (c) {
        case 1:
            std::cout << "Имя файла?" << std::endl;
            std::cin >> filename;
            k = make_file(filename);
            if (k < 0) std::cout << "Не удается создать файл" << std::endl;
            break;
        case 2:
            std::cout << "Имя файла?" << std::endl;
            std::cin >> filename;
            k = print_file(filename);
            if (k == 0) std::cout << "Пустой файл" << std::endl;
            if (k < 0) std::cout << "Не удается создать файл" << std::endl;
            break;
        case 3:
            std::cout << "Имя файла?" << std::endl;
            std::cin >> filename;
            std::cout << "N записей?" << std::endl;
            std::cin >> n;
            k = del_file(filename, n);
            if (k < 0) std::cout << "Не удается прочитать файл" << std::endl;
            break;
        case 4:
            std::cout << "Имя файла?" << std::endl;
            std::cin >> filename;
            std::cout << "N записей?" << std::endl;
            std::cin >> n;
            std::cout << "Новое время" << std::endl;
            std::cin >> t_example;
            k = add_file(filename, n, t_example);
            if (k < 0) std::cout << "Не удается прочитать файл" << std::endl;
            if (k == 0) k = add_end(filename, t_example);
            break;
        case 5:
            std::cout << "Имя файла?" << std::endl;
            std::cin >> filename;
            std::cout << "N записей?" << std::endl;
            std::cin >> n;
            std::cout << "Новое время" << std::endl;
            std::cin >> t_example;
            k = change_file(filename, n, t_example);
            if (k < 0) std::cout << "Не удается прочитать файл" << std::endl;
            if (k == 0) std::cout << "Такой записи нет" << std::endl;
            break;
        }
    } while (c != 0);

    return 0;
}