# Assignment of Tree

1. Fast way to find Diameter of a tree
<https://leetcode.com/problems/diameter-of-binary-tree/>

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
    // int maxDepth(TreeNode* root) {
    //     if(root == NULL) return 0;

    //     int leftHeight = maxDepth(root->left);
    //     int rightHeight = maxDepth(root->right);
    //     return max(leftHeight,rightHeight)+1;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == NULL) return 0;

    //     //ans left main hoga root ko consider nahi karke
    //     int op1 = diameterOfBinaryTree(root->left);
    //     //ans right main hoga root ko consider nahi karke
    //     int op2 = diameterOfBinaryTree(root->right);

    //     //ans left ki max height or root and right ki max height ko milakar hoga
    //     int op3 = maxDepth(root->left) + maxDepth(root->right);

    //     return max(op1,max(op2,op3));
    // }
    int D = 0;
    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh =  height(root->right);
        int currD = lh+rh;
        D = max(currD,D);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return D;
    }
};
```

2. Fast way to determine that the Binary tree is balanced or not
3. Check 2 trees are identical or not
4. Check 2 trees are mirror of each other or not.
5. Zig-Zag traversal of a binary tree
6. Transform to Sum tree.
7. Diagonal traversal of a binary tree
8. Vertical traversal of a binary tree
9. Morris traversal of a binary tree
10. Sum of longest bloodline of a tree
11. K-sum path in a binary tree
12. Max sum of non-adjacent nodes in binary tree
13. Max time to burn a binary tree
14. Flatten a Binary tree into Linked List
15. Check if a Binary Tree contains duplicate subtrees of size 2 or more
