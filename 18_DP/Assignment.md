# Assignment

## Linear DP

### Perfect Squares Leetcode

<https://leetcode.com/problems/perfect-squares/>

```cpp
class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n < 0) return INT_MAX;
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int limit = sqrt(n);
        for(int i=1;i<=limit;i++){
            ans = min(ans,solve( n - (i*i) , dp )); //INT_MAX or 0 1 2 3
        }

        if(ans != INT_MAX) ans++;
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
```

### Min Cost for Tickets Leetcode

## DP on Strings

### Longest Palindromic SubString Leetcode

### Distinct Subsequences Leetcode

### Min ASCII Delete Sum for 2 Strings Leetcode

### Word Break 1 and 2 Leetcode

## DP on Trees

### House Robber iii Leetcode

### Unique BST ii Leetcode

## DP on Intervals

### Stone Games Leetcode

### Burst balloons Leetcode

## LIS / LCS Variants

### Intervleaving Strings Leetcode

### Min Insertion steps to make a string palindrome Leetcode

### Russian Dolls Envelopes Leetcode

### Min Number of Removals to make Mountain Array Leetcode

### Make Array Strictly increasing Leetcode

## Buy & Sell Stocks Variants [all 5 variants] Leetcode

### 1st Variant [121. Best Time to Buy and Sell Stock] - Already Covered in Recursion Week HomeWork

## Knapsack DP

### Target Sum Leetcode

### Min Swaps to make Sequences increasing Leetcode

### Reducing Dishes Leetcode

### Ones and Zeroes Leetcode

## MinMax DP

### Predict the Winner Leetcode
