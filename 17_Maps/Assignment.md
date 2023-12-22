# hashMap and Tries Assignment

## Array subset of another array

<https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1>

```cpp
string isSubset(int a1[], int a2[], int n, int m) {
    if(n < m) return "No";
    unordered_map<int,int> hashMap;
    for(int i=0;i<n;i++){
        hashMap[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        // cout<<a2[i]<<" "<<hashMap[a2[i]]<<endl;
        if(hashMap[a2[i]]==0){
            return "No";
        } else {
            hashMap[a2[i]]--;
        }
        // cout<<a2[i]<<" - "<<hashMap[a2[i]]<<endl;
    }
    return "Yes";
}
```

## Union of two linked list

<https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1>

```cpp
class Solution
{
    public:
    struct Node*makeUnion(struct Node* head1, struct Node*head2)
    {
        // code here
        map<int,Node*> hashMap;
        Node*temp = head1;
        while(temp){
            hashMap[temp->data] = temp;
            temp = temp->next;
        }
        temp = head2;
        while(temp){
            hashMap[temp->data] = temp;
            temp = temp->next;
        }
        temp = NULL;
        Node* ans = temp;
        for(auto i:hashMap){
            // cout<<i.second->data<<endl;
            if(temp == NULL){
                temp = i.second;
                ans = temp;
            } else {
                temp->next = i.second;
                temp = temp->next;
            }
            // cout<<temp->data<<" "<<endl;
        }
        temp->next = NULL;
        return ans;
    }
};
```

## Intersection of two linked list

<https://leetcode.com/problems/intersection-of-two-linked-lists/>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * l1 = headA;
        ListNode * l2 = headB;
        while(l1->next!=NULL && l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1->next==NULL){
            //L2 is bigger
            int gap = 0;
            while(l2->next!=NULL){
                gap++;
                l2 = l2->next;
            }
            while(gap--){
                headB = headB->next;
            }
        } else {
            //L1 is bigger
            int gap = 0;
            while(l1->next!=NULL){
                gap++;
                l1 = l1->next;
            }
            while(gap--){
                headA = headA->next;
            }
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
        // int l1 = 0;
        // int l2 = 0;
        // ListNode* temp1 = headA;
        // ListNode* temp2 = headB;
        // while(temp1!=NULL){
        //     temp1 = temp1->next;
        //     l1++;
        // }
        // while(temp2!=NULL){
        //     temp2 = temp2->next;
        //     l2++;
        // }
        
        // int jump = 0;
        // if(l1>l2){
        //     temp1 = headA;
        //     temp2 = headB;
        //     jump = l1-l2; //list1 is bigger
        //     while(jump--){
        //         temp1 = temp1->next;
        //     }
        // } 
        // else{
        //     temp1 = headA;
        //     temp2 = headB;
        //     jump = l2-l1; //list1 is bigger
        //     while(jump--){
        //         temp2 = temp2->next;
        //     }
        // }
        // while(temp1!=NULL && temp2!=NULL){
        //     if(temp1==temp2){
        //         return temp1;
        //     } else {
        //         temp1=temp1->next;
        //         temp2=temp2->next;
        //     }
        // }
        // return NULL;

    }
};
```

approach using hashMap

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int > hashMap;
        ListNode* temp = headA;
        while(temp){
            hashMap[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        ListNode* ans = NULL;
        while(temp){
            if(hashMap.count(temp)>0){
                ans = temp;
                break;
            }
            temp = temp->next;
        }
        return ans;
    }
};
```

## Sum equal to sum

<https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1>

```cpp
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        int ans = 0;
        unordered_map<long long,int> hashMap;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++) {
                int sum = a[i] + a[j];
                if(hashMap.count(sum) == 0){
                    // cout<<"unique"<<sum<<endl;
                    hashMap[sum]++;
                } else {
                    // cout<<"present"<<sum<<endl;
                    return 1;
                }    
            }
            
        }
        return 0;
    }
};
```

## largest subarray with 0 sum

<https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1>

```cpp
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {
        // Your code here
        unordered_map<int,int> hashMap;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(sum == 0){
                ans = max(ans,i+1);
            }
            else if(hashMap.count(sum) == 0){
                //does not exist
                hashMap[sum] = i;
            } else {
                //exist before
                // 2-0;
                ans = max(ans,i-hashMap[sum]);
            }
        }
        return ans;
    }
};
```

## Implement Trie Prefix tree

<https://leetcode.com/problems/implement-trie-prefix-tree/>

