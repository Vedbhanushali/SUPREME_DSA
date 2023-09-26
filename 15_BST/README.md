# BST

for every node  
left subtree data < root->data < right subtree data  

## BST creation

```cpp
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* InsertIntoBST(Node* root,int data){
    if(root == NULL){
        Node* newNode = new Node(data);
        return newNode;
    }

    if(root->data > data){
        root->left = InsertIntoBST(root->left,data);
    } else {
        root->right = InsertIntoBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int d;
    cin>>d;
    while(d != -1){
        root = InsertIntoBST(root,d);
        cin>>d;
    }
}
int main() {
    Node* root = NULL;
    cout<<"Enter Data";
    takeInput(root);
    return 0;
}

```
