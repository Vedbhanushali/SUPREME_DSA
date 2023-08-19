#include <iostream>
using namespace std;

void solve(int** ptr) {
        //ptr = ptr + 1;

        //*ptr = *ptr + 1;

        **ptr = **ptr + 1;
}

int main() {
        int x = 12;
        int* p = &x;
        int** q = &p;
        solve(q);

        cout << x << endl;

  return 0;
}