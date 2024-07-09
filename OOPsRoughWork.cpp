#include <iostream>
using namespace std;
class A
{
public:
    virtual void print()
    {
        cout << "I'm in A" << endl;
    }
};
class B : public A
{
public:
    void print()
    {
        cout << "I'm in B" << endl;
    }
};
int main()
{
    A *obj = new B;
    obj->print();
    const char *p="12345";  // const char *p means that we can change the value of p but we can't change the value of *p. 
    const char **q=&p;  // const char **q means that can not change the value of **q.
    cout << *p << " " << "" << " " << p <<" "<< endl;
    // virtual can be used to achieve abstraction in runtime polymorphism. The ablove line will call print fn of class A if there were no virtual keyword but it is calling the print function of B. So, using virtual keyword, we have achieved abstraction in runtime polymorphism.
}