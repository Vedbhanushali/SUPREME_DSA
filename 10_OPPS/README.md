
# OOPS

## Static memory allocation

memory is allocated in stack (smaller is size fixed)

- stack memory stores local vairable and functions parameters
- memory allocated in stack is automatically deallocate

```cpp
class Animal {
    private :
    int age;
    public:
    int sex;
    string name;
    void eat(){
        cout<<"eat";
    }
    void sleep(){
        cout<<"Sleep";
    }    
    void getAge(){
        return age;
    }
    void setAge(int age){
        //same name of local and class variable then use this
        this->age = age;
    }
}

int main(){
    //static memory allocation
    Animal Dog;
    cout<<dog.sex;
    //cout<<dog.age not accessible
    dog.setAge(10);
    cout<<dog.getAge()
    Dog.eat();
}
```

## Dynamic memory allocation

memory is allocated in heap (memory is large)

- allocation using new.
- manually need to deallocate memory using delete.

```cpp
class Animal {
    private :
    int age;
    public:
    int sex;
    string name;
    void eat(){
        cout<<"eat";
    }
    void sleep(){
        cout<<"Sleep";
    }    
    void getAge(){
        return age;
    }
    void setAge(int age){
        //same name of local and class variable then use this
        this->age = age;
        // this is pointer to current object
    }
}

int main(){
    //static memory allocation
    Animal * Dog = new Animal;
    cout<<(*dog).sex;
    //above state can be access as this also
    cout<<dog->sex;
    //cout<<dog.age not accessible
    dog->setAge(10);
    cout<<dog->getAge()
    Dog->eat();
}
```

### 1D memory allocation

```cpp
int * arr = new int[n];
delete [] arr;
```

### 2D Memory allocation

```cpp
// Memory allocation
int **arr = new int* [row];
for(int i=0;i<row;i++){
    arr[i] = new int[col];
}

//memory deallocation
for(int i=0;i<row;i++){
    delete [] arr[i];
}
delete [] arr;
```

## Constructor

- function to initialize object properties
- no return value

```cpp
class Animal{
    private:
    int age;
    int y;
    public:

    //Default constructor
    Animal(){
        cout<<"Constructor called";
        this->age = 0;
        this->y = 0;
    }

    //Parameterized constructor with default argument
    Animal(int age,int y = 10){
        cout<<"Constructor called";
        this->age = age;
        this->y = y;
    }

    //copy constructor
    Animal(Animal & obj){
        this->age = obj.age;
        this->y = obj.y;
    }
    /* Note */
    /* Pass by reference in copy constructor because if pass by value then agin obj is copy of parameters and infinite loop is created. */
}
//Driver call
Animal a; // default constructor call
Animal *ptr = new Animal //default constructor call
Animal b(10,30); //parameterized constructor call
Animal b(10); // y value by default will become 10
Animal *ptr2 = new Animal(10); //parameterized constructor call
//copy constructor call
Animal c = a;
Animal d(a);
Animal e(*ptr);
```

## Destructor

- for static allocation automatically memory is free
- for dynamic allocatio memory release necessary

```cpp
class Animal {
    private :
    int age;
    public:
    int sex;
    string name;
    void eat(){
        cout<<"eat";
    }
    void sleep(){
        cout<<"Sleep";
    }
    void getAge(){
        return age;
    }
    void setAge(int age){
        //same name of local and class variable then use this
        this->age = age;
        // this is pointer to current object
    }
    Animal(){
        cout<<"constructor";
        this->age = 0;
        this->sex = 0;
    }
    ~Animal(){
        cout<<"Deconstructor called";
    }
}
int main(){
    Animal a;
    a.sex = 0;
    return 0;
    //for destructor will be by default call automatically

    Animal *b = new Animal();
    b->sex = 0;
    return 0;
    //here desctructor for b will be not called so need to use delete for call destructor
    delete b;
    return 0;
}
```

## OOPS 4 pillars

- Encapsulation
- Inheritance
- polymorphism
- Abstraction

### Encapsulation

- Data hiding
- security
- perfect encapsulation all data members are private

### Inheritance

Base class / parent class / super class -> [Inheritance] -> subclass / child class / derived class

code syntax

```cpp
class child : ____ Parent
//here Parent is parent class
// ___ is where mode of inheritance comes which are
// public
// private
// protected
```

