# Sliding window

<https://leetcode.com/discuss/general-discussion/1122776/summary-of-sliding-window-patterns-for-subarray-substring>

the sliding window technique is a common approach used to solve problems that involve finding or analyzing a subset of elements in a larger data structure such as array or string. here are the key patterns often used in sliding window problem statment

- fixed size window
- variable size window
- two pointer approach
- optimized sliding window

## Fixed-Size Windows

- Maintain a window of a fixed size (usually a contiguous subset of elements).
- Slide the window one element at a time to process the data.
- Useful for finding the maximum, minimum, or some other calculation within
a fixed-sized window.

questions
TODO

- Given an array of integers and a window size, find the maximum sum of any subarray of the given window size.
- Given a string, find the length of the longest
string containing only unique characters within a fix window size.
- Given an array of temperatures, find the minimum number of days it takes for a contiguous window of size K to have increasing temperatures.
- Given a binary array (containing only Os and 1s), find the maximum number of consecutive 1s with at most K Os allowed in the window.
- Given a string of characters, find the smallest window length that contains all the characters of
a given pattern.

## variable size window

- Start with a small window and gradually expand or shrink it based on certain conditions.
- Useful when the size of the window is not fixed and depends on the problem requirements.
- Often used to find a subarray or substring satisfying specific conditions (e.g., sum, product, or a certain property).

questions
TODO

- Given an array of positive integers and a target sum, find the minimum subarray length whos sum is greater than or equal to the target.
- Given a string, find the longest substring ith at most K distinct characters.
- Given an array of non-negative integers, find the subarray of length K with the maximum average value.
- Given a string, find the length of the longest substring that can be formed by repeating exactly K times.
- Given an array of integers, find the maximum product of a subarray with size at most K.

## Two pointer approach

- Use two pointer to define the boundaries of the window.
- One pointer usually represents the rt of the window, and the other represents the end.
- Move the pointers within the data structure based on certain conditions.
- Commonly used when the problem requires finding a target sum, a pair of elements, or a subarray with specific characteristics.

questions
TODO

- Given an array of integers and a target sum, find two numbers that add up to the target
- Give sorted array of integers, find two numbers whose absolute difference is closest to a given target value.
- Given a string, find the longest palindrome substring.
- Given a string, find the length of the longest substring without repeating characters.
- Given an array of integers, find a subarray with the given sum.

## Optimized window

- Apply additional optimization techniques to improve the sliding window solution
- Examples include precomputing sums or frequencies, utilizing data structures like heaps or hash maps, or skipping unnecessary calculations.
- Helps to reduce the time complexity and optimize the overall solution.

questions
TODO

- Given an array of integers, find the subarray with the maximum sum using the Kadane's algorithm.
- Given a string, find the longest substring with most K distinct characters using a hash map for character frequency tracking.
- Given an array of integers, find the median of every sliding window of size K using a min heap
and max heap.
- Given a binary array (containing only Os and Is), find the minimum size of a subarray that needs to be flipped to make all elements 1.
- Given an array of integers and a target sum, find the subarray with the smallest length that sums up to the target using a two-pointer approach and dynamic window resizing.

## Smallest window in a string containing all the characters of another string

<https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1>
or
<https://leetcode.com/problems/minimum-window-substring/>

```cpp
class Solution {
public:
    string minWindow(string s, string p) {
        // Your code here
        int len1 = s.length();
        int len2 = p.length();
        
        if(len1 < len2) return "";
        
        unordered_map<char,int> strMap;
        unordered_map<char,int> patMap;
        for(int i=0;i<p.length();i++){
            char ch = p[i];
            patMap[ch]++;
        }
        
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        int count = 0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            strMap[ch]++;
            //valid character (existing in pattern)
            if(strMap[ch] <= patMap[ch]) {
                count++;
            }
            if(count == len2) { //len2 pattern len
                //window is ready
                //minimizing window
                while(strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0){
                    if(strMap[s[start]] > patMap[s[start]])
                        strMap[s[start]]--;
                    start++;
                }
                
                int lenOfWindow = i - start + 1;
                if(lenOfWindow < ansLen){
                    ansLen = lenOfWindow;
                    ansIndex = start;
                }
            }
        }
        if(ansIndex == -1) return "";
        return s.substr(ansIndex,ansLen);
    }
};
```
