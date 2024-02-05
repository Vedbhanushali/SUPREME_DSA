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

<https://leetcode.com/problems/word-break/>

```cpp
class Solution {
public: 
    bool checkWord(string &word,vector<string> &wordDict){
        for(auto i:wordDict){
            if(i == word) return true;
        }
        return false;
    }
    bool solve(string &s,vector<string>&wordDict,int start,vector<int> &dp){
        if(start >= s.size()) return true;
        if(dp[start] != -1) return dp[start];

        bool ans = false;
        string word = "";
        for(int i=start;i<s.size();i++){
            word += s[i];
            if(checkWord(word,wordDict)){
                ans = ans || solve(s,wordDict,i+1,dp);
            }
        }
        return dp[start] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,-1);
        return solve(s,wordDict,0,dp);
    }
};
```

<https://leetcode.com/problems/word-break-ii/>

```cpp
class Solution {
public:
    unordered_map<int,vector<string> > dp;
    vector<string> solve(string &s,unordered_map<string,bool> &dict,int start){
        if(start >= s.size()) return {""};
        if(dp.find(start) != dp.end()) return dp[start];
        vector<string> ans;
        string word;
        for(int i=start;i<s.size();i++){
            // word.push_back(s[i]);
            word += s[i];
            if(!dict[word]) continue;
            // if(dict.find(word) == dict.end()) continue;
            //found in dict
            auto right = solve(s,dict,i+1);
            for(auto rightPart : right ){
                string endPart;
                if(rightPart.size() > 0) endPart = " "+rightPart;
                ans.emplace_back(word+endPart);
            }
        }
        return dp[start] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> dict;
        for(auto i:wordDict){
            dict[i] = 1;
        }
        return solve(s,dict,0);
    }
};
```

## DP on Trees

### House Robber ii & iii Leetcode

<https://leetcode.com/problems/house-robber-ii/>

```cpp
class Solution {
public:
    int solve(vector<int>& nums,int &low,int high,vector<int>& dp){
        if(high < low) return 0;
        if(high == low) return nums[low];
        if(dp[high]!= -1) return dp[high];

        //include
        int include = nums[high] + solve(nums,low,high-2,dp);
        //exclude
        int exclude = 0 + solve(nums,low,high-1,dp);

        return dp[high] = max(include,exclude);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        //size > 2
        vector<int> dp(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        int low1 = 0;
        int high1 = nums.size()-2;
        int low2 = 1;
        int high2 = nums.size()-1;
        return max(solve(nums,low1,high1,dp),solve(nums,low2,high2,dp2));
    }
};
```

<https://leetcode.com/problems/house-robber-iii/>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,unordered_map<TreeNode*,int> &dp){
        if(root == NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];

        int include = 0;
        int exclude = 0;
        //include 
        include = root->val;
        if(root->left) include += solve(root->left->left,dp) + solve(root->left->right,dp);
        if(root->right) include += solve(root->right->left,dp) + solve(root->right->right,dp);

        //exclude
        exclude = solve(root->left,dp) + solve(root->right,dp);
        return dp[root] = max(include,exclude);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root,dp);
    }
};
```

### Unique BST ii Leetcode

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> solve(int start,int end){
        if(start > end) {
            return {NULL};
        }
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left =  solve(start,i-1);
            vector<TreeNode*> right = solve(i+1,end);

            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.emplace_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return solve(1,n); 
    }
};
```

```cpp
class Solution {
public:
    
    vector<TreeNode*> solve(int start,int end, vector<vector<vector<TreeNode* > > > &dp){
        if(start > end) {
            return {NULL};
        }
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        if(dp[start][end].size()) return dp[start][end];

        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left =  solve(start,i-1,dp);
            vector<TreeNode*> right = solve(i+1,end,dp);

            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.emplace_back(root);
                }
            }
        }
        return dp[start][end] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        vector<vector<vector<TreeNode* > > > dp(n+1, vector<vector<TreeNode*> > (n+1));
        return solve(1,n,dp); 
    }
};
```

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>,vector<TreeNode*> > dp;
    vector<TreeNode*> solve2(int start,int end){
        if(start > end) {
            return {NULL};
        }
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        if(dp.find({start,end})!=dp.end())return dp[{start,end}];

        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left =  solve2(start,i-1);
            vector<TreeNode*> right = solve2(i+1,end);

            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.emplace_back(root);
                }
            }
        }
        return dp[{start,end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return solve2(1,n);
    }
};
```

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

### Partition Array for Maximum Sum

<https://leetcode.com/problems/partition-array-for-maximum-sum/description/>

```cpp
class Solution {
public:
    int solve(vector<int> &arr,int &k,int &n,int index,vector<int> &dp){
        if(index >= n) return 0;
        if(dp[index]!= -1) return dp[index];

        int maxi = INT_MIN;
        int ans = 0;
        for(int i=index; i < min(n,index+k); i++ ){
            maxi = max(maxi,arr[i]);
            int sum = maxi * (i-index+1) + solve(arr,k,n,i+1,dp);
            ans = max(ans,sum);
        }
        return dp[index] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(arr.size()+1,-1);
        return solve(arr,k,n,0,dp);
    }
};
```
