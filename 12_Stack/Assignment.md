# Assignment

## Remove All Adjacent Duplicates In String

<https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/?envType=daily-question&envId=2023-09-01>

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int i = 0;
        while(i<s.length()){
            if(ans.length()>0){
                if(ans[ans.length()-1]==s[i]){
                    ans.pop_back();
                } else {
                    ans.push_back(s[i]);
                }
            } else {
                ans.push_back(s[i]);
            }
            
            i++;
        }
        return ans;
    }
};
```

## Minimum Bracket Reversal

<https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1>

```cpp
int countRev (string s)
{
    // your code here
    if(s.size()&1) return -1;
    
    int ans = 0;
    stack<char> st;
    
    for(int i = 0;i<s.size();i++){
        if(s[i] == '{'){
            st.push(s[i]);
        } else {
            if(!st.empty() && st.top() == '{'){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }
    //let's count reversal
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        if(a == b) ans += 1;
        else ans += 2;
    }
    return ans;
}
```

## Celebrity Problem

<https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1>

```cpp

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        
        for(int i=0;i<M.size();i++){
            st.push(i);
        }
        
        while(st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(M[a][b]){
                // a is not cele
                st.push(b);
            } else {
                // b is not cele
                st.push(a);
            }
        }
        
        // one is remaining checking whether it is celeb or not
        int celeb = st.top(); st.pop();
        for(int i = 0;i<M.size() ;i++){
            if(M[celeb][i] != 0) return -1;
        }
        for(int i = 0;i<M.size();i++){
            if(M[i][celeb] != 1 && i!=celeb) return -1;
        }
        return celeb;
    }
};
```

## Next greater element in Linked List [leetcode]

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* prev,ListNode* head,int &count){
        while(head!=NULL){
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;
            count++;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* prev = NULL;
        int count = 0;
        head = reverseList(prev,head,count);
        int maxi = INT_MIN;
        vector<int> ans(count);
        int i = 0;
        stack<int> st;
        st.push(0);
        while(head){
            int curr = head->val;
            while(st.top() != 0 && st.top() <= curr){
                st.pop();
            }
            ans[i++] = st.top();
            st.push(curr);
            head = head->next;
        }
         
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

## N Stacks in an Array

two additional array is required in algorithm

- top size(n) (n- number of stack) it stores index of top element of ith stack  
initial value of all elements is -1
- next size(size) (size - size of arr)
  - can point to next free space
  - can point to next element after top element
  - initial value of next elements is i+1 index except last which will be -1
- freespot (variable)

algorithm of push -

1. find index;  
        int index = freeSpot;

2. update freespot  
        freeSpot = next[index];

3. insert  
        a[index] = X;

4. next update  
        next[index] = top[m-1];

5. update top  
        top[m-1] = index;

algorithm of pop is reverse steps of push

```cpp
#include<isotream>
using namespace std;

class NStack {
    int *a,*top,*next;
    int n; // no. of stack
    int size; //size of a array
    int freeSpot; // tells free space in main array

    public:
    NStack(int _n,int _s):n(_n),size(_s) {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i=0;i<n;i++){
            top[i] = -1;
        }
        for(int i=0;i<size-1;i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }
    //push X into mth stack
    bool push(int X,int m){ // m is stack number which stack to push
        if(freeSpot == -1){
            return false;
            //stack is full Overflow
        }

        //1. find index;
        int index = freeSpot;

        //2. update freespot
        freeSpot = next[index];

        //3. insert
        a[index] = X;

        //4. next update
        next[index] = top[m-1];

        //5. update top
        top[m-1] = index;

        return true; //pushed successfully
    }

