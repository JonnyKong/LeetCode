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

// 2024-01-07
class Solution2 {
public:
    Result getMinMax(TreeNode *root) {
        // Assumes input is non-NULL

        Result leftMinMax;
        if (root->left) {
            leftMinMax = getMinMax(root->left);
            if (!leftMinMax.isValid || leftMinMax.maxVal >= root->val) {
                return Result{0, 0, false};
            }
        }

        Result rightMinMax;
        if (root->right) {
            rightMinMax = getMinMax(root->right);
            if (!rightMinMax.isValid || rightMinMax.minVal <= root->val) {
                return Result{0, 0, false};
            }
        }

        return Result{
            root->left ? leftMinMax.minVal : root->val,
            root->right ? rightMinMax.maxVal : root->val,
            true};
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return getMinMax(root).isValid;
        }
    }
};