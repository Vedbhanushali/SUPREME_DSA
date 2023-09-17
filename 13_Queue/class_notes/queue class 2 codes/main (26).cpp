#include <iostream>
#include<deque>

using namespace std;

void solve(int arr[],int n, int k ) {
        deque<int> q;
        //process first window of size k 
        for(int i=0; i<k; i++) {
                if(arr[i] < 0) {
                        q.push_back(i);
                }
        }

        //remaining window ko process kro
        for(int i=k; i<n; i++) {
                //answer dedo purani wondow ka 
                if(q.empty()) {
                        cout << 0 << " ";
                }
                else {
                        cout << arr[q.front()] << " ";
                }

                //out of window elements ko remove krdo
                while((!q.empty()) && (i - q.front() >= k)) {
                        q.pop_front();
                }

                //check current element for insertion 
                if(arr[i] < 0 ) 
                        q.push_back(i);

        }

        //answer print karonfor last window
       if(q.empty()) {
                cout << 0 << " ";
        }
        else {
                cout << arr[q.front()] << " ";
        }


}

int main() {
  int arr[] = {12,-1,-7,8,-15,30,16,28};
  int size = 8;
  
  int k = 3;

  solve(arr,size,k);



  return 0;
}