#include <iostream>
#include<algorithm>
using namespace std;

int main() {
  int prices[] = {2,8,6,9,4,7};
  int n = 6;

  //algo starts here
  sort(prices, prices + n);

  int amount = 0;
  int buy = 0;
  int free = n-1;

  while(buy <= free) {
    amount += prices[buy];
    buy++;
    free--;
    free--;
  }
  cout << "asnwer is " << amount << endl;
  return 0;
}