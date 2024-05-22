# Practice Questions of Char array and string

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

<https://leetcode.com/problems/group-anagrams/>

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

### Approach

### Code

```cpp
class Solution {
public:
    std::array <int,256> hash(string s){
        std::array<int,256> h = {0};
        for(int i=0;i<s.size();i++){
            h[s[i]]++;
        }
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* 
        Approach 1
        Sorting approach - more time consuming 
        */
        // map<string, vector<string> > mp ; 
        // for(auto i: strs){
        //     string s = i;
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(i); 
        // }
        // vector< vector<string> > vect ; 
        // for(auto it =  mp.begin() ; it != mp.end(); it++){
        //     vect.push_back(it->second);
        // }
        // return vect;

        /* 
        Approach - 2
        storing freq hash as key in map rather than sorting and storing in map
        */
        /*
        new way to declare array
        std::array <int,256>  hash = {0};  //this method is used to declare array using STL
        // this is same as int hash[256] = {0}
        */

        map<std::array <int,256>, vector<string>> mp ;
        for(auto i: strs){
            mp[hash(i)].push_back(i); 
        }
        vector< vector<string> > vect ; 
        for(auto it =  mp.begin() ; it != mp.end(); it++){
            vect.push_back(it->second);
        }
        return vect;

    }
};
```

## longest palindromic substring

<https://leetcode.com/problems/longest-palindromic-substring/>

Given a string s, return the longest
palindromic

substring
 in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

```cpp
class Solution {
public:
    void expandAroundIndex(string &s,int i,int j,string &ans){
        int count = 0;
        if(i==j) {i--;j++;count++;}
        while(i>=0 && j<s.length() && s[i] == s[j]){
            count+=2;
            i--;
            j++;
        }
        if(count > ans.length()){
            if(i == -1){
                ans = s.substr(i+1,j);
            } else
            ans = s.substr(i+1,j-1-i);
        } 
    }
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int count = 0;
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            //odd
            cout<<endl<<endl<<"odd call"<<endl;
            expandAroundIndex(s,i,i,ans);
            //even
            cout<<"even call"<<endl;
            expandAroundIndex(s,i,i+1,ans);
        }
        return ans;

        // //substring
        // // two pointer approach
        // // odd even moving
        // string largest = "";
        // //odd traversal
        // int i = 0;
        // int n = s.size();
        // int large = 1;
        // while(i<n){
        //     int l = i-1;
        //     int r = i+1;
        //     int count = 1;
        //     for(;l>=0 && r<n;l--,r++){
        //         if(s[l]!=s[r]) break;
        //         count += 2; //mean equal
        //     }
        //     if(count>large){
        //         large = count;
        //         largest = s.substr(l+1,r-1);
        //     }
        //     i++; 
        // }

        // //even traversal
        // i = 0;
        // int j = i+1;
        // while(j<n){
        //     int l = i;
        //     int r = j;
        //     int count = 0;
        //     for(;l>=0 && r<n;l--,r++){
        //         if(s[l]!=s[r]) break;
        //         count += 2; //mean equal
        //     }
        //     if(count>large){
        //         large = count;
        //         largest = s.substr(l+1,r-1);
        //     }
        //     i++;
        //     j++;
        // }
        // return largest;
    }
};
```

## find the index of first occurence in a string