```cpp
class Animal {
    public:
    int age;
};
class Dog : public Animal {

};
int main(){
    Dog d1;
    cout<<<d1.age;
    return 0;
}
```

| Base class access modifier | <table><tr>modes/ types of inheritance</tr><tr><td>public</td><td>protected</td><td>private</td></tr></table> |
| -------- | -------- |
| public  | <table><tr><td>public</td><td>protected</td><td>private</td></tr></table>  |
| protected  | <table><tr><td>protected</td><td>protected</td><td>private</td></tr></table>  |
|  private | <table><tr><td>NA</td><td>NA</td><td>NA</td></tr></table> |

#### Types of inheritance

- single
- multilevel
- mulitiple
- Hierarchical
- Hybrid

In case of mulitple there is case of ambiguity to resolve it we have to use scopre resolution

```cpp
class A{
    public:
    int a;
};
class B{
    public:
    int a;
};
class C: public A,public B {
    //here a is ambiguis so to access when object is created scope reslution is required
};
int main(){
    C obj;
    cout<<obj.A::a<<" "<<obj.B::a;
    return 0;
}
```

### Polymorphism

existing in many forms, there are two types

- compile time polymorphism
  - function overloading
  - operator overloading
- runtime polymorphism
  - function overriding

#### Compile time polymorphism

functional overloading

```cpp

class Maths{
    public:
    int sum(int a,int b){
        return a+b;
    }
    int sum(int a,int b,int c){
        return a+b+c;
    }
    float sum(int a,float b){
        return a+b;
    }
}
int main(){
    Maths m;
    cout<<m.sum(1,2); //3
    cout<<m.sum(1,2,3) //6
    cout<<m.sum(1,3.5f) //4.5
    return 0;
}
```

Operator overloading

can make operator to do things which they are not intendent to do.

\+ is binary operator so o1 is calling onject and o2 is passed as argument object

```cpp
class Param {
    public:
    int val;
    int operator + (Param &obj){
        int v1=this->val;
        int v2 = obj->val
        return v1+v2;
    }
}
int main(){
    Param o1,o2;
    o1.val  =1;
    o2.val = 4;
    cout<<o1+o2; //5
}
```

### Runtime polymorphism

Function overriding - same function definition but different definition

```cpp
class Animal {
    public:
    void speak(){
        cout<<"speaking";
    }
};
class Dog : public Animal {
    public:
    void speak() {
        cout<<"Barking"
    }
};
int main(){
    Animal a;
    a.speak(); //speaking
    Dog b;
    b.speak(); //barking

    //upcasting
    Animal* c = new Dog()
    c->speak(); //will call parents function //speaking
    //Downcasting
    Dog * d = new Animal();
    Dog * d = (Dog *) new Animal();
    d.speak();
}
```

#### Virtual method used for upcasting ex -

```cpp
class Animal {
    public : 
        virtual void speak(){
            cout<<"speak";
        }
};
class Dog: public Animal {
    public:
    void speak(){
        cout<<"Barking";
    }
};
int main() {
    Animal* a= new Dog();
    a->speak(); //Barking
    //due to use of virtual object data pointer function is called not the assigned variable pointer
}
```

default behaviour of compiler function are called of two pointer assigned if we use virtual function the dynamic created object function are called.

```cpp
Animal * a = new Animal();
//only Animal constructor is called

Dog * a = new Dog();
// Animal constructor called and then Dog constructor called

//upcasting
Animal * a = new Dog();
//Animal 1st and Dog 2nd constructor called

Dog * a = new Animal();
//Animal constructor called only
```

### Abstraction

Implementation hiding
Encapsulation is a subset of Abstraction
It can be achieved with the help of Encapsulation and access modifier.

- Abstraction - essential info show
- Encapsulation - wrapping data member and member function using class

## Const keyword

The const keyword to declare that a variable, function, or object is immutable, i.e., its value cannot be changed after initialisation.

E.g., if you declare a variable as const int x = 5;, you cannot modify the value of x later in the program any attempt to modify the value will result in a compilation error.

You can declare a function as const, which means that it does not modify the state of the
object it is called on.

Compiler may be able to store const variables in read-only memory, which can result in faster
access time.

