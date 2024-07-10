#include <iostream>
using namespace std;
class A
{
public:
    virtual void print()
    {
        cout << "I'm in A" << endl;
    }

    A()
    {
        cout << "Parent constructor is called" << endl;
    }
    virtual ~A()
    {
        cout << "Parent destructor is called" << endl;
    }
};
class B : public A
{
    void *ptr;

public:
    void print()
    {
        cout << "I'm in B" << endl;
    }
    B()
    {
        ptr = (void *)malloc(256); // 256 bytes
        cout << "Child constructor is called" << endl;
    }
    ~B()
    {
        free(ptr);
        ptr = nullptr;
        cout << "Child destructor is called" << endl;
    }
};
int main()
{
    A *obj = new B;
    obj->print();
    const char *p = "12345"; // const char *p means that we can change the value of p but we can't change the value of *p.
    const char **q = &p;     // const char **q means that can not change the value of **q.
    cout << *p << " " << "" << " " << p << " " << endl;
    // virtual can be used to achieve abstraction in runtime polymorphism. The ablove line will call print fn of class A if there were no virtual keyword but it is calling the print function of B. So, using virtual keyword, we have achieved abstraction in runtime polymorphism.

    delete obj; // we have made the parent desctructor virtual coz if we don't do this, deleting this obj will directly call the parent destructor and it'll skip calling its own destructor i.e., child destructor. This obj memory will not free until it will call its own destructor
}