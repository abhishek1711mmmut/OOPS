#include <iostream>
using namespace std;

class Human
{
    // encapsulation -> information hiding (wrapping up data member and member function in a class), full encapsulation : class in which all data members are private
protected:
    int height;
    int weight;
    int age;

public:
    Human()
    {
    }

    int getAge()
    {
        return this->age;
    }

    int getWeight()
    {
        return this->weight;
    }

    int getHeight()
    {
        return this->height;
    }
};

// Inheritance -> inherits dm and mf from parent/base/super class to child/derived/sub class
class Male : protected Human
// public is mode of inheritance (In java, we use extend instead of public)
// Protected -> inherited dm & mf are only accessible inside this child class, they can not be accesible outside this class
// Private member can not be inherited
{
public:
    void printAge()
    {
        cout << this->age << endl;
    }
};

// Multilevel inheriting
class Animal
{
public:
    int age;

    void bark()
    {
        cout << "I'll bark" << endl;
    }
};

class Dog : public Animal
{
};

class Lebra : public Dog
{
};

// Multiple inheritance
class Lion
{
public:
    int age;

    void speak()
    {
        cout << "I'm a Lion" << endl;
    }
};

class Tiger
{
public:
    int weight;

    void speak()
    {
        cout << "I'm a Tiger" << endl;
    }
};

class Liger : public Lion, public Tiger
{
};

// Hierarchical inheritance -> one class serve as a parent class for more than one child
class Dog2 : Animal
{
};
class Dog3 : Animal
{
};

// Hybrid inheritance -> combination of multiple and multilevel inheritance

// Polymorphism -> existing in multiple forms (many form)
// Compile time (static) : function and operator overloading
// Run time (dynamic) : Overriding

// function overloading
class Maths
{
public:
    int a;
    int b;
    int add()
    {
        return a + b;
    }
    int add(int value)
    {
        return a + b + value;
    }
    float add(float value)
    {
        return a + b + value;
    }
};

// operator overloading
class Hero
{
public:
    int age;
    int weight;
    int height;

    Hero operator+(Hero &b) // hero is a return type which means after using + operator, it will return a hero type object
    {
        Hero ans;
        ans.age = this->age + b.age;
        ans.height = this->height + b.height;
        ans.weight = this->weight + b.weight;
        return ans;
    }
};

// function overriding
class Shape
{
public:
    int a;
    int b;

    int area()
    {
        return a * b;
    }
};

class Rectangle : public Shape
{
};

class Circle : public Shape
{
public:
    int area()
    {
        int radius = a / 2;
        return 3.14 * radius * radius;
    }
};


// creating class just for mcq ques, c is inherited from b, and b is inherited from a.
class a
{
public:
    a()
    {
        cout << "a is called" << endl;
    }
};

class b : public a
{
public:
    b()
    {
        cout << "b is called" << endl;
    }
};

class c : public b
{
public:
    c()
    {
        cout << "c is called" << endl;
    }
};

int main()
{
    Human h;
    h.getWeight();

    Male m;
    m.printAge();
    // cout << "Size " << sizeof(m) << endl;

    Lebra L;
    L.bark();

    Liger obj;
    cout << "Liger age and weight: " << obj.age << " " << obj.weight << endl;
    // obj.speak();  // this will give error bcoz tiger and lion, both have speak function. The compiler will confuse that which speak function it have to call. This problem is called inheritance ambiguity. So, to solve this problem, we use scope resolution operator (::).
    obj.Lion::speak();

    // function overloading
    Maths d;
    d.a = 10;
    d.b = 11;
    cout << "Addition result is " << d.add() << endl; // function overloading can be done either changing by no. of arguments or by changing type of argument
    cout << "Addition result is " << d.add(99) << endl;
    cout << "Addition result is " << d.add(80.1f) << endl;

    // Operator overhead
    Hero e;
    e.age = 2;
    e.height = 4;
    e.weight = 6;

    Hero f;
    f.age = 2;
    f.height = 4;
    f.weight = 6;

    Hero ans = e + f; // here, it will go in hero class, then e will be treated as current object, f will be passed by reference, and it will apply the logic of + operator which is defined in hero class
    // Note:- The compiler don't know how to add two hero type operator, we have to define + operator manually.
    cout << ans.age << " " << ans.height << " " << ans.weight << endl;

    // function overiding -> changing the function definition in child class which is inherited from parent class
    Circle *obj2 = new Circle;
    obj2->a = 6;
    cout << obj2->area() << endl;


    // MCQ ->
    // a *obj = new a;
    // a *obj = new b;     // this will first create variable of "a" type then create "b" type, means it will call the constructor of all inherited class, in the order of parent to child.
    // b *obj = new a;   // this will not work becaue it is creating a variable of "a" type and it expecting that it will return the property of "a" as well as "b" but it is not possible bcoz this variable only contains property of "a".
    // b *obj = new b;
    // a *obj = new c;
    // c *obj = new a;    // this will not work becaue it is creating a variable of "a" type and it expecting that it will return the property of "a" as well as "b" as well as "c" but it is not possible bcoz this variable only contains property of "a".

    return 0;
}