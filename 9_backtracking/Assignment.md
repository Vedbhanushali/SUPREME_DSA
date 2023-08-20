# Assignment

## Count inversion

<https://www.hackerrank.com/challenges/ctci-merge-sort/problem>

merge sort logic

```cpp
long merge(vector<int> &arr,vector<int> & temp,int start,int mid,int end){
    int i = start;
    int j = mid+1;
    int k = start;
    long c = 0;
    while(i<=mid && j<=end){ 
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            c += mid - i + 1;
        }
    }
    while(i<=mid ){ 
        temp[k++] = arr[i++];
    }   
    while(j<=end ){ 
        temp[k++] = arr[j++];
    }
    while(start <= end){
        arr[start] = temp[start];
        start++;
    }
    return c;
}
long mergeSort(vector<int>& arr,vector<int>& temp,int start,int end){
    if(start>= end){
        return 0;
    }
    int mid = start + (end - start)/2;
    long c = 0;
    c += mergeSort(arr,temp,start,mid); 
    c += mergeSort(arr,temp,mid+1,end);
    c += merge(arr,temp,start,mid,end);
    return c;
}
long countInversions(vector<int> arr) {
    long c = 0;
    vector<int> temp(arr.size(),0);
    c = mergeSort(arr,temp,0,arr.size()-1);
    return c;
}
```

## Max sub array sum

<https://leetcode.com/problems/maximum-subarray/>

```cpp
class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int maxi = INT_MIN;
    //     int current = 0;
    //     int s = 0;
    //     vector<int> subarr;
    //     for(int i=0;i<nums.size();i++){
    //         current += nums[i];
    //         if(current > maxi){
    //             maxi = current;
    //             subarr.clear();
    //             subarr.emplace_back(s);
    //             subarr.emplace_back(i);
    //         } if(current < 0){
    //             s = i + 1;
    //             current = 0;
    //         }
    //     }
    //     return maxi;
    // }
    
    int maxSubArrayRE(vector<int>& nums,int s,int e){
        if(s == e) return nums[s];

        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;
        
        int mid = s + (e-s) / 2;
        int maxLeftSum =  maxSubArrayRE(nums,s,mid);
        int maxRightSum = maxSubArrayRE(nums,mid+1,e);

        int leftBorderSum = 0,rightBorderSum = 0;
        for(int i = mid ; i>=s ;i--){
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }
        for(int i = mid+1 ; i<=e ;i++){
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum , max(maxRightSum,crossBorderSum));
    }
    int maxSubArray(vector<int>& nums){
        /* Approach - 1 */
        // return maxSubArrayRE(nums,0,nums.size()-1);


        /* Approach - 2 */
        // kadane's algorith
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i<nums.size() ;i++){
            sum = sum + nums[i];

            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};
```

## Combination sum

<https://leetcode.com/problems/combination-sum/>

```cpp
class Solution {
public:
    void combRE(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &v,int index){
        //base case
        if(target == 0 ){
            //ans is met
            ans.emplace_back(v);
            return;
        }
        if(target < 0){
            //answer not possible
            return;
        }

        for(int i = index;i<candidates.size();i++){
            v.emplace_back(candidates[i]);
            combRE(candidates,target-candidates[i],ans,v,i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combRE(candidates,target,ans,v,0);
        return ans;
    }
};
```

## Combination sum II

<https://leetcode.com/problems/combination-sum-ii/>

```cpp
class Solution {
public:
    void combRE(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &v,int index){
        //base case
        if(target == 0 ){
            //ans is met
            ans.emplace_back(v);
            return;
        }
        if(target < 0){
            //answer not possible
            return;
        }

        for(int i = index;i<candidates.size();i++){
            //to remove the scenario of getting same value but different index value creating duplicate answers
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            
            v.emplace_back(candidates[i]);
            combRE(candidates,target-candidates[i],ans,v,i+1); // for removing same element again and again changed index i to i+1
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sorting because answer is in sorted format
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combRE(candidates,target,ans,v,0);
        return ans;
    }
};
```

## permutation II

<https://leetcode.com/problems/permutations-ii/>

```cpp
class Solution {
public:
    // void permuteRE(vector<int>& nums,set<vector<int>> &ans,int i,int &N){
    //     if(i>=N-1){
    //         // ans.emplace_back(nums);
    //         ans.insert(nums);
    //         // for(auto i : nums){
    //         //     cout<<" "<<i;
    //         // }cout<<endl;
    //         return;
    //     }

    //     //recursive call
    //     for(int j = i ; j <N ;j++){
    //         swap(nums[i],nums[j]);
    //         //recursive call
    //         permuteRE(nums,ans,i+1,N);
    //         //backtracking
    //         swap(nums[i],nums[j]);
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     set<vector<int>> hashAns;
    //     int i = 0;
    //     int j = 0;
    //     int N = nums.size();
    //     permuteRE(nums,hashAns,i,N);
    //     for(auto i:hashAns){
    //         ans.emplace_back(i);
    //     }
    //     return ans;    
    // }

    void permuteRE(vector<int>& nums,vector<vector<int>> &ans,int i,int &N){
        if(i>=N-1){
            ans.emplace_back(nums);
            // ans.insert(nums);
            return;
        }

        //recursive call
        unordered_set<int> hashSet;
        for(int j = i ; j <N ;j++){
            if(hashSet.find(nums[j])!=hashSet.end()) continue;
            else hashSet.insert(nums[j]);
            swap(nums[i],nums[j]);
            //recursive call
            permuteRE(nums,ans,i+1,N);
            //backtracking
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int N = nums.size();
        vector<vector<int>> ans;
        // vector<vector<int>> hashAns;
        int i = 0;
        int j = 0;
        // int N1 = nums.size();
        permuteRE(nums,ans,i,N);
        return ans;    
    }
};
```

## Beautiful Arrangment

<https://leetcode.com/problems/beautiful-arrangement/>

```cpp
class Solution {
public:
    void countRE(vector<int> &v,int &n,int &ans,int currNum){
        //base case
        if(currNum >= n+1){
            //printing values
            // for(auto i:v) cout<<i;
            // cout<<endl;
            //pf
            ++ans;
            return;
        }

        for(int i = 1;i<=n;i++){
            if(v[i]==0 && ((currNum%i==0)||(i%currNum==0))){
                v[i] = currNum;
                countRE(v,n,ans,currNum+1);
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n+1);
        int ans = 0;
        countRE(v,n,ans,1);
        return ans;
    }
};
```

## Distribution repeating integers

<https://leetcode.com/problems/distribute-repeating-integers/>

```cpp
class Solution {
public:
    bool disRE(vector<int> &counts,vector<int> &quantity,int ithcustomer){
        //base case
        if(ithcustomer >= quantity.size()){
            return true;
        }

        for(int i = 0;i<counts.size();++i){
            if(quantity[ithcustomer] <= counts[i]){
                counts[i] -= quantity[ithcustomer];
                if(disRE(counts,quantity,ithcustomer+1)){
                    return true;
                } 
                counts[i] += quantity[ithcustomer];
            }
        }
        return false;

    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {   
        unordered_map<int,int> countMap;
        for(int i = 0;i<nums.size();i++){
            countMap[nums[i]]++;
        }
        vector<int> counts;
        for(auto i:countMap){
            counts.emplace_back(i.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        // sort(counts.rbegin(),counts.rend());
        return disRE(counts,quantity,0);
    }
};
```
