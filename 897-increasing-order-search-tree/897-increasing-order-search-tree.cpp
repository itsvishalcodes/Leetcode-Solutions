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
  TreeNode* sentinelRoot = new TreeNode(0);
  TreeNode* it = sentinelRoot;
  
  void constructInOrder(TreeNode* root) {
    if(!root) return;
    
    constructInOrder(root->left);
    it->right = new TreeNode(root->val);
    it = it->right;
    constructInOrder(root->right);
  }
  
  TreeNode* increasingBST(TreeNode* root) {
    constructInOrder(root);
    
    return sentinelRoot->right;
  }
};