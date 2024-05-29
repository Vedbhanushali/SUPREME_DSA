class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int> > q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end()) ;
        //jo bhi word queue me insert karunga, toh usko set me se remove krdunga
        st.erase(beginWord);

        while(!q.empty()) {
            pair<string,int> fNode = q.front();
            q.pop();

            string currString = fNode.first;
            int currCount = fNode.second;

            //check kahin destination tak toh nahi pohoch gye
            if(currString == endWord) 
                return currCount;
            
            for(int index=0; index<currString.length(); index++) {
                //hr index pr jo value h, usko main 'a' to 'z' se replace karunga
                char originalCharacter = currString[index];
                for(char ch='a'; ch<='z'; ch++) {
                    currString[index] = ch;
                    //check in wordList
                    if(st.find(currString) != st.end()) {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                //bringing back the currString to its original State
                currString[index] = originalCharacter;
            }
        }
        return 0;

    }
};