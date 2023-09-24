# Assignment of Tree

## Fast way to find Diameter of a tree

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

## Fast way to determine that the Binary tree is balanced or not

<https://leetcode.com/problems/balanced-binary-tree/>

```cpp
//normal way
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
};
```

Faster way

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
    bool isbalanced = true;
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int l = height(root->left);
        int r = height(root->right);

        if(isbalanced && abs(l-r) > 1){
            isbalanced = false;
            return 0;
        } 
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        int temp = height(root);
        return isbalanced;
    }
};
```

## Check 2 trees are identical or not

<https://leetcode.com/problems/same-tree/description/>

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

## Check 2 trees are mirror of each other or not

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

## Diagonal traversal of a binary tree

<https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1>

approach -

1. maitain a variable which increases on moving left only, all elements having same value of variable will be same when moving right so will store it in map.
2. using level order traversal - for root push in queue, till queue is empty perform if left exist then push in queue and move to right node and print that node.

1

```cpp

void solve(Node* root,map<int,vector<int>>&hashMap,int d){
    if(root == NULL) return;
    
    hashMap[d].emplace_back(root->data);
    //left
    solve(root->left,hashMap,d+1);
    //right
    solve(root->right,hashMap,d);
}
vector<int> diagonal(Node *root)
{
   // your code here
   map<int,vector<int>> hashMap;
   int d = 0;
   solve(root,hashMap,d);
   vector<int> answer;
   for(auto H:hashMap){
       for(int i=0;i<H.second.size();i++){
           answer.emplace_back(H.second[i]);
       }
   }
   return answer;
}
```

```cpp
vector<int> diagonal(Node *root)
{
   // your code here
   queue<Node*> q;
   
   q.push(root);
   vector<int> answer;
   while(!q.empty()){
       Node* curr = q.front();
       q.pop();
       while(curr){
           answer.emplace_back(curr->data);
           if(curr->left) q.push(curr->left);
           curr = curr->right;
       }  
   }
   return answer;
}
```

## Zig-Zag traversal of a binary tree

<https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == NULL) return answer;
        bool LtoR = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int width = q.size();
            vector<int> temp(width);

            for(int i=0;i<width;i++){
                TreeNode* curr = q.front();
                q.pop();
                int index = LtoR ? i : width - i - 1;
                temp[index] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            LtoR = !LtoR;
            answer.emplace_back(temp);
        }
        return answer;
    }   
};
```

## Transform to Sum tree

<https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1>

```cpp

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        
        int l = sum(root->left);
        int r = sum(root->right);
        int d = root->data;
        root->data = l + r;
        return l + d + r;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
};
```

## Vertical traversal of a binary tree

<https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/>

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        map<int,map<int,multiset<int>>> hashMap; //col,row , data->sorted {2,3,4}
        queue<pair<TreeNode*,pair<int,int>>> q; //Node , {row,col};
        q.push({root,{0,0}});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* &node = curr.first;
            int &row = curr.second.first;
            int &col = curr.second.second;
            hashMap[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto rows : hashMap){  //col -> rows -> (nodes) 
            vector<int> temp;
            for(auto row : rows.second){
                temp.insert(temp.end(),row.second.begin(),row.second.end());
            }
            answer.emplace_back(temp);
        }
        return answer;
    }
};
```

9. Morris traversal of a binary tree
10. Sum of longest bloodline of a tree
11. K-sum path in a binary tree
12. Max sum of non-adjacent nodes in binary tree
13. Max time to burn a binary tree
14. Flatten a Binary tree into Linked List
15. Check if a Binary Tree contains duplicate subtrees of size 2 or more
