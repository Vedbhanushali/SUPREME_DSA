# Heap

it is a DS which is complete binary tree that holds a heap property.  
complete binary tree - (all levels are completely filled except last one , and last level filling is from left to right)

Data in heap is stored in the form of array but it's representation is in form of tree.

there is two types of heap

- max heap - currNode is greater than both of child nodes.
- min heap - currNode is smaller than both of child nodes.

## Max heap

tree index from top to bottom and left to right will start from 1 (this is convenince of formula) as below  

0 index of array is considered dummy.  
heap data start from index 1.

for 1 base indexing formula of left child of currNode is - ```2*i```  
for 1 base indexing formula of right child of currNode is - ```2*i + 1```  
for 1 base indexing formula of parent is here i is index of current node -
```i/2```  
formula derived from dividing both above formula by 2 which gives i.

for 0 based indexing heap data start from index 0 then  
Formula of left child of currNode is - ```2*i + 1```  
Formula of right child of currNode is - ```2*i + 2```  

## Insertion in max heap

1. insert in last of array
2. check if parent node is less than curr inserted node data then swap till reach root node which is index 1

TC - O(log n)

```cpp
#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }
    void insert(int value){
        //value insert at end
        size = size + 1;
        int index = size;
        arr[index] = value;

        //value place at right position
        while(index > 1) { // index == 1 is last node after than no need of comparison
            int parentIndex = index/2;
            if(arr[parentIndex] <arr[index]){
                swap(arr[parentIndex],arr[index]);
                index = parentIndex;
            } else {
                break;
            }

        } 
    }
}

int main(){
    Heap h;
    h.insert(50);
    h.insert(30);
    h.insert(80);
    h.insert(100);

    for(int i=0;i<=h.size;i++){
        cout<<h.arr[i]<<" ";
    }
    return 0;
}
```

## Deletion in max Heap

Only root node can be deleted in heap  
algo

- replace last value with root node
- root node to correct position
TC - O(log n)

```cpp
#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }    
    int delete(){
        //returning deleted node data so storing it
        int ans = arr[1];
        //replace root node with last node data
        arr[1] = arr[size];
        size--;
        
        //place root node ka data on its correct position
        int index = 1;
        while(index < size){
            int left = 2*index;
            int right = 2*index+1;
            int largest = index;
            if(left < size && arr[largest] < arr[left]){
                largest = left;
            }
            if(right < size && arr[largest] < arr[right]){
                largest = right;
            }
            if(largest == index) {
                //value is at correct position
                return ans;
            } else {
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
    }
}
```

## Heapify

Build a max heap from arr

- no need to heapify leaf nodes if number of nodes - n then [(n/2)+1 , n ] this are leaf nodes ex, if n = 5 then (3,4,5) are leaf nodes 1 based indexing
TC - O(n) //TODO find why looks like nlogn (n for traversing arry and logn for heapify)

```cpp
void heapify(int arr[],int &n,int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largest = index;

    if(leftIndex< n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex < n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }
    if(index != largest){
        //left or right is greater than curr node
        swap(arr[largest],arr[index]);
        index = largest;
        heapify(arr,n,index)
    }
}
void buildHeap(int arr[],int n){
    for(int i = n/2 ;i>0;i--){
        heapify(arr,n,i);
    }
}
```

## Heap sort

TC - O(n logn)
algo  

1. first element and last element swap, (first/top element is maximum so will consider it and decrease the size of heap)
2. heapify

```cpp
void heapSort(int arr[],int n){
    while(n != 1){
        // cout<<arr[1]<<endl;
        swap(arr[1],arr[n]); //first and last
        n--;

        //heapify
        heapify(arr,n,1);
    }
}
```

## STL heap

```cpp
#include<iostream>
#include<queue>
using namespace std;
class comp {
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
}
int main(){
     //MAX heap
    priority_queue<int> pq;
    //insertion
    pq.push(1);
    pq.push(9);
    pq.push(3);

    //view
    cout<<pq.top(); //9

    //deletion
    pq.pop();

    pq.top(); // 3

    //size
    pq.size();
    pq.empty(); //check empty


    //MIN heap 
    priority_queue<int,vector<int>,greater<int> > pq;


    // CUSTOM comparator
    priority_queue<ListNode*,vector<ListNode*>,comp) minHeap;
    return 0;
}
```

## kth smallest number in array

approach create max heap and popping k elments will give kth smallest element

when solving using min heap space complexity will increase
n size heap  and require k pop
TC - O(n)

when solving using max heap will only require k size heap as will only insert when heap top element is smaller, this way heap of k size will contain k smallest elements and top element will be kth smallest as it is max heap
TC - O(nlogk)
SC - O(k)

