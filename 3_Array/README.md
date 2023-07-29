# Arrays

## Sort zero's & one's (Dutch national flag problem)

```c++
int start = 0;
int end = n-1;
int i = 0;
while(i<end){
    if(arr[i]==0){
        swap(arr[i],arr[start]);
        start++;
        i++;
    } else {
        swap(arr[i],arr[end]);
        end--;
    }
}
```

## Pascal Triangle

Remember this formula of `c = c*(i-j)/j;`  
This is used to find binomial coefficients

```c++
vector<vector<int>> answer;
        int n = numRows;
        int c = 1;
        for(int i=1;i<=n;i++){
            c=1;
            cout<<c;
            vector<int> temp;
            temp.emplace_back(c);
            for(int j=1;j<i;j++){
                c = c*(i-j)/(j);
                temp.emplace_back(c);
                cout<<c;
            }
            cout<<endl;
            answer.emplace_back(temp);
        }
        return answer;
```

## CODE SNIPPETS

### Swapping

```c++
// 1st way
temp = a
a = b
b = a
// 2nd way
a = a+b;
b = a-b;
a = a+b;
// 3rd way
a = a^b;
b = a^b;
a = a^b;
```

### REVERSE array

```c++
int arr_size = 5;
int arr[arr_size] = {1,2,4,5,6}
int start = 0;
int end = arr_size - 1;
while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
}
```
