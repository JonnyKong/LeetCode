class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {

        /* Sanity check */
        if(root == null)
            return new ArrayList<>();

        Stack<TreeNode> s = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>();
        TreeNode p;

        s.push(root);
        while(s.empty() == false) {
            p = s.pop();

            if(p.left != null)
                s.push(p.left);
            if(p.right != null)
                s.push(p.right);

            result.add(p.val);
        }

        Collections.reverse(result);
        return result;

    }

}