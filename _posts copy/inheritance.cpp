#include <iostream>

using namespace std;

class Base
{
public:
    Base(int i): data(i)
    {
        
    }
    virtual void do_thing() {}
    int data{};
    virtual ~Base()
    {
        cout << "called base destructor" << endl;
    }
};

class Derived: public Base
{
public:
    Derived(int i): Base(i)
    {

    }
    void do_thing() override {}
    void print(){
        // cout << data << endl;
    }
    ~Derived()
    {
        cout << "called derived destructor" << endl;
    }
};

int main()
{
    Base * b = dynamic_cast<Derived*>(new Derived(7));
    b->do_thing();
    b->print();
    delete b;
}