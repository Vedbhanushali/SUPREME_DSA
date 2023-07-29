# Assignment

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

## Painters Partition Problem

## Aggresive Cows

## EKO SPOJ

## PRATA
