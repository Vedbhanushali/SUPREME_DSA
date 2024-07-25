# Divide and Conqueor

## Merge Sort

TC - O(nlogn)

```cpp
//driving code
void merge(int * arr,int s , int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s+1;
    int len2 = e - mid;

    //creating arr of len1 and len2;
    int * left = new int[len1];
    int * right = new int[len2];
    int k = s;
    //copy values in two arrays
    for(int i=0;i<len1;i++){
        left[i] = arr[k++];
    }
    for(int j =0;j<len2;j++){
        right[j] = arr[k++];
    }
    //merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while(leftIndex < len1 && rightIndex<len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex++] = left[leftIndex++];
        } else {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }
    //copying rest if any array empty and one is not
    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    while(rightIndex < len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }
    //delete left and right newly created array
    delete[] left;
    delete[] right;
}
void mergeSort(int *arr,int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int arr[] = {1,4,6,7,9,3}
    int n = 6;
    int s = 0;
    int e = n-1;
    mergeSort(arr,s,e);
    return 0;
}
```

## Inplace merge Sort

driver code

```cpp
vector<int> sortArray(vector<int>& nums){
    mergeSort(nums,0,nums.size()-1);
    return nums;
}
```

```cpp
void mergeSort(vector<int> &v,int start,int end){
    if(start>=end) return;
    int mid = (start+end)>>1;
    mergeSort(v,start,mid);
    mergeSort(v,mid+1,end);
    mergeInPlace(v,start,mid,end);
}
void mergeInPlace(vector<int> &v,int start,int mid,int end){
    int total_len = end-start+1;
    int gap = total_len/2 + total_len%2;
    while(gap>0){
        int i=start;
        int j = start + gap;
        while(j<=end){
            if(v[i] > v[j]){
                swap(v[i],v[j]);
            }
            i++;
            j++;
        }
        gap = gap<=1 ? 0 : (gap/2) + (gap%2);
    }
}
```

## Quicksort

- partioning logic
- recursive logic
- left sort [] right sort
- base case only one element is there so already sorted so return

### pivot chosing

- pivot chosing
- find the right positon for pivot
- swap all left elements smaller than pivot and right elements bigger than pivot smaller < greater
- return pivot index

TC - O(nlogn)

```cpp
class Solution {
public:
    void quickSort(vector<int>&arr,int s,int e){
    if(s>=e){
        return;
    }
    int pivotIndex = partition(arr,s,e);
    quickSort(arr,s,pivotIndex-1);
    quickSort(arr,pivotIndex+1,e);
}
int partition(vector<int> &arr,int s,int e){
    int pivot = arr[s];
    int pivotIndex = s;
    int count = 0;
    for(int i=s;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int rightIndex = s + count - 1;
    swap(arr[rightIndex],arr[pivotIndex]);
    pivotIndex = rightIndex;
    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]<=pivot){
            i++;
        } else if(arr[j]>pivot){
            j--;
        } else {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
    vector<int> sortArray(vector<int>& nums) {
        //quick sort algorithm
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};
```

## QuickSort other

```cpp
void quickSort(int a[],int start,int end){
    if(start >= end) return;
    int pivot = end;
    int i = start - 1;
    int j =  start;
    while(j<pivot){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    i++; // i is the right postion of pivot element
    swap(a[i],a[pivot]);

    quickSort(a,start,i-1);
    quickSort(a,i+1,end);
}
```
