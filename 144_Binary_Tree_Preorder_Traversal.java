class Solution {

    public List<Integer> preorderTraversal(TreeNode root) {

        /* Sanity check */
        if(root == null)
            return new ArrayList<Integer>();

        Stack<TreeNode> s = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>();
        TreeNode p;
        s.push(root);

        while(s.empty() == false) {
            p = s.pop();
            result.add(Integer.valueOf(p.val));
            if(p.right != null)
                s.push(p.right);
            if(p.left != null)
                s.push(p.left);
        }

        return result;
    }

}