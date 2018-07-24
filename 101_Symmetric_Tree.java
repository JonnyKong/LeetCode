class Solution {

    public boolean isSymmetric(TreeNode root) {

        /* Sanity check */
        if(root == null)
            return true;
        
        root.left = invertTree(root.left);
        return isSameTree(root.left, root.right);

    }

    private TreeNode invertTree(TreeNode root) {

        TreeNode tmp;

        /* Sanity check */
        if(root == null)
            return root;

        tmp = invertTree(root.left);
        root.left = invertTree(root.right);
        root.right = tmp;
        return root;

    }

    private boolean isSameTree(TreeNode root1, TreeNode root2) {

        if(root1 == null && root2 == null)
            return true;
        else if(root1 == null || root2 == null)
            return false;
        else
            return (root1.val == root2.val &&
                    isSameTree(root1.left, root2.left) &&
                    isSameTree(root1.right, root2.right));
    }

}