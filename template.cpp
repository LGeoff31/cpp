#include <iostream>
using namespace std;

class Turtle
{
    virtual void drawShell() = 0;
    void drawHead() { cout << "head"; }
    void drawFeet() { cout << "Feet"; }

public:
    void draw()
    {
        drawHead();
        drawShell();
        drawFeet();
    }
};

class RedTurtle : public Turtle
{
public:
    void drawShell() override
    {
        cout << "RED SHELL" << endl;
    }
};
class GreenTurtle : public Turtle
{
public:
    void drawShell() override
    {
        cout << "Green SHELL" << endl;
    }
};

int main()
{
    Turtle *t = new RedTurtle;
    t->draw();
}