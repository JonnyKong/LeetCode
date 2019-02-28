/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
 private:
  TreeNode* p;
  stack<TreeNode*> address;

 public:
  BSTIterator(TreeNode* root) : p(root) {
    // while(!address.empty()) address.pop();
    while (p) {
      address.push(p);
      p = p->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !address.empty(); }

  /** @return the next smallest number */
  int next() {
    p = address.top();
    address.pop();
    int val = p->val;
    p = p->right;
    while (p) {
      address.push(p);
      p = p->left;
    }
    return val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */