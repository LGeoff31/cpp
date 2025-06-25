#include <iostream>
using namespace std;

/*
void useList(const List& l) {
    for (auto s : l) {
        s = "247";
    }
}

This actually compiles and works, we are only calling const of l.
Const guarantee's the object fields don't change which are nodes
This is an example of where we need to differentiate physical and logical constness.
1) Physical Constness: The field head node doesn't change
2) Logical Constness: Memory was mutated so logically adt has changed

The above example, it has logical constness not physical constness.

We face another problem.
Begin and End returns Iterators where the operator* has non-const return type
Sol'n: Use const overloading, 2 versions begin/end which return different iterators

To remove duplicated code, we use a template
To modularize Iterator and CIterator, we will have return type of template parameter

<typename T> is a template declaration, T is placeholder for any type
*/

class List
{
    struct Node
    {
        string data;
        Node *next;
        Node(const string &data, Node *next) : data(data), next(next) {}
        ~Node() { delete next; }
    };
    Node *head = nullptr;
    template <typename T>
    class MyIterator
    {
        Node *cur;
        explicit MyIterator<T>(Node *cur) : cur{cur} {}

    public:
        MyIterator<T> &operator++() {}

        bool operator!=(const MyIterator &other)
        {
            return cur != other.cur;
        }
        T operator*()
        {
            return cur->data;
        }
        friend class list;
    };
    using Iterator = MyIterator<string &>;
    using CIterator = MyIterator<const string &>;

    // Outside the Iterator class, we need to support .begin() and .end() methods
    Iterator begin()
    {
        return Iterator{head};
    }
    Iterator end()
    {
        return Iterator{nullptr};
    }
    CIterator begin() const
    {
        return Iterator{head};
    }
    CIterator end() const
    {
        return Iterator{nullptr};
    }
};

int main()
{

    return 0;
}