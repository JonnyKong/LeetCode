class Solution {
 public:
  void help(string str, TreeNode* root, vector<string>& result) {
    str += to_string(root->val);
    if (root->left == NULL && root->right == NULL) result.push_back(str);
    if (root->left) help(str + "->", root->left, result);
    if (root->right) help(str + "->", root->right, result);
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (root == NULL) return result;
    help(string(""), root, result);
    return result;
  }
};