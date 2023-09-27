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

## Inorder of BST

inorder traversal of BST tree gives nodes in sorted order

## Searching in BST

TC - O(log n)

```cpp
//assuming there are only unique values in tree
bool findNodeInBST(Node * root,int &target){
    //base case
    if(root == NULL) return false;

    if(root->data == target) return true;

    if(target > root->data){
        return findNodeInBST(root->right,target);
    } else {
        return findNodeInBST(root->left,target);
    }
}
//iterative solution
 TreeNode* searchBST(TreeNode* root, int val) {
       while(root != NULL && root->val != val){
           root = root->val > val ? root->left : root->right;
       }
       return root;
 }

/* -------- Normal Tree Search , if not BST then also this tree search will work TC - O(n) ------- */
 TreeNode* searchBST(TreeNode* root, int &val) {
        
        if(root == NULL) return NULL;

        if(root->val == val) return root;

        TreeNode* l = searchBST(root->left,val);
        TreeNode* r = searchBST(root->right,val);

        if(l) return l;
        return r;
 }
```

## Minimum and Maximum value in BST

- Minimum - go left-left till leaf node , and that leaf node is smallest value of BST
- Maximum - go right-right till leaf node, and that leaf node is largest value of BST

```cpp
int minVal(Node* root){
    Node* temp = root;
    if(temp == NULL) return NULL;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
int maxVal(Node* root){
    Node* temp = root;
    if(temp == NULL) return NULL;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
```

## Inorder Predeccessor / Successor