```cpp
int getKthSmallestElement(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int getKthGreatestElement(int arr[],int n,int k){
    //MIN heap
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        //all k greatest will be inside pq
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //out of all greatest mini is at top that would be kth greatest element  
    //ex 10 9 8 7 3 (3 is 5th greatest element) and would at top
    return pq.top();
}
int main(){
    int arr[] = {2,3,5,6,7};
    int n = 5;
    int k = 3;
    int ans = getKthSmallestElement(arr,n,k);
}
```

## Merge 2 Max - heap

approach

1. merge two heap arrays and build heap (heapify and create heap)  
TC - O(m+n)

2. push heap2 in heap1  
n = heap1 size  
m = heap2 size  
TC - O(mlogm)  

## Find if Complete Binary tree is heap or not

parent is greater than both child

```cpp
pair<bool,int> solve(Node* root){
    if(root == NULL) {
        pair<bool,int> p = make_pair(true,INT_MIN);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftAns = solve(root->left);
    pair<bool,int> rightAns = solve(root->right);
    if(leftAns.first && rightAns.first && leftAns.second < root->data && rightAns.second < root->data){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    } else {
        pair<bool,int> p = make_pair(false,root->data);
        return p;
    }
}
int main(){
    return solve(root).first;
}
```

## convert BST into max heap

approach -

1. same way as build heap method will build from just nodes which are not leaf node bottom to top heapify.
2. convert BST into inorder (sorted list) not this sorted list when insert into same BST in post order will give max heap

## Check given tree is CBT (complete binary tree) or not

using level order when nodes index is greater then total number of nodes mean in leaf nodes there are null between nodes in that level so not completely left filled so it will not be CBT

## Merge K - sorted array

```cpp
class info{
    public:
    int data;
    int row;
    int col;
    info(int val,int r,int c){
        data = val;
        row = r;
        col =c;
    }
}
bool compare(info* a,info *b){
    return a->data > b->data;
}
vector<int> mergeKSortedArrays(int arr[][4],int k,int n){
    priority_queue<info*,vector<info*>,compare> minHeap;

    //har array ka first element insert karo
    for(int i=0;i<k;i++){
        info* temp = new info(arrp[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while(!minHeap.empty()){
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);
        if(topCol + 1 < n){
            info* newInfo = new info(arr[topRow][topCol+1],topRow,topCol+1);
            minHeap.push(newInfo);
        }
    }
}
```

## Merge K sorted LL

<https://leetcode.com/problems/merge-k-sorted-lists/>

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
class comp {
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue < ListNode*,vector<ListNode*>,comp> minHeap;
        for(auto i:lists){
            if(i)
                minHeap.push(i);
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty()){
            ListNode* topElement = minHeap.top();
            minHeap.pop();

            //insertion in ans
            if(head == NULL){
                head = topElement;
                tail = topElement;
            } else {
                tail->next = topElement;
                tail = tail->next;
            }

            //add next node in heap
            if(tail->next){
                minHeap.push(tail->next);
            }
        }
        return head;
    }
};
```

## Smallest range covering element from k lists

approach -
we have to one element from each LL if range is made of min and max of element than all elment will be in that range  
and we also have to minimize this range of [min,max] so achieve it need to increase min from LL (can't do max as going next will give higher value in sorted LL)

```cpp
class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};
class comp{
    public:
    bool operator()(node* a,node *b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        priority_queue<node*,vector<node*>,comp> minHeap;
        int k = nums.size();
        for(int i=0;i<k;i++){
            int element = nums[i][0]; 
            maxi = max(maxi,element);
            mini = min(mini,element);
            minHeap.push(new node(element,i,0));
        }
        int ansStart = mini;
        int ansEnd = maxi;
        while(!minHeap.empty()){
            node* top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            //mini updated
            mini = topElement;

            //check for answer
            if(maxi - mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }

            //check for new element in same list
            if(topCol+1 < nums[topRow].size()){
                /* -------------------------------IMPR--------------------*/
                //update maxi also
                maxi = max(maxi,nums[topRow][topCol+1]);
                node* newNode = new node(nums[topRow][topCol+1],topRow,topCol+1);
                minHeap.push(newNode);
            } else {
                //there is no element in list
                break;
            }
        }
        return {ansStart,ansEnd};
    }
};
```

## Remove stones to minimize the total

<https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/>

```cpp
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(auto i:piles){
            maxHeap.push(i);
        }
        while(k--){
            int top = maxHeap.top();
            maxHeap.pop();
            top = top - top/2;
            maxHeap.push(top);
        }
        int ans = 0;
        while(!maxHeap.empty()){
            ans += maxHeap.top(); maxHeap.pop();
        }
        return ans;

    }
};
```

## make_heap and heapify stl TODO

```cpp
vector<int> v = {3,5,6,7,3,9}
make_heap(v.begin(),v.end());
```

## Reorganize string

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

<https://leetcode.com/problems/reorganize-string/>

```cpp
class Solution {
public:
    string reorganizeString(string s) {
        //create mapping
        int freq[26] = {0};
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            freq[ch-'a']++;
        }

