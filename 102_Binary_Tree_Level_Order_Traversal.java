class Solution {

    public List<List<Integer>> levelOrder(TreeNode root) {
        
        /* Sanity check */
        if(root == null)
            return new ArrayList<>();

        /* Queue BFS */
        Queue<TreeNode> qNode = new LinkedList<>();
        Queue<Integer> qLevel = new LinkedList<>();

        List<List<Integer>> result = new ArrayList<>();

        qNode.add(root);
        qLevel.add(Integer.valueOf(0));

        while(qNode.isEmpty() == false) {
            TreeNode node = qNode.poll();
            Integer level = qLevel.poll();

            /* Add current node to result list */
            if(level == result.size())      /* First node of this level */
                result.add(new ArrayList<>());

            result.get(level).add(node.val);

            /* Update queue */
            if(node.left != null) {
                qNode.add(node.left);
                qLevel.add(level + 1);
            }
            if(node.right != null) {
                qNode.add(node.right);
                qLevel.add(level + 1);
            }

        }

        return result;

    }

}