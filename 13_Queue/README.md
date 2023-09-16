# Queue

Data structure following FIFO

insertion in rear (push)  
deletion from front (pop)  

used in graph and sliding window

## operations

<https://en.cppreference.com/w/cpp/container/queue>

- push
- pop
- front
- empty
- size

```cpp
#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(5);
    q.push(4);
    q.push(15);
    
    //size
    cout<<q.size(); //3

    //removal
    q.pop(); //removed 5

    // checking if q is empty

    if(q.empty()){
        cout<<"q is empty";
    } else {
        cout<<"q is not empty";
    }

    //front
    cout<<q.front();
    return 0
}
```

## Custom implementation of Queue

push, pop, getFront, isEmpty, getSize

```cpp
class Queue {
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout<<"Q is full";
        } else {
        arr[rear++] = data;
        }
    }

    void pop(){
        if(front == rear){
            cout<<"Q is empty";
        } else {
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront(){
        if(front == rear){
            cout<<"Q is empty";
            return -1;
        }
        else {
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        } else 
        return false;
    }

    int getSize(){
        return rear - front;
    }
};

int main(){
    Queue q(10);

    q.push();
    q.getFront(); //10
    q.getSize(); //1
    q.pop();
    q.isEmpty(); //true
    return 0;
}
```

## Circular Queue

```cpp
class CirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        //Queue full
        //single element case -> first element
        //circular nature
        //normal flow

        if((front == 0 && rear == size-1) || (rear == front - 1)){
            cout<<"Q is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data; 
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        } else {
            rear++;
            arr[rear] = data;
        }
    }
    void pop() {
        //empty check
        //single element check
        //circular nature 
        //normal flow

        if(front == -1){
            cout<<"Q is empty";
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        } else {
            arr[front] = -1;
            front++;
        }
    }
};
```

## Input restricted Queue

Input allowed in rear
Output allowed from rear and front

push_back, pop_front, pop_back

## Output restricted Queue

Input allowed in rear and front
Output allowed from front only
push_front, push_back, pop_front

## Doubly ended Queue (Deque)

don't confuse name with dequeue (mean pop) similarly enquque(push,insert)

operations allowed  
push_rear  
push_front  
pop_rear  
pop_front  

## Circular Doubly ended queue

```cpp
class Deque{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
        front =-1;
        rear = -1;
    }

    void pushRear(int data){
        //Queue full
        //single element case -> first element
        //circular nature
        //normal flow

        if((front == 0 && rear == size-1) || (rear == front - 1)){
            cout<<"Q is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data; 
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        } else {
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(){
        if((front == 0 && rear == size-1) || (rear == front - 1)){
            cout<<"Q is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[front] = data; 
        }
        else if(front == 0 && rear!=size-1){
            front = size-1;
            arr[front] = data;
        } else {
            front--;
            arr[front] = data;
        }
    }

    void popFront(){
        //empty check
        //single element check
        //circular nature 
        //normal flow

        if(front == -1){
            cout<<"Q is empty";
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        } else {
            arr[front] = -1;
            front++;
        }
    }

    void popRear(){
        //empty check
        //single element check
        //circular nature 
        //normal flow

        if(front == -1){
            cout<<"Q is empty";
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            arr[rear] = -1;
            rear = size - 1;
        } else {
            arr[rear] = -1;
            rear--;
        }
    }

    void print(){
        for(int i = 0;i<size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
```

## STL Deque

```cpp
#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);
    // 10 5 20 30

    cout<<dq.size(); // 4
    dq.pop_front(); //10 pop
    dq.pop_back(); // 30 pop

    cout<<dq.front(); //5
    cout<<dq.back(); // 20

    cout<<dq.empty(); //false dq is not empty
    return 0;
}
```

## Reverse a Queue

approach

1. using stack
TC - O(n)
SC- O(n)

2. using recusion
TC - O(n)
SC- O(1)