        //max heap creation
        priority_queue<node,vector<node>, compare> maxHeap;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                node temp('a'+i,freq[i]);
                maxHeap.push(temp);
            }
        }
        string ans = "";

        while(maxHeap.size() > 1){
            //because taking out two elements
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();
            ans += first.data;
            ans += second.data;
            first.count--;
            second.count--;
            if(first.count != 0) maxHeap.push(first);
            if(second.count != 0) maxHeap.push(second);
        }
        if(!maxHeap.empty()){
            // ans += (maxHeap.top()).data;
            node temp = maxHeap.top();
            maxHeap.pop();
           if(temp.count > 1){
               return "";
           } else {
               ans += temp.data;
           }
        }
        return ans;
    }
};
```

## Longest Happy string

<https://leetcode.com/problems/longest-happy-string/>

```cpp
class node {
    public:
    char data;
    int count;
    node(char d,int c){
        data = d;
        count = c;
    }
};
class compare {
    public:
    bool operator()(node a,node b){
        return a.count < b.count;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node,vector<node>, compare> maxHeap;
        if(a>0) { 
            node t('a',a);
            maxHeap.push(t);
        }
        if(b>0){ 
            node t('b',b);
            maxHeap.push(t);
        }
        if(c>0){ 
            node t('c',c);
            maxHeap.push(t);
        }
        // cout<<maxHeap.top().data<<" "<<maxHeap.top().count;
        string ans = "";
        while(maxHeap.size() > 1){
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            if(first.count >= 2){
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            } else {
                ans += first.data;
                first.count--; //0
            }

            //is condition par fas ta hai IMP second.count >= first.count then only use two
            if(second.count >= 2 && second.count >= first.count){
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            } else {
                ans += second.data;
                second.count--; //0
            }

            if(first.count > 0){
                maxHeap.push(first);
            }
            if(second.count > 0){
                maxHeap.push(second);
            }
        } 
        // cout<<ans;
        if(maxHeap.size() == 1) {
            //still one element present
            node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count >= 2){
                ans += temp.data;
                ans += temp.data;
                temp.count -=2;
            } else {
                ans += temp.data;
                temp.count--;
            }
        }
        return ans;
    }
};
```

## Find Median from Data Stream

<https://leetcode.com/problems/find-median-from-data-stream/>

here median is (median after sorting the all the data)

approach -

1. storing data in vector and and when asked sort the vector and return the median

2. will use two heaps (max and min) max heap will contain all elments smaller than median and min will contain elements bigger than median. here three cases
    1. minHeap.size() == maxHeap.size()
    then medain is avg(maxTop , minTop)
    2. maxHeap.size() == minHeap.size()+1
    mean there is one element more in maxHeap then minHeap so medain is in maxHeap
    3. maxHeap.size() + 1 = minHeap.size()
    mean there is one elment extra in minHeap then maxHeap so medain is in minHeap
    Insertion of element
        1. if maxHeap.size() == minHeap.size() then find median and insert element if smaller than medain then insert in left side and bigger than medain then insert in right side
        2. now leftside (size) and rightside (size+1) so median is top of minHeap and when element is smaller than median then insert in maxHeap but when bigger than median then insert in minHeap will make leftside (size) and rightside (size+1) so to balance our earlier case of finding median pop form minHeap and insert in maxHeap and insert new element in minHeap.
        3. vice versa of above

```cpp
void callMedian(int &median,priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap,int &element){  
    if(minHeap.size() == maxHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = minHeap.top();
        } else {
            maxHeap.push(element);
            medain = maxHeap.top();
        }
    } else if(maxHeap.size() > minHeap.size(){
        if(median < element){
            minHeap.push(element);
            median = (minHeap.top()+maxHeap.top()) / 2;
        } else {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            medain = (minHeap.top()+maxHeap.top()) / 2;
        }
    } else if(maxHeap.size() < minHeap.size()) {
        if(element > median){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            median = (minHeap.top()+maxHeap.top()) / 2;
        } else {
            maxHeap.push(element);
            median = (minHeap.top()+maxHeap.top()) / 2;
        }
    }
}
int main(){
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;
    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++){
        int element = arr[i];
        callMedian(median,maxHeap,minHeap,element);
        cout<<median;
    }
    return 0;
}
```
