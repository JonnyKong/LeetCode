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
    TreeNode* helper(const vector<int> & nums, int left, int right){
        if(left > right) return NULL;
        TreeNode* root = new TreeNode(nums[(left + right) >> 1]);
        root -> left = helper(nums, left, ((left + right) >> 1) - 1);
        root -> right = helper(nums, ((left + right) >> 1) + 1, right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = helper(nums, 0, nums.size() - 1);
        return root;
    }
};