class Solution {
    public TreeNode invertTree(TreeNode root) {
        TreeNode tmp;

        /* Sanity check */
        if(root == null)
            return root;

        tmp = invertTree(root.left);
        root.left = invertTree(root.right);
        root.right = tmp;
        return root;
    }
}