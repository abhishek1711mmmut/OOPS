#include <iostream>
using namespace std;

// The main difference b/w class and struct is that in struct, by default, everything is public whereas in class, everything is private by default

// Struct -> used for data bundling is more important, there is not encapsulation
// Class -> used when there is responsibility, functionality & for applying abstraction

struct base
{
    int value;
    base(int _val)
    {
        value = _val;
        cout << __FUNCTION__ << endl;
    }
    virtual void fun()
    {
        cout << __FUNCTION__ << endl;
    }
};

// Struct is nearly sale as classs.
// Above code will not work in C.

int main()
{
    base b(4);
    b.fun();
    cout << b.value << endl;
    return 0;
}