```cpp
int main(){
    const int x = 5;
    //Intialization can be done 
    // but we cannot re-assigne value
    x = 10;//error

    //const with pointer
    int *a = new int;
    *a = 2;
    cout<<*a; //2
    delete a;
    int b = 5;
    a=&b;
    cout<<*a; //5

    const int *a = new int(2);
    //and
    int const *b = new int(5);
    //both syntax are same because
    //If I write const before * then content will be const

    // this mean data/content of pointer is const
    // but pointer can be reassigned

    cout<<*a; //2
    *a = 20; //will throw compilation error
    //this will not throw error
    int b = 5;
    a = &b;
    cout<<*a; //valid

    // const pointer but non const data
    int * const a = new int(2);
    //this mean data/content can be changed but 
    // pointer can not be reassigned
    cout<<*a; // 2;
    *a = 20; //valid
    cout<<*a; //20
    int b = 30;
    a = &b; //will throw error

    //const pointer and const data
    const int * const a = new int(50);
    *a = 50; //error
    a = &b; //error
    return 0;
}
```

If method of class is made const then it means that method can't change any of the member variable

```cpp
class abc{
    int x;
    int *y;
    public:
    abc(){
        x = 0;
        y = new int(0);
    }
    int getX() const{ //this mean it can never modify any variable of class
        x = 50; // error
        return x;
    }
    void setX(int _val){ //setter function can never contain const
        x =_val;
    }
    int getY(){
        return y;
    }
    void setY(int _val){
        *y = _val;
    }
};
void printAB(const abc &a ){ // now that that we have marked our argument variable as const
//this print function cannot modify any variable of a object
    cout<<a.getX(); //valid
    cout<<a.getY(); //will throw error because this function is not const, mean it is possible that this function might change the variables of a object
    cout<<a.setX(); //will throw error as function modifying variable of a object
}
int main(){
    abc a;
    cout<<a.getX();
    cout<<a.getY();
    return 0;
}
```

## mutable (used for debugging purpose only - production code not good practise)

```cpp
class abc{
    mutable int x;
    int *y;
    public:
    abc(){
        x = 0;
        y = new int(0);
    }
    int getX() const{ //this mean it can never modify any variable of class
        x = 50; // will not throw error because we have made it mutable
        return x;
    }
};
```

## Initialization list

```cpp
class abc{
    mutable int x;
    int *y;
    const int z;
    public:
    
    //old ctor method (ctor -  constructor)
    // abc(int _x,int _y,int _Z){
    //     x = _x;
    //     y = new int(_y);
    //     z = _z; //will throw error because z is const and reassigning value
    // }

    // better way of writing ctor
    abc(int _x,int _y):x(_x), y(new int(_y)), z(_z){
        // z can be reassign in this method.

        // normal constructor code can also be written 
        cout<<"constructor called";
        x = _x * 10; // valid
        z = _z * 10; //not valid, reassigne only possible in initialization list
    } 

    int getX() const{ //this mean it can never modify any variable of class
        x = 50; // will not throw error because we have made it mutable
        return x;
    }
};
```

## Macros

In C++, macros are preprocessor directives that allow you to define constants, functions, or code snippets that can be used throughout your code. They are typically defined using the \#define directive and are evaluated by the preprocessor before the code is compiled.

Macros can be used for a variety of purposes, such as defining constants or creating shorthand for commonly used expressions.

```cpp
#include <iostream>
using namespace std;
#defing PI 3.145954
#defint MAX(x,y) (x>y ? x:y)

float circleArea(float r){
    return PI * r * r;
}

int main(){
    cout<< circleArea(3.2);
    cout<<MAX(3,5)
    int a = 0;
    int b = -1;
    cout<<MAX(a,b) // (0>-1 ? 0 : -1) // expansion
    return 0;
}
```

## Shallow copy vs deep copy

```cpp
class abc{
    public:
    int x;
    int *y;
    abc(int _x,int _y):x(_x),y(new int(_y)) {}
    
    //default dumb copy constructor
    // it does shallow copy
    // abc(const abc & obj){
    //     x = obj.x;
    //     y = obj.y;
    // }

    //deep copy for copy constructor
    abc(const abc & obj){
        x = obj.x;
        y = new int(*obj.y);
    }
    void print() {
        cout<<x<<y<<*y;
    }
    ~abc(){
        delete y;
    }

};
int main(){
    abc a(1,3);
    a.print();

    abc b(a);
    b.print();
    
    // here content of b is exactly same as a event pointer y points to same address as address of y in object a, now both are linked if obj a changes y pointer value
    // it will also affect obj b
    b.*y = 20;
    a.print(); // y = 20;
    b.print(); // y = 20
    return 0;
}
```

