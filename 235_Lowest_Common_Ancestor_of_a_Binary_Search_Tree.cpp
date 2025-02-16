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

// 2025-02-16
class Solution2 {
    vector<TreeNode*> findPath(TreeNode* root, TreeNode *p) {
        // Returns the reverse-order (bottom-up) path
        if (root == NULL) {
            return vector<TreeNode*>();
        }
        vector<TreeNode*> path;
        if (p -> val < root -> val) {
            path = findPath(root->left, p);
        } else if (p -> val > root -> val) {
            path = findPath(root->right, p);
        }
        path.push_back(root);
        return path;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        auto p1 = findPath(root, p);
        auto p2 = findPath(root, q);
        std::reverse(p1.begin(), p1.end());
        std::reverse(p2.begin(), p2.end());

        // Find the last common element
        int i = 0;
        while (i + 1 < p1.size() && i + 1 < p2.size() && p1[i + 1] == p2[i + 1]) {
            i++;
        }
        return p1[i];
    }
};