#include <iostream>
using namespace std;

// a class is a user defined data type
class emptyClass
{
};

class myClass
{
    // data members
private:
    // public: // these are access modifiers
    int subs;
    bool b;
    int views;

public:
    int *values;
    // member functions
    // int getSubscribers()
    // {
    //     return subs;
    // }

    // private:
public:
    void print()
    {
        cout << subs << endl;
    }

    // getters & setters
    int getSubs()
    {
        return subs;
    }
    void setSubs(int value)
    {
        subs = value;
    }

    // Default constructor -> it is just a function without return type
    myClass()
    {
        subs = 0; // initialising the variables when a new object is created
        views = 0;
        cout << "Creating an object, I'm inside constructor" << endl;
        values = new int[5];
        for (int i = 0; i < 5; i++)
        {
            values[i] = 101;
        }
    }

    // Parameterised Constructor
    // myClass(int subsCount, int viewCount)
    // {
    //     subs = subsCount;
    //     views = viewCount;
    //     cout << "I'm inside Parameterised constructor" << endl;
    // }

    // Parameterised Constructor with this keyword -> current object
    myClass(int subs, int views)
    {
        this->subs = subs;
        this->views = views;
        cout << "I'm inside Parameterised constructor" << endl;
    }

    myClass(int subsCount, int viewCount, int n)
    {
        subs = subsCount * n;
        views = viewCount * n;
        cout << "I'm inside 2nd Parameterised constructor" << endl;
    }

    // copy constructor
    myClass(myClass &temp)
    // we use pass by reference in above temp bcoz if we use pass by value, then a copy of object of myClass type is created. When a new copy is created, then again copy constructor is called. Then, again due to pass by value, a copy is created, then again it call copy constructor. So, it will be infinite loop. That's why we use pass by reference.
    {
        this->subs = temp.subs;
        this->views = temp.views;
        cout << "I'm inside copy constructor" << endl;
        this->values = temp.values;
    }
    myClass (myClass *temp){
        cout << "I'm inside pointer copy constructor" << endl;
    }

    // Destructor -> this will only delete static memory variables bcoz it has only access to stack memory
    ~myClass()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    cout << "Size of empty class is " << sizeof(emptyClass) << endl; // it takes 1 byte to track it
    // homework -> size of empty class in java?
    cout << "Size of myClass is " << sizeof(myClass) << endl; // int is of 4 byte and bool is of 1 byte, instead of taking 5 byte, it takes 8 byte. It is due to padding and greedy alignment.
    // homework -> explore padding and greedy

    // Object creation
    myClass first; // static alloation -> it allocates memory in stack. When we use new keyword, it allocates memory dynamically in heap memory
    // we use dot operator in static whereas arrows in dynamic
    // cout << "Printing the subs of first object " << first.b << endl;
    first.print();

    cout << first.getSubs() << endl;

    // Dynamic allocation
    myClass *second = new myClass();

    // access data members
    cout << second->getSubs() << endl;

    //  if we want to access dynamic variable using dot operator, then
    cout << (*second).getSubs() << endl; // first, we dereference it, then we can use dot operaator

    // in static allocation, uninitialised variable may initialised with garbage value whereas in case of dynamic allocation, variable initialised with 0.

    myClass *third = new myClass(2, 3);     // this will call parameterised constructor
    myClass *fourth = new myClass(2, 3, 4); // this will call 2nd parameterised constructor

    myClass fifth;
    fifth.setSubs(200000000);
    myClass copyOfFifth(fifth); // this will call copy constructor
    // myClass copyOfFifth(third); // this will call pointer copy constructor, this will not call copy constructor as third is dynamically allocated which is not of object type, third is pointer

    cout << "before changing fifth, value of copyOfFifth at 1st index " << copyOfFifth.values[1] << endl;
    fifth.values[1] = 123;
    cout << "after changing fifth, value of copyOfFifth at 1st index " << copyOfFifth.values[1] << endl;

    // To dynamically allocated object, we have to manually use delete keyword
    delete third;
    delete fourth;
}