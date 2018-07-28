class Solution {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        ArrayList<TreeNode> pResult = new ArrayList<>();
        ArrayList<TreeNode> qResult = new ArrayList<>();

        getPath(root, p, pResult);
        getPath(root, q, qResult);
        Collections.reverse(pResult);
        Collections.reverse(qResult);

        int len, index;
        len = Integer.min(pResult.size(), qResult.size());

        for(index = 0; index < len - 1; ++index) {
            if(pResult.get(index) == qResult.get(index) &&
                    pResult.get(index + 1) != qResult.get(index + 1)) {
                break;
            }
        }

        return pResult.get(index);
    }

    boolean getPath(TreeNode root, TreeNode p, ArrayList<TreeNode> result) {

        if(root == null)
            return false;

        else if(root.val == p.val) {
            result.add(root);
            return true;
        }

        else if(getPath(root.left, p, result) == true) {
            result.add(root);
            return true;
        }

        else if(getPath(root.right, p, result) == true) {
            result.add(root);
            return true;
        }

        else
            return false;

    }

}