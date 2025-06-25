#include <iostream>
using namespace std;

/*
By default, the default copy constructor does a shallow copy
So if we deep copy, we need to write our own copy ctor

lvalue: An expression we can take the address of i.e int x = 5, &x returns something
rvalue: Temporary values that will be destroyed soon i.e f(5) after f returns 5 is gone, also can't take address

Typically we cannot bind a lvalue to rvalue, however, we can bind const lvalue to references to rvalues
f(int &x)
f(5)
vs
f(const int &x)
f(5)
const allows temporary memory location to store argument

a = move(b) moves all data from b to a in O(1)
move is included in include <utility>
move takes a value and FORCES it to a rvalue, that way we don't use copy constructor O(1)
*/

struct Node
// this is a pointer to the current object
// *this is the object itself
{
    string data;
    Node *next;
    // Regular constructor
    Node(string data, Node *next) : data{data}, next{next} {}
    // Deep copy constructor, override
    Node(const Node &other) : data{other.data}, next{other.next ? new Node{*(other.next)} : nullptr} {}
    // Move that takes in rvalue reference
    Node(Node &&other) : data{move(other.data)}, next{other.next} { other.next = nullptr; }
    // Copy assignment operator
    Node &operator=(const Node &other)
    {
        Node temp{other};
        swap(data, temp.data);
        swap(next, temp.next);
        return *this;
        // When temp goes out of scope, its dtor is run so cleaned up :)
    }

    // Move assignment operator
    Node &operator=(Node &&other)
    {
        swap(data, other.data);
        swap(next, other.next);
        return *this;
    }
    // Delete constructor
    ~Node()
    {
        delete next;
    }
};

void printLinkedList(Node *root)
{
    while (root)
    {
        cout << root->data << "->";
        root = root->next;
    }
}

Node getAlphabet()
{
    return Node{"a", new Node{"b", new Node{"c", nullptr}}};
}

void f(const string &s)
{
    cout << "1" << endl;
}

void f(const string &&s)
{
    cout << "2" << endl;
}

int main()
{
    Node n{"a", new Node{"b", new Node{"c", nullptr}}};
    Node p{"d", new Node{"e", new Node{"f", nullptr}}};
    n = n;
    // Node p{n}; // Calls the copy constructor (shallow)
    // p.next->data = "z";
    // printLinkedList(&p);
    printLinkedList(&n);

    // Inefficiency since getAlphabet stack frame creates the llist, then to get to caller stack frame calls copy construct (INEFFICIENT)
    // We know temporary list made in getAlphabet() will be destroyed, we could've just used it
    // Node a = getAlphabet();

    // int x = 5;
    // int &y = x;
    // x = 10;
    // cout << "Hello" << endl;
    // cout << &x << endl;
    // cout << y << endl;

    // string &&rvalue = f(); // Extending the lifetime of an rvalue
    // cout << rvalue << endl;
    // string s = "Hello world";
    // f(s);

    return 0;
}