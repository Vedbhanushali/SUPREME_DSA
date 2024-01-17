class Solution {
public:

    int solveUsingRecursion(vector<int>& coins, int amount) {
        //base case
        if(amount == 0) {
            return 0;
        }
        if(amount < 0 ) {
            return INT_MAX;
        }

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int ans = solveUsingRecursion(coins, amount - coins[i]);
            if(ans != INT_MAX) {
                mini = min(mini,1+ ans);
            }
        }
        return mini;
    }


    
    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        //base case
        if(amount == 0) {
            return 0;
        }
        if(amount < 0 ) {
            return INT_MAX;
        }
        //ans already exists
        if(dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int ans = solveMem(coins, amount - coins[i], dp);
            if(ans != INT_MAX) {
                mini = min(mini,1+ ans);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int solveTab(vector<int>& coins, int amount) {
        //step1: create dp array 
        vector<int> dp(amount+1, INT_MAX);
        //step2: base case dekho
        dp[0] = 0;
        //step3: check the range and flow of top down approach and code accordingly
        for(int target = 1; target <= amount; target++) {
                int mini = INT_MAX;
                for(int i=0; i<coins.size(); i++) {
                    if(target - coins[i] >=0 ) {
                    int ans = dp[target - coins[i]];
                    if(ans != INT_MAX) {
                        mini = min(mini,1+ ans);
                    }
                    }
                    
                }
                dp[target] = mini;
                
        }
    return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins, amount);
        // if(ans == INT_MAX)
        //     return -1;
        // else
        //     return ans;

        // vector<int> dp(amount+1, -1);
        // int ans = solveMem(coins,amount, dp);
        // if(ans == INT_MAX)
        //     return -1;
        // else 
        //     return ans;

        int ans = solveTab(coins, amount);
        if(ans == INT_MAX)
            return -1;
        else 
            return ans;


    }
};









