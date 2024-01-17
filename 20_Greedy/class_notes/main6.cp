#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
  int n = 7;
  int m = 3;
  int arr[] = {7,3,2,4,9,12,56};
  //sort
  sort(arr, arr + n);

  //check differences in m-size window
  int i = 0;
  int j = m-1;
  int diff = INT_MAX;
  while(j<n) {
    int newDiff = arr[j] - arr[i];
    diff = min(diff, newDiff);
    j++;
    i++;
  } 
  cout << "Answer is: " << diff << endl;




  return 0;
}