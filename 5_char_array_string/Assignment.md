# Assignment of Char array and string

## valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

`Input: s = "anagram", t = "nagaram"
Output: true`

Example 2:

`Input: s = "rat", t = "car"
Output: false`

<https://leetcode.com/problems/valid-anagram/>

### approach

if number of characters in both string matches then they are anagrams

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[256] = {0};
        for(auto i : s){
            freq[i]++;
        }
        for(auto i : t){
            freq[i]--;
        }
        for(auto i : freq){
            if (i!=0){
                return false;
            }
        }
        return true;
    }
};
```

## Reverse only letters

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"

Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

<https://leetcode.com/problems/reverse-only-letters/>

### approach

two pointer approach of reversing string just one thing to taken care is that when character is not alphabet then move the pointers respectively

```cpp
class Solution {
public:

    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            cout<<s[start]<<"  "<<s[end]<<endl;
            //if( !((s[start]>='a') && (s[start]<='z')) && !((s[start]>='A') && (s[start]<='Z')) ) {
            if(!isalpha(s[start])){
                cout<<"found - start"<<endl;
                start++;
                //continue;
            }
            //else if ( !((s[end]>='a') && (s[end]<='z')) && !((s[end]>='A') && (s[end]<='Z'))){
            else if(!isalpha(s[end])){
                cout<<"found - end"<<endl;
                end--;
                //continue;
            } else {
                swap(s[start],s[end]);
                cout<<"swaped"<<s[start]<<" "<<s[end]<<endl;
                start++;
                end--;
            }

        }
        cout<<s<<endl;
        return s;
    }
};
```

## longest common prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

<https://leetcode.com/problems/longest-common-prefix/>

### approach

will loop through until we hit the case where no common prefix character is present

and for first string every element will compare whether this character is present in the other string if its then will add in ans if doesn't will break infinite loop

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        char current = 'a';
        string ans = "";
        int index = 0;
        bool break_out = false;
        while(1){
            int i = 1;
            for(;i<strs.size();i++){
                if(index >= strs[0].size()){
                    break_out = true;
                    break;
                }
                current = strs[0][index];
                if(index >= strs[i].size()){
                    break_out = true;
                    break;
                }
                if(strs[i][index]!=current){
                    break_out = true;
                    break;
                }
                if(i==strs.size()-1){
                    ans = ans + current;
                }

            }
            index++;
            if(break_out){
                break;
            }
        }
        return ans;
    }
};
```

## Reverse vowels of a string

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

<https://leetcode.com/problems/reverse-vowels-of-a-string/>

### approach

two pointer approach of reversing string just one thing to taken care is that when character is not vowel then move the pointers respectively.

```cpp
class Solution {
public:
    bool isVowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
            return true;
        }
        if(s=='A' || s=='E' || s=='I' || s=='O' || s=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string str) {
        int s = 0,e = str.length() - 1;
        while(s<e){
            if(!isVowel(str[s])){
                s++;
            } else if(!isVowel(str[e])){
                e--;
            } else {
                swap(str[s],str[e]);
                s++;
                e--;
            }
        }
        return str;
    }
};
```

## isomorphic string

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

<https://leetcode.com/problems/isomorphic-strings/>

### approach

will keep track using two maps for s and t ,first map track string s is mapped to which character of t and if character of s already mapped and character of s and t does not show same as map then throw error and second map tracks if character of t is already map when character of s is not mapped will throw error.

```cpp
class Solution {
public:
    bool isIsomorphic(string s,string t){
        if(s.length()!=t.length()){
            return false;
        }
        int hash[256] = {0};
        bool isMapped[256] = {0};
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==0){
                if(isMapped[t[i]]==false){
                    hash[s[i]] = t[i];
                    isMapped[t[i]]=true;
                } else {
                    return false;
                }
            } else {
                if(t[i]!=hash[s[i]]){
                   return false;
                }
            }
        }
        return true;
    }
};
```

## reorganize string

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
<https://leetcode.com/problems/reorganize-string/>

### approach

```cpp
class Solution {
public:
    string reorganizeString(string s) {
        //greedy approach filling most occurence one by one and other characters between them
        int hash[26]={0};
        int n = s.length();
        for(auto i : s){

            hash[i-'a']++;
            //cout<<hash[i-'a']<<i<<endl;
        }
        //finding max element
        int max_fre = INT_MIN;
        char max_fre_char;
        for(int i=0;i<26;i++){
            //cout<<max_fre<<" "<<hash[i]<<endl;
            if(max_fre < hash[i]){
                max_fre = hash[i];
                max_fre_char = i + 'a';
            }
        }
        //cout<<max_fre_char<<" "<<max_fre<<endl;
        // check if able to fill all max_fre char
        int index = 0;
        while(index < n && max_fre > 0){
            s[index] = max_fre_char;
            max_fre--;
            index += 2;
        }
        //cout<<s<<" "<<max_fre<<endl;
        if(max_fre != 0 ){
            return "";
        }
        //filling other characters
        hash[max_fre_char - 'a'] = 0;
        //cout<<"----"<<endl;
        //for(int i=0;i<26;i++){
        //    cout<<(char)(i+'a')<<" "<<hash[i]<<endl;
        //}
        //cout<<" --- "<<endl;
        for(int i=0;i<26;i++){
            while(hash[i]>0){
                index = index >= n ? 1 : index ;
                s[index] = i + 'a';
                hash[i]--;
                index+=2;
            }
        }
        return s;
    }
};
```

## group anagram

## longest palindromic substring

## find the index of first occurence in a string

## string to integer (stoi)

## string compression

## Integers to roman

## Zigzag conversion

## Largest number
