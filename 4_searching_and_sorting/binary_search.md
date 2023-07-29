# Binary search

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

## Find first occurrence

```c++
int first_occ(vector<int> v,int target){
    int s = 0;
    int e  = v.size() -1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==target){
            // store and still search left side
            ans = arr[mid];
            end = mid - 1;
        } else if(arr[mid]<=target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
```

### STL way of first occurrence

```c++
int ans = lower_bound(v.begin(), v.end(),target);
cout<<ans-v.begin(); //index of first occurrence
```

## similarly last occurence of target

```c++
int first_occ(vector<int> v,int target){
    int s = 0;
    int e  = v.size() -1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==target){
            // store and still search left side
            ans = arr[mid];
            start = mid + 1;
        } else if(arr[mid]<=target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
```

### STL way of last occurrence

```c++
int ans = upper_bound(v.begin(), v.end(),target);
cout<<ans-v.begin(); //index of first occurrence
```

## Total number of occurrences

answer is lastoccurrence - first occurrence

```c++
int ans = upper_bound(v.begin(),v.end(),target) - lower_bound(v.begin(),v.end,target);
```

```cpp
class Solution {
public:
    int binarySearch(vector<int> arr, int target, int start, int end) {

    int mid = start + (end - start ) / 2;

    while(start <= end) {
        int element = arr[mid];

        if(element == target) {//element found, then return index
        return mid;
        }

        if(target < element) {
        //search in left
        end = mid - 1;
        }
        else {
        //search in right
        start = mid + 1;
        }

        mid = start + (end - start ) / 2;

    }

  //element not found
  return -1;

}
    int findPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s < e) {
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1])
        return mid;
        if(mid-1 >= 0 && arr[mid-1] > arr[mid])
        return mid-1;

        if(arr[s] >= arr[mid])
        e = mid - 1;
        else
        s = mid ;
        mid = s + (e-s)/2;
    }
    return s;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivot(nums);

        if(target >= nums[0] && target <= nums[pivotIndex]){
            //search in array A
            int ans = binarySearch(nums, target, 0, pivotIndex);
            return ans;
        }

        if(pivotIndex+1 < nums.size() &&
        target >= nums[pivotIndex+1] && target <= nums[nums.size()-1]){
            //search in array B
            int ans = binarySearch(nums, target, pivotIndex+1, nums.size()-1);
            return ans;
        }
        return -1;

    }
};
```

## Find missing element

n given and elements from 1 to n present in n-1 size array one missing find that element?

1.  ans = total_sum - sum_of_array
2.  using binary search  
    sort the array first and notice this thing

        | array |1 2 3 4 6 7 8|
        | --- | --- |
        |index | 0 1 2 3 4 5 6|

        before index 4 , ```index + 1 == arr[index]``` but after index 4 ```index + 2 == arr[index]```

```c++
int first_missing(vector<int> v,int target){
    int s = 0;
    int e  = v.size() -1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==mid+1){
            // mean left side all is ok ans is in right side
            start = mid + 1;
        } else {    // another case is arr[mid] == mid+2
            //mean ans is in right side
            ans = mid+1; //+1 because want to return missing number not its index
            end = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
```

## Find peak element in a mountain array

```c++
int find_peak(vector<int> v,int target){
    int s = 0;
    int e  = v.size() -1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<e){
        if(arr[mid] < arr[mid + 1]){
            //right search
            // on left slope
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
```

## Find pivot

```c++
int find_pivot(vector<int> v,int target){
    int s = 0;
    int e  = v.size() -1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<e){
        if(mid+1 < arr.size() && arr[mid] > arr[mid + 1]){
            //found answer
            return mid;
        } else if(mid-1>=0 && arr[mid] > arr[mid - 1]){
            return mid;
        }
        if(arr[s] < arr[mid]){
            //mean on left slope
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
```

## search in rotated sorted array (application of finding pivot element)

once pivot element is found perform binary search on left side and right side of array.

## Find square root

```c++
int find_sq_root(int n){
    int s = 0;
    int e  = n;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(mid*mid == n){
            return mid;
        } else if(mid*mid < n){
            ans = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return ans;
}
```

## Binary search in nearly sorted array

element at index i - possible it will be on either of i-1,i or i+1 index, apart from them if we reorder i-1,i,i+1 it will in monotically increasing order or descending order

```c++
int nearly_sorted(vector<int> arr,int target){
    int s = 0;
    int e  = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        } else if(mid+1 < arr.size() && arr[mid+1]==target){
            return mid+1;
        } else if(mid-1>=0 && arr[mid-1]==target){
            return mid-1;
        }

        if(arr[mid]>target){
            s = mid + 2;
        } else {
            e = mid-2;
        }
        mid = s + (e-s)/2;
    }
    return -1; // answer not found
}
```

## Divide two numbers using binary search

```c++
int nearly_sorted(int dividend,int divisor){
    int s = 0;
    int e  = dividend;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(mid*divisor == dividend){
            return mid;
        } else if(mid*divisor < divisor){
            ans = mid;
            s = mid + 1;
        } else {
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans; // answer not found
}
```

## Find odd occuring element in array

- all elements occurs eve no of times except one.
- all repeating occurences of elements appear in pairs
- pairs are not adjacent
- there connot be more than 2 consecutive occurence of any elements. find the elements appear odd no of times.

solution

1. xor method bit manipulation.
2. index based binary search
   even - E and odd - O
   | array |1 | 1 |2 |2 | 4 | 5| 5| 6| 6|
   | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |
   | pattern | E | O | E | O | on E | O | E | O | E |
   |index | 0 | 1| 2| 3| 4| 5| 6 |7| 8|

```c++
int find_element(vector<int> arr,int target){
    int s = 0;
    int e  = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(s==e) return s;
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                //search on right side
                s = mid + 2;
            } else {
                e = mid;
            }
        }
        mid = s + (e-s)/2;
    } else {
        //odd case
        if(arr[mid]==arr[mid-1]){
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return s; // answer not found
}
```

## Binary search on 2D matrix

```c++
int cols = 5;
int rows = 5;
int binaryy_search(int arr[][cols],int target){
    int s = 0;
    int e = rows * cols - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        row_index = mid/cols;
        col_index = mid%cols;
        if(arr[row_index][col_index]==target){
            return mid;
        } else if(arr[row_index][col_index] < target){
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1; // ans not found
}
```
