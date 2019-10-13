//
// Created by Aykut Ismailov on 12.10.2019 г..
//

#include <cmath>
#include "complex.h"

complex& complex::operator=(const complex& other)
/**
 * Функцията присвоява стойноста на комплексно число на този обект
 * @param other - обект от тип complex
 * @return този обект
 */
{
    std::cout << "operator=." << std::endl;
    re = other.re;
    im = other.im;
    return *this;
}

complex complex::operator+(complex& other)
/**
 * Функция за намиране на сбор на две комплексни числа
 * @param other - второ събираемо
 * @return обект от тип complex със стойност сбора на първото събираемо(този обект) и второто събираемо(other)
 */
{
    std::cout << "operator+." << std::endl;
    return complex(re + other.re, im + other.im);
}

complex complex::operator-(complex& other)
/**
 * Функция за намиране на разлика на две комплексни числа
 * @param other - умалител
 * @return обект от тип complex със стойност разликата на умаляемото(този обект) и умалителя(other)
 */
{
    std::cout << "operator-." << std::endl;
    return complex(re - other.re, im - other.im);
}

complex complex::operator*(complex& other)
/**
 * Функция за намиране на произведение на две комплексни числа
 * @param other - втори множител
 * @return обект от тип complex със стойност произведението на първия множител(този обект) и втория множител(other)
 */
{
    std::cout << "operator*." << std::endl;
    return complex(re * other.re - im * other.im,
                   re * other.im + im * other.re);    //формула за умножение на комплексни числа
}

complex complex::operator/(complex& other)
/**
 * Функция за намиране на частно на две комплексни числа
 * @param other - делител
 * @return обект от тип complex със стойност частното на делимо(този обект) и делител(other)
 */
{
    std::cout << "operator/." << std::endl;
    return complex(
            (re * other.re + im * other.im) / (other.re * other.re - other.im * other.im),
            (-(re * other.im) + (im * other.re)) / (other.re * other.re - other.im * other.im));  // формела за делене на комплексли числа
}


bool complex::operator==(const complex& other)
/**
 * Функцията срамнява за равенство между две комплексни числа
 * @param other - второто комплексно число
 * @return true/false в зависимост дали двете числа да равни
 */
{
    std::cout << "operator==." << std::endl;
    return re == other.re && im == other.im;    // проверяваме дали и двете части(реална и имагинерна) са равни
}

complex complex::operator-()
/**
 * Функцията връща нов обект от тип complex със стойност (този обект)*(-1)
 * @return (този обект)*(-1)
 */
{
    std::cout << "operator- unary." << std::endl;
    return complex(-re, -im);
}

complex::operator double()
/**
 * Функцията връща модула на комплексното число в тип double
 * @return |този обект|
 */
{
    std::cout << "cast double." << std::endl;
    return sqrt(re * re + im * im);
}

complex::operator int()
/**
 * Функцията връща модула на комплексното число в тип int
 * @return |този обект| като цяло число
 */
{
    std::cout << "cast int." << std::endl;
    return int(sqrt(re * re + im * im));
}

void* complex::operator new(std::size_t size)
/**
 * Функцията връща указател към обект от тип complex
 * @param size големина на обекта
 * @return *complex
 */
{
    std::cout << "operator new." << std::endl;
    void* c = ::new complex();
//  void* c = malloc(size); също е вариант
    return c;
}

void complex::operator delete(void* c)
/**
 * Функцияна освобождава памет заделена за обект от тип complex
 * @param c
 */
{
    std::cout << "operator delete." << std::endl;
    free(c);
}

std::ostream& operator<<(std::ostream& out, const complex& obj)
/**
 * Функция за извеждане към поток за изход
 * @param out поток за изход
 * @param obj обек за извеждане
 * @return потока out с предаден на него obj в подходяща форма
 */
{
    out << obj.re << " " << obj.im << "i";
    return out;
}

std::istream& operator>>(std::istream& in, complex& obj)
/**
 * Функция за взема информация от поток за вход и я въвежда в обект от тип complex
 * @param out поток за вход
 * @param obj обек от тип complex, в който запазваме извлечената от потока информация
 * @return потока in с извлечени от него данни и запазени в obj в подходяща форма
 */
{
    in >> obj.re >> obj.im;
    return in;
}

int complex::operator,(int)
{
    std::cout << "operator," << std::endl;
    return 0;
}

