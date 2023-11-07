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

### custom comparator

```cpp
bool comp(pair<int,int>& a,pair<int,int>& b){
    return a.second < b.second; //sorting ascending order based on pair second value
}
// custom Comparator logic of a < b : mean ascending and  a > b mean descending order
--------------------- main fun
vector<pair<int,int>> vec = {{1,2},{3,3},{4,5}};

//by default in custom is not provided sorting will applied on first element of pair
sort(vec.begin(),vec.end());

//sorting based on second pair element
sort(vec.begin(),vec.end(),comp);
```

```cpp
//string length sorting
bool comp(string &a,string &b){
    retrun a.size() < b.size();
}
--------------main fun
vector<string> vect = {"ved","dev","server"};
sort(vect.begin(),vect.end(),comp);
```

### sort in descending order

```cpp
int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
int n = sizeof(arr) / sizeof(arr[0]);
sort(arr, arr + n, greater<int>());
```


