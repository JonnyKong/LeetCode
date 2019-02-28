class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> address;
    vector<int> result;
    TreeNode* cur = root;
    if (!root) return result;

    while (1) {
      while (cur) {  // to the leftmost
        address.push(cur);
        cur = cur->left;
      }
      if (address.empty()) break;
      cur = address.top();
      address.pop();
      result.push_back(cur->val);
      cur = cur->right;
    }
    return result;
  }
};