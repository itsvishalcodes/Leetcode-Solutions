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
  bool isValidBST(TreeNode* root, long long int sbGreater = LLONG_MIN, long long int sbSmaller = LLONG_MAX) {
    // cout<<INT_MIN<<endl<<INT_MAX<<endl;
    if(!root) return true;
    if(root->val <= sbGreater or root->val >= sbSmaller) return false;
    
    return isValidBST(root->left, sbGreater, root->val) and isValidBST(root->right, root->val, sbSmaller);
  }
};