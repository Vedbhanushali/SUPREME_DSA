
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
    public:

    //Default constructor
    Animal(){
        cout<<"Constructor called";
        this->age = 0;
    }

    //Parameterized constructor
    Animal(int age){
        cout<<"Constructor called";
        this->age = age;
    }

    //copy constructor
    Animal(Animal & obj){
        this->age = obj.age;
    }
    /* Note */
    /* Pass by reference in copy constructor because if pass by value then agin obj is copy of parameters and infinite loop is created. */
}
//Driver call
Animal a; // default constructor call
Animal *ptr = new Animal //default constructor call
Animal b(10); //parameterized constructor call
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
int main(){
    abc a;
    cout<<a.getX();
    cout<<a.getY();
    return 0;
}
```

L - value => variable having memory location
R - value => variable doesn't have memory location