## Local and global variables

- global variable
  - written outside a function
  - accessible to all function same copy
- local variable
  - written inside a function
  - accessible inside that function scope only
  - scoped

```cpp
#include <iostream>
using namespace std;

//global variable
int x = 2;
int main(){
    // x = 20; //will access global variable and modify
    // ::x = 20; same as above if x not declared before it will take reference of globar variable
    int x = 20;
    cout<<x; //20 - will access local first preference higher , if not found then it will look for global scope
    //if want to access global variable explicitly
    cout<<::x; //2
    return 0;
}
```

## Static Keyword in class

static data member - that variable is going to share memory with all of the class instances

static member function - there is no instance of that class being passed into that method

```cpp
class abc {
    public:
    int x,y;
    void print() const {
        cout<<x<<y;
    }
};
int main(){
    abc a = {1,2};
    abc b = {2,5};
    a.print(); // 1 2
    b.print(); // 2 5
}
```

Static data member

```cpp
class abc{
    public:
    static int x,y;
    void print() const {
        cout<<x<<y;
    }
};
// need to define class static variables outside class to use them
int abc::x;
int abc::y;

int main(){
    abc a;
    a.x = 10;
    b.y = 5;
    a.print(); // 10 5
    
    abc b;
    b.x = 15;
    b.y = 20;
    a.print(); //15 20 --- will modify for class a as well as static member is shared among all class instances
    b.print(); //15 20


    return 0;
}
```

Static member function

```cpp
class abc{
    public:
    static int x,y;
    static void print() const { // function can only use static data members as It does not know instance data members
        cout<<x<<y;
    }
};
// need to define class static variables outside class to use them
int abc::x;
int abc::y;

int main(){
    abc a;
    a.x = 10;
    b.y = 5;
    abc::print(); // 10 5
    
    return 0;
}
```

## Abstraction deep

- Delivering only essential information to the outer world while masking the background details.
- It is a design and programming method that separates the interface from the implementation.
- Real life e.g., various functionalities of AirPods but don't know the actual implementation/working
  - To drive a car, one only needs to know the driving process and not the mechanics of the car engine

Abstraction in Header files

1. Function's implementation is hidden in header files.
2. We could use the same program without knowing its inside working.
3. E.g., Sort(), for example, is used to sort an array, a list, or a collection of items, and we know that if we give a container to sort, it will sort it, but we don't know which sorting algorithm it uses to sort that container.

Abstraction using Classes

1. Grouping data members and member functions into classes using access specifiers.
2. A class can choose which data members are visible to the outside world and which are hidden.

What is Abstract Class?

1. Class that contains at least one pure virtual function, and these classes cannot be instantiated.
2. It has come from the idea of Abstraction.

Bird.h implementation

```cpp
#if !define(BIRD_H)
#define BIRD_H
#include <iostream>
class Bird{
    public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    //classes that inherits this class
    // has to implement pure virutal functions
};
class sparrow: public Bird{
    private:
    void eat(){
        std::cout<<"sparrow is eating";
    }
    void fly(){
        std::cout<<"sparrow is flying";
    }
};
class eagle: public Bird{
    private:
    void eat(){
        std::cout<<"eagle is eating";
    }
    void fly(){
        std::cout<<"eagle is flying";
    }
};

#endif //BIRD_H
```

main file implementation

```cpp
#include <iostream>
#include "bird.h"
using namespace std;

void bridDoesSomething(Bird *&b){
    b->eat();
    b->fly();
}

int main() {
    Bird *bird1 = new sparrow();
    birdDoesSomething(bird1); //here sparrow related functions will be called
    Bird *bird1 = new eagle(); 
    birdDoesSomething(bird2); // here eagle related functions will be called

    Bird *b = new Bird(); //cannot instantiate Bird interface object, other class which inherits this interface their class can be instantiate
    return 0;
}
```

Design Strategy

- Abstraction divides code into two categories:interface and implementation. so when creating your component, keep the interface separate from the implementation(Bird.h file) so that if  underlying implementation changes, the interface stays the same(main file)

