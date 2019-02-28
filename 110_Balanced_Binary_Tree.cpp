/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (!root) return 1;
    if (!isBalanced(root->left)) return 0;
    if (!isBalanced(root->right)) return 0;
    return abs(depth(root->left) - depth(root->right)) < 2;
  }

  int depth(TreeNode* root) {
    if (!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }
};