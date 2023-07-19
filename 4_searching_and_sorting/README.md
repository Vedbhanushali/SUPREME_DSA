# Searching and Sorting

## Binary search

prerequisite data structure should be monotonically sorted in increasing order or descending order.  

TC - O(log(n))

```c++
int binary_search(int arr[],int size,int target){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start) /2;
    while(start < end){
        if(target == arr[mid]){
            return mid; //index of target in arr
        }
        else if(target < arr[mid]){
            end =mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1; //no answer found
}
```

using STL library binary search
```c++
vector<int> v = {1,2,4,6,7};
int target = 4;
if(binary_search(v.begin(),v.end(),target)){
    cout<<"answer found"<<endl;
} else {
    cout<<"answer not found"<<endl;
}
// for array
int size = 4;
int arr[size] = {1,4,5,6};
int target2 = 5;
int ans = binary_search(arr,arr+size,5);
```
