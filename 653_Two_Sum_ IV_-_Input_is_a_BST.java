class Solution {

    public boolean findTarget(TreeNode root, int k) {
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        TreeNode cur;

        while(!s.empty()) {
            cur = s.pop();

            if(contains(root, k - cur.val, cur))     /* Valid */
                return true;

            if(cur.left != null)
                s.push(cur.left);
            if(cur.right != null)
                s.push(cur.right);
        }

        return false;
    }

    /* contains - Returns whether value num is in BST (excluding exclude) */
    private boolean contains(TreeNode root, int num, TreeNode exclude) {
        if(root == null)
            return false;
        else if(num == root.val)
            return root != exclude;
        else if(num < root.val)
            return contains(root.left, num, exclude);
        else
            return contains(root.right, num, exclude);
    }

}

