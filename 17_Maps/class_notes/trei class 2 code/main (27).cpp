class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                this->isTerminal = false;
        }
};





class Solution {
public:
void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;
        }
        //rec call
        return searchWord(child, word.substr(1));

}

    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        //loop on first string
        for(int i=0; i<strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;

            //compare this charachter with alll 
            //the remaining strings at the same index
            for(int j=1; j<strs.size(); j++  ) {
                //compare
                if(strs[j].size() < i || ch != strs[j][i]) {
                    match = false;
                    break;
                }
            }

            if(match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};