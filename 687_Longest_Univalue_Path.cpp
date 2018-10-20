/**
 * Key observation: No matter whether path passes from root, it has to pass
 *  root of some subtree. Keep global optimum value.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <unordered_map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    /* Return max path that passes through root */
    int max_value = INT_MIN;

    int dfs(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int max_l = dfs(root -> left);
        int max_r = dfs(root -> right);
        int result_local = 1;

        if (root -> left && root -> val == root -> left -> val &&
                root -> right && root -> val == root -> right -> val) {
            max_value = max(max_value, max_l + max_r + 1);
            result_local = max(max_l, max_r) + 1;
        }
        else if (root -> left && root -> val == root -> left -> val) {
            max_value = max(max_value, max_l + 1);
            result_local = max_l + 1;
        }
        else if (root -> right && root -> val == root -> right -> val) {
            max_value = max(max_value, max_r + 1);
            result_local = max_r + 1;
        } else {
            max_value = max(result_local, max_value);
        }
        return result_local;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        dfs(root);
        return max_value - 1;
    }
};

int main() {
    vector<int> a = {1, 3, 2};
    int b = Solution().kEmptySlots(a, 1);
    cout << b << endl;
}