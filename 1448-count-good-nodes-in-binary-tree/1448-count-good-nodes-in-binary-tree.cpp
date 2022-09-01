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
    int goodNodes(TreeNode* root, int max_path = INT_MIN) {
      if(!root) return 0;
      
      if(root->val < max_path) {
        return goodNodes(root->left, max(max_path, root->val)) + goodNodes(root->right, max(max_path, root->val));
      }
      return 1 + goodNodes(root->left, max(max_path, root->val)) + goodNodes(root->right, max(max_path, root->val));
    }
};