# Practice Questions

## Last occurrence of a char

```cpp
void lastOccurrenceOfChar(string& s,char x,int i,int &ans){
    if(i >= s.size()) return;

    if(s[i] == x){
        ans = i;
    }

    lastOccurrenceOfChar(s,x,i+1,ans);
}
//driver code
char x= 'A';
string str = "BCADSA";
char ans;
lastOccurrenceOfChar(str,x,0,ans);
cout<<ans;
```

## Reverse a string RE

```cpp
void reverseString(string &s,int i,int j){
    if(i >= j) return;
    swap(s[i],s[j]);
    reverseString(s,i+1,j-1);
}
//driver code
string str = "asdf";
reverseString(s,0,str.size()-1);
```

## Add string RE

<https://leetcode.com/problems/add-strings/>

```cpp
class Solution {
public:
    void solve(string& s1,string& s2,int p1,int p2,int &carry,string& ans){
        //base case
        if(p1<0 && p2<0){
            if(carry!=0){
                ans.push_back((carry+'0'));
            }
            return;
        }

        //processing
        int n1 = (p1<0) ? 0 : s1[p1]-'0';
        int n2 = (p2<0) ? 0 : s2[p2]-'0';
        int a = n1 + n2 + carry;
        carry = a / 10;
        a = a %10;
        ans.push_back((a+'0'));

        //recursion
        solve(s1,s2,p1-1,p2-1,carry,ans);
    }
    string addStrings(string num1, string num2) {
        //using recursion we will solve
        string ans="";
        int carry = 0;
        solve(num1,num2,num1.size()-1,num2.size()-1,carry,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

## palindrome check RE

```cpp
bool isPalindrome(string &s,int i,int j){
    if(i>=j) return true;

    if(s[i]!=s[j]) return false;

    return isPalindrome(s,i+1,j-1);
}
//driver code
cout<<isPalindrome(str,0,str.size()-1);
```

## Remove all occurrence of substring

<https://leetcode.com/problems/remove-all-occurrences-of-a-substring/>

```cpp
class Solution {
public:
    void solve(string &s,string& part){
        int found = s.find(part);
        if(found!=string::npos){
            string leftPart = s.substr(0,found);
            string rightPart = s.substr(found+part.size(),s.size()-found-part.size());
            s=leftPart + rightPart;
            solve(s,part);
        } else {
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        // int pos = s.find(part);
        // while(pos != string::npos){
        //     s.erase(pos,part.length());
        //     pos = s.find(part);
        // }
        // return s;
        
        /* recursive solution */
        solve(s,part);
        return s;
    }
};
```

## print all subarrays using RE

```cpp
void printSubarrays(vector<int> &nums,int start,int end){
    if(end == nums.size()) return;

    for(int i = start;i<= end;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;

    printSubarrays(nums,start,end+1);
}
void printSub(vector<int>&nums){
    for(int i = 0;i<nums.size();i++){
        printSubarrays(nums,i,i);
    }
}
int main(){
    vector<int> nums{1,2,3,5};
    printSub(nums);
    return 0;
}
```

## Buy and sell stocks

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

## House Robber - TODO Optimization

<https://leetcode.com/problems/house-robber/>

```cpp
class Solution {
public:
    int robRE(vector<int>& nums,int i){
        //base case
        if(i>=nums.size()){
            return 0; //can't rob the house
        }

        //logic
        //rob current house and check rest after leaving one position
        int n1 = nums[i] + robRE(nums,i+2);
        //leave this house and starting robing next house
        int n2 = 0 + robRE(nums,i+1);

        return max(n1,n2);
    }
    int rob(vector<int>& nums) {
        int i = 0;
        return robRE(nums,i);
        // still not optimization is need - DP
    }
};
```

## Integer to English words

<https://leetcode.com/problems/integer-to-english-words/>

```cpp
class Solution {
public:
    //global vector
    vector<pair<int,string> > mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000,
"Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80,
"Eighty"}, {70,
"Seventy"}, {60,
"Sixty"}
, {50,"Fifty"}, {40,
"Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18,
"Eighteen"}, {17,
"Seventeen"}, {16,
"Sixteen"}, {15,
"Fifteen"}, {14,
"Fourteen"},{13,
"Thirteen"}, {12,
"Twelve"}, {11,
"Eleven"}, {10, "Ten"}, {9, "Nine"}, {8,
"Eight"}, {7,
"Seven"}, {6, "Six"}, {5,
"Five"}, {4,
"Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

    string numberToWords(int num) {
        //base case
        if(num == 0){
            return "Zero";
        }

        //search in mp just greater than i
        for(int i=0;i<mp.size();i++){
            if(num>=mp[i].first){
                string a = "";
                if(num>=100){
                    a = numberToWords(num/mp[i].first) + " ";
                }
                string b = mp[i].second;
                string c = "";
                if(num%mp[i].first!=0){
                    c = " "+numberToWords(num%mp[i].first);
                } 
                return a + b + c;
            }
        }
        return "";
    }
};
```

## Wild card Matching - TODO Optimization

<https://leetcode.com/problems/wildcard-matching/>

```cpp
class Solution {
public:
    bool matchRE(string &s,int si,string &p,int pi){
        //base case
        if(si==s.size() && pi==p.size()){ //all characters are matched
            return true;
        }
        if(si==s.size() && pi<p.size()){ //s over but p still have characters
            // while(p[pi]=='*'){
            //     pi++;
            // }
            // if(pi==p.size()){
            //     return true;
            // } else {
            //     return false;
            // }
            while(pi <p.size()){
                if(p[pi] != '*') return false;
                pi++;
            }
            return true;
        }
        //normal case for recursion
        if(s[si]==p[pi] || p[pi]=='?'){
            return matchRE(s,si+1,p,pi+1);
        }
        if(p[pi]=='*'){ //encount *
            bool case1 = matchRE(s,si,p,pi+1); //considering * as null
            bool case2 = matchRE(s,si+1,p,pi); //let * consume one character
            return case1 || case2;
        } 
        //it is else part match is not found    
        return false;

    }
    bool isMatch(string s, string p) {
        int si = 0;
        int pi = 0;
        return matchRE(s,si,p,pi);
    }
};
```

## Perfect squares

<https://leetcode.com/problems/perfect-squares/>

```cpp
class Solution {
public:
    int numSquaresRE(int n){
        //base case
        if(n==0) return 1; //ans found
        if(n<0) return 0; //trying to subtract bigger value so return not found

        int ans = INT_MAX;
        int maxPerfectSquare = sqrt(n);
        int i = 1;
        while(i<=maxPerfectSquare){
            int perfectSquare = i * i;
            int noOfPerfectSquareReq = numSquaresRE(n-perfectSquare) + 1;
            if(noOfPerfectSquareReq < ans){
                ans = noOfPerfectSquareReq;
            }
            i++;
        }
        return ans;
    }
    int numSquares(int n) {
        return numSquaresRE(n)-1;
    }
};
```

## Minimum cost for tickets

<https://leetcode.com/problems/minimum-cost-for-tickets/>

```cpp
class Solution {
public:
    int minCostRE(vector<int>& days, vector<int>& costs,int i) { //i is used for traversing days
        //base case
        //all days are completed
        if(i>=days.size()){
            return 0;
        }

        //cost to travel 1 day
        int cost1 = costs[0] + minCostRE(days,costs,i+1);

        //cost to travel 7 days
        
        int travelupto = days[i] + 7 - 1;
        int j = i;
        while(j<days.size() && days[j]<=travelupto){
            j++;
        }
        int cost7 = costs[1] + minCostRE(days,costs,j);

        //cost to travel 30 days
        travelupto = days[i] + 30 - 1;
        j = i;  
        while(j<days.size() && days[j]<=travelupto) { //order matters here j out of bound check first then access days[j]
            j++;
        }
        int cost30 = costs[2] + minCostRE(days,costs,j);

        return min(cost1 , min(cost7,cost30));
        // if(i>=days.size()) return 0;

        // int cost1 =  costs[0] + minCostRE(days,costs,i+1);

        // int j = i;
        // int passEndDay = days[i] + 7 - 1;
        
        // while(j<days.size() && days[j]<=passEndDay){
        //     j++;
        // }
        // int cost7 = costs[1] + minCostRE(days,costs,j);

        // j = i;
        // passEndDay = days[i] + 30 -1;
        
        // while(j<days.size() && days[j]<=passEndDay){
        //     j++;
        // }
        // int cost30 = costs[2] + minCostRE(days,costs,j);
        
        // return min(cost1,min(cost7,cost30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return minCostRE(days,costs,0);
    }
};
```

## Number of dice roll with target sum

<https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/>

```cpp
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        //base
        if(target < 0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            //rolling all dice ans saving its ans if ans found as 1 else 0
            ans = ans + numRollsToTarget(n-1,k,target-i);
        }
        return ans;
    }
};
```
