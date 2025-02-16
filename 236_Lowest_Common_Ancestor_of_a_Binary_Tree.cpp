/**
 * Logistics: The behavior of the function is:
 * If both node is in subtree, return common ancestor
 * If either node is in subtree, return this node
 * Else return NULL.
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
      return root;
    else
      return left ? left : right;
  }
};

class Solution2 {
 public:
  bool dfs(TreeNode* root, const TreeNode* target, vector<TreeNode*>& path) {
    if (root == target)
      return true;
    else if (root == NULL)
      return false;

    if (dfs(root->left, target, path)) {
      path.push_back(root->left);
      return true;
    } else if (dfs(root->right, target, path)) {
      path.push_back(root->right);
      return true;
    }
    return false;
  }

  TreeNode* last_common(const vector<TreeNode*>& a,
                        const vector<TreeNode*>& b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 && j >= 0 && a[i] == b[j]) {
      --i;
      --j;
    }
    return a[i + 1];
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path_a;
    vector<TreeNode*> path_b;
    if (dfs(root, p, path_a) == false || dfs(root, q, path_b) == false) {
      cerr << "Fatal: Node not found" << endl;
      exit(1);
    }
    path_a.push_back(root);
    path_b.push_back(root);
    return last_common(path_a, path_b);
  }
};

// 2024-01-09
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If both p or q exists, return their LCA
        // If only p or q exists, return p or q
        if (root == NULL || root == p || root == q) {
            return root;
        } else {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (left && right) {
                return root;
            } else {
                return left ? left : right;
            }
        }
    }
};

// 2025-02-16
class Solution4 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If only one of P or Q is under root, return P or Q
        // If none of P or Q is under root, return NULL
        if (root == NULL) {
            return NULL;
        } else if (p == root || q == root) {
            return root;
        } else {
            auto l = lowestCommonAncestor(root->left, p, q);
            auto r = lowestCommonAncestor(root->right, p, q);
            if (l && r) {
                // P and Q belong to different sub-trees
                return root;
            } else {
                // P and Q belong to the same sub-tree
                return l ? l : r;
            }
        }
    }
};
