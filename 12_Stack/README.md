# STACK

data structure which stores item in LIFO order

Stack operation -

- push operation insert at top  
- pop operation remove element from top  
- s.top() return top element of the stack  
- s.size() to find number of elements in stack

<https://en.cppreference.com/w/cpp/container/stack>

```cpp
#include<isotream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    
    //insertion
    st.push(4);
    st.push(5);
    st.push(2);

    //remove
    st.pop();

    //check element at top
    cout<<st.top(); // 5

    //size of stack
    cout<<st.size(); // 2

    //checking if stack is empty or not
    cout<<st.empty(); // false

    //printing stack elements
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}
```

Nature of stack whatever is given in input when we output it will be in reverse order.

## Custom stack implementation not using stl stack library

two ways -

1. using vector/array
2. using linked list

```cpp
class Stack{
    //properties
    int top; //index of top element
    int *arr; // pointer storage
    int size; //array size
    public:
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    //functions
    void push(int data){
        if(top+1>=size){
            //stack overflow
            cout<<"stack overflow"<<endl;
        } else {
        top++;
        arr[top] = data;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        } else {
            cout<<"stack underflow"<<endl;
        }
    }
    int getTop(){
        if(top>=0){
            return arr[top];
        } else {
            //no elements in arr
            return -1;
        }
    }
    int getSize(){
        return top+1;
    }
    bool isEmpty(){
        return (top == -1) ? true : false;
    }
};

int main(){
    Stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(!st.isEmpty()){
        cout<<st.getTop();
        st.pop();
    }
    return 0;
}
```

## create 2 stack in 1 array

- 1st stack will start from beginning of arr
- 2nd stack will start from ending of arr

```cpp
class Stack {
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        
        if(top2-top1 == 1){
            //space not available
            cout<<"overflow in stack1";
        } else {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1(){
        if(top1>=0){
            top1--;
        }  else {
            cout<<"underflow in stack1";
        }
    }
    void push2(){
        if(top2-top1 == 1){
            //space not available
            cout<<"overflow in stack2";
        } else {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2(){
        if(top2<size){
            top2++;
        } else {
            cout<<"underflow in stack2";
        }
    }
};
```

## reverse string using stack

```cpp
string str = "ved";
stack<char> st;
for(int i = 0;i<str.size();i++){
    st.push(st[i]);
}
while(!st.empty()){
    cout<<st.top();
    st.pop();
}
```

## find middle element in stack

approach -

- recursively pop element and store top element till reached to size which is equal to intial stack size/2(half) - middle element print it
- return from that case and push again which has been pop earlier

```cpp

void printMiddle(stack<int> st,int &totalSize){
    if(st.emtpy()) {
        cout<<"stack is empty no middle element";
        return;
    }
    if(st.size() == totalSize/2 + 1){
        cout<<"middle element is"<<st.top();
        return;
    }
    int temp = st.top();
    st.pop();
    printMiddle(st,totalSize);
    st.push(temp);
}
//driver call;
int sz = st.size();
printMiddle(st,sz)
```
