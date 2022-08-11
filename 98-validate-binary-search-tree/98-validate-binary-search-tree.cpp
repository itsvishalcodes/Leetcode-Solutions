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
  bool isValidBST(TreeNode* root, long long int largest = LLONG_MIN, long long int smallest = LLONG_MAX) {
    if(!root) return true;
    
    if(root->val <= largest or root->val >= smallest) return false;
    
    return isValidBST(root->left, largest, root->val) and isValidBST(root->right, root->val, smallest);
    
  }
};