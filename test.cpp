#include <iostream>
using namespace std;

struct A
{
    int x;
    A(int val = 10) : x{val} {}
    ostream &operator<<(ostream &out)
    {
        return out << x;
    }
};

int main()
{
    A a1, a2;
    int y = 50;
    (a2 << (a1 << cout)) << y;
    ((cout << a2) << a1) << y;
    return 0;
}