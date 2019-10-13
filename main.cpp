#include <iostream>
#include <array>
#include <algorithm>
#include "complex.h"

using namespace std;

int main()
{
    complex c1(0, 0), c2(1, 2);

    cin >> c1;

    cout << endl;
    cout << c1 << endl;
    cout << c2 << endl;

    cout << endl;
    cout << c1 + c2 << endl << c1 - c2 << endl;
    cout << c1 * c2 << endl << c1 / c2 << endl;

    cout << endl;
    cout << (c1 == c2 ? "true" : "false") << endl; // ternary operator

    cout << endl;
    double d1 = double(c1); // C-style cast
    double d2 = static_cast<double>(c2); // C++ cast
    cout << d1 << endl << d2 << endl;

    cout << endl;
    int i1 = int(c1); // C-style cast
    int i2 = static_cast<int>(c2); // C++ cast
    cout << i1 << endl << i2 << endl;

    cout << endl;
    complex* cp = new complex(2, 3);
    cout << *cp << endl;
    delete cp;

    cout << endl;
    std::array<complex, 3> carr;

    cout << "initial carr:" << endl;
    for(complex c:carr) // range-based for loop
    {
        cout << c << endl;      // извеждаме началните стойности на масива
        c = c1;
    }

    cout << endl;
    cout << "carr after range-based for" << endl;
    for(complex& c:carr) // range-based for loop
    {
        cout << c << endl;      // извеждаме промени от предишния for
        c = c1;
    }

    cout << endl;
    cout << "carr after range-based for loop with &" << endl;
    for(auto c = carr.begin(); c != carr.end(); c++) // auto се нагажда според типа, който се присвои на променливата
    {
        cout << *c << endl;     // извеждаме промени от предишния for
        c->operator=(c2);       //(*c) = c2; също може да се използва
    }

    cout << endl;
    cout << "carr after for loop with iterator" << endl;
    for(int i = 0; i < carr.size(); i++)
    {
        cout << carr[i] << endl;    // извеждаме промени от предишния for
    }

    cout << endl;
    cout << "void demonstration" << endl;
    cout << (c1, 123) << endl;
    cout << ((void) c1, 123) << endl;    //(void) подтиска изпълнението на operator,
}