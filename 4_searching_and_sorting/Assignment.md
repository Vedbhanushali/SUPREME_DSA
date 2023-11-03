# Practice Questions

## K-Diff Pairs In An Array

nums - [...]  
nums[i] - nums[j] = k find pairs

1. two loops find pairs brute force O(n^2)

2. two pointers approach  
   sort and using two pointers one at start and one at end we can find move forward and backward respectively to find the pairs

   ```cpp
    sort(vect.begin(),vect.end())
    int i= 0; int j = vect.length() - 1;
    int ans = 0;
    while(i<j){
        if(vect[j]-vect[i] == k){
        ans++;
        i++;
        j--;
        } else if (vect[j]-vect[i] > k){
        //difference is greater so need to less it by increasing vect[i]
        i++;
        } else {
        j--;
        }
    }
    return ans;
   ```

3. using binary search

   sort  
   find the x for every element where  
   here arr[j] - arr[i] = k  
   so arr[j] = arr[i] + k  
   x = arr[i] + k; <-- need to find this number

   ```cpp
   sort(v.begin(),v.end())
   int ans = 0;
   for(auto i: arr){
    int target = k + i;
    ans += upper_bound(v.begin(),v.end(),target) - lower_bound(v.begin(),v.end,target);
   }
   return ans;
   ```

## Find K-Closest Element

<https://leetcode.com/problems/find-k-closest-elements/>

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

1. approach
   sort according to the difference of and return first k elements
2. two pointer approach
   first create the differenct array and by intution we find that where the difference is minimum there is range where all elements are present
   there are two method inside it one closing from outside and second expanding from middle

```c++
class Solution {
public:
    vector<int> sorting_approach(vector<int> arr, int k,int x){
        vector<pair<int,int> > my_vector;
        for(int i=0;i<arr.size();i++){
            my_vector.push_back({abs(arr[i]-x),arr[i]});
        }
        sort(my_vector.begin(),my_vector.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(my_vector[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> closing_bound(vector<int> arr, int k , int x){
        //two pointer approach
        int l =0;
        int h = arr.size()-1;
        while(h-l>=k){
            if(x- arr[l]>arr[h]-x){
                l++;
            } else {
                h--;
            }
        }
        return vector<int> (arr.begin()+l,arr.begin()+h+1);
    }
    int lowerBound(vector<int> arr,int x){
        int s =0;
        int e = arr.size()-1;
        int ans = e;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid]>=x){
                ans = mid;
                e = mid -1;
            } else if(arr[mid]>x){
                e = mid -1;
            } else {
                s = mid +1;
            }
        }
        return ans;
    }
    vector<int> expand_bound(vector<int> arr, int k, int x){
        //two pointer approach
        // int mini = INT_MAX;
        // int mini_index = -1;
        // for(int i=0;i<arr.size();i++){
        //     if(abs(arr[i]-x)<mini){
        //         mini = abs(arr[i] -x);
        //         mini_index = i;
        //     }
        // }
        int h = lowerBound(arr,x);
        int l = h -1;

        while(k--){
            if(l<0){
                h++;
            } else if(h>=arr.size()){
                l--;
            }
            else if(x-arr[l]>arr[h]-x){
                h++;
            } else {
                l--;
            }
        }
        return vector<int> (arr.begin()+l+1,arr.begin()+h);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //return sorting_approach(arr,k,x);
        //return closing_bound(arr,k,x);
        return expand_bound(arr,k,x);
    }
};
```

## Exponential Search & Unbounded

- improves binary search
- we divide the array into subarray and apply binary searh
- i is in power of 2 (1,2,4,8,16) so subarray are divided like
  [1,2] [2,4] [4,8] [8,16]...
- ans is between i/2 and i
- we go till as arr[i] >= x where i is in power of 2 and answer lie in range of [i/2 to i]

```cpp
int expsearch(int a[],int n,int x){
    if(a[0]==x) return 0;
    while(i<n && a[i]<=x){
        i = i*2;
    }
    return bs(a,i/2,min(i,n-1),x);
}
int bs(int arr[],int l,int h,int x){
    while(l<=e){
        int mid = l + (e-l)/2;
        int(a[mid]==x) return mid;
        else if(a[mid] < x) start = mid +1;
        else end = mid - 1;
    }
}
```

## Binary searching in infinite array

- application in searching in infinite array (unbound array)
- better than BS when x is smaller near beginning.

```cpp
while(1){
    if(arr[i]>x){
        break;
    } else if(a[i]==x){
        ans = a[i]; //incase ans is power of 2 and we already hit it we will return it directly
        return ans;
    } else {
        i = i*2;
    }
}
//now apply bs
 return bs(a,i/2,i,x);
```

## Book Allocation Problem

<https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1>

You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most books allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.

### approach

