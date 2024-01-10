class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return 0;
        }
        return rangeSumBST(root->left, low, high)
            + rangeSumBST(root->right, low, high)
            + ((root->val >= low && root->val <= high) ? root->val : 0);
    }
};

// 2024-01-09 (with pruning)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return 0;
        }

        int ret = 0;
        if (root->val >= low && root->val <= high) {
            ret += root->val;
        }

        if (root->val < low) {
            // No need to go left
            ret += rangeSumBST(root->right, low, high);
        } else if (root->val > high) {
            // No need to go right
            ret += rangeSumBST(root->left, low, high);
        } else {
            ret += rangeSumBST(root->left, low, high);
            ret += rangeSumBST(root->right, low, high);
        }
        return ret;
    }
};
