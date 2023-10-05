# Heap

it is a DS which is complete binary tree that holds a heap property.  
complete binary tree - (all levels are completely filled except last one , and last level filling is from left to right)

Data in heap is stored in the form of array but it's representation is in form of tree.

there is two types of heap

- max heap - currNode is greater than both of child nodes.
- min heap - currNode is smaller than both of child nodes.

## Max heap

tree index from top to bottom and left to right will start from 1 (this is convenince of formula) as below  

0 index of array is considered dummy.  
heap data start from index 1.

for 1 base indexing formula of left child of currNode is - ```2*i```  
for 1 base indexing formula of right child of currNode is - ```2*i + 1```  
for 1 base indexing formula of parent is here i is index of current node -
```i/2```  
formula derived from dividing both above formula by 2 which gives i.

for 0 based indexing heap data start from index 0 then  
Formula of left child of currNode is - ```2*i + 1```  
Formula of right child of currNode is - ```2*i + 2```  

## Insertion in max heap

1. insert in last of array
2. check if parent node is less than curr inserted node data then swap till reach root node which is index 1

TC - O(log n)

```cpp
#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }
    void insert(int value){
        //value insert at end
        size = size + 1;
        int index = size;
        arr[index] = value;

        //value place at right position
        while(index > 1) { // index == 1 is last node after than no need of comparison
            int parentIndex = index/2;
            if(arr[parentIndex] <arr[index]){
                swap(arr[parentIndex],arr[index]);
                index = parentIndex;
            } else {
                break;
            }

        } 
    }
}

int main(){
    Heap h;
    h.insert(50);
    h.insert(30);
    h.insert(80);
    h.insert(100);

    for(int i=0;i<=h.size;i++){
        cout<<h.arr[i]<<" ";
    }
    return 0;
}
```

## Deletion in max Heap

Only root node can be deleted in heap  
algo

- replace last value with root node
- root node to correct position
TC - O(log n)

```cpp
#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }    
    int delete(){
        //returning deleted node data so storing it
        int ans = arr[1];
        //replace root node with last node data
        arr[1] = arr[size];
        size--;
        
        //place root node ka data on its correct position
        int index = 1;
        while(index < size){
            int left = 2*index;
            int right = 2*index+1;
            int largest = index;
            if(left < size && arr[largest] < arr[left]){
                largest = left;
            }
            if(right < size && arr[largest] < arr[right]){
                largest = right;
            }
            if(largest == index) {
                //value is at correct position
                return ans;
            } else {
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
    }
}
```

## Heapify

Build a max heap from arr

- no need to heapify leaf nodes if number of nodes - n then [(n/2)+1 , n ] this are leaf nodes ex, if n = 5 then (3,4,5) are leaf nodes 1 based indexing

```cpp
void heapify(int arr[],int &n,int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largest = index;

    if(leftIndex< n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex < n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }
    if(index != largest){
        //left or right is greater than curr node
        swap(arr[largest],arr[index]);
        index = largest;
        heapify(arr,n,index)
    }
}
```
