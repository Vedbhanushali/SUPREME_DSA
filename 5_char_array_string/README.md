# Char array and string

## cin

cin reads character reads till it finds space,tab or new line

## to read complete line

```c++
char ch[100];
cin.getline(ch,50); // 50 here is maximum size till we want to read
cout<<ch
```

## check palindrome

1. Approach two pointers

   ```c++
   string s = "ved";
   int i = 0;
   int j = s.length()-1;
   while(i<j){
       if(s[i] != s[j]){
           return false;
       }
       i++;
       j--;
   }
   return true;
   ```

2. Approach reverse - if both string are same then palindrome

   ```c++
   string s = "ved";
   string scopy = s;
   reverse(s.begin(), s.end());
   if(s==s.copy) return true
   else return false
   ```

## Remove duplicates

```c++
 string s = "abbaccca";
  sort(s.begin(),s.end());
  string ans;
  ans += s[0];
  int top = 0;
  for(int i=1;i<s.length();i++){
    if(ans[top]==s[i]) continue;
    ans += s[i];
    top++;
  }
  cout<<ans;
  return 0;
```

## Remove all occurrences of part from main string

```cpp
string s;
string part;
cin>>s>>part;
int pos = s.find(part);
while(pos!=string::npos){
    s.erase(pos,part.length());
    pos = s.find(part);
}
return s; //removed part from s
```

## Valid palindrome 2

if we delete any one char can we make palindrome

```cpp
bool check_palindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
main(){
    string s;
    cin>>s;
    int i = 0;
    int j = s.length()-1;
    while(i<=j){
        if(s[i] !=s[j]){
            // ek bar i ko remove
            // ek bar j ko remove
            return checkpalindrome(s,i+1,j) || checkpalindrome(s,i,j+1);
        }
        i++;
        j--;
    }
    return false;
}
```

## Minimum time difference

list of 24 hour clock time return minimum minutes difference between any two time points

timePoints = ["12:10","10:15","17:50","18:00"]

```cpp
main() {
    //first convert all time to minutes
    vector<int> minutes;
    for(int i=0; i<timePoints.size(); i++) {
        string arr = timePoints[i];
        int hours = stoi(arr.substr(0,2));
        int minutes = stoi(arr.substr(3,2));
        int totalMinutes = hours * 60 + minutes;
        minutes.emplace_back(totalMinutes);
    }
    // now sorting to get all values near to each other
    sort(minutes.begin(), minutes.end());
    int mini = INT_MAX;
    for(int i=1;i<minutes.size();i++) {
        mini = min(mini, minutes[i]-minutes[i-1]);
    }
    // 1440 is 24hr in minutes make 1 day forward to get +ve difference
    int lastDiff = (minutes[0] + 1440) - minutes[minutes.size()-1];
    mini = min(mini, lastDiff);
    return mini;
}
```

## Palindromic substring

<https://leetcode.com/problems/palindromic-substrings/>

approach two pointer, even length substring and odd length substring check one by one by expanding pointers

```cpp
class Solution {
public:
    int expandAroundIndex(string s , int i, int j){
        int  count = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for(int i=0;i<n;i++){
            //odd approach
            int oddAns = expandAroundIndex(s,i,i);
            //even approach
            int evenAns = expandAroundIndex(s,i,i+1);
            count = count + oddAns + evenAns;
        }
        return count;
    }
};
```
