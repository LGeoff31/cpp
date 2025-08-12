#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/*
We can bundle a struct to deal with errors
But then all return types are larger and akward to access data fields
However C++ has its own way of dealing with exceptions
v.at(100) fetches v[100] and throws an exception if it indexes out of bounds
To raise an exception, we use the THROW keyword, we get from #include <stdexcept>

When a exception is raised, the control flow will search through stack upwards looking for catch block handles exception
This is called stack unwinding.
Dtors of objects are run on the stack during this process of stack unwinding.
If handle is found, we jump to that point, otherwise, program crashes at end.

Note in catch block (out_of_range r) -> where r indicates error message description
*/

void f()
{
    throw out_of_range("F threw");
    cout << "f done" << endl;
}

void q()
{
    f();
    cout << "q done" << endl;
}

void h()
{
    q();
    cout << "h done" << endl;
}

int main()
{
    try
    {
        h();
    }
    catch (out_of_range r)
    {
        cout << r.what() << endl;
    }
    return 0;
}