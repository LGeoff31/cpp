

class Enemy
{
public:
    virtual void beStruckBy(Weapon &w) = 0;
};

class Monster : public Enemy
{
public:
    void beStrucyBy(Weapon &w)
    {
        w.strike(*this);
    }
};

class Turtle : public
{
public:
    void beStruckBy(Weapon &w)
    {
        w.strike(*this);
    }
};

class Weapon
{
public:
    virtual void strike(Monster &m) = 0;
    virtual void strike(Turtle &t) = 0;
    virtual ~Weapon() {}
};

class Rock : public Weapon
{
public:
    void strike(Monster &m) override
    {
        cout << "Rock vs Monster" << endl;
    }
    void strike(Monster &m) override
    {
        cout << "ROck vs Turtle" << endl;
    }
}

int
main()
{
    Enemy *e = ...;
    Weapon *w = ... e->beStruckBy(*w);
}

/*
Assume WLOG e = turtle, w = rock.
e->beStruckyBy(*w), since beStruckBy is virtual, cause dynamic type which is turtle.
Turtle->beStruckyBy passes in Turtle type, give reference *this, so this calls dynamic type for w which is rock.
Then calls rock vs turtle.
*/