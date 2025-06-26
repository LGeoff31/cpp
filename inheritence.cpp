#include <iostream>
using namespace std;

/*
It's not always a good idea to add virtual to all superclass methods.
EFFICIENCY issues.
Adding virtual method increases object size => more RAM => Less efficient
Virtual makes object 8 bytes larger (goes towards vptr)
Vptr is what allows dynamic dispatch to work, w/o it, NO inheritence

*/
class Book
{

public:
    Book(string author, string title, int length) : author{author}, title{title}, length{length} {}
    int getLength()
    {
        return length;
    }

    virtual bool isHeavy() const
    {
        return length > 200;
    }
    virtual void name() const
    {
        cout << "The book is " << title << endl;
    }

protected:
    string author;
    string title;
    int length;
};

class Text : public Book
{
    string topic;

public:
    Text(string author, string title, int length, string topic) : Book{author, title, length}, topic{topic} {}
    bool isHeavy()
    {
        return length > 500;
    }
    void name() const
    {
        cout << "'The text is " << title << endl;
    }
};

class Comic : public Book
{
    string hero;

public:
    Comic(string author, string title, int length, string hero) : Book{author, title, length}, hero{hero} {}
};

int main()
{
    int choice;
    Book *b = new Text{"geoffrey", "Hunger Games", 600, "a"};
    b->name();
    return 0;
}