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