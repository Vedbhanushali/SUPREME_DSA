# Dynamic Programming

what is already calculate no need to calculate again

## approaches

- top down (recursion + memoization)
- bottom up (tabulation)
- space optimization

## when to apply DP

overlapping subproblems and optimal substructure (bigger problem solved using smaller optimal problems)

## TOP DOWN (Memoization)

1. create dp array (n) size
2. store ans in dp and return dp as answer
3. after base case write if ans already calculated in dp then return direct answer.

## BOTTOM UP (Tabulation)

1. create dp array
2. observe base case and store it in DP
3. unlike top down will start from bottom that is will go from 0 to n instead of n to 0 in iterative way

## Space optimization

- can be applied to some problems
- approach is optimization of bottom up approach

## 1D DP and 2D DP

D here is dimensions of DP array used

## Fibonacci

```cpp
int recSolve(int n){
    //base case
    if(n == 0 || n == 1){
        return n;
    }
    int ans = recSolve(n-1) + recSolve(n-1);
}
//recursion + memoization
int topDownSolve(int n,vector<int>&dp){
    if(n == 1 || n == 0) return n;
    //step 3 check if and already exist
    if(dp[n] != -1){
        return dp[n];
    }
    //step 2 replace and with dp
    dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
    return dp[n];
}
// bottom up approach Tabulation method
int bottomUpSolve(int n){
    //step1 create DP array
    if(n ==0 || n==1) return n;
    vector<int> dp(n+1,-1);
    //step2 observe base case in above solution
    dp[0] = 0;
    dp[1] = 1;
    //step3 bottom 2 to top n (0 and 1 are base case so not to include)
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
//space optimization
//here we need only past two values to no need to store whole array in bottom approach
int spaceOptSolve(int n){
    if(n ==0 || n==1) return n;
    int prev1 = 0;
    int prev2 = 1;
    int curr;
    for(int i=2;i<=n;i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}
int fib(int n){
    // int ans = recSolve(n);
    // return ans;

    // DP solution
    //step 1 create dp array
    //here n goes from 0 to n (n+1)size dp
    vector<int> dp(n+1,-1);
    int ans = topDownSolve(n,dp);
}
```

## Coin change

<https://leetcode.com/problems/coin-change/>

