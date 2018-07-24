class Solution {

    public List<Integer> inorderTraversal(TreeNode root) {

        /* Sanity check */
        if(root == null)
            return new ArrayList<>();

        Stack<TreeNode> s = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>();
        TreeNode n = root;

        while(true) {
            /* Push all left child to stack */
            while(n != null) {
                s.push(n);
                n = n.left;
            }

            /* Termination */
            if(s.empty())
                return result;

            n = s.pop();
            result.add(Integer.valueOf(n.val));
            n = n.right;
        }
    }
}