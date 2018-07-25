class Solution {

    public TreeNode buildTree(int[] preorder, int[] inorder) {

        /* Sanity check */
        if(preorder.length == 0)
            return null;

        return buildTreeHelper(preorder, inorder, 0, 0, preorder.length - 1);
    }


    /* buildTreeHelper - Recursively construct the binary tree with preorder[rootIndex]
    as root, from inorder[start] to inorder[end] inclusively. */
    private TreeNode buildTreeHelper(final int[] preorder, final int[] inorder,
                                     int rootIndex, int start, int end) {

        /* Sanity check */
        if(start > end)
            return null;

        /* Preorder[start] divides inorder array into two subtrees */
        /* Find the head in inorder array */
        TreeNode root = new TreeNode(preorder[rootIndex]);

        for(int i = start; i <= end; ++i) {

            if(inorder[i] == root.val) {
                root.left = buildTreeHelper(preorder, inorder, rootIndex + 1, start, i - 1);
                root.right = buildTreeHelper(preorder, inorder, rootIndex + 1 + i - start, i + 1, end);
            }

        }

        return root;
    }

}