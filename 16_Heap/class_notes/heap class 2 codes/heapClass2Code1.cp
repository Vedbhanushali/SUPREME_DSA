#include <iostream>
#include <queue>
using namespace std;

int main() {
  //max-heap
  priority_queue<int> pq;
  pq.push(3);
  pq.push(6);
  pq.push(9);
  pq.push(4);
  pq.push(8);

  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "Size: " << pq.size() << endl;
  if(pq.empty()) {
          cout << "Max heap is empty" << endl;
  }
  else {
          cout << "Max heap is not empty" << endl;
  }




  return 0;
}