```cpp
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseUsingStack(queue<int> &q){
    stack<int> s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

void reverseRec(queue<int> &q){
    if(q.empty()) return;

    int element = q.front();
    q.pop();

    reverseRec(q);
    q.push(element); 
}
int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    return 0;
}
```

## Reverse first K element of queue

- k element push in stack
- stack pop all and push in queue
- (n-k) pop from queue and push in queue

```cpp
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseK(queue<int> &q,int k){
    stack<int> st;
    int count = 0;
    int n = q.size();

    if(k ==0 || k>n) return;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        st.push(temp);
        count++;

        if(count == k) break;
    }

    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }

    count = 0;
    while(!q.empty() && n-k!=0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if(count == n-k){
            break;
        }
    }
}
int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    return 0;
}
```

## Interleave first and second half of Queue

INPUT - 10,20,30,40,50,60,70,80  
OUTPUT - 10,50,20,60,30,70,40,80

```cpp
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void interLeaveQueue(queue<int> &q){
    if(q.empty()) return;
    int n = q.size();
    int k = n/2;
    int count = 0;
    queue<int> q2;

    // seperate both halves
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count == k) break;
    }

    // interleaving start
    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();

        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second); 
    }
    if(n&1) {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}
int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    return 0;
}
```

## First -ve integer in every window of size k (Sliding window + queue)

<https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1>

INPUT vector: 12,-1,-7,8,-15,30,16,28 ,  k=3  

Approach  
q to store index of elments

- answer q.front() if empty then 0
- remove out of window elment from q
- new element insertion in q

```cpp
# include<iostream>
# include<deque>
# include<stack>

using namespace std;
void solve(int arr[],int n,int k){
    deque<int> q;

    //process first window of size k
    for(int i=0;i<k;i++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    //remainig window process
    for(int i=k;i<n;i++){

        //answer dedo purani window ka
        if(q.empty()){
            cout<<"0 ";
        } else {
            cout<<q.front()<<" ";
        }

        //out of window removal
        if(!q.empty() && q.front() == i-k){
            q.pop_front();
        } 
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    //answer print karon for last window
    if(q.empty()){
        cout<<"0 ";
    } else {
        cout<<q.front()<<" ";
    }
}
int main(){
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = 8;
    int k = 3;

    solve(arr,size,k);
    return 0;
}
```

## Non-repeated character in a string

<https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1>

```cpp
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
    //   int hash[26] = {0};
    //   for(auto ch:S){
    //       hash[ch-'a']++;
    //   }
    //   char answer = '$';
    //   for(char ch:S){
    //       if(hash[ch-'a'] == 1){
    //           answer = ch;
    //           break;
    //       }
    //   }
    //   return answer;
        queue<char> q;
        int hash[26] = {0};
        for(char ch:S){
            q.push(ch);
            hash[ch-'a']++;
            while(!q.empty() && hash[q.front()-'a'] > 1){
                q.pop();
            }
        }
        
        return q.empty() ? '$' : q.front();
    }
};
```

## Gas Station

<https://leetcode.com/problems/gas-station/>

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int balance = 0;
        int deficit = 0;
        for(int i=0;i<gas.size();i++){
            //yahi par galti hogi
            balance += gas[i] - cost[i];
            if(balance < 0){
                //yahi par galti hogi
                deficit += balance;
                start = i+1;
                balance = 0;
            }
        }
        if(balance + deficit >= 0) return start;
        return -1;
    }
};
```

## Sliding window maximum (Queue + sliding window)

<https://leetcode.com/problems/sliding-window-maximum/>

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> answer;

        //processing k window
        for(int i=0;i<k;++i){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }

        //inserting answer of first window
        answer.emplace_back(nums[q.front()]);

        //sliding window in next k
        for(int i=k;i<nums.size();++i){
            // if(!q.empty() && nums[i-k] == nums[q.front()]){
            if(!q.empty() && i-k == q.front()){
                q.pop_front();
            }
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            answer.emplace_back(nums[q.front()]);
        }
        return answer;
    }
};
```
