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
  vector<vector<int>> result;
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    result.push_back(vector<int>());
    result[0].push_back(root->val);
    queue<TreeNode*> bfs;
    bfs.push(root);
    int count = 1, tempCount = 0;
    int level = 0;
    while (!bfs.empty()) {
      result.push_back(vector<int>());
      tempCount = 0;
      ++level;
      for (int i = 0; i < count; ++i) {
        TreeNode* temp = bfs.front();
        bfs.pop();
        if (temp->left) {
          bfs.push(temp->left);
          ++tempCount;
          result[level].push_back(temp->left->val);
        }
        if (temp->right) {
          bfs.push(temp->right);
          ++tempCount;
          result[level].push_back(temp->right->val);
        }
      }
      count = tempCount;
    }
    for (int i = 1; i <= level; i += 2)
      reverse(result[i].begin(), result[i].end());
    if (result[level].empty()) result.pop_back();
    return result;
  }
};