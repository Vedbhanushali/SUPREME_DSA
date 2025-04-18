# Practice Questions

## Sort colors

<https://leetcode.com/problems/sort-colors/>

approach

1. sort
2. count frequency and overwrite them one by one by count
3. 3 pointer approach

```c++
int low = 0;
int high  = arr.size() -1;
int mid = 0;
while(mid <= high){
    if(arr[mid] == 0){
        swap(arr[mid],arr[low]);
        low++; //
        mid++; //doing this because it makes sure that at arr[low] it will be 1 only if 2 it will be already handled
    } else if(arr[mid]==1){
        mid++;
    } else {
        swap(arr[mid],arr[high]);
        high--;
    }
}
```

## move all -ve number to left side of array

1. sort
2. dutch national flag approach 0,1 consider 0 as negative and 1 as positive

## find duplicate Number

Q. nums n sizes containing n+1 integers in range [1,n] only one repeating number return repeated number  
[1,3,4,2,2] answer - 2

answer

1. sort and linearly look arr[i] == arr[i+1]
2. -ve marking visited elements
   jump through value of arr as index with marking that value as negative for already visited when we reach again that same node its index value is the answer.
3. set all values to their index and also check if already at that index same value is already present then it is our answer.

## missing elements from an array with duplicate

n size of array contains [1,n] numbers  
[1 3 5 3 4] answer - 2  
1 2 3 4 5

answer

1. -ve marking visited elements
   jump through value of arr as index with marking that value as negative for already visited when we reach again that same node stop and again traverse the array one the one element which is +ve is repeating and its index value is missing(answer)

2. swap such that index and element on same boxes
   and when swaping check that if element is already present there at that index mean duplicate is found and from where we are swaping is missing element

```c++
int i = 0;
while(i<n){
    int index = arr[i] - 1;
    if(arr[i]!=arr[index]){
        swap(arr[i],arr[index]);
    } else {
        i++;
    }
}
```

here all elements will be placed at its correct position now lineary loop throught them checking value at index is same index==arr[index] if not that element is missing

example

5 3 3 3 1  
after applying function  
1 3 3 3 5  
1 2 3 4 5 -- index  
so answer is 2 and 4 is missing

## Find first occurence

element occur more than once and return smallest index of first occurence.

using hashmap

```c++
int arr = {} //some value
unordered_map<int,int> hashMap;
for(int i = 0;i <arr.size();i++){
    if(hashMap.find(arr[i])!=hashMap.end){
        //mean found
        return hashMap[arr[i]];
    } else {
        hashMap[arr[i]] = i;
    }
}
```

## Common element in 3 sorted array

approach - three pointers

```c++
int i = 0;
int j = 0;
int k = 0;
set<int> st;
while(i<n1&&j<n2&&k<n3){
    if(A[i]==B[j] && B[j]==C[k]){
        i++; j++; k++;
        st.insert(A[i]);
    }
    else if(A[i]<B[j]){
        i++;
    } else if(B[j]<C[k]){
        j++;
    } else {
        k++;
    }
}
vector<int> ans;
for(auto i:st){
    ans.push_back(i);
}
```

## Wave print a matrix

top - bottom then next column  
bottom - top then next column ...  
example  
1 2 3 4  
5 6 7 8  
9 10 11 12  
answer - 1 5 9 10 6 2 3 7 11 4 8 12

```cpp
int m =vec.size(); //row
int n = vec[0].size(); //col
for(int startCol = 0;; startCol<n; startCol++){
    if((startCol)&1){ //if odd column then print from bottom to top
        for(int i = 0;i<m;i++){
            cout<<vec[i][startCol]<<" ";
        }
    } else { // print from top to bottom
        for(int i = m-1;i>=0;i--){
            cout<<vec[i][startCol]<<" ";
        }
    }
}
```

## Spiral print a matrix

<https://leetcode.com/problems/spiral-matrix-ii/description/>
example
1 2 3  
4 5 6  
7 8 9  
answer 1 2 3 6 9 8 7 4 5

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;

  // result matrix
        vector<vector<int>> v(n, vector<int> (n));
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right (row will be fixed)
            for(int i = c1; i <= c2; ++i)
                v[r1][i] = ++val;

    // move down(col will be fixed)
            for(int i = r1+1; i <= r2; ++i)
                v[i][c2] = ++val;

            // move right to left
            // move  up
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(int i = c2-1; i>c1; --i)
                    v[r2][i] = ++val;

     // move up (col will be fixed)
     for(int i = r2; i>r1; --i)
                    v[i][c1] = ++val;
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return v;
    }

};
```

## add two number of array

[9 5 4 9]  
[_ 2 1 4] add them  
[9 7 6 3]

```c++
vector<int> ans;
string a = [1,2,3,5,5];
string b = [5,4,6];
int i = a.size()-1;
int j = b.size()-1;
int carry = 0;
while(i>=0 && j>=0){
    int x = a[i] + b[j] + carry;
    int digit = x%10;
    ans.push_back(digit);
    carry = digit / 10;
    i--;
    j--;
}
while(i>=0){
    int x = a[i] + 0 + carry;
    int digit = x % 10;
    ans.push_back(digit);
    carry = x / 10;
    i--;
}

while(j>=0){
    int x = b[j] + 0 + carry;
    int digit = x % 10;
    ans.push_back(digit);
    carry = x / 10;
    j--;
}
if(carry){
    //both of equal size than still carry can be present case
    ans.push_back(carry);
}
//for testcase
// a = [0,1,2,3,4]
// b = [      4,0]
// ans = [0 1 2 7 4]
// here we don't want this zero
// in our way we are calculating reverly so 0 is at end so will remove unnecessary zeroes
while(ans[ans.size()-1]==0){
    ans.pop_back();
}
// need to reverse because answer is strored in reverse order
reverse(ans.begin(),ans.end());
```

## Find Factorial of number

```cpp
int factorial(int N){
    int ans = 1;
    for(int i=2;i<=N;i++){
        ans *= i;
    }
    return ans;
}
```
