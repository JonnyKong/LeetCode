class Solution {
 public:
  vector<bool> pathA;
  vector<bool> pathB;

  void find(vector<bool>& path, TreeNode* root, TreeNode* p) {
    if (root == nullptr) return;
    if (root->val == p->val) {
      return;
    } else if (p->val < root->val) {
      path.push_back(0);
      find(path, root->left, p);
    } else if (p->val > root->val) {
      path.push_back(1);
      find(path, root->right, p);
    }
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p == q) return p;

    find(pathA, root, p);
    find(pathB, root, q);

    int i = 0;
    TreeNode* cur = root;
    while (1) {
      if (i >= pathA.size() || i >= pathB.size() || pathA[i] != pathB[i])
        return cur;
      if (pathA[i] == 0)
        cur = cur->left;
      else
        cur = cur->right;
      ++i;
    }
  }
};