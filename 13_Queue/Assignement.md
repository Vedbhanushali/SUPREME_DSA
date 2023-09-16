# Assignment of Queue

## Implement Queue using Stack

<https://leetcode.com/problems/implement-queue-using-stacks/>

using two stacks queue implementation

approaches -

1. TC of push - O(1)  
TC of pop - O(n)  
TC of front - O(n)  
algo -  

    - push - push in s1
    - pop -

        ```cpp
        if(s2 not empty){
            s2.pop
        } else {
            S1 -> to S2
            S1.pop
        }
        ```

2. TC of push - O(n)  
TC of pop - O(1)  
TC of front - O(1)  

    - push -

        ```cpp
        s1 -> s2
        add x to s1
        s2 -> s1
        ```

    - front - s1.top()
    - pop - s1.pop()

based on question type take decision which to use depending of which operation is used most push or pop

```cpp
class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
       if(s2.empty()){
           while(!s1.empty()){
               int t = s1.top();
               s1.pop();
               s2.push(t);
           }

           if(s2.empty()){
               return -1;
           } else {
               int t = s2.top();
               s2.pop();
               return t;
           }
       } else {
           int t = s2.top();
           s2.pop();
           return t;
       }
    }
    
    int peek() {
        if(s2.empty()){
           while(!s1.empty()){
               int t = s1.top();
               s1.pop();
               s2.push(t);
           }

           if(s2.empty()){
               return -1;
           } else {
               int t = s2.top();
               return t;
           }
       } else {
           int t = s2.top();
           return t;
       }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

## Implement Stacks using Queue

<https://leetcode.com/problems/implement-stack-using-queues/description/>

approaches -

1. using two queue  
algo -  

    - pop -
        Q1 pop()
    - top -
        Q1 front()
    - push -

        ```cpp
        push x in Q2
        all Q1 to Q2
        all Q2 to Q1
        ```

2. using one queue

    - push -

        ```cpp
        Q1 - push
        loop -> (size-1)
            Q.pop()
            Q.push()
        ```

    - top - q.front()
    - pop - q.pop()

```cpp
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size()-1;
        while(size--){
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    
    int pop() {
        int p = -1;
        if(!q.empty()){ 
            p = q.front();
            q.pop();
        }
        return p;
    }
    
    int top() {
        int p = -1;
        if(!q.empty()){ 
            p = q.front();
            // q.pop();
        }
        return p;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

## Implement "K" queues in an array

requires
arr - size (n-1)
front (k size) - front index of qith (initialized all -1)
rear - (k-size) - rear index of qith (initialized all -1)
next (n - size) - stores index of next item for all items in arr (initialized i to i+1 except last to -1)
freespot(variable) - current available free spot konsa hain in main array (initialized to 0)

algorithm

- push(x,ith_q):
  - overflow if (freespot == -1) return false
  - find first free index
  int index = freespot
  - update freespot -> next[index]
  - if first element of qith
  if(front[qi] == -1){
    front[qi] = index;
  } else {
    //link new element to that q's rearest element
    next[rear[qith]] = index
  }
  - update next
  next[index] = -1
  - update rear
  rear[qn] = index
  arr[index] = x;
  return true

- pop(qith)

  - underflow
    if(front[qith] == -1) return false;
  - find index to pop
    int index = front[qith]
  - update front
    front[qith] = next[index]
  - manage freespot
    next[index] = freespot  
    freespot = index

```cpp
#include<iostream>
using namespace std;

class KQueue{
    public:
    int n,k,freespot;
    int *arr, *front, *rear, *next;

    KQueue(int _n,int _k):n(_n),k(_k),freespot(0){
        arr = new int[n];
        next = new int[n];
        rear = new int[n];
        front = new int[n];

        for(int i=0;i<k;++i){
            front[i] = -1;
            rear[i] = -1;
        }
        for(int i=0;i<n-1;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    //push x into ith queue
    bool push(int X,int qi){
        // overflow
        if(freespot == -1){
            return false;
        }

        //find freespot
        int index = freespot;
        
        //update freespot
        freespot = next[index];

        //if first element
        if(front[qi] == -1){
            front[qi] = index;
        } else {
            //link new element to qi rearest element
            next[rear[qi]] = index;
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    //pop element from qith queue
    int pop(int qi){

        //underflow
        if(front[qi] == -1){
            return -1;
        }

        //find index to pop
        int index = front[qi];

        //front update
        front[qi] = next[index];

        //manage freespot
        next[index] = freespot;
        freespot = index;

        //pop
        return arr[index];
    }

    ~KQueue(){
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};
int main(){

    KQueue kq(8,3);
    cout<<kq.push(1,0);
    cout<<kq.push(2,0);
    cout<<kq.push(5,1);
    cout<<kq.push(3,0);
    cout<<kq.pop(1);
    cout<<kq.pop(1); //underflow
    return 0;
}
```

## Sum of min/max element of all subarray of size "k" [Similar: LC-239. Sliding Window Maximum]