    //pop from mth stack
    int pop(int m){
        if(top[m-1] == -1) {
            return -1; 
            //stack underflow
        }

        //steps reverse of push
        int index = top[m-1];

        top[m-1] = next[index];

        int poppedElement = a[index];

        next[index] = freeSpot;
        freeSpot = index;

        return poppedElement;
    }

    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
}
int main() {
    NStack s(3,6);
    cout<<s.push(10,1); //true
    cout<<s.pop(1); // 10
    return 0;
}
```

## Online Stock Span [Leetcode]

<https://leetcode.com/problems/online-stock-span/>

```cpp
class StockSpanner {
public:
    stack<pair<int,int> > st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```

## Simplify Path [Leetcode]

<https://leetcode.com/problems/simplify-path/>

```cpp
class Solution {
public:
    void stackReverse(stack<string> &s,string &answer){
        if(s.empty()) return;

        string topElement = s.top();
        s.pop();
        stackReverse(s,answer);
        answer += topElement;
    }
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;
        while(i<path.size()){
            int start = i;
            int end = i+1;
            while(end < path.size() && path[end]!='/'){
                end++;
            }
            string minPath = path.substr(start,end-start);
            i = end;
            if(minPath == "/" || minPath == "/.") continue;
            if(minPath != "/..") s.push(minPath);
            else if(!s.empty()) s.pop();
        }
        string answer = s.empty() ? "/" : "";
        stackReverse(s,answer);
        return answer;
    }
};
```

## Check If Word Is Valid After Substitutions [Leetcode]

<https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/>

Stack solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a') return false;
        stack<char> st;

        for(auto ch : s){
            if(ch == 'a'){
                st.push('a');
            } else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.push('b');
                } else {
                    return false;
                }
            } else {
                //ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return st.empty();
        /* recursive solution */
        // // cout<<s<<"---------------"<<s.size()<<endl;
        // if(s.size() == 0){
        //     return true;
        // }
        // int fnd = s.find("abc");
        // // cout<<fnd<<endl;
        // if(fnd != string::npos){
        //     string left = s.substr(0,fnd);
        //     // cout<<left<<" ";
        //     string right = s.substr(fnd+3,s.size());
        //     // cout<<right<<endl;
        //     return isValid(left+right);
        // }
        // return false;
    }
};
```

Recursive solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0){
            return true;
        }
        int fnd = s.find("abc");
        if(fnd != string::npos){
            string left = s.substr(0,fnd);
            string right = s.substr(fnd+3);
            return isValid(left+right);
        }
        return false;
    }
};
```

## Decode Strings [Leetcode]

<https://leetcode.com/problems/decode-string/>

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch:s){
            if(ch == ']'){
                string stringToRepeat = "";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top = st.top();
                    stringToRepeat += top == "[" ? "" : top;
                    st.pop();
                }

                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(),numericTimes.end());
                int times = stoi(numericTimes);
                string currentdecode = "";
                while(times--){
                    currentdecode += stringToRepeat;
                }
                st.push(currentdecode);
            } else {
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

## Max rectangle in Binary Matrix with all Is

<https://leetcode.com/problems/maximal-rectangle/>

solved using finding max retangle area in histogram (next smaller and prev smaller stack implementation)

```cpp
class Solution {
public:
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
    // for(auto i: prev){
    //     cout<<i<<" ";
    // }cout<<endl;
    // for(auto i: next){
    //     cout<<i<<" ";
    // }cout<<endl;
    int MaxArea = 0;
    for(int i = 0;i<heights.size();i++){
        int len = heights[i];
        int wid = next[i] - prev[i] - 1;
        int area = len * wid;
        MaxArea = max(MaxArea, area);
    }
    return MaxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(n,vector<int> (m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mat[i][j] = (matrix[i][j]-'0');
            }
        }

        int area = largestRectangleArea(mat[0]);
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]){
                    mat[i][j] += mat[i-1][j];
                } else {
                    mat[i][j] = 0;
                }
            }
            area = max(area,largestRectangleArea(mat[i]));
        }
        return area;
    }
};
```

## Car Fleet - I [Leetcode]

<https://leetcode.com/problems/car-fleet/>

```cpp
class Solution {
    class Car {
        public:
        int pos,speed;
        Car(int _p,int _s):pos(_p),speed(_s){}
    };
    static bool comp(Car &a,Car &b){
        return a.pos < b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0;i<position.size();i++){
            Car car(position[i],speed[i]);
            cars.emplace_back(car);
        }
        sort(cars.begin(),cars.end(),comp);
        
        stack<float> st;
        for(int i=0;i<cars.size();i++){
            float time = (target - cars[i].pos) / ((float)cars[i].speed);
            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};
```

## Car Fleet - 11 [Leetcode]

<https://leetcode.com/problems/car-fleet-ii/description/>

```cpp
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> answer(cars.size(),-1);

        stack<int> st;

        for(int i=cars.size()-1;i>=0;--i){

            //check if car ahead of current car is faster?
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }
            //car slower is ahead then find colllision time

            while(!st.empty()){
                double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);

                if(answer[st.top()] == -1 || colTime <= answer[st.top()]){
                    answer[i] = colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};
```
