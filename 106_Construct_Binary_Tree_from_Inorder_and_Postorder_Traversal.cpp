/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }

        TreeNode* r = new TreeNode();
        r->val = postorder[postorder.size() - 1];

        // Find left tree size
        int left_sz = 0;
        for (; left_sz < inorder.size(); left_sz++) {
            if (inorder[left_sz] == r->val) {
                break;
            }
        }

        auto inorder_left = vector<int>{inorder.begin(), inorder.begin() + left_sz};
        auto postorder_left = vector<int>{postorder.begin(), postorder.begin() + left_sz};
        r->left = buildTree(inorder_left, postorder_left);

        auto inorder_right = vector<int>{inorder.begin() + left_sz + 1, inorder.end()};
        auto postorder_right = vector<int>{postorder.begin() + left_sz, postorder.end() - 1};
        r->right = buildTree(inorder_right, postorder_right);

        return r;
    }
};
