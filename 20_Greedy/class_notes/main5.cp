#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  double ratio1 = ((1.0)*a.first) / a.second;
  double ratio2 = ((1.0)*b.first) / b.second;
  return ratio1 > ratio2;
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int n= 3;
  int capacity = 50;

  vector<pair<int,int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({val[i], wt[i]});
  }

  sort(data.begin(), data.end(), cmp);
  int totalValue = 0;
  //check eac items k entire itm lelu ya frraction lu
  for(int i=0;i<n; i++) {
    pair<int,int> item = data[i];
    int itemValue = item.first;
    int itemWeight = item.second;
    //entire inclusioon wala case
    if(itemWeight <= capacity) {
      //add kardo value ko
      totalValue += itemValue;
      //update krdo capacity ko
      capacity = capacity - itemWeight;
    }
    else {
      //fraction include krdo
      //update value
      double ratio = ((1.0)*itemValue) / itemWeight;
      int valueToAdd = ratio * capacity;
      totalValue += valueToAdd;

      //udpate capacity;
      capacity = 0;
    }
  }
  cout << "Answer is: "<< totalValue << endl;
  return 0;
}