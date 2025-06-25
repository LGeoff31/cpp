#include <iostream>
#include "Rational.h"
using namespace std;

/*
Overloading: Providing multiple definitions of a method with differing number/type of arguments
Operator overloading: Overloading typical operation (=, [], etc) to treat objects as if they're primitive types

Note, iostreams must be passed by reference & for operation>> and operation<<

Friend keyword: Gives access to the private/protected fields of another class
When we use friend in .H, we don't have to prefix that function with Rational::, it will already have access

*/

Rational::Rational(int num, int denom) : num{num}, denom{denom} {}

int Rational::getNum() const
{
    return num;
}
int Rational::getDenom() const
{
    return denom;
}
void Rational::setNum(int num)
{
    this->num = num;
}
void Rational::setDenom(int denom)
{
    this->denom = denom;
}

Rational Rational::operator+(Rational const &rhs) const
{
    return Rational{num * rhs.denom + rhs.num * denom, denom * rhs.denom};
}

Rational &Rational::operator=(Rational const &rhs)
{
    if (this != &rhs)
    {
        num = rhs.num;
        denom = rhs.denom;
    }
    return *this;
}

Rational operator+(int lhs, const Rational &rhs)
{
    return Rational(lhs) + rhs;
}

istream &operator>>(istream &in, Rational &r)
{
    char slash;
    in >> r.num >> slash >> r.denom;
    return in;
}

ostream &operator<<(ostream &out, const Rational &r)
{
    out << r.num << '/' << r.denom;
    return out;
}

int main()
{
    Rational a{3, 4}, b{2, 5};
    Rational c = a + b;
    cout << c << endl;

    Rational e;
    e = c = a;
    cout << a << endl;
    cout << c << endl;
    cout << e << endl;

    return 0;
}

// 0.75 + 0.4 = 1.15 -> 3/20 -> .15