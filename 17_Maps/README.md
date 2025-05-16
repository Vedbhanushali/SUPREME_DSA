# HashMaps and tries

## hashmap

it is datastructure which store data in form of key value pair

types of map
ordered map - TC O(logn)
unordered map - TC O(1)

H.W.
write data structure insertion,deletion and searching can be done in O(1) TC

## hashmap stl

```cpp
#include<unordered_map>

int main(){
    unordered_map<string,int> m;
    
    //insertion
    //1st way
    pair<string,int> p = make_pair("test",8);
    m.insert(p);
    //2nd way
    pair<string,int> p2("t",3);
    m.insert(p2);
    //3rd way
    m["t2"] = 4;

    //access
    //1st way
    cout<<m.at("test");
    //2nd way
    cout<<m["t2"];

    //search
    cout<<m.count("test"); //if greater than 0 then key exist
    //search can be done using find
    if(m.find("test") != m.end()){
        cout<<"test found";
    }

    //size
    cout<<m.size(); //3

    //when access not present key in map it will create that key with value 0
    cout<<m["notPresent"]; //0
    cout<<m.size(); //4 because of above it created key

    //printing
    for(auto i:m){
        cout<<i.first<<" "<<i.second;
    }
}
```

## Implementation

1. ordered map -  uses BST internally TC - O(logn) for all operations

## custom hashMap implementation

## using Bucket array

we were creating 26 size hashMap for 26 alphabets where we were mapping index of array using function of char-'a' - index of array

this function is called hash function. hash function contains

1. hashcode - conversion of key to numeric value
2. compression function - adjust above numeric value to approriate range of array

### collision in array

when two different keys map to same address then it is called collision.

### collision handling - open hashing

storing both collided value in same address in form of linked list

### collistion handling - linear probing

when there is collision then will find next free space in array and insert value there

### collision handling - quadratic probing

when there is collision then will find next free space with gap of i^2 position i is increasing in array and insert value there

## good hash function

number of elements  - n
free box - b

load factor - (n/b < 0.7) mean good hash function

## find freq of characters in string

```cpp
string str = "ved";
unordered_map<char,int> freq;
for(auto i:str){
    freq[ch]++;
}
```

## check circular LL

```cpp
bool checkCircular(Node* head){
    unordered_map<Node*,bool> vis;
    Node* temp = head;

    while(temp!=NULL){
        if(vis.find(temp)!=vis.end()){
            vis[temp] = true;
        } else {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
```

## Mutliset to find min and max in single Data structure

### stl algorithm

```cpp
    // can contain duplicate entries also 
    // below will be created in ascending order
    multiset<int> m; 
    // below will be in descending order
    multiset<int, greater<int> > m2;
    m.insert(1);
    m.insert(3);
    m.insert(2);
    m.insert(2);
    m.insert(2);
    multiset<int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        cout << *itr << " ";
    } 
    // OUTPUT - 1 2 2 2 3
    cout<<"max : "<<*m.rbegin()<<endl; // OUTPUT - 3
    cout<<"min : "<<*m.begin()<<endl; //OUTPUT - 2
    // erase on single instance of 
    m.erase(m.find(2)); //OUTPUT - 1 2 2 3
    // erase all instance of provided
    m.erase(2); // 1 3
```

<https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        //this is magic code
        // int i = 0, j;
        // multiset<int> m;
        // for (j = 0; j < A.size(); ++j) {
        //     m.insert(A[j]);
        //     if (*m.rbegin() - *m.begin() > limit) {
        //         //max - min > limit
        //         m.erase(m.find(A[i]));
        //         i++;
        //     }
        // }
        // return j - i;
        int s = 0;
        int e = 0;
        int ans = 0;
        int maxi = INT_MIN;
        int mini = INT_MIN;
        multiset<int> ms;
        // ms.insert(10005);
        // ms.insert(-10005);
        while(e<A.size() && s<A.size()){
            // cout<<"s "<<s<<" e "<<e<<endl;
            ms.insert(A[e]);
            // for(auto it = ms.begin();it!=ms.end();it++) cout<<*it<<" ";
            //     cout<<endl;
            maxi = *ms.rbegin();
            mini = *ms.begin();
            // cout<<"maxi "<<maxi<<" mini "<<mini<<endl;
            if(maxi - mini <= limit){
                // cout<<"went inside : "<<e-s+1<<endl;
                ans = max(ans,e-s+1);
                e++;
            } else {
                // ms.erase(A[s]);
                multiset<int>::iterator itr;
                itr = ms.find(A[s]);
                // cout<<"clearing ";
                // cout<<*itr<<endl;
                if(itr != ms.end())
                    ms.erase(itr);
                itr = ms.find(A[e]);//because re entry will be done 
                if(itr!=ms.end())
                    ms.erase(itr);
                s++;
            }
        }
        // ans = max(ans,e-s+1);
        return ans;
    }
};
```