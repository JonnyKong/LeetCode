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
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return root;
    else if (root->left == nullptr && root->right == nullptr)
      return root;

    TreeNode *temp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(temp);

    return root;
  }

  bool isSameTree(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr)
      return true;
    else if (root1 == nullptr || root2 == nullptr)
      return false;
    else
      return root1->val == root2->val && isSameTree(root1->left, root2->left) &&
             isSameTree(root1->right, root2->right);
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    else
      return isSameTree(root->left, invertTree(root->right));
  }
};