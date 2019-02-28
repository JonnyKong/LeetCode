class Solution {
 private:
  vector<int> result;
  void traverse(TreeNode* a) {
    if (!a) return;
    traverse(a->left);
    result.push_back(a->val);
    traverse(a->right);
  }

 public:
  void inorderTraversal(TreeNode* root) { traverse(root); }

  bool isValidBST(TreeNode* root) {
    if (!root) return 1;
    inorderTraversal(root);
    for (int i = 0; i < result.size() - 1; ++i)
      if (result[i] >= result[i + 1]) return 0;
    return 1;
  }
};