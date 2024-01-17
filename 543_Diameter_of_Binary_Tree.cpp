class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        treeDepth(root, maxDiam);
        return maxDiam - 1; // -1 because diam definition is number of edges, not nodes
    }
    
    int treeDepth(TreeNode *root, int & maxDiam) {
        if (root == NULL) {
            return 0;
        }

        int l = treeDepth(root->left, maxDiam);
        int r = treeDepth(root->right, maxDiam);
        int diam = l + r + 1;
        maxDiam = max(maxDiam, diam);
        return max(l, r) + 1;
    }
};
