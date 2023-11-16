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
bool solve(TreeNode* root, long long int lb, long long int ub) {
    //base case
    if(root == NULL)
        return true;
    
    if(root->val > lb && root->val < ub) {
        bool leftAns = solve(root->left, lb, root->val);
        bool rightAns = solve(root->right, root->val, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }

}
    bool isValidBST(TreeNode* root) {
        long long int lowerBound = -4294967296 ;
        long long int upperBound = 4294967296;
        bool ans  = solve(root, lowerBound, upperBound );
        return ans;
    }
};









