class Solution {
public:

    int solveUsingRecursion(string& a, string& b, int i, int j) {

        //base case
        if( i == a.length()) {
            return b.length()-j;
        }

        if(j == b.length()) {
            return a.length()-i;
        }

        int ans = 0;
        if(a[i] == b[j]) {
            ans = solveUsingRecursion(a,b,i+1,j+1);
        }
        else {
            //operation perform karo 
            int insert = 1 + solveUsingRecursion(a,b,i,j+1);
            int deleted = 1 + solveUsingRecursion(a,b,i+1,j);
            int replace = 1 + solveUsingRecursion(a,b,i+1, j+1);
            ans = min(insert, min(deleted, replace));
        }
        return ans;
    }

    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp) {

        //base case
        if( i == a.length()) {
            return b.length()-j;
        }

        if(j == b.length()) {
            return a.length()-i;
        }

        if(dp[i][j] != -1) 
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]) {
            ans = solveUsingMem(a,b,i+1,j+1, dp);
        }
        else {
            //operation perform karo 
            int insert = 1 + solveUsingMem(a,b,i,j+1, dp);
            int deleted = 1 + solveUsingMem(a,b,i+1,j, dp);
            int replace = 1 + solveUsingMem(a,b,i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    }

    int solveUsingTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));

        for(int j =0; j<=b.length(); j++) {
            dp[a.length()][j] =  b.length()-j;
        }

        for(int i =0; i<=a.length(); i++) {
            dp[i][b.length()] = a.length() - i;
        }

        for(int i = a.length()-1; i>=0; i--) {
            for(int j =b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = dp[i+1][j+1];
                }
                else {
                    //operation perform karo 
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] =  ans;
                
            }
        }
        return dp[0][0];
    }


int solveUsingTabSO(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int j =0; j<=b.length(); j++) {
            next[j] =  b.length()-j;
        }

        for(int i = a.length()-1; i>=0; i--) {
            //every row starts here
            //yaha galti karoge
            curr[b.length()] = a.length()-i;
            
            for(int j =b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = next[j+1];
                }
                else {
                    //operation perform karo 
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                curr[j] =  ans;
            }
            //shift
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        if(word1.length() == 0) 
            return word2.length();
        
        if(word2.length() == 0)
            return word1.length();
        int i = 0;
        int j = 0;


        //vector<vector<int> > dp(word1.length(), vector<int>(word2.length(), -1));

        //return solveUsingMem(word1, word2, i, j, dp);
        return solveUsingTabSO(word1, word2);
    }
};