//
// Created by Aykut Ismailov on 12.10.2019 г..
//
#include <cstdlib>
#include <iostream>

#ifndef PE_LECTURE_COMPLEX_H
#define PE_LECTURE_COMPLEX_H


class complex
{
private:
    double re;
    double im;
public:
    complex() : re(0), im(0)
    {
    }

    explicit complex(double re, double im) : re(re), im(im)
    {
    }

    complex& operator=(const complex&);     // оператор за присвояване

    complex operator+(complex&);        // сбор на комплексни числа
    complex operator-(complex&);        // разлика на комплексни числа
    complex operator*(complex&);        // произведение на комплексни числа
    complex operator/(complex&);        // частно на комплексни числа

    bool operator==(const complex&);    // проверка за равенство на коплексни числа

    complex operator-();                // умножение по -1

    explicit operator double();         // кастване към double
    explicit operator int();            // кастване към int

    void* operator new(std::size_t);    // създаване на указател към complex
    void operator delete(void*);        // изтриване на указател към complex

    friend std::ostream& operator<<(std::ostream&, const complex&); // изход
    friend std::istream& operator>>(std::istream&, complex&);       // вход

    int operator,(int);

    ~complex() = default;
};

#endif //PE_LECTURE_COMPLEX_H
