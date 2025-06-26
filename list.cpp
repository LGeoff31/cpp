#include <iostream>
using namespace std;

/*
By putting node inside the private field of List, now representation exposure is eliminated.
Clients can not mutate the Node to point to itself, etc
Invariants
1) No cycles
2) All next ptrs are heap-allocated or nullptr
3) No sharing between lists

We face a new problem. the ith is slow but giving access to nodes is representation exposure.
There is a common design pattern called the Iterator pattern.

We need to operator overload the following for Iterator pattern
1) ++
2) *
3) !=

for (string s: l) // This implicitly uses the Iterator
equivalent to
for (Iterator it = l.begin(), it != l.end(); it++) {
    string s = *it;
}

Note, the auto keyword allows the type to be implicitly determined by fcn return type, sort of how Python does it
We want to hide the details, not allow clients to create Iterator
We make Iterator ctor private, and friend List so List has access
Hence we have prevented forgery, clients can not create Iterator bc now private
Only List can call Iterator ctor
Encapsulation is the idea of grouping related data together in classes.
Adding friend keyword weakens encapsulation by potentially imposing more possibilities of hurting invariants.
So only use friends, when they can do something for you
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
    class Iterator
    {
        Node *cur;
        friend class list;

    public:
        explicit Iterator(Node *cur) : cur{cur} {}
        bool operator!=(const Iterator &other)
        {
            return cur != other.cur;
        }
        Iterator &operator++()
        {
            cur = cur->next;
            return *this;
        }
        string operator*()
        {
            return cur->data;
        }
    };

public:
    void push(const string &s)
    {
        head = new Node{s, head};
    }

    // Outside the Iterator class, we need to support .begin() and .end() methods
    Iterator begin() const
    {
        return Iterator{head};
    }
    Iterator end() const
    {
        return Iterator{nullptr};
    }
    string ith(int i)
    {
        int count = 0;
        for (Iterator it = begin(); it != end(); ++it)
        {
            if (count == i)
            {
                return *it;
            }
            count++;
        }
        return "";
    };
};
void printList(const List &l)
{
    for (auto s : l)
    {
        cout << s << endl;
    }
}

int main()
{
    List l;
    l.push("geoff");
    l.push("ansdrew");
    l.push("patrick");
    l.push("kevin");
    printList(l);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << l.ith(i) << endl;
    // }

    return 0;
}