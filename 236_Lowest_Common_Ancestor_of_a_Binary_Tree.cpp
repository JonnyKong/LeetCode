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
    bool dfs(TreeNode *root, const TreeNode *target, vector<TreeNode *> & path) {

        if(root == target) return true;
        else if(root == NULL) return false;

        if(dfs(root -> left, target, path)) {
            path.push_back(root -> left);
            return true;
        }
        else if(dfs(root -> right, target, path)) {
            path.push_back(root -> right);
            return true;
        }
        return false;

    }

    TreeNode *last_common(const vector<TreeNode*> & a, const vector<TreeNode*> & b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 && j >= 0 && a[i] == b[j]) {
            --i; --j;
        }
        return a[i + 1];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_a;
        vector<TreeNode*> path_b;
        if(dfs(root, p, path_a) == false || dfs(root, q, path_b) == false) {
            cerr << "Fatal: Node not found" << endl;
            exit(1);
        }
        path_a.push_back(root);
        path_b.push_back(root);
        return last_common(path_a, path_b);
    }
};
