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
  vector<int> pre;
  void util(TreeNode* root, int& k) {
    if(!root) return;
    
    util(root->left, k);
    pre.push_back(root->val);
    util(root->right, k);
    
  }
  int kthSmallest(TreeNode* root, int k) {
    util(root, k);  
    
    return pre[k-1];
  }
};