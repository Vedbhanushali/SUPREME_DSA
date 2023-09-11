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

## Insert at bottom of stack (insert top of stack element to bottom)

```cpp
void solve(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int currentTop = s.top();
    s.pop();
    solve(s,target);
    s.push(currentTop);
}
void insertAtBottom(stack<int> &s){
    if(s.empty()){
        cout<<"stack is empty can't insert at bottom";
        return;
    }
    int target = s.top();
    s.pop();
    solve(s,target);
}
```

## reverse a stack using only one stack

```cpp
void insertAtBottom(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int currentTop = s.top();
    s.pop();
    insertAtBottom(s,target);
    s.push(currentTop);
}
void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    int target = s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s,target);
}
```

## Valid parenthesis

<https://leetcode.com/problems/valid-parentheses/>

```cpp
bool isValid(string s) {
        stack<char> st;  
        for(auto i:s)  
        {
            if(i=='(' or i=='{' or i=='[') st.push(i); 
            else {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();  
            }
        }
        return st.empty();  //at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
    }
```

## Sort a stack

```cpp
void insertSorted(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top() >= target){
        s.push(target);
        return;
    }

    int currTop = s.top();
    s.pop();
    insertSorted(s,target);
    s.push(currTop);
} 
void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int currTop = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,currTop);
}
```

## Remove redundant brackets

```cpp
```

## Min stack

<https://leetcode.com/problems/min-stack/>

```cpp
class MinStack {
public:
    vector< pair<int,int> > st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int> p = make_pair(val,val);
            st.push_back(p);
        } else {
            pair<int,int> p;
            p.first = val;
            p.second = min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

## longest valid paratheses

<https://leetcode.com/problems/longest-valid-parentheses/>

approach - index based stack usage

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxi = 0;
        st.push(-1);
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            } else {
                st.pop();
                if(st.empty()){
                    st.push(i);
                } else {
                    int len = i - st.top();
                    maxi = max(len,maxi);
                }
            }
        }
        return maxi;
    }
};
```

## Next smaller element

INPUT = 2 1 4 3  
OUTPUT = 1 -1 3 -1

```cpp
vector<int> nextSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for(int i = v.size()-1; i >=0 ;i--){
        int curr = v[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
```

## Prev Smaller element

INPUT = 2 1 4 3  
OUTPUT = -1 -1 1 1

```cpp
vector<int> prevSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for(int i = 0;i<v.size();i++){
        int curr = v[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
```

## Largest rectangular area in histogram

<https://leetcode.com/problems/largest-rectangle-in-histogram/>

```cpp
vector<int> prevSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for(int i = 0;i<v.size();i++){
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top(); 
        s.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for(int i = v.size()-1; i >=0 ;i--){
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top() == -1 ? v.size() : s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    vector<int> prev = prevSmaller(heights);
    vector<int> next = nextSmaller(heights);

    int MaxArea = 0;
    for(int i = 0;i<heights.size();i++){
        int len = heights[i];
        int wid = next[i] - prev[i] - 1;
        int area = len * wid;
        MaxArea = max(MaxArea, area);
    }
    return MaxArea;
}
```
