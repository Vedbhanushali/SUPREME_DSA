#include <iostream>
using namespace std;

void solve(int arr[]) {
        cout <<"Size inside solve function " << sizeof(arr) << endl;
        cout <<"arr: " << arr << endl;
        cout << "&arr: " << & arr << endl;

        arr[0] = 50;
}

void update(int *p) {
        cout << "Address stored inside p is: " << p << endl;
        cout << "Address of p  is:" << &p << endl;
        *p = *p + 10;
}

int main() {

        //int arr[4] = {12,44,66,18};

        // cout << arr << endl;
        // cout << arr[0] << endl;
        // cout << &arr << endl;
        // cout << &arr[0] << endl;

        // int* p = arr;
        // cout << p << endl;
        // cout << &p << endl;

        // cout << *arr << endl;
        // cout << arr[0] << endl;
        // cout << *arr + 1 << endl;
        // cout << *(arr) + 1 << endl;
        // cout << *(arr + 1) << endl;
        // cout << arr[1] << endl;
        // cout << *(arr + 2) << endl;
        // cout << arr[2] << endl;
        // cout << *(arr + 3) << endl;
        // cout << arr[3] << endl;

        // int i = 0;
        // cout << arr[i] << endl;
        // cout << i[arr] << endl;
        // cout << *(arr + i) << endl;
        // cout << *(i + arr) << endl;

        // //arr = arr + 2;

        // // int* p = arr;
        // // p = p + 2;

        // // int arr[10];
        // // cout << sizeof(arr) << endl;

        // // int* p = arr;
        // // cout << sizeof(p) << endl;

        // // cout << sizeof(*p) << endl;

        // // char ch[10] = "Babbar";
        // // char* c = ch;

        // // cout << ch << endl;
        // // cout << &ch << endl;
        // // cout << ch[0] << endl;

        // // cout << &c << endl;
        // // cout << *c << endl;
        // // cout << c << endl;

        // char name[9] = "SherBano";
        // char* c = &name[0];

        // cout << name << endl;
        // cout << &name << endl;
        // cout << *(name + 3) << endl;
        // cout << c << endl;
        // cout << &c << endl;
        // cout << *(c + 3) << endl;
        // cout << c+2 << endl;
        // cout << *c << endl;
        // cout << c+8 << endl; 

        // char ch = 'k';
        // // char* cptr = &ch;

        // // cout << cptr << endl;

        // // char name[10] = "babbar";
        // // cout << name << endl;

        // // char* c = "babbar";
        // // cout << c << endl;


        // int arr[10] = {1,2,3,4};
        // cout << "Size inside main function. " << sizeof(arr) << endl;
        // cout << arr << endl;
        // cout << &arr << endl;

        // //printing array inside main
        // for(int i=0; i<10; i++) {
        //         cout << arr[i] << " ";
        // }cout << endl;
        // cout << endl << endl << "Now calling solve function" << endl;

        // solve(arr);

        // cout << "Wapas main function me aagye h " << endl;

        // for(int i=0; i<10; i++) {
        //         cout << arr[i] << " ";
        // }cout << endl;

        int a = 5;
        cout << "Address of a is: " << &a << endl;
        int* ptr = &a;
        cout << "address stored in ptr is: " << ptr << endl;
        cout << "Address of ptr is: " << &ptr << endl;
        update(ptr);
        cout<<"value of a is: " << a << endl;



        return 0;
}