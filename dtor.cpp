#include <iostream>
using namespace std;

struct X
{
    int *a;
    X(int n) : a{new int[n]} {}
    ~X() { delete[] a; }
};

struct Y : public X
{
    int *b;
    Y(int n, int m) : X{new int[n]}, b{new int[n]} {}
    ~Y() { delete[] b; }
};
