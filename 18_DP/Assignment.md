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

<https://leetcode.com/problems/stone-game/description/>

```cpp
class Solution {
public:
    bool solve(vector<int>&piles,int start,int end,int alice,int bob,vector<vector<int> > &dp){
        if(start > end) {
            return alice > bob;
        }
        if(dp[start][end]!=-1) return dp[start][end];
        
        if((end-start)&1) {
            //bob turn
            //first and then last chosing
            return dp[start][end] = solve(piles,start+1,end,alice,bob+piles[start],dp) | solve(piles,start,end-1,alice,bob+piles[end],dp);
        } else {
            // alice turn
            //first and then last chosing
            return dp[start][end] = solve(piles,start+1,end,alice+piles[start],bob,dp) | solve(piles,start,end-1,alice+piles[end],bob,dp);
        }
    }
    bool stoneGame(vector<int>& piles) {
        vector< vector<int> > dp(piles.size()+1,vector<int> (piles.size()+1,-1));
        return solve(piles,0,piles.size()-1,0,0,dp);
    }
};
```

<https://leetcode.com/problems/stone-game-ii/>

```cpp
class Solution {
public:
    int Mysolve(vector<int>&piles,bool aliceTurn,int start,int M){
        if(start >= piles.size()) {
            return 0;
        }

        int total = 0;
        int ans = aliceTurn ? INT_MIN : INT_MAX;
        int n = piles.size();
        for(int x=start; x <  min( start + 2*M, n) ; x++){
            total += piles[x];
            if(aliceTurn){
                ans = max(ans,total + Mysolve(piles,!aliceTurn,x+1,max(x-start+1,M)));
            } else {
                ans = min(ans,Mysolve(piles,!aliceTurn,x+1,max(x-start+1,M)));
            }
        }
        return ans;
    }
    int solve(vector<int> &piles,int index,int M,int alice,vector<vector<vector<int> > >&dp){
        if(index >= piles.size()) {
            return 0;
        }
        if(dp[index][M][alice]!=-1) return dp[index][M][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
        for(int X=1;X<=2*M;X++){
            if(index+X-1 >= piles.size()) break;
            total += piles[index+X-1];
            if(alice){
                ans = max(ans,total + solve(piles,index+X,max(M,X),!alice,dp));
            } else {
                ans = min(ans,0 + solve(piles,index+X,max(M,X),!alice,dp));
            }
        }
        return dp[index][M][alice] = ans;
    }
    int stoneGameII(vector<int>& piles) {

        // return Mysolve(piles,true,0,1);
        vector< vector< vector<int> > > dp(piles.size()+1,vector<vector<int>> (piles.size()+1,vector<int> (2,-1)));
        return solve(piles,0,1,true,dp);
    }
};
```

<https://leetcode.com/problems/stone-game-iii/>

```cpp
class Solution {
public:
    int solve(vector<int>&stone,int index,vector<int>&dp){
        if(index >= stone.size()) {
            return 0;
        }
        if(dp[index]!=INT_MIN) return dp[index];
        int ans = INT_MIN;
        int total = 0;
        for(int x = 1;x<=3;x++){
            if(index+x-1 >= stone.size()) break;
            total += stone[x+index-1];
            ans = max(ans,total-solve(stone,x+index,dp));
        }
        return dp[index] = ans;
    }
    string stoneGameIII(vector<int>& stone) {
        vector<int> dp(stone.size(),INT_MIN);
        int ans =  solve(stone,0,dp);
        if(ans < 0) return "Bob";
        if(ans > 0) return "Alice";
        return "Tie";
    }
};
```

### Burst balloons Leetcode (Building recusion tree from bottom) IMP

<https://leetcode.com/problems/burst-balloons/>

```cpp
class Solution {
public:
    int solve(vector<int>& nums,int start,int end,vector<vector<int> > &dp){
        if(start > end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int coins = INT_MIN;
        for(int i=start;i<=end;i++){
            coins = max(coins,
                nums[start-1] * nums[i] * nums[end+1]
                + solve(nums,start,i-1,dp) + solve(nums,i+1,end,dp)
            );
        }
        return dp[start][end] = coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        return solve(nums,1,nums.size()-2,dp);
    }
};
```

## LIS / LCS Variants

### Intervleaving Strings Leetcode

<https://leetcode.com/problems/interleaving-string/>

```cpp
class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int> > > &dp){
        if(i >= s1.size() && j>=s2.size() && k>=s3.size()) return true;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool flag = false;
        if( i<s1.size() && s1[i] == s3[k]){
            flag = flag | solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if( j<s2.size() && s2[j] == s3[k]){
            flag = flag | solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j][k] = flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector< vector< vector<int> > > dp(s1.size()+1,vector< vector<int> > (s2.size()+1, vector<int> (s3.size()+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
```

