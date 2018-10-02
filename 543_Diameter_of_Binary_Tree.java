class Solution {

    /* diameterOfBinaryTree - Return the diameter of a binary tree. The diameter
     *      of a binary Tree is the length of the longest path between any two
     *      nodes in a tree. This path may or may not pass through the root.
     *
     *      Because the path is bound to pass through a particular node in the
     *      tree, where the diameter of the tree is depth(l) + depth(r) + 1.
     *
     *      Thus, declare global variable to record the max diameter with root
     *      being any node within the tree. 
     *      
     *      The call stack is identical to that of finding the max depth of a 
     *      binary tree, only calculating recording results halfway.
     **/

    private int resultMax = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return resultMax;
    }

    private int maxDepth(TreeNode root) {
        if(root == null)
            return 0;
        else {
            int depthLeft = maxDepth(root.left);
            int depthRight = maxDepth(root.right);
            if(resultMax < depthLeft + depthRight)
                resultMax = depthLeft + depthRight;
            return Integer.max(depthLeft, depthRight) + 1;
        }
    }

}