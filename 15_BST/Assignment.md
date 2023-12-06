# Practice Questions

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

## Count pairs from 2 BST whose sum is equal to given value "X"

<https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1>

approach

1. perfrom inorder traversal into BST1 LNR and store in vector1, and perform reverse inorder traversal into BST2 and store in vector2, now vect1 is in asc order and vect2 is in desc order now using two pointer approach we can find the target x.
2. using BST property of traversing and instead of using system stack for recursion making custom stack and performing Inorder of BST1 and reverse Inorder of BST2 comparing top elements sum to target. code is below

```cpp
/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans = 0;
        stack<Node*> s1,s2;
        Node* a = root1;
        Node* b = root2;
        while(1){
            while(a){
                //inorder LNR
                s1.push(a);
                a = a->left;
            }
            while(b){
                //reverse inorder RNL
                s2.push(b);
                b=b->right;
            }
            
            if(s1.empty() || s2.empty()){
                break; //BST1 or BST2 traversal has end
            }
            auto atop = s1.top();
            auto btop = s2.top();
            
            int sum = atop->data + btop->data;
            if(sum == x){
                ans++;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if(sum < x){
                s1.pop();
                a = atop->right;
            } else {
                // sum > x
                s2.pop();
                b = btop->left;
            }
        }
        return ans;
    }
};
```

## Convert a normal BST into a Balanced BST

<https://leetcode.com/problems/balance-a-binary-search-tree/>

approach is like this when convert BST into inorder ,
now when we build tree from inorder considering mid of inorder as root tree will automatically balanced.

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
    void inorder(TreeNode* root,vector<int>& in){
        if(root == NULL) return;
        inorder(root->left,in);
        in.emplace_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* buildTree(vector<int> &in,int s,int e){
        if(s > e) return NULL;

        int mid = s + (e-s)/2;
        int data = in[mid];
        TreeNode* root = new TreeNode(data);
        root->left = buildTree(in,s,mid-1);
        root->right = buildTree(in,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        //build balanced BST using inorder traversal
        return buildTree(in,0,in.size()-1);
    }
};
```

## Find the median of BST in O(n) time and 0(1) space

<https://practice.geeksforgeeks.org/problems/median-of-bst/1>

approach -

1. make vector using inorder, find median using formula,  
TC: O(n) SC: O(n) (n space used in rec and n space to store inorder vector)
2. using morris traversal perfrom inorder, TC: O(n) , SC: O(n) (not rec and no need of storing inorder in vector will compute on traversal)
    - morris traversal to find no of nodes
    - morris traversal to reach to desired node

```cpp
/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
int findCount(Node* root) {
        int count = 0;
        
        //Moris traversal
        Node* curr = root;
        while(curr){
            //if left node is null , then visit current node and go right
            if(curr->left == nullptr){
                // ans.emplace_back(curr->val);
                count++;
                curr = curr->right;
            } else {
                //find inorder predecessor
                Node* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }
                //curr node predecessor not calculated case
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    //predecessor already calculated
                    // so visit curr and move to right
                    pred->right = nullptr; //unlinking the predecesoor link
                    // ans.emplace_back(curr->val);
                    count++;
                    curr = curr->right;
                }
            }
        }
        return count;
    }
float solveMorris(Node* root,int n) {
        int i = 0;
        int odd1 = (n+1)/2, odd1Val = -1;
        int even1 = n/2, even1Val = -1;
        int even2 = n/2+1 , even2Val = -1;
        //Moris traversal
        Node* curr = root;
        while(curr){
            //if left node is null , then visit current node and go right
            if(curr->left == nullptr){
                // ans.emplace_back(curr->val);
                // count++;
                i++;
                if(i == odd1) odd1Val = curr->data;
                if(i == even1) even1Val = curr->data;
                if(i == even2) even2Val = curr->data;
                curr = curr->right;
            } else {
                //find inorder predecessor
                Node* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }
                //curr node predecessor not calculated case
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    //predecessor already calculated
                    // so visit curr and move to right
                    pred->right = nullptr; //unlinking the predecesoor link
                    // ans.emplace_back(curr->val);
                    i++;
                    if(i == odd1) odd1Val = curr->data;
                    if(i == even1) even1Val = curr->data;
                    if(i == even2) even2Val = curr->data;
                    curr = curr->right;
                }
            }
        }
        float median = 0.0;
        if(n&1){
            //odd
            median = odd1Val;
        } else {
            median = (even1Val + even2Val)/2.0;
        }
        return median;
    }