```cpp
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'a';
        if(!root->children[index]){
            //create new
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }
    bool searchUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            return root->isTerminal;
        }
        int index = word[i] - 'a';
        if(root->children[index]==NULL){
            return false;
        }
        return searchUtil(root->children[index],word,i+1);
    }
    bool startWithUtil(TrieNode*root,string &word,int i){
        if(i>=word.size()){
            return true;
        }
        int index = word[i] - 'a';
        if(root->children[index]==NULL){
            return false;
        }
        return startWithUtil(root->children[index],word,i+1);
    }
    void insert(string word) {
        insertUtil(root,word,0);
    }
    
    bool search(string word) {
        return searchUtil(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return startWithUtil(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

## Replace words

<https://leetcode.com/problems/replace-words/description/>

```cpp
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'a';
        if(!root->children[index]){
            //create new
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }
    bool searchUtil(TrieNode* root,string &word,int &i){
        if(root->isTerminal) return true;
        if(i>=word.size()){
            return root->isTerminal;
        }
        int index = word[i] - 'a';
        if(root->children[index]==NULL){
            return false;
        }
        i++;
        return searchUtil(root->children[index],word,i);
    }
    bool startWithUtil(TrieNode*root,string &word,int i){
        if(i>=word.size()){
            return true;
        }
        int index = word[i] - 'a';
        if(root->children[index]==NULL){
            return false;
        }
        return startWithUtil(root->children[index],word,i+1);
    }
    void insert(string word) {
        insertUtil(root,word,0);
    }
    
    int search(string word) {
        int i = 0;
        bool gotIt = searchUtil(root,word,i);
        return gotIt ? i : -1;
    }
    
    bool startsWith(string prefix) {
        return startWithUtil(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;
        //inserting dictonary into trie
        for(auto root:dictionary){
            trie.insert(root);
        }
        //pick each word and find in trie whether the root is available or not
        int start = 0;
        int end = 0;
        while(end < sentence.size()){
            if(sentence[end] == ' ' || end == sentence.size()-1){
                int len = end == sentence.size()-1 ? sentence.size() :end-start; //for sentence.size() size case it does not matter as we are last word how much more size we add we will receive only last word
                string word = sentence.substr(start,len);
                int trieMatchIndex = trie.search(word);
                ans +=trieMatchIndex != -1 ? word.substr(0,trieMatchIndex):word;
                if(sentence[end] == ' '){
                    ans += " ";
                }
                start = end + 1;
            }
            ++end;
        }
        return ans;
    }
};
```

## Top K frequent words

<https://leetcode.com/problems/top-k-frequent-words/description/>

Method1 - using hashmap to find frequency and maxheap to find top frequent occured character

Method2 - using trie acting as hashMap
custorm hashMap implementation using trie

```cpp
class comp {
    public:
    bool operator()(const pair<int,string>&a,const pair<int,string>&b){
        return a.first == b.first ? a < b : a.first > b.first; // min heap logic
    }
};

class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int freq;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        freq = 0;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            root->isTerminal = true;
            root->freq++;
            return;
        }
        int index = word[i] - 'a';
        if(!root->children[index]){
            //create new
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }
    void insert(string word) {
        insertUtil(root,word,0);
    }    
    void traverseUtil(TrieNode* root,string &s,priority_queue< pair<int,string>, vector<pair<int,string>>, comp> &pq,int &k){
        if(!root){
            return;
        }
        if(root->isTerminal){
            // cout<<s;
            //store k frequent words

            if(pq.size() < k){
                pq.push({root->freq,s});
            }
            else if(pq.size() == k && root->freq > pq.top().first){
                pq.pop();
                pq.push({root->freq,s});
            }
        }
        for(int i=0;i<26;i++){
            if(root->children[i]){
                s.push_back(i+'a');
                // cout<<s<<" ";
                traverseUtil(root->children[i],s,pq,k);
                s.pop_back();
            }
        }
    }
    void traverse(priority_queue<pair<int,string>, vector<pair<int,string> >, comp>&pq,int &k){
        string s="";
        traverseUtil(root,s,pq,k);
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        vector<string> answer;
        for(auto word:words){
            trie.insert(word);
        }
        priority_queue< pair<int,string>, vector<pair<int,string>>, comp>pq;
        trie.traverse(pq,k);
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            answer.emplace_back(curr.second);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
```

## Camelcase matching

<https://leetcode.com/problems/camelcase-matching/>

Method 1 : can be solved using two pointer approach

Method 2 : using tries  
TC - O(pl) + O(n*m)  
pl - pattern length, n - no of queries, m - length of query[i]

```cpp
class TrieNode{
    public:
    char data;
    TrieNode *children[58];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i=0;i<58;i++){
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'A';
        if(!root->children[index]){
            //create new
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }
    bool searchUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            return root->isTerminal;
        }
        int index = word[i] - 'A';
        if(root->children[index]){
            return searchUtil(root->children[index],word,i+1);    
        } 
        else if(islower(word[i])) {
            return searchUtil(root,word,i+1);
        }
        return false;
    }

    void insert(string word) {
        insertUtil(root,word,0);
    }
    
    bool search(string word) {
        return searchUtil(root,word,0);
    }
    
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie trie;
        vector<bool> ans;
        trie.insert(pattern);
        for(auto query:queries){
            ans.push_back(trie.search(query));
        }
        return ans;
    }
};
```

## Palindrome Pairs

```cpp
// class TrieNode{
//     public:
//     char data;
//     TrieNode *children[26];
//     int stringNumber;

