class Solution {
/*
Observation: always better to set camera on a leaf's parent over the leaf.

Greedily set camera on all leaves' parent. Then, "remove" the covered nodes.

Since algorithm is bottom-up, it is natural to use DFS.

def dfs(root):
    Return 0 if root is leaf
    Return 1 if root is leaf's parent, increment camera count
    Return 2 if root is leaf's grandparent

       0    -> returns 0
      /
     0   -> returns 2,
    /
   0    -> returns 1, cnt += 1
  /
 0  -> returns 0
*/
public:

    int dfs(TreeNode* root, int &cnt) {
        // Assumes root != NULL
        if (root->left == NULL && root->right == NULL) {
            return 0;
        } else if (root->left && root->right) {
            int l = dfs(root->left, cnt);
            int r = dfs(root->right, cnt);

            if (l == 0 || r == 0) {
                // If one child is leaf, this node needs cover
                cnt += 1;
                return 1;
            } else if (l == 1 || r == 1) {
                // One child has camera, this node is already covered
                return 2;
            } else {
                return 0;
            }
        } else {
            int c = dfs(root->left ? root->left : root->right, cnt);
            if (c == 0) {
                cnt += 1;
                return 1;
            } else if (c == 1) {
                return 2;
            } else {
                return 0;
            }
        }
    }

    int minCameraCover(TreeNode* root) {
        int cnt = 0;
        int ret = dfs(root, cnt);
        if (ret == 1 || ret == 2) {
            return cnt;
        } else {
            // Not covered by child, need to add one
            return cnt + 1;
        }
    }
};
