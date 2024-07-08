// Abstraction -> Bird *obj=new Ostrich; // in this example, we created a variable of bird type but we hide that which type of bird it is like whether it is penguin. ostrich or eagle.
// 2nd example -> when we include <maths.h> header file, there is pow() function, now this fun. can be implemented in two way, either by loop or by recursion. When we use pow() func. from this header file, we don't know how it is implemented i.e., the implementation is hidden. This is Abstraction.
// 3rd example -> sorting algo, Sort *obj=new QuickSort; // this will slow bcoz quicksort has worst case tc of O(n^2). So, Sort *obj=new MergeSort; just by changing one line of code, we can increase the speed.

// Advantage -> 1) since implementation is hiddn, security is increased. 2) reuseability 3) low coupling (easily detachment and attachment)

// Runtime Polymorphism
#include <iostream>
using namespace std;
class Hero
{
public:
    virtual void dummy() // virtual is used to abstract the class
    {
        cout << "I'm in hero" << endl;
    }
};

class PLayer : public Hero
{
public:
    int n;
    void dummy()
    {
        cout << "I'm in PLayer" << endl;
    }

    void print() const
    {
        // using const in front of method does not allow to change any value of this object
        // this->n=6; this will give error bcoz modifying value inside const func. is not possible
        cout << "I'm inside print" << endl;
    }
};

// Friend Class
class A
{
private:
    int value;
    void print()
    {
        cout << "I'm in class A" << endl;
    }
    friend class B; // friend class can access private and protected members of class in which they are declared that they are friend
};

class B
{
public:
    void printValue(A temp)
    {
        temp.print();
    }
};

// Friend Function
class Math
{
private:
    int value = 150;

    friend void printValue(Math m); // friend function can assess private and protected members in their printValue in that function
};

void printValue(Math temp)
{
    cout << temp.value << endl;
}

int main()
{
    Hero *obj = new PLayer;
    // Above, we created a variable of base class but actual object is of sub class, then calling any common function will call the base class function if it it not virtual function.
    obj->dummy();

    int x = 5;
    int y = 6;
    const int *a = &x; // const doesn't allow to modify the value. All three will run successfully bcoz it is containing the address of x, not the value of x;
    x = 12;
    int *const b = &x;
    x = 13;
    const int *const c = &x;

    // enum -> user defined data type, which assign some limited values
    // enum Gender{
    //     male, female
    // };

    // Friend Class
    A obj1;
    B obj2;
    obj2.printValue(obj1);

    // Friend Function
    Math obj3;
    printValue(obj3);
}