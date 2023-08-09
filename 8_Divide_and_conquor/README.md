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
void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int pivot = partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot,e);
}
int partition(int arr[],int s,int e){
    int pivot = arr[s];
    int pivotIndex = s;
    int count = 0;
    for(int i=0;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int rightIndex = s + count;
    swap(arr[rightIndex],arr[pivotIndex]);
    pivotIndex = rightIndex;
    int i = s;
    int j = e;
    while(i<pivotIndex && j<pivotIndex){
        if(arr[i]<=pivot){
            i++;
        } else if(arr[i]>pivot){
            j--;
        } else {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivot;
}
```
