#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H
#include "Print.h"

class Book :public Pring {
protected:
    int pages;
    std::string publisher;

public:
    Book();
    Book(const Book&);
    Book(std::string, std::string, int, std::string);
    ~Book() {};
    //once again
    void Show();
    void Input();
    //setters and getters
    int get_pages() { return pages; };
    void set_pages(int p) { pages = p; };
    void set_publish(std::string publ) { publisher = publ; };
    std::string get_publish() { return publisher;};

    Book& operator=(const Book&);
};

#endif //MAIN_CPP_STUDENT_H