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

<https://leetcode.com/problems/minimum-cost-for-tickets/>

```cpp
class Solution {
public:
    int minCostRE(vector<int>& days, vector<int>& costs,int i,vector<int> &dp) { //i is used for traversing days

        if(i>=days.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        //cost to travel 1 day
        int cost1 = costs[0] + minCostRE(days,costs,i+1,dp);

        //cost to travel 7 days
        int travelupto = days[i] + 7 - 1;
        int j = i;
        while(j<days.size() && days[j]<=travelupto){
            j++;
        }
        int cost7 = costs[1] + minCostRE(days,costs,j,dp);

        //cost to travel 30 days
        travelupto = days[i] + 30 - 1;
        j = i;  
        while(j<days.size() && days[j]<=travelupto) { //order matters here j out of bound check first then access days[j]
            j++;
        }
        int cost30 = costs[2] + minCostRE(days,costs,j,dp);

        dp[i] = min(cost1 , min(cost7,cost30));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return minCostRE(days,costs,0,dp);
    }
};
```

## DP on Strings

### Longest Palindromic SubString Leetcode

<https://leetcode.com/problems/longest-palindromic-substring/>

```cpp
class Solution {
public:
    int maxLen = 1,start = 0;
    bool solve(string& s,int i,int j,vector<vector<int> > &dp){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool flag = false;
        if(s[i] == s[j]) {
            flag = solve(s,i+1,j-1,dp);
        }
        if(flag) {
            int currLen = j-i+1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }
    string longestPalindrome(string s) {
        vector<vector<int> > dp(s.size()+1,vector<int> (s.size()+1,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                bool t = solve(s,i,j,dp);
            }
        }
        return s.substr(start,maxLen);
    }
};
```

### Distinct Subsequences Leetcode

<https://leetcode.com/problems/distinct-subsequences/>

```cpp
class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector< vector<int> > &dp){
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int include = 0;
        int exclude = 0;
        if(s[i] == t[j]){
            include = solve(s,t,i+1,j+1,dp);
            exclude = solve(s,t,i+1,j,dp);
        } else {
            exclude = solve(s,t,i+1,j,dp);
        }

        return dp[i][j] = include + exclude;
    }
    int numDistinct(string s, string t) {
        vector< vector<int> > dp(s.size()+1 , vector<int> (t.size()+1, -1));
        return solve(s,t,0,0,dp);
    }
};
```

### Min ASCII Delete Sum for 2 Strings Leetcode

<https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/>

```cpp
class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector< vector<int> > &dp){
        int cost = 0;
        if( i >= s.size() || j >= t.size()){
            for(int x=i;x<s.size();x++) cost +=s[x];
            for(int x=j;x<t.size();x++) cost +=t[x];
        }
        else if(dp[i][j] != -1 ) return dp[i][j]; 
        else if (s[i] == t[j]){
            cost = solve(s,t,i+1,j+1,dp);
        } else {
            int cost1 = s[i] + solve(s,t,i+1,j,dp);
            int cost2 = t[j] + solve(s,t,i,j+1,dp);
            cost = min(cost1,cost2);
        }
        return dp[i][j] = cost;
    }
    int minimumDeleteSum(string s, string t) {
        vector< vector<int> > dp(s.size()+1 , vector<int> (t.size()+1, -1));
        return solve(s,t,0,0,dp);
    }
};
```

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
