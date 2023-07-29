# Sorting

## Selection sort

minimmy swap from start to end

```cpp
// n-1 rounds
for(int i=0;i<n-1;i++){
    minIndex = i
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minIndex]){
            arr[minIndex] = arr[j];
        }
        // for above we can also write
        //arr[minIndex] = min(arr[minIndex],arr[j]);
    }
    swap(arr[i],arr[minIndex]);
}
```

## Bubble sort

ith round we ith largest element ko uski right position place karte hai

```cpp
for(int i=0;i<n;i++){
    bool swapped = false;
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped = true;
        }
    }
    if(!swapped){
        break;
    }
}
```

## Insertion sort

insert element at their right position

```cpp
for(int round=1;round<n;round++){
    int val = arr[round];
    int j = round-1;
    for(;j>=0;j--){
        if(arr[j]>val){
            arr[j+1]=arr[j];
        } else {
            break;
        }
    }
    //copy insert value after swift
    arr[j+1] = val;
}
```

## Sort using stl sort

```c++
//arr sort
//n is size of array
sort(arr,arr+n);
//vec is vector
sort(vect.begin(),vect.end());
```