- In this instance, any program that uses these interfaces would remain unaffected and would require recompilation with the most recent implementation.

## Inline function

to reduce function call overhead

It is used when function is smaller, because if used in bigger function then executable size will increase as the code size will increase as code will be copied and pasted in where called

1. An inline function is a regular function that is defined by the inline keyword.
2. The code for an inline function is inserted directly into the code of the calling function by compile while compiling, which can result in faster execution and less overhead compared to regular function calls.
3. Instead of calling function the statements of functions are pasted in calling function.
4. Used with small sized functions. So that executables are small (handled automatically by compiler optimisation levels).

```cpp
#include <iostream>

inline void numberShow(int num){
    cout<<num;
} //this way we don't need to edit all the functional calls and also it reduces function call overhead
int main(){
    numberShow(10);
    numberShow(20);
    return 0;
}
```

## Friend keyword

- friend is a keyword in C++ that is used to share the information of a class that was previously hidden.
- For example, the private members of a class are hidden from every other class and cannot be modified except through getters or setters. Similarly, the protected members are hidden from all classes other than its children classes.

```cpp
#include<iostream>
using namespace std;

class A{
    private:
    int x;
    public:
    A(int _x):x(_x){};
    int getX() const {
        return x;
    }
    int setX(int _x){
        x = _x;
    }

    //by using friend keyword allowing to access private member of this class
    friend class B;
    friend void print(const A&a);
};
class B{
    public:
    void print(const A& a){
        cout<<a.x; //valid
    }
};
void print(const A &a){
    cout<<a.x;
}
int main(){
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}
```

1. Although information hiding is encouraged because it prevents unwanted bugs in a program, there are cases where two classes need to frequently interact with each other.
2. In such a scenario, one of the classes declares another to be its friend.
3. The class declaring the friendship can now make all of its data available to its friend

## Private constructor

used when we don't want user to create that class instance and keep track of instance of that class

```cpp
#include <iostream>
using namespace std;
class Box {
    int w;
    Box(_w):w(_w){};
    public:
    int getW() const{ return w;}
    void setW(int _w) {
        w = _w;
    }
    friend class BoxFactory;
}
class BoxFactory{
    int count;
    public:
    Box getABox(int _w){
        ++count
        return new Box(_w);
    }
}
int main(){
    BoxFactory bfact;
    Box b = bfact.getABox(5);
    Box b = new Box(5); //not possible
    cout<<b.getW();
    return 0;
}
```

## Virtual Constructor vs Virtual Destructor

- way to achive runtime polymorphism

How Virtual works

1. VTables Formed for every class having at least one virtual function and for its derived classes.
2. It is static arrays, hence one instance for a class.
3. VPtr (a hidden member pointer) is added by compiler to classes with virtual and its derived classes.
4. Depending upon the object type VPtr is bonded to a VTable.

VTabIes are created at compile time.
When object of a particular type is created at runtime. There will be a VPtr which will be initialised to point to a static VTable at the time of construction.

### Can we make virtual constructor

NO.
Constructor cannot be virtual, because when constructor of a class is executed there is no virtual table in the memory, means no virtual pointer defined yet. So, the constructor should always be non-virtual.
A virtual call is a mechanism to get work given partial information. In particular virtual allows us to call a function knowing only any Interfaces and not the exact type of object. To create an object you need complete information. In particular, you need to know the exact
type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.

### Can we make virtual dtor?

1. Yes.
2. It is really important to handle proper destruction of Derived classes.

```cpp
class Base {
    public:
        Base(){
            cout<<"base ctor";
        } //ctor cannot be virtual because if object is not created virtual table will not be created.
        virtual ~Base(){
            cout<<"Base dtor";
        } // dtor should be virtual this implies that derived class from base after code completetion will first call derived destructor as base class vptr points to and then Base class dtor will be called
};
class Derived: public Base {
    int *a;
    public:
    Derived(){
        a = new int[20];
        cout<<"Derived ctor";
    }
    ~Derived() {
        delete[] a;
        cout<<"Derived dtor";
    }
};
int main() {
    Base *b = new Derived();
    return 0;
}
// OUTPUT-
// Base ctor
// Derived ctor
// Derived dtor
// Base dtor
```
