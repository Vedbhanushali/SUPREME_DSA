# Recursion

## Print 1 to n

```cpp
void solve(int n){
 if(n==0) return
 solve(n-1);
 cout<<n;
}
```

output - 1 2 3 4 5

```cpp
void solve(int n){
 if(n==0) return
 cout<<n;
 solve(n-1);
}
```

output - 5 4 3 2 1

## factorial

```cpp
int fact(int n){
    if(n==1) return n;
    return n * fact(n-1);
}
```

## Fibonaci

n >= 2 , fib will return the number at index n

```cpp
int fib(int n){
    if(n==0 || n==1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}
```

## climbing stairs

current position at 0th step and need to reach nth stair how many ways can jump 1 step or 2 step at a time.

```cpp
int climb(int n){
    if(n==0 || n==1) return 1;
    return climb(n-1) + climb(n-2);
}
```

## Array print all element using recursion

```cpp
void print(int arr[],int n,int i){
    if(i>=n) return;
    cout<<arr[i];
    print(arr,n,i+1);
}
//function call
print(arr,size,0);
```

Another approach

```cpp
void print(int arr[],int n){
    if(n==0) return
    cout<<arr[0];
    print(arr+1,n-1);
}
```

## Find max in array using recursion

```cpp
void findMax(int arr[],int i,int n,int &maxi){
    if(i>=n) return;
    maxi = max(arr[i],maxi);
    findMax(arr,i+1,n,maxi);
}
//function call
int maxi = INT_MIN;
findMax(arr,0,arr_size,maxi);
```

## finding value in array using recursion

```cpp
bool checkKey(int arr[],int key,int i,int n){
    if(i>=n) return false;
    if(arr[i] == key){
        return true;
    }
    return checkKey(arr,key,i+1,n);
}
//function call
int key = 3;
int arr = [1,4,5,3,6];
checkKey(arr,key,0,5);
```

## print all digits of number using recursion

```cpp
void print(int n){
    if(n==0) return
    int ans = n%10;
    print(n/10);
    cout<<ans;
}
```

## Finding is array is sorted

```cpp
bool isSorted(int arr[],int i,int n){
    if(i>=n-1) return true;
    if(arr[i] > arr[i+1]) return false;
    return isSorted(arr,i+1,n);
}
//function call
isSorted(arr,0,arr_size);
```

## Binary search using recursion

```cpp
int binarySearch(vector<int> &v,int s,int e,int &target){
    if(s>e) return -1;

    int mid = s + (e-s)/2;

    if(v[mid]==target) return mid;
    else if(v[mid] <target) s = mid+1;
    else e = mid - 1;
    
    return binarySearch(v,s,e,target);
}
//function call
int main(){
    vector<int> v = {1,4,5,6,7,9};
    int target = 5;
    int n = v.size();
    int s = 0;
    int e = n-1;
    int ans = binarySearch(v,s,e,target);
}
```

## Subsequence of string

if few characters are omitted  then resultant string is subsequence  
it is powerset of given string

approach

- include - exclude
- bit masking //TODO

```cpp
//function call
void printSubsequence(string str,string output,int i);{
    if(i>=str.size()){
        cout<<output<<endl;
        return;
    }
    //exclude call
    printSubsequence(str,output,i+1);
    //include call
    output.push_back(str[i])
    printSubsequence(str,output,i+1);
}
int main(){
    string str = "abc";
    string output = "";
    int i = 0;
    printSubsequence(str,output,i);
}
```

## Coin exchange

find minimum number of elements required to reach target sum.

```cpp
int solve(arr,target){
    if(target==0) return 0;
    if(target < 0)
        return INT_MAX;
    int mini = INT_MAX
    for(int i=0;i<n;i++){
        int ans = solve(arr,target-arr[i])
        if(ans!=INT_MAX){
            mini = min(mini,ans+1);
        }
    }
    return mini;
}
```

## Cut into segments

N length rod, find max no of segments you can make of three segments.
x = 5,y=2,z=2

```cpp
int solve(int n,int x,int y,int z){
    if(n<=0) return INT_MIN;
    if(n==0) return 0;
    int a1 = solve(n-x,x,y,z)+1;
    int a2 = solve(n-y,x,y,z)+1;
    int a3 = solve(n-z,x,y,z)+1;
    return max(a1,max(a2,a3));
}
//function call
int ans = solve(7,5,2,2);
if(ans < 0) cout<<"no segments possible"
```

## Maximum sum of adjacent elements

find non adjacent elements whose sum is maximum

2 1 4 9  
pairs are  
2 4  
2 9  
1 9  

```cpp
void solve(vector<int> &arr,int sum,int i,int &maxi){
    if(i >= arr.size()){
        maxi = max(maxi,sum);
        return;
    }
    //include
    solve(arr,sum+arr[i],i+2,maxi);
    //exclude
    solve(arr,sum,i+1,maxi);
}
//function call
main(){
    vector<int> arr = {1,3,5,9};
    int sum = 0;
    int i = 0;
    int maxi = INT_MIN;
    solve(arr,sum,i,maxi);
    cout<<"ans "<<maxi;
}
```