Recursion solution

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int ans = INT_MIN;
        for(int i=0;i<coins.size();i++){
            if(amount - coins[i] >= 0){
                int subAns = coinChange(coins,amount-coins[i]);
                ans = min(ans,subAns+1);
            }
        }
        return ans;
    }
};
```

DP solution

```cpp
class Solution {
public:
    int solve(vector<int>& coins,int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i]);
            if(ans!=INT_MAX)
                mini = min(mini,ans+1);    
        }
        return mini;
    }
    int solveMem(vector<int>&coins,int amount,vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveMem(coins,amount-coins[i],dp);
            if(ans!=INT_MAX)
                mini = min(mini,ans+1);    
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int solveTab(vector<int>& coins,int amount){
        if(amount == 0) return 0;
        vector<int> dp(amount+1,INT_MAX); //storing minimum coins  required to get ith dp value
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                int ans = INT_MAX;
                if(i-coins[j] >= 0 && dp[i-coins[j]]!=INT_MAX){
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i],1+ans);   
                }
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins,amount);
        // return ans == INT_MAX ? -1 : ans;

        // vector<int> dp(amount+1,-1);
        // int ans = solveMem(coins,amount,dp);
        // return ans == INT_MAX ? -1 : ans;

        int ans = solveTab(coins,amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## house robber

<https://leetcode.com/problems/house-robber/description/>

```cpp
 class Solution {
public:
    //n zero based indexing (4 house 0,1,2,3)
    int solveRec(vector<int>& nums,int n){
        if(n < 0){
            return 0;
        }
        if (n == 0){
            return nums[0];
        }
        
        //include
        int include = solveRec(nums,n-2) + nums[n];
        //exclude 
        int exclude = solveRec(nums,n-1) + 0;

        return max(include,exclude);
    }
    int solveMem(vector<int>& nums,int n,vector<int>&dp){
        if(n < 0){
            return 0;
        }
        if (n == 0){
            return nums[0];
        }
        if(dp[n]!=-1) return dp[n];
        
        //include
        int include = solveMem(nums,n-2,dp) + nums[n];
        //exclude 
        int exclude = solveMem(nums,n-1,dp) + 0;

        dp[n] = max(include,exclude);
        return dp[n];
    }
    int solveTab(vector<int>& nums,int n){ //4 -3
        if(n == 0) return nums[0];
        vector<int> dp(n+1,0); //finding maxi so init with 0
        dp[0] = nums[0];
        for(int i=1;i<=n;i++){
            int temp = 0;
            if(i-2 >= 0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1] + 0;
            dp[i] = max(include,exclude);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        
        // return solveRec(nums,nums.size()-1);

        // vector<int> dp(nums.size()+1,-1);
        // return solveMem(nums,nums.size()-1,dp);

        return solveTab(nums,nums.size()-1);
    }
};
```

## Painting Fence

the problem states that there are n fences which can be coloured with one of k colours in such a way that not more than two adjacent fences have the same colour.  
formula is ```f(n) = (f(n-1) *f(n-2))*(k-1);```

```cpp
int solveRec(int n,int &k){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k* k; //k(same) + k* (k-1) (diff)
    }
    if(dp[n] != -1) return dp[n];

    dp[n] = (solveRec(n-1,k) * solveRec(n-2,k))*(k-1);
    return dp[n];
}
int solveMem(int n,int &k,vector<int>& dp){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k* k; //k(same) + k* (k-1) (diff)
    }

    int ans = (solveMem(n-1,k) * solveMem(n-2,k))*(k-1);
    return ans;
}
int solveTab(int n,int &k){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k* k; //k(same) + k* (k-1) (diff)
    }
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = k*k;
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1]*dp[i-2])*(k-1);
    }
    return dp[n];
}
int spaceOpt(int n,int &k){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k* k; //k(same) + k* (k-1) (diff)
    }
    int prev1 = k;
    int prev2 = k*k;
    int curr = 0;
    for(int i=3;i<=n;i++){
        curr = (prev1*prev2)*(k-1);
        //yaha hi galti hoti hai
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;

}
int main(){
    int n = 4;
    int k = 3;
    int ans = solveRec(n,k);
    vector<int> dp(n+1,-1);
    int ans1 = solveMem(n,k);
    return 0;
}
```

## 0/1 knapsack problem - 2D DP problem

problem - given a set of n items numbered from 1 to n each with wieght wi and value vi along with a maximum weight capacity W. maximize the sum of the values of the items in knapsack so that the sum of the weigths is less than or equal to the knapsack's capacity.

same pattern (TODO)

- subset sum
- equal subset sum partition
- min subset sum difference

```cpp
// index of last element
int solveRec(vector<int>&weight,vector<int> &value,int index,int &W ){
    //base case
    if(index == 0){
        if(weight[0] <= W)
            return value[0];
        else 
            return 0;
    }

    //include
    int include = 0;
    if(value[index] <=W ){
        include = value[index] + solveRec(weight,value,index-1,W-weight[index]);
    }
    //exclude
    int exclude = 0 + solveRec(weight,value,index-1,W);
    return max(include,exclude);
}
int solveMem(vector<int>&weight,vector<int> &value,int index,int &W,vector<vector<int>>&dp ){
    //base case
    if(index == 0){
        if(weight[0] <= W)
            return value[0];
        else 
            return 0;
    }
    if(dp[index][W] != -1){
        return dp[index][W];
    }
    //include
    int include = 0;
    if(weight[index] <=W ){
        include = value[index] + solveMem(weight,value,index-1,W-weight[index],dp);
    }
    //exclude
    int exclude = 0 + solveMem(weight,value,index-1,W,dp);
    dp[index][W] = max(include,exclude);
    return dp[index][W];
}
int solveTab(vector<int>&weight,vector<int> &value,int n,int &capacity){
    // TIMESTAMP:01:25:08
    vector<vector<int>> dp(n,vector<int> (capacity+1,0));
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        } else {
            dp[0][w] = 0;
        } 
    }
     
    for(int index=1;index<n;index++){
        for(int wt = 0; wt<= capcity; wt++){
            //include
            int include = 0;
            if(weight[index] <= wt){
                include = value[index] + dp[index-1][wt-weight[index]]
            }
            //exclude
            int exclude = 0 + dp[index-1][wt];
            dp[index][wt] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}
int spaceOpt(vector<int>&weight,vector<int> &value,int n,int &capacity){
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);

    for(int w=weight[0];w<=capacity;w++){
        if(weight[0] <= capacity){
            prev[w] = value[0];
        } else {
            prev[w] = 0;
        } 
    }
     
    for(int index=1;index<n;index++){
        for(int wt = 0; wt<= capcity; wt++){
            //include
            int include = 0;
            if(weight[index] <= wt){
                include = value[index] + prev[wt-weight[index]]
            }
            //exclude
            int exclude = 0 + prev[wt];
            curr[wt] = max(include,exclude);

        }
        //shift yahi galti hoti hai
        //shift sabhi capacity calculate ho jay bade main karni hai
        prev = curr;
    }
    return prev[capacity];
}

int spaceOpt2(vector<int>&weight,vector<int> &value,int n,int &capacity){
    vector<int> curr(capacity+1,0);

    for(int w=weight[0];w<=capacity;w++){
        if(weight[0] <= capacity){
            curr[w] = value[0];
        } else {
            curr[w] = 0;
        } 
    }
     
    for(int index=1;index<n;index++){
        //ulta chalna hai right to left,
        //left to right jayengo to left ki value override jo jaygi.
        for(int wt = capcity;wt>=0; wt--){
            //include
            int include = 0;
            if(weight[index] <= wt){
                include = value[index] + curr[wt-weight[index]]
            }
            //exclude
            int exclude = 0 + curr[wt];
            curr[wt] = max(include,exclude);

        }
    }
    return curr[capacity];
}
int main(){
    vector<int> weight= {4,5,1};
    vector<int> value = {1,2,3};
    int n = 3;
    int capacity = 4;

    // int ans = solveRec(weight,value,n-1,capacity);

    // vector<vector<int>> dp(n,vector<int> (capacity+1,-1));
    // int ans = solveMem(weight,value,n-1,dp);

    int ans = solveTab(weight,value,n);
    return 0;
}
```

## Partition equal subset sum

<https://leetcode.com/problems/partition-equal-subset-sum/>

```cpp
class Solution {
public:
    bool solveRec(int index,vector<int>&nums,int target){
        //base case
        int n = nums.size();
        if(index >= n ){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }

        int include = solveRec(index+1,nums,target-nums[index]);
        int exclude = solveRec(index+1,nums,target);
        return (include || exclude);
    }
     bool solveMem(int index,vector<int>&nums,int target, vector<vector<int>> &dp){
        //base case
        int n = nums.size();
        if(index >= n ){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int include = solveMem(index+1,nums,target-nums[index],dp);
        int exclude = solveMem(index+1,nums,target,dp);
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }
    bool solveTab(vector<int>&nums,int &target){
        vector<vector<bool> > dp(nums.size()+1,vector<bool>(target+1,0));
        for(int i = 0;i<nums.size();i++){
            dp[i][0] = 1;
        }

        for(int i = nums.size()-1; i >= 0;i--){
            for(int j = 1;j<=target;j++){
                bool include = 0;
                if(j-nums[i]>=0)
                    include = dp[i+1][j-nums[i]];
                bool exclude = dp[i+1][j];
                dp[i][j] = (include || exclude);
            }
        }
        return dp[0][target];
    }
    bool spaceOpt(vector<int>&nums,int &target){
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0] = 1;
        for(int i = nums.size()-1; i >= 0;i--){
            for(int j = 1;j<=target;j++){
                bool include = 0;
                if(j-nums[i]>=0)
                    include = prev[j-nums[i]];
                bool exclude = prev[j];
                curr[j] = (include || exclude);
            }
            //shift yahi galiti hotit hai
            prev = curr;
        }
        return curr[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        //yaha galti hogi
        if(sum & 1){
            return false;
        }
        int target = sum/2;

        // bool ans = solveRec(0,nums,target);
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // bool ans = solveTab(0,nums,target,dp);
        // int ans = solveTab(nums,target);
        int ans = spaceOpt(nums,target);
        return ans;
    }
};
```

## Number of dice roll with target

<https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/>

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;
    int solveRec(int n,int k,int target){
        //base
        if (n<0 || target < 0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            //rolling all dice ans saving its ans if ans found as 1 else 0
            ans = ans + solveRec(n-1,k,target-i);
        }
        return ans;
    }
    int solveMem(int n,int k,int target,vector<vector<int> > &dp){
        //base
        if (n<0 || target < 0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            //rolling all dice ans saving its ans if ans found as 1 else 0
            // ans = ans + solveMem(n-1,k,target-i);
           ans = (ans%MOD + solveMem(n-1,k,target-i,dp)%MOD)%MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }
    int solveTab(int n,int k,int target){
        vector<vector<long long int>> dp(n+1,vector<long long int> (target+1,0)); 
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int t = 1;t<=target;t++){    

                long long int ans = 0;
                for(int j=1;j<=k;j++){
                    //rolling all dice ans saving its ans if ans found as 1 else 0
                    // ans = ans + solveMem(n-1,k,target-i);
                    // ans = (ans%MOD + solveMem(n-1,k,target-i,dp)%MOD)%MOD;
                    long long int temp = 0;
                    if(t - j >= 0){
                        temp = dp[i-1][t-j];
                    }
                    ans = (ans % MOD + temp % MOD) % MOD;
                }
                dp[i][t] = ans;
            }
        }
        return dp[n][target];
        
    }
    int spaceOpt(int n,int k,int target){
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            for(int t = 1;t<=target;t++){    

                long long int ans = 0;
                for(int j=1;j<=k;j++){
                    //rolling all dice ans saving its ans if ans found as 1 else 0
                    // ans = ans + solveMem(n-1,k,target-i);
                    // ans = (ans%MOD + solveMem(n-1,k,target-i,dp)%MOD)%MOD;
                    long long int temp = 0;
                    if(t - j >= 0){
                        temp = prev[t-j];
                    }
                    ans = (ans % MOD + temp % MOD) % MOD;
                }
                curr[t] = ans;
            }
            //shift
            prev = curr;
        }
        return prev[target];
        
    }
    int numRollsToTarget(int n, int k, int target) {

        // int ans = solveRec(n,k,target);

        // vector<vector<int>> dp(n+1,vector<int> (target+1,-1)); 
        // int ans = solveMem(n,k,target,dp);

        // int ans = solveTab(n,k,target);
        int ans = spaceOpt(n,k,target);
        return ans;
    }
};
```

## minimum swaps to make sequence increasing

TODO

## Guess number higher or lower II

<https://leetcode.com/problems/guess-number-higher-or-lower-ii/>

```cpp
class Solution {
public:
    int solveRec(int start,int end){
        if(start >= end) return 0;

        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans, i + max(solveRec(start,i-1),solveRec(i+1,end)));
        }
        return ans;
    }
    int solveMem(int start,int end,vector<vector<int> > & dp){
        if(start >= end) return 0;
        if(dp[start][end] != -1 )return dp[start][end];

        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans, i + max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }
    int solveTab(int n){
        if(n == 1) return 0;
        vector<vector<int> > dp(n+2,vector<int> (n+2,0));
        for(int start = n;start>=1;start--){
            for(int end = 0;end <=n; end++){
                if(start >= end) continue;
                int ans = INT_MAX;
                for(int i=start;i<=end;i++){
                    ans = min(ans, i + max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end] = ans;

            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // int ans = solveRec(1,n);
        // return ans;
        // vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        // int ans = solveMem(1,n,dp);
        int ans = solveTab(n);
        return ans;
    }

};
```

## Minimum cost tree from leaf values

<https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/>

```cpp
class Solution {
public:
    int solveRec(vector<int>& arr,map < pair<int,int>, int>& maxi,int left,int right){
        if(left == right){
            return 0; //leaf node
        }
        int ans = INT_MAX;
        for(int i = left;i<right;i++){
            ans = min(ans,
            maxi[{left,i}] * maxi[{i+1,right}] + 
            solveRec(arr,maxi,left,i) +
            solveRec(arr,maxi,i+1,right)
            );
        }
        return ans;
    }
    int solveMem(vector<int>& arr,map < pair<int,int>, int>& maxi,int left,int right,vector<vector<int> > &dp){
        if(left >= right){
            return 0; //leaf node
        }
        if(dp[left][right] != -1) return dp[left][right];
        int ans = INT_MAX;
        for(int i = left;i<right;i++){
            ans = min(ans,
            maxi[{left,i}] * maxi[{i+1,right}] + 
            solveMem(arr,maxi,left,i,dp) +
            solveMem(arr,maxi,i+1,right,dp)
            );
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int solveTab(vector<int>& arr,map < pair<int,int>, int>& maxi){
        int n = arr.size();
        vector<vector<int> > dp(n+1,vector<int> (n+1,0));
        for(int left = n - 1;left >= 0 ; left--){
            for(int right = left + 1;right <= n-1 ; right++){
                if(left >= right) continue;
                int ans = INT_MAX;
                for(int i = left;i<right;i++){
                    ans = min(ans,
                    maxi[{left,i}] * maxi[{i+1,right}] + 
                    dp[left][i] +
                    dp[i+1][right]
                    );
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map < pair<int,int>, int> maxi;
        //pre computation of maxi in range left,right
        int n = arr.size();
        for(int i=0;i<n;i++) {
            maxi[{i,i}] = arr[i];
            for(int j = i+1;j<n;j++){
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }
        // int ans = solveRec(arr,maxi,0,n-1);
        // vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        // int ans = solveMem(arr,maxi,0,n-1,dp);
        int ans = solveTab(arr,maxi);
        return ans;
    }
};
```

## Unique binary search tree

TODO
