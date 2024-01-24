class Solution {
public:
    int solveUsingRecursion(string a, string b, int i, int j) {
        if(i == a.length()) {
            return 0;
        }
        if(j == b.length()) 
            return 0;

        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solveUsingRecursion(a,b, i+1, j+1);
        else {
            ans =  0 + max(solveUsingRecursion(a,b,i,j+1),solveUsingRecursion(a,b,i+1,j));
        }
        return ans;

    } 

    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp) {
        if(i == a.length()) {
            return 0;
        }
        if(j == b.length()) 
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solveUsingMem(a,b, i+1, j+1, dp);
        else {
            ans =  0 + max(solveUsingMem(a,b,i,j+1, dp),solveUsingMem(a,b,i+1,j, dp));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    } 

    int solveUsingTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i = a.length()-1; i>=0; i--) {
            for(int j = b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + dp[i+1][j+1];
                else {
                    ans =  0 + max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] =  ans;
                
            }
        }
        return dp[0][0];
    }


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

    int longestCommonSubsequence(string text1, string text2) {
        // int i = 0;
        // int j = 0 ;
        // vector<vector<int> > dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveUsingMem(text1, text2, i, j, dp);
        return solveUsingTabSO(text1, text2);
    }
};