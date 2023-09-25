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

## K-sum path in a binary tree

<https://leetcode.com/problems/path-sum-iii/description/>

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
    int ans;
    void pathFromNode(TreeNode* root,long long int target){
        if(root == NULL) return;

        if(root->val == target){
            ans++;
        }

        pathFromNode(root->left,target-root->val);
        pathFromNode(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, int &targetSum) {
        if(!root) return 0;

        pathFromNode(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};
```

## Morris traversal of a binary tree

It is modified version of Inorder traversal where  
TC - O(n)  
SC - O(1)  

It is determining inorder predecessor

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
    void solve(TreeNode* root,vector<int> &ans){
        if(root == NULL) return;

        solve(root->left,ans);
        ans.emplace_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // solve(root,ans);
        
        //Moris traversal
        TreeNode* curr = root;
        while(curr){
            //if left node is null , then visit current node and go right
            if(curr->left == nullptr){
                ans.emplace_back(curr->val);
                curr = curr->right;
            } else {
                //find inorder predecessor
                TreeNode* pred = curr->left;
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
                    ans.emplace_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
```

## Max sum of non-adjacent nodes in binary tree

<https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1>

child node will return {considered,not_considered} child node sum to parent,  
parent will decide from that node if considering parent node then can't consider child node sum, but if not considering parent node then can consider max of (considering child , not considering child)

```cpp
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){ // {include_sum,exclude_sum}
        if(root == NULL) return {0,0};
        
        auto l = solve(root->left);
        auto r = solve(root->right);
        //sum including node
        int a = l.second + r.second + root->data;
        //sum not included of node
        int b = max(l.first,l.second) + max(r.first,r.second);
        
        return {a,b};
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = solve(root);
        return max(ans.first,ans.second);
    }
};
```

## Sum of longest bloodline of a tree

<https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1>

```cpp
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    pair<int,int> solve(Node* root){ // pair length,sum
        if(root == NULL) return {0,0};
        
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        int sum = 0;
        if(l.first == r.first){
            sum = max(l.second,r.second) + root->data;
        } else if(l.first > r.first){
            sum = l.second + root->data;
        } else {
            sum = r.second + root->data;
        }
        return {1+max(l.first,r.first),sum};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        return solve(root).second;
    }
};

```

## Flatten a Binary tree into Linked List

<https://leetcode.com/problems/flatten-binary-tree-to-linked-list/>

Approach is similar using moris traversal with modification

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr  = root;
        while(curr){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
```

## Max time to burn a binary tree

<https://practice.geeksforgeeks.org/problems/burning-tree/1>

```cpp
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
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
class Solution {
  public:
    Node* makeNodetoParentMappingAndFindTargetNode(Node* root,int target,unordered_map<Node*,Node*>& parentMap){
        Node* targetNode = root;
        queue<Node*> q;
        q.push(root);
        parentMap[root] = NULL;
        while(!q.empty()){
            
                Node* curr = q.front(); q.pop();
                if(target == curr->data){
                    targetNode = curr;
                }
                if(curr->left){
                    parentMap[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parentMap[curr->right] = curr;
                    q.push(curr->right);
                }
        }
        return targetNode;
    }
    int burnTree(Node* targetNode,unordered_map<Node*,Node*>&parentMap){
        int t = 0;
        unordered_map<Node*,bool> isburn;
        queue<Node*> q;
        q.push(targetNode);
        isburn[targetNode] = 1;
        
        while(!q.empty()){
            int size = q.size();
            bool isFireSpread = false;
            for(int i=0;i<size;i++){
                Node* curr = q.front();q.pop();
                if(curr->left && !isburn[curr->left]){
                    q.push(curr->left);
                    isburn[curr->left] = true;
                    isFireSpread = true;
                }
                if(curr->right && !isburn[curr->right]){
                    q.push(curr->right);
                    isburn[curr->right] = true;
                    isFireSpread = true;
                }
                if(parentMap[curr] && !isburn[parentMap[curr]]){
                    q.push(parentMap[curr]);
                    isburn[parentMap[curr]] = true;
                    isFireSpread = true;
                }
            }
            if(isFireSpread) t++;
        }
        return t;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parentMap; //Node its parent pointers
        Node* targetNode = makeNodetoParentMappingAndFindTargetNode(root,target,parentMap);
        return burnTree(targetNode,parentMap);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
```

## Check if a Binary Tree contains duplicate subtrees of size 2 or more

<https://leetcode.com/problems/find-duplicate-subtrees/>

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
    string solve(TreeNode* root,unordered_map<string,int> &hashMap,vector<TreeNode*>& answer){
        if(root == NULL ) return "N";

        string temp = to_string(root->val) + ","+solve(root->left,hashMap,answer) +","+ solve(root->right,hashMap,answer);
        hashMap[temp]++;
        if(hashMap[temp] == 2){
            answer.emplace_back(root);
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> hashMap;
        vector<TreeNode*> answer;
        solve(root,hashMap,answer);
        return answer;
    }
};
```
