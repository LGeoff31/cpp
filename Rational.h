#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

/*
For our rational class, we want to support the following
getters/setters for num/denom
operator+
operator=
in/out
*/

class Rational
{
    int num;
    int denom;

public:
    Rational(int num = 0, int denom = 1);

    int getNum() const;
    int getDenom() const;
    void setNum(int num);
    void setDenom(int num);

    Rational operator+(Rational const &rhs) const; // Adding rational to current rational object
    friend Rational operator+(int lhs, Rational const &rhs);
    Rational &operator=(Rational const &rhs);

    friend istream &operator>>(istream &in, Rational &r);
    friend ostream &operator<<(ostream &out, const Rational &r);
};

#endif