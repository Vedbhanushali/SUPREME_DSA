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

Inorder Predeccessor of root is max of root->left  

```cpp
Node* findMax(Node* root){
    if(root == NULL) return NULL;
    TreeNode* r = root;
    while(r->right){
        r = r->right;
    }
    return r;
}
Node* findPredecessor(Node* root){
    return findMax(root->left);
}
```

Inorder Successor of root is min of root->right  

Inorder traversal of BST IP - 1 2 4 5 7 10  
for 4 - 2 is predecessor
for 4 - 5 is successor  

In case there is not left subtree for predeccessor then calculate inorder traversal and find the predeccessor

In case there is not right subtree for Successor then calculate inorder traversal and find the Successor

## Deletion in BST

three cases

- root node does not have any children root->left == NULL and root->right == NULL then delete root nodeby sending NULL to its parent node;
- root node  have one children either root->left == NULL or root->right == NULL then delete root nodeby sending not null child of root to its parent node;
- root node  have two children either root->left != NULL and root->right != NULL then delete root nodeby replacing root data with root's predecessor or successor;

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
    int maxVal(TreeNode* root){
        TreeNode* temp = root;
        if(temp == NULL) return NULL;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            if(root->left == NULL && root->right==NULL){
                delete root;
                return NULL;
            } else if(root->left !=NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else if(root->left == NULL && root->right!=NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else {
                int predecessor = maxVal(root->left);
                root->val = predecessor;
                root->left = deleteNode(root->left,predecessor);
                return root;
            }
        } else if(root->val > key){
            root->left = deleteNode(root->left,key);
        } else {
            //root->data < key
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};
```

## Validate BST

<https://leetcode.com/problems/validate-binary-search-tree/>

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
    bool solve(TreeNode* root,long low,long high){
        if(root == NULL) return true;
        if(root->val <= low || root->val >= high) return false;

        return solve(root->left,low,root->val) && solve(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
```

## Lowest common ancestor

cases

- p and q < root , then go in left
- p and q > root , then go in right
- p == root || q == root , then it is answer
- p < root && q > root or vise versa mean p and q are in diff branch then root node is answer

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
        if(p->val == root->val || q->val == root->val) return root;
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        } else if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right,p,q); 
        } else {
            //both in diff branch
            return root;
        }
    }
};
```

## Kth Smallest Element in a BST

<https://leetcode.com/problems/kth-smallest-element-in-a-bst/>

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
    void solve(TreeNode* root,int &k,int &ans){
        if(root == NULL) return;
        solve(root->left,k,ans);
        k--;
        if(k == 0) {ans = root->val; return;}
        solve(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
         int ans = root->val;
         solve(root,k,ans);
         return ans;
    }
};
```

## create BST from  Inorder Traversal

<https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/>

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
    TreeNode* solve(vector<int>& nums,int s,int e){
        if(s > e) return NULL;

        int mid = s + (e-s)/2;
        int data = nums[mid];
        TreeNode* root = new TreeNode(data);
        root->left = solve(nums,s,mid-1);
        root->right = solve(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);   
    }
};
```

## Convert a BST into balanced BST

## 2 SUM in BST

approach -

- traversal whole tree and for each node , find target-node in tree TC - (n for traversal) and for each n - (searchin in BST - logn) so O(n) - nlogn
- Travere Inorder BST and store in array, here data is sorted now using two pointer approach we start and end we can find sum.

<https://leetcode.com/problems/two-sum-iv-input-is-a-bst/>

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
    void storeInorder(TreeNode* root,vector<int>& inorder){
        if(root == NULL) return;

        storeInorder(root->left,inorder);
        inorder.emplace_back(root->val);
        storeInorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root,inorder);
        int s = 0;
        int e = inorder.size() - 1;
        while(s < e){
            int sum = inorder[s] + inorder[e];
            if(sum == k) return true;
            if(sum > k){
                e--;
            } else {
                s++;
            }
        }
        return false;
    }
};
```