<https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/>

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        /* 
            1st approach using find STL library
        */
        // int n = haystack.find(needle);
        // if(n==string::npos){
        //     return -1;
        // } 
        // return n;

        /* 
            2nd Approach manually writing find function 
        */
        int n = haystack.size();
        int m = needle.size();

        for(int i=0;i<=n-m;i++){
            int j = 0;
            for(;j<m;j++){

                if(needle[j] != haystack[i+j]){
                    break;
                }
            }
            cout<<j<<endl;
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};
```

## string to integer (stoi)

<https://leetcode.com/problems/string-to-integer-atoi/>

```cpp
class Solution {
public:
    int myAtoi(string s) {
        int ans = 0 , i = 0, sign = 1; // 1 considered as +ve
        //wiping all spaces
        while(s[i] == ' '){
            i++;
        }
        //if getting sign considering it
        if(i<s.size() && (s[i]=='+' || s[i]=='-') ){
            sign = s[i]=='-' ? -1 : 1;
            i++;
        }

        while(s.size() && isdigit(s[i])) {
            if((ans > INT_MAX/10) || (ans == (INT_MAX/10)) && (s[i]-'0') > 7 ){
                return sign==1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        return ans*sign;
    }
};
```

## string compression

<https://leetcode.com/problems/string-compression/>

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int count = 1;
        int i=1;
        if(chars.size()<2){
            return chars.size();
        }
        for(;i<chars.size();i++){
            cout<<count<<endl;
            if(chars[i]==chars[i-1]){
                count++;
            } else {
                if(count==1){
                    chars[index++] = chars[i-1];
                    continue;
                }
                if(count < 10){
                    chars[index++] = chars[i-1];
                    chars[index++] = count + '0'; 
                } else {
                    chars[index++] = chars[i-1];
                    int start = index;
                    while(count){
                        chars[index++] = (count % 10) + '0';
                        count = count /10;
                    }
                    reverse(chars.begin()+start,chars.begin()+index);
                }
                count=1;
            }
        }
        if(count>1){
            chars[index++]=chars[i-1];
            if(count < 10){
                    chars[index++] = count + '0'; 
            } else {
                    int start = index;
                    while(count){
                        chars[index++] = (count % 10) + '0';
                        count = count /10;
                    }
                    reverse(chars.begin()+start,chars.begin()+index);
            }
        } else {
            chars[index++] = chars[i-1];  
        }
        for(auto i : chars){
            cout<<i<<" "; 
        }
        cout<<endl;
        return index;

        //another approach using hashMap not working correctly
        //but approach is good
        // int count = 0;
        // unordered_map<char,int> hashMap;
        // string order;
        // for(int i=0;i<chars.size();i++){
        //     if(!hashMap[chars[i]]){
        //         //not found then add
        //         order += chars[i];
        //     }
        //     hashMap[chars[i]]++;
        // }
        // int i = 0;
        // for(auto m:order){
        //     count++;
        //     chars[i++] = m;
        //     if(hashMap[m]==1) continue;
        //     int s = i;
        //     while(hashMap[m]){
        //         count++;
        //         chars[i++] = ('0'+hashMap[m]%10);
        //         hashMap[m] /= 10;
        //     }
        //     reverse(chars.begin()+s,chars.begin()+i);
        // }
        // return count;
    }
};
```

## Integers to roman

<https://leetcode.com/problems/integer-to-roman/>

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string romanToInt[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string  ans = "";
        for(int i=0;i<13;i++){
            while(num>=values[i]){
                num = num - values[i];
                ans = ans + romanToInt[i];
            }
        
        }
        return ans;
    }   
};
```

## Zigzag conversion

<https://leetcode.com/problems/zigzag-conversion/>

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() == 1 || numRows == 1){
            return s;
        }
        vector<string> vect(numRows);
        int row = 0 , i =0,direction = 1; //[1 Top to Down] and [0 - down to top]
        // i to iterate on whole string
        while(true){
            
            if(direction){ //up to down
                while(row < numRows && i < s.size()){
                    vect[row++].push_back(s[i++]);
                }
                row = row - 2;
            } else { // down to top
                while(row >= 0  && i<s.size()){
                    vect[row--].push_back(s[i++]);
                }
                row = 1;
            }
            
            if(i>= s.size()){
                break;
            }
            direction = !direction;
        }

        string ans="";
        for(int i=0;i<numRows;i++){
            ans += vect[i];
        }
        return ans;
    }
};
```

## Largest number

<https://leetcode.com/problems/largest-number/>

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

Example 1:

Input: nums = [10,2]
Output: "210"

```cpp
class Solution {
public:
    static bool my_comparator(int a, int b) { 
        string a_str = to_string(a);
        string b_str = to_string(b);
        return a_str+b_str > b_str+a_str;
        /*
        if(a==b){
            return false;
        }
        int x =a,y=b;
        vector<int> a_vect;
        vector<int> b_vect;
        while(a){
            a_vect.push_back(a%10);
            a = a/10;
        }
        while(b){
            b_vect.push_back(b%10);
            b = b/10;
        }
        reverse(a_vect.begin(),a_vect.end());
        reverse(b_vect.begin(),b_vect.end());
        // for(auto i:a_vect){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:b_vect){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        int i = 0;
        while(i<a_vect.size() && i<b_vect.size()){
            if(a_vect[i]==b_vect[i])
            i++;
            else
            break;
        }
        cout<<i<<endl;
        if(i==a_vect.size() && i==b_vect.size()){
            cout<<"a is bigger"<<x<<" "<<y<<endl;
            return true;
        }
        if(i==a_vect.size() && i<b_vect.size()){
            //cout<<"a is bigger"<<x<<" "<<y<<endl;
            if(b_vect[i]<=a_vect[0]){
                return true; //a first
            } else {
                return false; //b first
            }
            
        } else if (i<a_vect.size() && i==b_vect.size()){
            cout<<"b is bigger"<<x<<" "<<y<<endl;
            if(a_vect[i]<b_vect[0]){
                return false; //b first
            } else {
                return true; // a first
            }
            //return false; //b first
        } else {
            if(a_vect[i]>b_vect[i]){
                cout<<"a is bigger"<<x<<" "<<y<<endl;
                return true;
            } else {
                cout<<"b is bigger"<<x<<" "<<y<<endl;
                return false;
            }
        }
        //return false;
        // if()
        // if(a_vect[i-1]==b_vect[i]){
        //     if(i<a_vect.size()){
        //         return true;
        //     } else {
        //         return false;
        //     }
        // } else {
            
        // }
        */
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),my_comparator);
        string ans = "";
        for(int i=0;i<nums.size();i++){
            string t = to_string(nums[i]);
            if(t[0]=='0' && ans=="0"){
                continue;
            }
            ans = ans + to_string(nums[i]);
        }
        return ans;
    }
};
```

## Palindrome Partitioning

<https://leetcode.com/problems/palindrome-partitioning/description/>

```cpp
class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void solve(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        solve(0, s, path, ret);
        return ret;
    }
};
```