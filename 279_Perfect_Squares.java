/**
 * This solution uses DFS.
 * 
 * We start DFS with larger numbers, because there is a guaranteed solution
 * of all 1s, which would require many calls. 
 * 
 * Starting with larger numbers with pruning beats 95% submissions, whereas
 * a DP solution only beats 65%.
 */

class Solution {

    public int numSquares(int n) {

        int cur = 0;

        /* Obtain the max number whose square <= n */
        while((cur + 1) * (cur + 1) <= n)
            cur++;

        /* Start DFS */
        dfs(0, n, cur);

        return result;
    }

    private int result = Integer.MAX_VALUE;         /* Global min */

    /* DFS from large numbers */
    private void dfs(int used, int rem, int cur) {

        /* Pruning */
        if(used >= result)
            return;

        /* Found a combination */
        if(rem == 0) {
            result = used < result ? used : result;
            return;
        }

        /* Not found */
        else if(rem < 0)
            return;

        /* DFS */
        for(int i = cur; i > 0; --i) {
            dfs(used + 1, rem - i * i, i);
        }
    }
}