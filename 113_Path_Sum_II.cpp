/**
 * Key observation: 
 * 1) ROOT TO LEAF node. 
 * 2) Might have negative node
 * 3) If reach 0, have to keep searching
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    void pathSumHelper(TreeNode *root, vector<vector<int>> &result,
            vector<int> &cur, int rem) {
        if (root == NULL)
            return;
        cur.push_back(root -> val);
        if (root -> val == rem) {
            /* Make sure is leaf */
            if (root->left == NULL && root->right == NULL)
                result.push_back(cur);
        }
        pathSumHelper(root -> left, result, cur, rem - root -> val);
        pathSumHelper(root -> right, result, cur, rem - root -> val);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur;
        vector<vector<int>> result;
        pathSumHelper(root, result, cur, sum);
        return result;
    }
};


int main() {
    TreeNode *root = new TreeNode(5);
    root -> left = new TreeNode(4);
    root -> right = new TreeNode(8);
    Solution().pathSum(root, 9);
    return 0;
}