
#ifndef MAIN_CPP_CLASS1_H
#define MAIN_CPP_CLASS1_H

#include "iostream"

class class1 {
    double first;
    double second;
    unsigned int number;
public:
    void Init(double f, double s);

    void Read();

    void Show() { std::cout << "Числитель равен " << first << " и знаменатель равен " << " " << second << std::endl; }

    void range(unsigned int n);

};

#endif //MAIN_CPP_CLASS1_H