```cpp
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int A[],int N,int M,int sol){
        int pageSum = 0;
        int c = 1;
        for(int i=0;i<N;i++){
            if(A[i] > sol){
                return false;
            }
            if(pageSum + A[i] > sol){
                c++;
                pageSum = A[i];
                if(c>M){
                    //mean books still pending but students over
                    return false;
                }
            } else {
                pageSum += A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) return -1;
        
        int start  = 0;
        int end = accumulate(A,A+N,0);
        
        int ans = -1;
        
        while(start<=end){
            int mid = (start + end)>>1;
            if(isPossible(A,N,M,mid)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
```

## Painters Partition Problem

```cpp
//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int arr[],int n,int k,long long sol){
        long long sum = 0;
        int c = 1;
        for(int i=0;i<n,i++){
            if(arr[i] > sol){
                return false;
            }
            if(arr[i] + sum > sol ){
                c++;
                if(c>k){
                    return false;
                }
                sum = arr[i];
                
            } else {
                sum += arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long start = 0;
        long long end = accumulate(arr,arr+n,0);
        long long ans = -1;
        
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int k,n;
  cin>>k>>n;
  
  int arr[n];
  for(int i=0;i<n;i++)
      cin>>arr[i];
  Solution obj;
  cout << obj.minTime(arr, n, k) << endl;
 }
 return 0;
}
// } Driver Code Ends
```

## Aggresive Cows

<https://practice.geeksforgeeks.org/problems/aggressive-cows/0>

```cpp
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool isPossible(vector<int>& stalls,int cows,int minDis){
        //can we place cows with at least minDistance    
        int c = 1;
        int pos = stalls[0]; 
        for(int i = 1;i<stalls.size();i++){
            if(stalls[i] - pos >= minDis){
                c++;
                pos = stalls[i];
            }
            if(c == cows) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s = 0;
        int e = stalls[stalls.size()-1] - stalls[0];
        int ans = -1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(isPossible(stalls,k,mid)){
                ans = mid;
                s = mid+1;
            } else {
                e = mid - 1;
            }
            mid = s + (e-s) / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
```

## EKO SPOJ

<https://www.spoj.com/problems/EKO/>

Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

Output
The first and only line of output must contain the required height setting.

Example
Input:
4 7
20 15 10 17

Output:
15

```cpp
#include<iostream>
#include<std/bitsc++.h>
using namespace std;
bool isPossible(vector<long long int> & trees, long long int m,long long int height){
    long long int sum = 0;
    for(long long int i = 0;i<trees.size();i++){
        if(trees[i] > mid)
        sum += trees[i] - height;
    }
    return (sum >= m) 
}
long long int solve(vector<long long int> &trees, long long int &m){
    long long int start = 0;
    long long int end = *max_element(trees.begin(),trees.end());
    long long int ans = -1;
    while(start <= e){
        long long int mid = start + (end - start)/2;
        if(isPossible(trees,m,mid)){
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
int main(){
    long long int n,m;
    cin>>n>>m;
    vector<long long int> trees;
    while(n--){
        long long int height;
        cin>> height;
        trees.emplace_back(height);
    }
    cout<<solve(trees,m);
    return 0;
}
```

## PRATA

<https://www.spoj.com/problems/PRATA/>

IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

Example
Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
12
36
1

```cpp
#include<iostream>
#include<std/bitsc++.h>
using namespace std;

bool isPossible(vector<int>& cookRanks,int p,int timeLimit){
    int currP = 0; //track of cooked parata
    for(int i = 0;i<cookRanks.size();i++){
        int R = cookRanks[i] , j = 1; // j - 1 for first time then increase as time increase as 1R, 2R, 3R,...
        int timeTaken = 0;
        while(true){
            if(timeTaken + j*R<=timeLimit){
                timeTaken += j*R;
                ++j;
                ++currP;
            } else {
                break; 
            }
        }
        if(currP >= P) return true;
    }
    return false;
}
int completeOrder(vector<int>& cookRanks,int p){
    int s = 0;
    int max_rank = *max_element(cookRanks.begin(),cookRanks.end());
    int e = (max_rank*(p*(p+1) / 2));
    int ans = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(cookRanks,p,mid)){
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
void solve(){
    int nP,int nC;
    cin>>nP>>nC;
    vector<int> cookRanks;
    while(nC--){
        int rank;cin>>rank;
        cookRanks.emplace_back(rank);
    }
    cout<<completeOrder(cookRanks,nP);
}
int main(){
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
```

## Find Distance Value between two arrays

question : <https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/>

Learning of how to approach bs where condition is ans contained in absolute
```| ans | <= d```

Solution approach
<https://leetcode.com/problems/find-the-distance-value-between-two-arrays/solutions/4245137/intuitive-equation-solved-solution-with-diagram-c-easy-to-understand/>

### Code

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n-1, x = arr1[i] - d, y = arr1[i] + d;
            
            while (l <= r) {
                int mid = l+ (r-l)/2;
                if (arr2[mid] < x) {
                    l = mid + 1;
                } 
                else if (arr2[mid] > y) {
                    r = mid - 1;
                } 
                else {
                    cnt++; break;
                }
            }
        }
        return m - cnt;
    }
};
```

