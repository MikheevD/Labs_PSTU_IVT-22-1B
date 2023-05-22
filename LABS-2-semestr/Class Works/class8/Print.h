#ifndef MAIN_CPP_PRING_H
#define MAIN_CPP_PRING_H
#include <utility>

#include "iostream"
#include "Object.h"

class Pring :public Object {
protected:
    std::string title;
    std::string avtor;
public:
    Pring();
    Pring(std::string, std::string);
    Pring(const Pring&);
    ~Pring();
    void Show();
    //do we really need input?
    void Input();
    //setters and getters
    void set_title(std::string str) { title = str; };
    void set_avtor(std::string sta) { avtor = sta; };
    std::string get_avtor() { return avtor; };
    std::string get_title() { return title; };
    Pring& operator=(const Pring&);
    void HandleEvent(const TEvent& event);
};

#endif //MAIN_CPP_PRING_H