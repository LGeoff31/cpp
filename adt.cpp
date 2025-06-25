#include <iostream>
#include "adt.h"
using namespace std;

/*
Interface: How clients use your ADT
Implementation: Details that should be hidden
I.e AVL ADT, the interface includes insert, delete but client shouldn't know implementation like restructuring, tree rebalancing

There are two types of ADT misuse
1) Forgery: Client can create an invalid instance of a class
2) Tampering: Client can update the instance in a unexpected way

The explicit keyword beside a function prevents the compiler from performing implicit conversion

Note, not all classes should have a default constructor i.e student class, you don't know by default name, id, b-day, etc
If you don't write a default ctor, the compiler will write one for you i.e primitive fields uninitialized

Important to have default values in .h files instead .cc.
The reason, if a function is called w/o arguments, compiler must use default values at call site. But caller only includes .h file, not .cc.
So default arguments must be visible to caller.

4 steps during object construction
1) Space is allocated for the object
2) The objects superclass constructors (if any) are called
3) Member fields are initialized (via MIL)
4) The constructor body runs

MIL is quicker than initializing fields in the ctor body, since w/o MIL, it populates fields with default values then overwrites in ctor body, less efficient
*/

/* EXPLICIT KEYWORD EXAMPLE */

Meter::Meter(double val) : val{val} {}
void Meter::display()
{
    cout << val << " meters!" << endl;
}

void printDistance(Meter m)
{
    Meter l; // Uses the default values provided in the constructor parameters, note these should really appear only in .h files
    m.display();
    l.display();
}

/* EXPLICIT KEYWORD EXAMPLE */

int main()
{
    printDistance(5.0); // printDistance implicitly converts 5.0 (double) to meter calling the Meter constructor
    return 0;
}