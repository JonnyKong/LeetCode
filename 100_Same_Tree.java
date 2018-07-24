class Solution {
    public boolean isSameTree(TreeNode root1, TreeNode root2) {
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