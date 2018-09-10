class Solution {

    public int minDepth(TreeNode root) {

        if(root == null)
            return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);

        return (left * right == 0) ? (left + right + 1) : Integer.min(left, right) + 1;

    }

}