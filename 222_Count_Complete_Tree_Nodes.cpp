/**
 * Iterative solution.
 *
 * Actually, iterative solution is much easier to implement.
 *
 * Tip: Update p_xxxx variables immediately after updating p.
 */

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  int depth(TreeNode *root) {
    if (root == NULL)
      return 0;
    else
      return 1 + depth(root->left);
  }

 public:
  int countNodes(TreeNode *root) {
    /* Sanity check */
    if (root == NULL) return 0;

    TreeNode *p = root;
    int p_depth = depth(root); /* Current depth of p */
    int p_level = 0;           /* Current layer of p */
    int num_prev_level = 0;    /* Sum of number of nodes on layers above */
    int p_index = 1; /* Number of left nodes on same level including p */

    /* Exit if p reached last level */
    while (p_depth > 1) {
      int depth_left = p_depth - 1;
      int depth_right = depth(p->right);
      if (depth_left != depth_right) { /* Search for gap in left */
        p = p->left;
        p_depth = depth_left;
        p_index = (p_index - 1) * 2 + 1;
      } else { /* Search for gap in right */
        p = p->right;
        p_depth = depth_right;
        p_index = p_index * 2;
      }
      /* Add full level */
      num_prev_level += (1 << (p_level++));
    }
    return num_prev_level + p_index;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  cout << Solution().countNodes(root) << endl;
}