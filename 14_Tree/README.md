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

## Check if two tree are identical or not

<https://leetcode.com/problems/same-tree/>

```cpp
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p == NULL && q!=NULL) return false;
            if(p != NULL && q==NULL) return false;
            if(p == NULL && q == NULL) return true;

            //NLR
            if(p->val != q->val) return false;
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};
```

## check if two trees are mirror images of each other or not

<https://leetcode.com/problems/symmetric-tree/>

```cpp
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
    bool check(TreeNode* p,TreeNode* q){
        if(p == NULL && q!=NULL) return false;
        if(p != NULL && q==NULL) return false;
        if(p == NULL && q == NULL) return true;
        //NLR
        if(p->val != q->val) return false;
        return check(p->left,q->right) && check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};
```

## Check if binary tree is balanced binary tree

<https://leetcode.com/problems/balanced-binary-tree/>

property of any node - height absolute diff <=1  
each node abs(left subtree height - right subtree height) <=1

```cpp
int height(TreeNode* root){
    if(root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}
bool isBalanced(TreeNode* root){

    //base case
    if(root == NULL) return true;

    //1 case
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight-rightHeight);

    bool ans = (diff<=1);

    //recustion
    bool leftans = isBalanced(root->left);
    bool rightans = isBalanced(root->right);

    if(ans && leftans && rightans){
        return true;
    } else {
        return false;
    }

}
```

## Check whether BT is sum tree or not / convert BST into sum tree

```cpp
int convertIntoSumTree(TreeNode* root){
    if(root == NULL) return 0;

    int leftans = convertIntoSumTree(root->left);
    int rightans = convertIntoSumTree(root->right);
    root->data = leftans + root->data + rightans;
    return root->data;
}
```

## Lowest common Ancestor

<https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;

        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);

        if(leftans == NULL && rightans == NULL) return NULL;
        else if(leftans != NULL && rightans == NULL) return leftans;
        else if(leftans == NULL && rightans !=NULL) return rightans;
        else{
            return root;
        }
    }
};
```

## Kth ancestor

find p
k step up till (k--) k == 0 ans is found

```cpp
bool kthAncestor(Node* root,int &k,Node* p){

    if(root == NULL){
        return false;
    }

    if(root->val == p->val) return true;

    bool leftAns = kthAncestor(root->left,k,p);
    bool rightAns = lthAncestor(root->right,k,p);

    if(leftAns || rightAns) k--;

    if(k == 0) {
        //yahi par faste hai
        k = -1;
        // k pass by referece hai to agar ans mil gaya hai to 
        // vapas na maile isliye isko negative kar diya
        cout<<"Answer is :"<<root->data;
    }

    return leftAns || rightAns;
}
```

## Path Sum

<https://leetcode.com/problems/path-sum/>

```cpp
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
    bool solve(TreeNode* root,int t,int sum){
        if(root == NULL) return false;
        if(sum+root->val == t && !root->left && !root->right) return true;
        //left search and right search
        bool left = solve(root->left,t,sum+root->val);
        if(left) return true;
        bool right = solve(root->right,t,sum+root->val);
        return right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};
```

## Path Sum II

<https://leetcode.com/problems/path-sum-ii/>

```cpp
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
    void solve(TreeNode* root,int t,int sum,vector<int> &curr,vector<vector<int>> &ans){
        if(root == NULL) return;
        
        
        curr.emplace_back(root->val);
        if(sum+root->val == t && !root->left && !root->right){
            //ans
            ans.emplace_back(curr);
        }
        //left search and right search
        solve(root->left,t,sum+root->val,curr,ans);
        solve(root->right,t,sum+root->val,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> curr;
        solve(root,targetSum,0,curr,answer);
        return answer;
    }
};
```

## Sum of longest bloodline TODO

## build tree from inorder and preorder traversal

and
build tree from inorder and postorder traversal

```cpp
//this function can be optimized using hashMap key as element and value as index of element of inrder
int findposition(int inorder[],int size,int element){
    int index = -1;
    for(int i=0;i<size;i++){
        if(element == inorder[i]) index = i;
    }

    return index;
}
Node* buildTreeFromInorderPreorder(int inorder[],int preorder[], int size,int &preIndex,int inorderStart,int inorderEnd){
    //base case
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    int element = preorder[preIndex++];
    Node* root = new Node(element);
    int pos = findposition(inorder,size,element);

    root->left = buildTreeFromInorderPreorder(inorder,preorder,size,preIndex,inorderStart,pos-1);
    root->right = buildTreeFromInorderPreorder(inorder,preorder,size,preIndex,pos+1,inorderEnd);

    return root;
}
Node* buildTreeFromInorderPostOrder(int inorder[],int postOrder[],int size,int &postIndex,int inorderStart,int inorderEnd){
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int element = postIndex[postIndex];
    postIndex--;
    Node* root = new Node(element);
    int pos = findposition(inorder,size,element);

    root->right = buildTreeFromInorderPostOrder(inorder,preorder,size,preIndex,pos+1,inorderEnd);
    root->left = buildTreeFromInorderPostOrder(inorder,preorder,size,preIndex,inorderStart,pos-1);

    return root;
}
```

## Top View of binary Tree

```cpp
void printTopView(Node* root){
    if(root == NULL) return;

    //create a map for storing horizontal distance of topnodes
    map<int,int> topNode;

    //level order;
    //we will store a pair consisting of node and horizontal distance
    queue<pair<Node* ,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int HD = temp.second;

        if(topNode.find[hd]==topNode.end()){ //not found hd
            topNode[hd] = frontNode->data;
        }
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left,HD-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right,HD+1));
    }

    //ans in topNode map
    cout<<"Answer is"<<endl;
    for(auto i:topNode){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
```

## Bottom View of Binary Tree

```cpp
void printBotto,View(Node* root){
    if(root == NULL) return;

    //create a map for storing horizontal distance of topnodes
    map<int,int> topNode;

    //level order;
    //we will store a pair consisting of node and horizontal distance
    queue<pair<Node* ,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int HD = temp.second;

        
        topNode[hd] = frontNode->data;
        
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left,HD-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right,HD+1));
    }

    //ans in topNode map
    cout<<"Answer is"<<endl;
    for(auto i:topNode){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
```