float findMedian(struct Node *root)
{
      //Code here
      int n = findCount(root);
      return solveMorris(root,n);
}
```

## Check whether BST contains Dead end

<https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1>

approach - check only leaf node, will keep track of all nodes visited in hashMap and for leaf node will check if data +1 && data-1 exist in map mean nothing can be inserted so that is dead end.

```cpp
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void solve(Node* root,unordered_map<int,bool>& visited,bool&ans){
    if(root == NULL) return;
    
    visited[root->data]=1;
    if(root->left == NULL && root->right == NULL){
        int plus = root->data + 1;
        int minus = root->data - 1  == 0 ? root->data : root->data - 1;
        if(visited.find(plus)!=visited.end() && visited.find(minus)!=visited.end()){
            ans = true;
            return;
        }
    }
    solve(root->left,visited,ans);
    solve(root->right,visited,ans);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_map<int,bool> visited;
    bool ans = false;
    solve(root,visited,ans);
    return ans;
}
```

## Flatten BST to sorted list

approach -

1. perform inorder on BST and store int in vector, now construct LL from it. TC: O(n) and SC - O(n)
2. perform inorder on BST and store BST Node in vector, not vec[i]->left = NULL and vec[i]->right = vec[i+1] node. TC: O(n) and SC: O(n)
3. flatten using inorder traversal on go using a dummy/prev node which will act as predecessor.

```cpp
void in(Node* root,Node* &prev){
    if(root == NULL) return NULL;
    in(root->left,prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    in(root->right,prev);
}
Node* flatten(Node* root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    in(root,prev);
    //prev is now last node
    prev->left = NULL;
    prev->right = NULL;
    // after dummy node LL is available
    return dummy->next;
}
```

## Count BST nodes that lie in a given range

approach -

1. perfrom inorder or any traversal and count number which are in range of low and high, TC:O(n)
2. using BST property will decide whether will find nodes in range of low and high and caluclate code is below

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
    int solve(TreeNode* root, int low, int high){
        if(root == NULL){
            return 0;
        }
        int ans = 0;
       if(root->val >= low && root->val <= high){
           ans += root->val;
           ans += solve(root->left,low,high);
           ans += solve(root->right,low,high);
       }
      else if(root->val > high){
           ans += solve(root->left,low,high);
       }
       else{
           ans += solve(root->right,low,high);
       }
       return ans;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};
```

## Replace every element with the least greater element on its right

approach - will traverse array from right -> left so that when we will have already visited previous nodes, and will add those data in BST, while adding if we move left of any node then it will becomes its least greater element of (inorder successor), so last node from which we moved left is answer.  
SC - O(n)
TC - theta(nlogn) (average case)
//O(n^2) worst case when arr is in descending order

<https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article>

```cpp

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution{
    public:
    Node* insert(Node* root,int val,int&succ){
        if(root == NULL) return new Node(val);
        if(val >= root->data) {
            root->right = insert(root->right,val,succ);
        } else {
            succ = root->data;
            root->left = insert(root->left,val,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(),-1);
        Node* root = NULL;
        for(int i=arr.size()-1;i>=0;--i){
            int succ = -1;
            root = insert(root,arr[i],succ);
            ans[i] = succ;
        }
        return ans;
    }
};
```

## Valid BST from preorder

Problem Description

You are given a preorder traversal A, of a Binary Search Tree.
Find if it is a valid preorder traversal of a BST.
Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.

<https://www.interviewbit.com/problems/valid-bst-from-preorder/>

### Approach  

is to use construch BST from preorder traversal min max appraoch if constructed (mean all nodes created from preorder array) then valid BST else not

```cpp
void build(int &i,int mini,int maxi,vector<int> &A){
    if(i>=A.size()){
        return;
    }

    if(A[i] > mini && A[i] < maxi){
        //valid
        //create node dummy
        //int rootData = A[i];
        //now try to insert in left and then in right
        i++;
        build(i,mini,A[i],A);
        build(i,A[i],maxi,A);
    }
}
int solve(vector<int>& preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    build(i,mini,maxi,preorder);
    return i == preorder.size();
}
```
