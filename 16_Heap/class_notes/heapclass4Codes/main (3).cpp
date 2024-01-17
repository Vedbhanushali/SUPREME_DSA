#include <iostream>
#include<queue>
#include<vector>
using namespace std;
 
int signum(int a , int b) {
        if(a == b) 
                return 0;
        if(a > b )
                return 1;
        if(a < b)
                return -1;
}

void callMedian(double &median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap, int element) {

        switch(signum(minHeap.size(), maxHeap.size())) {
                case 0:if(element > median) {
                        minHeap.push(element);
                        median = minHeap.top();
                        }
                        else {
                        maxHeap.push(element);
                        median = maxHeap.top();
                       }
                        break;
                case 1: if(element > median ) {
                        int minTop = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(minTop);
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        else {
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        break;
                case -1: if(element > median) {
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                         }
                         else {
                        int maxTop = maxHeap.top();
                        maxHeap.pop();
                        minHeap.push(maxTop);
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        break;

        }

}

int main() {
        int arr[12] = {5,15,1,3,2,8,7,9,10,6,11,4};
        int n = 12;

        //5 6 5 6 5 6
        double median = 0;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int i=0; i<n; i++) {
                int element = arr[i];
                callMedian(median, maxHeap,minHeap, element);
                cout << "arr[i]->median:  " << median << endl;
        }cout << endl;



        return 0;
}