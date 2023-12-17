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

## Tries

is a multiway tree data structure
used for pattern searching

if node present then traverse  
if not present then create it.  
also make last inserted node terminal becase when a new string is inserted and whose prefix is already there in trie to identify that prefix string terminal is required. also terminal helps in deleting string
just deleting teminal meam that string didn't match

## trie structure

```cpp
class TrieNode {

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data  = d;
        for(int i=0; i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

bool searchWord(TrieNode* root,string word){
    if(word.length() == 0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch-'a';
    //present case 
    if(root->children[index]!=NULL){
        return searchWord(root->children[index],word.substr(1));
    } else {
        return false;
    }
}
void deleteWord(TrieNode* root,string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    deleteWord(root->children[index],word.substr(1));
}
int main() {
    TreiNode* root = new TrieNode('-');
    insertWord(root,"coding");
    searchWord(root,"code"); //false
    searchWord(root,"coding"); // true
    searchWord(root,"cod"); //false
    deleteWord(root,"coding"); //deleted
    return 0;
}
```

## Longest common prefix

<https://leetcode.com/problems/longest-common-prefix/>

approach 1 using sort

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string ans  = "";

       int i =  strs[0].length();
       int j = strs[n-1].length();

       int s=0,e = 0;
        while(s<i && e<j){
           if(strs[0][s]==strs[n-1][e]){
               ans.push_back(strs[0][s]);
               s++;
               e++;
           }

           else
           break;
        }
        return ans;
    }
};
```

approach 2 using trie
will insert all string in trie and when there is single child node of root we can consider it common prefix and we need do this child of child till we found terminal or more than one child nodes of root.

```cpp
class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char d){
        this->data  = d;
        for(int i=0; i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
        childCount = 0;
    }   
};
class Solution {
public:
    void insertWord(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        char ch = word[0];
        int index = ch-'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        } else {
            child = new TrieNode(ch);
            root->children[index] = child;
            root->childCount++;
        }

        //recursion
        insertWord(child,word.substr(1)); 
    }
    void findLCP(string first,string &ans,TrieNode* root){
        //yaha galti hoti  jab empty string insert ki ho to root hi terminal hoga
        if(root->isTerminal) return;
        for(int i=0;i<first.size();i++){
            char ch = first[i];
            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch-'a';
                root = root->children[index];
            } else break;
            if(root->isTerminal){
                return;
            }
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        //insert all string
        for(auto i: strs){
            insertWord(root,i);
        }

        string ans = "";
        string first = strs[0];
        findLCP(first,ans,root);
        return ans;
    }
}; 
```

## Implement dictonary

trie - [love,lover,loving,lost,last,lane,lord]  
input - l  
output - [love,lover,loving,lost,last,lane,lord]  
input - lo  
output - [love,lover,loving,lost,lord]  
input - lov  
output - [love,lover,loving]  

```cpp
void storeSuggestions(TrieNode* curr,vector<string>& temp,string &prefix){
    if(curr->isTerminal){
        temp.emplace_back(prefix);
    }
    //a to z choice
    for(char ch = 'a';ch<='z';ch++){
        int index = ch-'a'; 
        TrieNode* next = curr->children[index];

        if(next != NULL){
            prefix.push_back(ch);
            storeSuggestions(next,temp,prefix);
            prefix.pop_back();
        }
    }
}
vector<vector<string>> getSuggestions(TrieNode* root,string input){
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";
    for(int i=0;i<input.length();i++){
        char lastch = input[i];

        int index = lastch - 'a';
        TrieNode* curr = prev->children[index];

        if(curr == NULL)
            break;
        else {
            //iske andar main sarre suggestion store karke langa
            vector<string> temp;
            prefix.push_back(lashch);
            storeSuggestions(curr,temp,prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}
int main() {
    vector<string> c;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");
    string input = "lovi";
    TreiNode* root= new TrieNode("-");
    for(int i=0;i<v.size();i++){
        insertWord(root,v[i]);
    }
    vector<vector<string>> ans = getSuggestions(root,input);
    //ans will be
    //love,lover,loving,last,lost,lane,lord
    //love,lover,loving,lost,lord
    //love,lover,loving
    //loving
    return 0;
}
```
