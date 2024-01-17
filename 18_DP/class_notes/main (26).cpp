class Solution {
public:
    int recSolve(int n) {
        //base case
        if(n == 1 || n == 0) {
            return n;
        }
        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }
    //Recursion + Memoisation
    int topDownSolve(int n, vector<int>& dp) {
        //base case
        if(n == 1 || n == 0) {
            return n;
        }
        //step3: check if aNS ALREADY EXIst
        if(dp[n] != -1) {
            return dp[n];
        }
        //step2: replace ans woth dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2, dp);
        return dp[n];
    }
    //tabulation method
   int bottomUpSolve(int n) {
       //step1: create a dp array
       vector<int> dp(n+1, -1);

       //step2:base case
       dp[0] = 0;
       if(n == 0) 
       return dp[0];
       dp[1] = 1;

       //step3: topDown approach me n kaise travel krra h 
       for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
       }

       return dp[n];

   }

   int spaceOptSOlve(int n) {
       
       //step2:base case
       int prev2 = 0;
       
       int prev1 = 1;

       if(n==0)
        return prev2;
       if(n == 1)
        return prev1;
       int curr;
       //step3: topDown approach me n kaise travel krra h 
       for(int i = 2; i<=n; i++) {
            curr = prev1 + prev2;
            //shifting
            prev2 = prev1;
            prev1 = curr;
       }

       return curr;

   }

    int fib(int n) {
        // int ans = recSolve(n);
        // return ans;

        //step1: create dp array
        // vector<int> dp(n+1, -1);
        // int ans = topDownSolve(n, dp);
        // return ans;

        return spaceOptSOlve(n);

    }
};