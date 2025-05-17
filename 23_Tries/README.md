# Tries

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
void insertWord(TrieNode* root,string word) {
    if(word.size() == 0) {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL) {
        //already present
        child = root->children[index];
    } else {
        //not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child,word.substr(1));
}
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
void storeSuggestions(TrieNode* curr, vector<string>& temp, string &prefix) {
	if(curr -> isTerminal) {
		temp.push_back(prefix);
        return;
	}
	//a to z tak choices dedo
	for(char ch ='a'; ch<='z'; ch++) {
		int index = ch-'a';

		TrieNode* next = curr->children[index];

		if(next != NULL) {
			//if child exists
			prefix.push_back(ch);
			storeSuggestions(next, temp, prefix);
			prefix.pop_back();
		}
	}	
}
vector<vector<string>> getSuggestion(TrieNode* root, string input) {
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";
    for(int i=0;i<input.size();i++) {
        char currCh = input[i];
        int index = currCh - 'a';
        TrieNode* curr = prev->children[index];
        if(curr == NULL) {
            break;
        } else {
            vector<string> temp;
            prefix.push_back(currCh);
            storeSuggestions(curr,temp,prefix); //from curr char all possible children string it will generate
            output.push_back(temp);
            prev = curr;
        }
    }
    return output
}

int main() {
    TreiNode* root = new TrieNode('-');
    insertWord(root,"coding");
    cout<<searchWord(root,"code")<<endl; //false
    cout<<searchWord(root,"coding")<<endl; // true
    cout<<searchWord(root,"cod")<<endl; //false
    deleteWord(root,"coding"); //deleted

    vector<string> v;
    v.push_back("love");
	v.push_back("lover");
	v.push_back("loving");
	v.push_back("last");
	v.push_back("lost");
	v.push_back("lane");
	v.push_back("lord");

	string input = "lovi";
    TrieNode* root1 = new TrieNode('-');
    for(string &s : v){
        insertWord(root1,s);
    }
    vector<vector<string>> ans = getSuggestion(root1,input);
    for(auto i : ans){
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }
    // OUTPUT
    /*
    Printing the answer: 
    lane, last, lord, lost, love, lover, loving, 

    lord, lost, love, lover, loving, 

    love, lover, loving, 

    loving,  
    */
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
    string longestCommonPrefixSecondMethod(vector<string> words) {
        TrieNode* root = new TrieNode('-');
        for(string &s : words){
            insertWord(root,s);
        }
        string prefix = "";
        TrieNode* curr = root;
        while(!curr->isTerminal) {
            int count = 0;
            int index = -1;
            for(int i=0;i<26;i++){
                if(curr->children[i]) {
                    count++;
                    index = i;
                }
            }
            if(count > 1) break;
            prefix += ('a'+index);
            curr = curr->children[index];
        }
        return prefix;
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
