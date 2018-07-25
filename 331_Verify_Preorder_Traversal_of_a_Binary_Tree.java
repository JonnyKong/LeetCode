class Solution {

    /* isValidSerialization - Verify whether a binary tree serialization is valid. It
     *      traverses the serialization and records the number of out-degrees.
     *      Since binary trees have the property of #null == #node + 1, we can verify
     *      this property in the end, and #null - #node never defaults during traversal.
     **/
    public boolean isValidSerialization(String preorder) {

        /* Sanity check */
        if(preorder.length() == 0)
            return true;

        /* Parse input */
        String[] preorder_part = preorder.split(",");

        int diff = 1;
        for(int i = 0; i < preorder_part.length; ++i) {
            System.out.println(preorder_part[i]);
            if(preorder_part[i].equals("#") == false) {
                diff++;
            } else {
                diff--;
                /* Diff shall not default except at the end */
                if(diff == 0 && i != preorder_part.length - 1)
                    return false;
            }
        }

        return diff == 0;
    }

}