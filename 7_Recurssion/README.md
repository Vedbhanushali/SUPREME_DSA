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

## fining value in array using recursion

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
    printSubsequence(str,output,i);
}
int main(){
    string str = "abc";
    string output = "";
    int i = 0;
    printSubsequence(str,output,i);
}
```
