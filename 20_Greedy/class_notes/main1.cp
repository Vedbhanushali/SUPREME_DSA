#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}

int solve(int n, int arr[], int dept[]) {
  vector< pair<int, int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({arr[i], dept[i]});
  }

  sort(data.begin(), data.end(), cmp);


  int cnt = 1;
  cout << data[0].first << ", "<< data[0].second << endl;
  int lastDept = data[0].second;
  for(int i=1; i<n; i++) {
    if(data[i].first >= lastDept) {
      //current train can be included
      cnt++;
      lastDept = data[i].second;
      cout << data[i].first << ", "<< data[i].second << endl;    }
  }
  return cnt;
}

int main() {
  int n = 4;
  int arr[] = {5,8,2,4};
  int dept[] = {7,11,6,5};

  int ans = solve(n, arr, dept) ;
  cout << "Answer is:  " << ans << endl;


  return 0;
}