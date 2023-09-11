#include <iostream>
using namespace std;

class Stack {
       
        private:
        int *arr;
        int top;
        int size;

 public:
        Stack(int size) {
                arr = new int[size];
                this-> size = size;
                top = -1;
        }

        //functions
         
        void push(int data) {
                if(size - top > 1) {
                        //space available
                        //insert
                        top++;
                        arr[top] = data;
                }
                else {
                        //space not available
                        cout << "Stack Overflow"<< endl;
                }
        }

        void pop() {
                if(top == -1 ) {
                        //stack is empty
                        cout << "Stack underflow, cant delete element" << endl;
                }
                else {
                        //stack is not empty
                        top--;
                }
        }

        int getTop() {
                if(top == -1) {
                        cout << "There is not element in Stack " << endl;
                }
                else {
                        return arr[top];
                }
        }

        //return number of valid elements present in stack
        int getSize() {
                return top + 1;
        }

        bool isEmpty() {
                if(top == -1) {
                        return true;
                }
                else {
                        return false;
                }

        }
};

int main() {

  //CREATION
  Stack s(5);

  //insertion
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  //s.push(60);

  while(!s.isEmpty()) {
          cout << s.getTop() << " ";
          s.pop();
  }cout << endl;

  cout << "Size of stack " << s.getSize() << endl;

  s.pop();

  return 0;
}