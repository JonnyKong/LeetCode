/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Task {
 public:
  TreeNode* add;
  int level;
  Task(TreeNode* add_, int level_) : add(add_), level(level_) {}
};

void traverse(TreeNode* root, vector<vector<int>>& result) {
  if (root == NULL) return;
  queue<Task> tasks;
  tasks.push(Task(root, 0));
  while (!tasks.empty()) {
    Task temp = tasks.front();
    tasks.pop();
    // if(result.size() <= temp.level)
    result.resize(temp.level + 1);
    result[temp.level].push_back(temp.add->val);
    if (temp.add->left) tasks.push(Task(temp.add->left, temp.level + 1));
    if (temp.add->right) tasks.push(Task(temp.add->right, temp.level + 1));
  }
}

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    traverse(root, result);
    return result;
  }
};

// 2023-12-26
class Solution {
public:
    void bfs(queue<TreeNode*> & bfs_queue, vector<vector<int>> & all_levels) {
        if (bfs_queue.size() == 0) {
            return;
        }

        vector<int> current_level;
        int size = bfs_queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode *n = bfs_queue.front();
            bfs_queue.pop();
            current_level.push_back(n->val);

            if (n->left) {
                bfs_queue.push(n->left);
            }
            if (n->right) {
                bfs_queue.push(n->right);
            }
        }
        all_levels.push_back(current_level);
        bfs(bfs_queue, all_levels);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> all_levels; 
        queue<TreeNode*> bfs_queue;
        if (root != NULL) {
            bfs_queue.push(root);
            bfs(bfs_queue, all_levels);
        }
        return all_levels;
    }
};