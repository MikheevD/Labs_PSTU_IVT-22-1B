#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H
#include "iostream"
#include "string"
#include "Time.h"
using namespace std;

template <class T>
class Vector {
    T* data;
    int size;
public:
    Vector(int s, T t);
    ~Vector();
    Vector(const Vector<T>&);
    Vector& operator=(const Vector<T>&a);
    T& operator[](int index);
    Vector operator* (const Vector<T>& k);
    Vector operator* (int k);
    Vector operator* (const Time& t);
    int operator()();
    friend ostream& operator<< (ostream& out, const Vector<T>&a);
    friend istream& operator>> (istream& in, Vector<T>&a);
};

#endif //MAIN_CPP_VECTOR_H

