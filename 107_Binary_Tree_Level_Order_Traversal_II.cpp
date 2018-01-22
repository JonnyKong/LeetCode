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
private:
    vector<int> temp;
    vector<vector<int> > result;
public:
    void traverseTree(TreeNode* h, int depth){
        if(!h) return; 
        if(depth == 0) temp.push_back(h -> val);
        else{
            traverseTree(h -> left, depth - 1);
            traverseTree(h -> right, depth - 1);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        result.clear();
        if(root == NULL) return result;
        int i = 0;
        while(1){
            temp.clear();
            traverseTree(root, i++);
            if(temp.empty()){
                break;
            }
            result.push_back(temp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};