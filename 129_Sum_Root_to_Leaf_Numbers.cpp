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
    vector<string> result;
    void dfs(TreeNode* root, string str){
        if(!root) return;
        if(root -> left && root -> right){
            dfs(root -> left, str + (char)(root -> val + '0'));
            dfs(root -> right, str + (char)(root -> val + '0'));
            return;
        }
        else if(root -> left){
            dfs(root -> left, str + (char)(root -> val + '0'));
        }
        else if(root -> right){
            dfs(root -> right, str + (char)(root -> val + '0'));
        }
        else result.push_back(str + (char)(root -> val + '0'));
    }
    int sumNumbers(TreeNode* root) {
        int out = 0;
        dfs(root, string(""));
        for(string str : result){
            //reverse(str.begin(), str.end());
            out += stoi(str);
        }
        return out;
    }
};