### Min Insertion steps to make a string palindrome Leetcode

<https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/>

```cpp
class Solution {
public:
     int t[501][501]; //0 to 500 index
    int solve(string &s,int i,int j){
        if(i>j)
        return 0;

        if(i==j)
        return 1;

        if(t[i][j]!=-1)
            return t[i][j];
        
        if(s[i]==s[j])
            return t[i][j] = 2 + solve(s,i+1,j-1);
        else
            return t[i][j] = max(solve(s,i+1,j),solve(s,i,j-1));

    }
    int longestPalindromeSubseq(string &s){
        memset(t,-1,sizeof(t));
        return solve(s,0,s.length()-1); 
    }
    int minInsertions(string s) {
        return (s.size() - longestPalindromeSubseq(s));
    }
};
```

### Russian Dolls Envelopes Leetcode

<https://leetcode.com/problems/russian-doll-envelopes/>

```cpp
class Solution {
public:
    int solveMem(vector<vector<int>> &nums,int prev,int curr,vector<vector<int>>&dp) {
        if(curr >= nums.size()) return 0;
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];
        int include = 0;
        int exclude = 0;
        if(prev == -1 || (nums[prev][0] < nums[curr][0] && nums[prev][1] < nums[curr][1])){
            include = 1 + solveMem(nums,curr,curr+1,dp);
            exclude = 0 + solveMem(nums,prev,curr+1,dp);
        } else {
            exclude = 0 + solveMem(nums,prev,curr+1,dp);
        }
        dp[prev+1][curr] = max(include,exclude);
        return dp[prev+1][curr];
    }
    int Optimal(vector<vector<int>> &arr) {
        if(arr.size() == 0) return 0;
        vector<int> ans;
        ans.push_back(arr[0][1]);  
        for(int i=1;i<arr.size();i++){
            if(arr[i][1] > ans.back()){
                //include
                ans.push_back(arr[i][1]);
            } else {
                //overwrite
                int index = lower_bound(ans.begin(),ans.end(),arr[i][1]) - ans.begin();
                // if(index == ans.size()) ans[index-2] = arr[i];
                // else ans[index] = arr[i];
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& nums) {
        // sort(nums.begin(),nums.end(),comp);
        // vector<vector<int> >dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        // return solveMem(nums,-1,0,dp);
        sort(nums.begin(),nums.end(),comp);
        return Optimal(nums);
    }
};
```

### Min Number of Removals to make Mountain Array Leetcode

### Make Array Strictly increasing Leetcode

### Largest Divisible Subset

<https://leetcode.com/problems/largest-divisible-subset/description/>

```cpp
class Solution {
public:
    // map<pair<int,int>,vector<int> > dp;
    // vector<int> solve(vector<int> &nums,int index,int prev,vector<int>&output){
    //     if(index >= nums.size()){
    //         //base case;
    //         return output;
    //     }
    //     if(dp.find({index,prev})!=dp.end()) dp[{index,prev}];

    //     // take case
    //     vector<int> take;
    //     vector<int> leave;
    //     if(output.size() == 0 || (nums[index]%prev==0)){
    //         output.emplace_back(nums[index]);
    //         take = solve(nums,index+1,nums[index],output);
    //         output.pop_back();
    //     }
    //     // leave case 
    //     leave = solve(nums,index+1,prev,output);
    //     return dp[{index,prev}] = take.size() > leave.size() ? take : leave;
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<int> output;
        // return solve(nums,0,-1,output);
        int n = nums.size();
        vector<int> count(n);
        vector<int> pre(n);
        // int[] pre = new int[n];
        // Arrays.sort(nums);
        sort(nums.begin(),nums.end());
        int maxi = 0, index = -1;
        for (int i = 0; i < n; i++) {
            count[i] = 1;
            pre[i] = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (1 + count[j] > count[i]) {
                        count[i] = count[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (count[i] > maxi) {
                maxi = count[i];
                index = i;
            }
        }
        // List<Integer> res = new ArrayList<>();
        vector<int> res;
        while (index != -1) {
            res.emplace_back(nums[index]);
            // res.add(nums[index]);
            index = pre[index];
        }
        return res;
    }
};
```

## Buy & Sell Stocks Variants [all 5 variants] Leetcode

### Best Time to Buy and Sell Stock

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock/>

