# Pointers & Mathematical algorithms

for pointers refer theory - book

## Seive of Erathosthenes - count prime

- from 2 to n-1 array number mark all of them as prime
- start from 2 till end mark all the number comes in the table of 2 as non prime
- repeat 2 till n-1 only for prime number
- rest elements marked as prime will be counted

```cpp
int countPrime(int n){
    if(n==0) return 0;
    vector<bool> prime(n,true);
    prime[0]=prime[1] = false;
    int ans = 0;
    for(int i=2;i<n;i++){
        if(prime[i]){
            ans++;
            j = i*2;
            while(j<n){
                prime[j] = false;
                j = j+i;
            }
        }
    }
    return ans;
}
```

## GCD Euclid algorithm

```
gcd(a,b) = gcd(a-b,b) for(a>b)
or
gcd(a,b) = gcd(b-a,a) for (b>a)
```

```cpp
int gcd(int a,int b){
    if(a==0 || b==0) return 0;
    while(a>0 && b>0){
        if(a>b){
            a=a-b;
        } else {
            b = b-a;
        }
    }
    return a==0 ? b : a;
}

```

applying this till one of the parameter becomes zero

above formula is similar to  
gcd(a,b) = gcd(a%b,b) this is not prefer because modulus is heave operation compared to subtraction above

another important formula

```
gcd(a,b) * lcm(a,b) = a*b
```

## Modulus properties

```
- (a+b)%M = a%M + b%M
- a%m - b%M = (a-b)%M
- (((a%M)%M)%M) = a%M
- a%M * b%M = (a*b)%M
```

## Fast exponential

find a^b ?  
`( a * a * a * .... a ) b times`  
TC - O(b)

another approach divide and conquor

```cpp
int exp(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = ans * a;
        } else {
            ans = a * a;
        }
        b= b>>1;
    }
    return ans;
}
```

## Pigeon hole

## catalan number BST

## Inclusion - Exclusion principle

## chinese reminder theorem

## lucas's theorem

## Fermat's Theorem

## Probablity concepts
