
class Subject
{
    vector<observer *> observers;

public:
    void detatch(Observer *o)
    {
        v.erase(v.begin(), v.end(), o)
            observers.pop_back();
        // remove observer
    }
    void attatch(Observer *o)
    {
        observers.push_back(o);
    }
    void notifyObservers()
    {
        for (observer *o : observers)
        {
            o->notify();
        }
    }
    ~Subject() = 0
};

class Observer
{
public:
    virtual void notify() = 0;
    virtual ~Observer() {};
};

class Tweeter : public Subject
{
    ifstream in;
    string lastTweet;

public:
    Tweeter(const string &filename) : in{filename} {}
    string getState()
    {
        return lastTweet;
    }
    bool tweet()
    {
        getline(in, lastTweet);
        return in.good();
    };
};

class Follower : public Observer
{
    Tweeter *iFollow;
    string name;

public:
    Follower(Tweeter *t, string s) : iFollow{t}, name{s}
    {
        t->attatch(this);
    }
    void notify() override
    {
        cout << "Notified" << endl;
    }

    ~Follower()
    {
        t->detatch(this);
    }
}
