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
  void dfs(TreeNode* root, int val, int depthToInsert, int currDepth) {
    if(!root) return;
    if(currDepth == depthToInsert-1) {
      TreeNode* newLeft = new TreeNode(val, root->left, nullptr);
      TreeNode* newRight = new TreeNode(val, nullptr, root->right);
      root->left = newLeft;
      root->right = newRight;
      return;
    }
    dfs(root->left, val, depthToInsert, currDepth+1);
    dfs(root->right, val, depthToInsert, currDepth+1);
  }
  
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth == 1) {
      TreeNode* newRoot = new TreeNode(val, root, nullptr);
      return newRoot;
    }
    
    dfs(root, val, depth, 1);
    return root;
  }
};