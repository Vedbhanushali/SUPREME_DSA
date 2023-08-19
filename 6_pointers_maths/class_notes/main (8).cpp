#include <iostream>
using namespace std;

void util(int* p )
{
        // p = p + 1;
        *p = *p + 1;
}

int main() {
  int a = 5;

  int* p = &a;

  cout << "before" << endl;
  cout << a << endl;
  cout << p << endl;
  cout << *p << endl;

  util(p);

  cout << endl << "after" << endl;
  cout << a << endl;
  cout << p << endl;
  cout << *p << endl;
  return 0;
}