#ifndef MAIN_CPP_CLASS2_H
#define MAIN_CPP_CLASS2_H

#include <iostream>

class Namber {
    float Mantissa;
    int Order;
    std::string Repres ;
public:
    Namber();

    Namber(float mantissa, int order, std::string repres);

    Namber(Namber& dude);

    ~Namber();

    float get_mantissa() { return Mantissa; }

    int get_order() { return Order; }

    std::string  get_repres() { return Repres; }

    void set_Mantissa(float mantissa) { Mantissa = mantissa; }

    void set_Order(int order) { Order = order; }

    void set_Repres(std::string repres) { Repres = repres; }

    void show() {
        std::cout << "У числа мантисса равна  " << Mantissa << ", порядок числа  " << Order << ", строковое представление "
            << Repres << std::endl;
    }
};

#endif //MAIN_CPP_STUDENT_H