```cpp
class Solution {
public:
    void maxProfitFinder(vector<int>&p , int i,int& minPrice, int& maxProfit){
        //base case
        if(i==p.size()){
            return;
        }

        //processing
        minPrice = min(minPrice,p[i]);
        int todayProfit = p[i] - minPrice;
        if(todayProfit>maxProfit){
            maxProfit = todayProfit;
        }
        //recursion call
        maxProfitFinder(p,i+1,minPrice,maxProfit);

    }
    int maxProfit(vector<int>& prices) {
        // int maxi = INT_MIN;
        // int mini = INT_MAX;
        // for(int i=0;i<prices.size();i++){
        //     if(mini>prices[i]){
        //         mini = prices[i];
        //     }
        //     else if(mini < prices[i]){
        //         if(maxi < prices[i]-mini){
        //             maxi = prices[i] - mini;
        //         }
        //     }
        // }
        // return maxi == INT_MIN ? 0 : maxi;

        /* recursivre solution */
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        maxProfitFinder(prices,0,minPrice,maxProfit);
        return maxProfit;
    }
};
```

### Best time to buy and sell stock II 

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/>

```cpp
class Solution {
public: 
    int solve(vector<int>&prices,int index,int buy,vector<vector<int> >&dp){
        //my thinking 
        if(index >= prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];

        if(buy){
            return dp[index][buy] = max(solve(prices,index+1,!buy,dp) - prices[index],solve(prices,index+1,buy,dp));
        } else {
            int sell = INT_MIN;
            for(int i=index;i<prices.size();i++)
                sell = max(sell,solve(prices,i+1,!buy,dp) + prices[i]);
            return dp[index][buy] = sell;
        }
    }
    int supreme(vector<int>&prices,int index,int buy,vector<vector<int> >&dp){
        //supreme logic
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1 )return dp[index][buy];

        int profit = 0;
        if(buy){
            //buy or ignore
            profit = max(supreme(prices,index+1,!buy,dp)-prices[index],supreme(prices,index+1,buy,dp));
        } else {
            //sell or ignore
            profit = max(supreme(prices,index+1,!buy,dp)+prices[index],supreme(prices,index+1,buy,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        // return solve(prices,0,true,dp);
        // int res = 0;
        // int n = prices.size();
        // for(int i = 0; i < n-1; i++) {
        //     res += max(0, prices[i+1] - prices[i] );
        // }
        // return res;
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        return supreme(prices,0,1,dp);
    }
};
```

### Best time to buy and sell stock III

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/>

```cpp
class Solution {
public:
    int supreme(vector<int>&prices,int index,int buy,int limit,vector<vector<vector<int>>>&dp){
        //supreme logic
        if(index >= prices.size() || limit == 0) return 0;

        if(dp[index][buy][limit] != -1 ) return dp[index][buy][limit];

        int profit = 0;
        if(buy){
            //buy or ignore
            profit = max(supreme(prices,index+1,!buy,limit,dp)-prices[index],supreme(prices,index+1,buy,limit,dp));
        } else {
            //sell or ignore
            profit = max(supreme(prices,index+1,!buy,limit-1,dp)+prices[index],supreme(prices,index+1,buy,limit,dp));
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int> (3,-1)));
        return supreme(prices,0,1,2,dp);
    }
};
```

### Best time to buy and sell stock IV

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1177124555/>

```cpp
class Solution {
public:
 int supreme(vector<int>&prices,int index,int buy,int limit,vector<vector<vector<int>>>&dp){
        //supreme logic
        if(index >= prices.size() || limit == 0) return 0;

        if(dp[index][buy][limit] != -1 ) return dp[index][buy][limit];

        int profit = 0;
        if(buy){
            //buy or ignore
            profit = max(supreme(prices,index+1,!buy,limit,dp)-prices[index],supreme(prices,index+1,buy,limit,dp));
        } else {
            //sell or ignore
            profit = max(supreme(prices,index+1,!buy,limit-1,dp)+prices[index],supreme(prices,index+1,buy,limit,dp));
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return supreme(prices,0,1,k,dp);
    }
};
```

### Best time to buy and sell stock V (Best Time to Buy and Sell Stock with Transaction Fee)

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/>

```cpp
class Solution {
public:
    int supreme(vector<int>&prices,int index,int buy,int &fee,vector<vector<int> >&dp){
        //supreme logic
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1 )return dp[index][buy];

        int profit = 0;
        if(buy){
            //buy or ignore
            profit = max(supreme(prices,index+1,!buy,fee,dp)-prices[index],supreme(prices,index+1,buy,fee,dp));
        } else {
            //sell or ignore
            profit = max(supreme(prices,index+1,!buy,fee,dp)+prices[index]-fee,supreme(prices,index+1,buy,fee,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        return supreme(prices,0,1,fee,dp);
    }
};
```

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