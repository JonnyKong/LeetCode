class Solution {
public:
    // Returns early when k reaches 0
    int inorder(TreeNode *root, int &k) {
        if (root == NULL) {
            return -1;
        }

        int ret = inorder(root->left, k);
        if (ret >= 0) {
            return ret;
        }

        // visit
        k -= 1;
        if (k == 0) {
            return root->val;
        }

        return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
