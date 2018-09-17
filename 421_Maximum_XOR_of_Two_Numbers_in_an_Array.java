/**
 * Bitwise operation & Trie.
 * 
 * We build a prefix tree (trie), where root denotes the MSB bit. Left branch
 * means the next bit is 0, and right brance means next bit is 1.
 * 
 * For each number in the array, we start from the root and search for the
 * optimal path at each node.
 */

class Solution {

    public int findMaximumXOR(int[] nums) {

        /* Build trie from 2nd MSB. Left 0, right 1 */
        TrieNode root = new TrieNode();
        for(int i = 0; i < nums.length; ++i) {

            TrieNode cur = root;
            for(int j = 30; j >= 0; --j) {

                if(((nums[i] >> j) & 1) == 0) {
                    if(cur.left == null)
                        cur.left = new TrieNode();
                    cur = cur.left;
                }

                else {
                    if(cur.right == null)
                        cur.right = new TrieNode();
                    cur = cur.right;
                }
            }
        }

        /* Find optimal combination */
        int result = 0;
        for(int i = 0; i < nums.length; ++i) {

            TrieNode cur = root;
            int result_tmp = 0;

            for(int j = 30; j >= 0; --j) {
                int bit = (nums[i] >> j) & 1;

                if(bit == 0) {
                    if(cur.right != null) {
                        cur = cur.right;
                        result_tmp |= (1 << j);
                    } else {
                        cur = cur.left;
                    }
                }

                else {
                    if(cur.left != null) {
                        cur = cur.left;
                        result_tmp |= (1 << j);
                    } else {
                        cur = cur.right;
                    }
                }

            }
            result = result_tmp > result ? result_tmp : result;
        }
        return result;
    }

}

class TrieNode {
    TrieNode left;
    TrieNode right;
}