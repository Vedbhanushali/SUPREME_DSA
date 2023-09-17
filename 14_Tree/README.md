# Tree

Tree is non linear data structure

## Types of Tree

- Binary tree : Tree with at most two child is called binary tree
- N-ary tree : Tree nodes can have atmost n childs of zero.
- skew tree : all node after root in left or right

## Terms of Tree

- node : data structure smallest unit
    binary tree node

    ```cpp
    class Node{
        int data;
        Node* left;
        Node* right
    };
    ```

    N-ary tree node

    ```cpp
    class Node{
        int data;
        vector<Node* > child;
    }
    ```

- root : top most node of tree
- parent : node just above level of given node is parent node
- child : node just below level of given node is child node
- ancestor: all node above level till root of given node are all ancestor.
- descendant: all node below level till leaf of given node
- sibling : all child of same parents are sibling
- leaf : node which doesn't have any children

## Tree Traversals

- level order
- inorder/preorder/postorder
- morris order

## Building tree

- create using level order traversal

- create using recusively
    create root node  
    root-> left - recursion()  
    root-> right - recursion()

    example - 20,30,50,-1,60,-1,-1,40,-1,-1,100,-1,-1

    for data == -1 consider null value

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
            left = NULL;
            right = NULL;
        } 
    };
    Node* buildTree(){
        int data;
        cout<<"Enter data"<<endl;
        cin>>data;
        
        if(data == -1){
            return NULL;
        }
        Node * root = new Node(data);
        cout<<"Enter data for left node of "<<data<<endl;
        root->left = buildTree();
        cout<<"Enter data for left node of "<<data<<endl;
        root->right = buildTree();
        return root;
    }
    ```

## Level order Traversal

using queue

```cpp
void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    //Order will be left to right
    while(!q.empty()){

        Node* temp = q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    //for right to left traversal reverse the order
    /*
    while(!q.empty()){

        Node* temp = q.front();
        q.pop();
        cout<<temp->data;
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    */
}

void levelOrderTraversalNewLine(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    //Order will be left to right
    while(!q.empty()){

        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.emtpy()) q.push(NULL);

        } else {
            cout<<temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
```

## Inorder Traversal - LNR

```cpp
void inorderTraversal(Node * root){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorderTraversal(Node->left);
    cout<<root->data;
    inorderTraversal(Node->right);
}
```

## PreOrderTraversal - NLR

```cpp
void preorderTraversal(Node * root){
    //base case
    if(root == NULL){
        return;
    }

    //NLR
    cout<<root->data;
    preorderTraversal(Node->left);
    preorderTraversal(Node->right);
}
```

## PostOrder traversal - LRN

```cpp
void postorderTraversal(Node * root){
    //base case
    if(root == NULL){
        return;
    }

    //LRN
    postorderTraversal(Node->left);
    postorderTraversal(Node->right);
    cout<<root->data;
}
```

HW //TODO  

- Inorder/preorder/postorder traversal using iterative
- create tree using level order traversal

## Maximum depth / height of tree

<https://leetcode.com/problems/maximum-depth-of-binary-tree/>

```cpp
int height(Node* root){
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight,rightHeight)+1;
    return ans;
}
```

## Maximum depth / height of N-ary tree

<https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/>

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)return 0;
        // cout<<root->val;
        if(root->children.size() == 0)return 1;
        int maxD = 0;
        for(auto node: root->children){
            maxD = max(maxD, maxDepth(node));
        }

        return 1+maxD;
        
    }
};
```

## Diameter of Tree

<https://leetcode.com/problems/diameter-of-binary-tree/>

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        //ans left main hoga root ko consider nahi karke
        int op1 = diameterOfBinaryTree(root->left);
        //ans right main hoga root ko consider nahi karke
        int op2 = diameterOfBinaryTree(root->right);

        //ans left ki max height or root and right ki max height ko milakar hoga
        int op3 = maxDepth(root->left) + maxDepth(root->right);

        return max(op1,max(op2,op3));
    }
};
```

HW

## Check if two tree are identical or not //TODO

## check if two trees are mirror images of each other or not //TODO

## balanced binary tree //TODO

property of any node - height absolute diff <=1
