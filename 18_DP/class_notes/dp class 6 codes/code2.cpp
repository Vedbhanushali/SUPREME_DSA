class Solution {
public:

int solveUsingTabSO(string a, string b) {
        //vector<vector<int> > dp(a.length()+101, vector<int>(b.length()+129, 0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i>=0; i--) {
            for(int j = b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + next[j+1];
                else {
                    ans =  0 + max(curr[j+1], next[j]);
                }
                curr[j] =  ans;      
            }
            //shift
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;
        return solveUsingTabSO(first, second);
    }
};