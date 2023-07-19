# Basics of programming

## difference of endl and /n

| endl | \n |
| --- | --- |
|IT doesn't occupy any memory | It occupies 1 byte memory as it is character |
| It keeps flushing the queue in the output buffer throughout the process | It flushes the output buffer only once at the end of the program |

```cout<<"\n"``` looks performance wise better but in real ```cout<<endl``` ia muxh bwrrwe in c++, as it doesn't occupies any memory and also if flusing of stream is required.

## C basic datatypes

| | 32 bit CPU | 64 bit CPU |
| --- | --- | --- |
| char | 1 | 1 |
| short | 2 | 2 |
| int | 4 | 4 |
| long | 4 | 8 |
| long long | 8 | 8 |
| float | 4 | 4 |
| double | 8 | 8 |

boolean data types consumes 1 byte but 1 bit is sufficient becase 1 bit memory is not addressable minimum memory size is 1 byte.

## ASCI table IMP

| a | 97 |
| --- | --- |
| z | 123 |
| A | 65 |
| Z | 91 |

## How negative numbers are stored in memory

2's complement is stored in memory for negative numbers

- 1's complement of 1010100 is 0101011 (flip bits)
- 2's complement of 1010100 is 0101100 (1's complement + 1)

for +ve number int a = +15 binary is  
00...101  
32 bits where MSB is 0

for -ve number int a = -5 binary is (2's complement of +5)
111...011  
32 bits where MSB is 1

How computer reads negative number is it performs 1's complement + 1 on 2's complement data

## Switch

- switch construct can be used with int, char types of vairable only
- if any case is hit then control falls down the ladder without checking case again printing everything below it. so switch checks only once and falls down.
- if missing case or default statements still compiler accepts but without case statement nothing will be printed inside of switch.

    ```c++
    switch(a){
        cout<<"asd";
    }
    ```

- expression leading to integer can be used as swtich constants

    ```c++
    char code = 'A';
    switch(code){
        case 64+1: cout<<"A"; break;
        case 8*8+2: cout<<"B"; break;
        default cout<<"C";
    }    
    ```

    output - A
- cannot use float , string or double inside of switch cases.
- all integer constants are allowed for switch cases.

## Miscellaneous

- assignmentt operator used in if condition will returin boolean which will be always true.
- cout also returns true in if condition.
- modulus operation is heavy so for finding even numbers
instead of ```n%2==0``` we can write ```n&1==0``` true then even false then odd.

## Time Complexity & Space

O(1) < O(Logn) < O(✓n) < O(n)< O (nlogn)< O(n^2) < O(n^3) < O(2^n) < O(N!) < O(N^N) 