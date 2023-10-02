# Assignments

## Find inorder successor and inorder predecessor in a BST

The inorder predecessor Of a node p is the node q that comes just before p in the binary tree's inorder traversal.
Given the root node of a binary search tree and the node p , find the inorder predecessor of node p . If it does not exist. return null.

Approach -

1. perform inorder traversal on BST and store ans in vector, using Binary search find target and return number next to it that will be its successor and number before it would be predecessor.
2. perform inorder traversal and find one value which is just greater than x will be successor and for predecessor keep one variable which will keep track of number less than x , maximize x to find inorder predecessor by updating on every node of inorder traversal.
3. normal BST approach of comparing root and making decision of moving forward. (Most IMP below is the code)

<https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1>

```cpp
Node* findPredecessor(Node* root,Node* p){
    Node* pred = NULL;
    Node* curr = root;
    while(curr){
        if(curr->data < p->data){
            pred = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return pred;
}
Node* findSuccessor(Node* root,Node* p){
    Node* succ = NULL;
    Node* curr =  root;
    while(curr){
        if(curr->data <= p->data){
            curr = curr->right;
        } else {
            succ = curr;
            curr = curr->left;
        }
    }
    return succ;
}
```

## Construct BST from preorder traversal

<https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/>

### approach

1. find Inorder from preorder by sorting it. now we have inorder and preorder we can generate tree from it.

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
    int findposition(vector<int>&inorder,int size,int element){
        int index = -1;
        for(int i=0;i<size;i++){
            if(element == inorder[i]) index = i;
        }
        return index;
    }
    TreeNode* buildTreeFromInorderPreorder(vector<int>&inorder,vector<int>&preorder, int size,int &preIndex,int inorderStart,int inorderEnd){
        //base case
        if(preIndex >= size || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = findposition(inorder,size,element);

        root->left = buildTreeFromInorderPreorder(inorder,preorder,size,preIndex,inorderStart,pos-1);
        root->right = buildTreeFromInorderPreorder(inorder,preorder,size,preIndex,pos+1,inorderEnd);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        vector<int> inorder(size);
        for(int i =0;i<size;i++){
            inorder[i] = preorder[i];
        }
        sort(inorder.begin(),inorder.end());
        int preIndex = 0;
        return buildTreeFromInorderPreorder(inorder,preorder,size,preIndex,0,size-1);
    }
};
```

2. BST approach using range code below

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
    TreeNode* build(int &i,int min,int max,vector<int>& preorder){
        if(i >= preorder.size()){
            return nullptr;
        }
        TreeNode* root = nullptr;
        if(preorder[i] > min && preorder[i] < max){
            root = new TreeNode(preorder[i++]);
            root->left = build(i,min,root->val,preorder);
            root->right = build(i,root->val,max,preorder);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN;
        int max = INT_MAX;
        int i =0;
        return build(i,min,max,preorder);
    }
};
```

## Convert a normal BST into a Balanced BST

4. Merge two BST
5. Count pairs from 2 BST whose sum is equal to given value "X"
6. Find the median of BST in O(n) time and 0(1) space
7. Count BST nodes that lie in a given range
8. Replace every element with the least greater element on its right
9. Check preorder is valid or not
10. Check whether BST contains Dead end:
11. Flatten BST to sorted list
