# Bit manipulation

## ODD/EVEN checking

```cpp
if(n&1){
    cout<<"is odd";
} else {
    cout<<"is even";
}
```

## Bit masking

get ith bit ? (i is from right to left and zero based indexed)

ex - 4th bit;

```cpp
//finding 4th bit of n
int n = 108;
int bit_mask = 1<<(4); //000...01000 (made left shif of 1)
int ans = (bit_mask & n)>>(4); //again right shit to make ans 0 or 1 
```

## Change ith bit

1. set ith bit

    ```cpp
    int n = 10;
    //seting 4th bit
    int bit_mask = 1<<(4);
    int ans = bit_mask | n;
    ```

2. clearing ith bit

    ```cpp
    int n = 10;
    //clearing 4th bit
    int i = 4;
    int bit_mask = ~(1<<i); //~(000...1000) -> (111...0111)
    int ans = bit_mask & n;
    ```

3. update ith bit

```cpp
void clearIthBit(int &n,int i){
    int bit_mask = ~(1<<i); //~(000...1000) -> (111...0111)
    n = bit_mask & n;
}
void updateIth(int n,int i,int target){
    clearIthBit(n,i);
    int mask = (target<<i);
    n = n | mask;
    cout<<"after updateing n >> "<<n;

}
```

## Single number

```cpp
int singleNumber(vector<int> & nums){
    int ans = 0;
    for(int i : nums){
        ans = ans ^ i;
    }
    //same cancel out and 0 ^ n = n
    return ans;
}
```

## clear last i bits

```cpp

int n = 108;
int i = 3;
// 1st way
int ans = (n>>i)<<i;

// 2nd way
int mask = (-1<<i); //1111...111 => 1111...10000
int ans2 = mask & n;
```

## Check power of 2

n = 16 //10000  
and (n-1) 15 = 01111  
& of both is 0  
but if any non power of 2 number  
n = 14 1110  
(n-1) = 13 1101  
& of both is not equal to zero

```cpp
bool is powerOf2(int n){
    return n & (n-1) == 0
}
```

## Count set bits

```cpp
int n = 10;
int count = 0;
while(n !=0 ){
    if(n&1) count++;
    n = n>>1;
}
```

another way

```cpp
int n = 10;
int count = 0;
while(n != 0){
    //remove last set bit
    n = (n & (n-1));
    count++;
}
```

## Fast exponential

TODO

## Clear range of bits

    i--clear-j     
1101010101000011101  

creating a mask for before i and after j and middle part willl be zero
and or of both will give like

```cpp
    i--clear-j     
1101010101000011101  
1111000000000011111  <-- mask
-------------------  
1101000000000011101  & operation  
```

mask is created by
mask a - 1111000000000000000
mask b - 0000000000000011111  
or of both

```cpp
int n = 108;
int a = (-1<<(i+1));
int b = (1<<j)-1;
int mask = (a | b);
int ans = mask & n;
```

## Subsequence using bitmasking

str = "abc"  
subsequence is powerset of (str) - {a,b,c,ab,ac,bc,abc,""}  

```cpp
vector<string> getSubsequence(string str){
    vector<string> ans;
    int n = str.length();
    //1<<n is 2^n
    for(int num = 0; num < (1 << n) ; num++){
        string temp = "";
        //we will create subsequunce string in this temp string
        for(int i=0;i<n;i++){
            char ch = str[i];
            //num = 5 - 101
            // i = 0 1 2
            int mask = (1<<i)
            if(mask & num != 0){
                temp += ch;
            }
        }
        ans.emplace_back(temp);
    }
    return ans;
}

```
