class Solution {

    private int result = Integer.MIN_VALUE;

    /* maxPathSum - Return the max path sum, with path not necessarily passing
     *              through root.
     **/
    public int maxPathSum(TreeNode root) {
        maxPathSumRoot(root);
        return result;
    }

    /* maxPathSum - Return the max path sum of a binary tree, originating
     *      from the root.
     **/
    public int maxPathSumRoot(TreeNode root) {

        if(root == null)
            return 0;

        else {
            int resultLeft = Integer.max(maxPathSumRoot(root.left), 0);
            int resultRight = Integer.max(maxPathSumRoot(root.right), 0);

            if(resultLeft + resultRight + root.val > result)
                result = resultLeft + resultRight + root.val;

            return Integer.max(resultLeft, resultRight) + root.val;
        }
    }

}