//     TrieNode(char ch) {
//         data = ch;
//         stringNumber = -1;
//         for(int i=0;i<26;i++){
//             children[i] = NULL;
//         }
//     }
// };
// class Trie {
// public:
//     TrieNode *root;
//     Trie(){
//         root = new TrieNode('\0');
//     }
//     void insertUtil(TrieNode* root,string &word,int i,int& stringNumber){
//         if(i>=word.size()){
//             // root->isTerminal = true;
//             root->stringNumber = stringNumber;
//             return;
//         }
//         int index = word[i] - 'a';
//         if(!root->children[index]){
//             //create new
//             root->children[index] = new TrieNode(word[i]);
//         }
//         insertUtil(root->children[index],word,i+1,stringNumber);
//     }

//     void insert(string &word,int &stringNumber) {
//         insertUtil(root,word,0,stringNumber);
//     }
//     bool isPalindrome(string &word,int low,int high){
//         while(low <= high){
//             if(word[low]!=word[high]){
//                 return false;
//             }
//             low++;
//             high--;
//         }
//         return true;
//     }
//     void searchCase2(TrieNode* curr,vector<int>& word_s_palindrome,string s){
//         if(curr->stringNumber!=-1){
//             //terminal
//             if(isPalindrome(s,0,s.size())){
//                 word_s_palindrome.emplace_back(curr->stringNumber);
//             }
//         }
//         for(int i=0;i<26;i++){
//             if(curr->children[i]!=0){
//                 s.push_back(i+'a');
//                 searchCase2(curr->children[i],word_s_palindrome,s);
//                 s.pop_back();
//             }
//         }
//     }
//     void search(string &word,vector<int> &word_s_palindrome) {
//         cout<<"word "<<word<<endl;
//         TrieNode* curr = root;

//         //case 1 when prefix of string word , exactly matches with a word in trie
//         for(int i=0;i<word.size();i++){
//             int index = word[i] - 'a';
//             if(curr->stringNumber != -1){
//                 cout<<"completely matched"<<curr->stringNumber;
//                 //reached end of trie but still word is remaining or not both case
//                 //check rest of the word is palindrome or not
//                 if(isPalindrome(word,i,word.size()-1)){
//                     word_s_palindrome.push_back(curr->stringNumber);
//                 }
//             }

//             if(curr->children[index]){
//                 curr = curr->children[index];
//             } else {
//                 return;
//             }
//         }

//         //case 2 search word is a prefix of a word in trie
//         //checking remaining subtrees in trie for palindrome
//         // string s = "";
//         searchCase2(curr,word_s_palindrome,"");
//     }

// };
// class Solution {
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         vector<vector<int>> ans;
//         Trie trie;
//         //insert all words in reverse order and its string number as index of terminal node
//         for(int i=0;i<words.size();i++){
//             auto reverseWord = words[i];
//             reverse(reverseWord.begin(),reverseWord.end());
//             trie.insert(reverseWord,i);
//         }

//         //find all  palindromic pairs 
//         for(int i=0;i<words.size();i++){
//             vector<int> word_s_palindrome; //will store ith word palindromes index 
//             trie.search(words[i],word_s_palindrome);
//             for(auto it: word_s_palindrome){
//                 if(it!=i){
//                     ans.push_back({i,it});
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>res;
        buildTrie(words);
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            for(auto x: Trie[s]) if(isPalindrome(x.first) && i != x.second) res.push_back({i, x.second});
            for(int j = 0; j <= s.size(); j++)
                if(m.count(s.substr(0, j)) && isPalindrome(s.substr(j)) && i != m[s.substr(0, j)]) 
                    res.push_back({i, m[s.substr(0, j)]});
        }    
        return res;
    }
    
private:
    unordered_map<string, vector<pair<string, int> > >Trie;
    unordered_map<string, int>m;
    void buildTrie(vector<string>& words){
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
            for(int j = 0; j < s.size(); j++) Trie[s.substr(0, j)].push_back({s.substr(j), i});
        }
    }
    
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
};
```
