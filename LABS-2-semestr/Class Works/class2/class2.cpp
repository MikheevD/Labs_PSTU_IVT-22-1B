#include "class2.h"

Namber::Namber() {
    Mantissa = 0;
    Order = 0;
    Repres = "";
};

Namber::Namber(float mantissa, int order, std::string repres) {
    Mantissa = mantissa;
    Order = order;
    Repres = repres;
}

Namber::Namber(Namber& dude) {
    Mantissa = dude.Mantissa;
    Order = dude.Order;
    Repres = dude.Repres;
}

Namber::~Namber() {
    std::cout << "Удалить число" << " " << Mantissa << std::endl;
    Mantissa = 0;
    Order = 0;
    Repres = "";
}
