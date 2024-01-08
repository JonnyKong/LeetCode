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
