class Solution {

    public int maxDepth(TreeNode root) {

        if(root == null)
            return 0;
        else
            return Integer.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

}