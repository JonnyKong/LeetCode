class Solution {
public:
  // Returns max path sum of a tree starting from root (but not necessarily ends
  // at a leaf, when there are negative nodes), recording path sum in the
  // process
  int pathSumHelper(TreeNode *root, int &maxPathSumSeen) {
    if (root == NULL) {
      return 0;
    } else {
      int lSum = pathSumHelper(root->left, maxPathSumSeen);
      int rSum = pathSumHelper(root->right, maxPathSumSeen);
      int pathSum = lSum + rSum + root->val;
      maxPathSumSeen = max(pathSum, maxPathSumSeen);
      return max(max(lSum, rSum) + root->val, 0);
    }
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int maxPathSumSeen = INT_MIN;
            pathSumHelper(root, maxPathSumSeen);
            return maxPathSumSeen;
        }
    }
};
