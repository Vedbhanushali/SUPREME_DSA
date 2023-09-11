#include<isotream>
using namespace std;

class NStack {
    int *a,*top,*next;
    int n; // not of stack
    int size; //size of a array
    int freeSpot; // tells free space in main array

    public:
    NStack(int _n,int _s):n(_n),size(_s) {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i=0;i<n;i++){
            top[i] = -1;
        }
        for(int i=0;i<size-1;i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }
    //push X into mth stack
    bool push(int X,int m){ // m is stack number which stack to push
        if(freeSpot == -1){
            return false;
            //stack is full Overflow
        }

        //1. find index;
        int index = freeSpot;

        //2. update freespot
        freeSpot = next[index];

        //3. insert
        a[index] = X;

        //4. next update
        next[index] = top[m-1];

        //5. update top
        top[m-1] = index;

        return true; //pushed successfully
    }

    //pop from mth stack
    int pop(int m){
        if(top[m-1] == -1) {
            return -1; 
            //stack underflow
        }

        //steps reverse of push
        int index = top[m-1];

        top[m-1] = next[index];

        int poppedElement = a[index];

        next[index] = freeSpot;
        freeSpot = index;

        return poppedElement;
    }

    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
}
int main() {
    NStack s(3,6);
    cout<<s.push(10,1); //true
    cout<<s.pop(1); // 10
    return 0;
}