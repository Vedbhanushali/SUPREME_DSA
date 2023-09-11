#include <iostream>
#include<stack>
using namespace std;

int main() {

        //creation
        // stack<int> st;

        // //insertion
        // st.push(10);
        // st.push(20);
        // st.push(30);
        // st.push(40);

        // //remove
        // st.pop();

        // //check element on top
        // cout << "Element on top is: " << st.top() << endl; 

        // //size
        // cout << "size of stack is: " << st.size() << endl;

        // if(st.empty()) 
        //         cout << "stack is empty" << endl;
        // else
        //         cout << "stack is not empty" << endl;                



        stack<int> s;

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);

        while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
        }
        cout << endl;


        return 0;
}