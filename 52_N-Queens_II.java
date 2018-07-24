class Solution {

    private int result;

    public int totalNQueens(int n) {

        /* Sanity check */
        if(n == 0)
            return 0;

        result = 0;
        int[] pos = new int[n];

        dfs(pos, 0);

        return result;
    }

    /* dfs */
    private void dfs(int[] pos, int index) {
        /* One solution found */
        if(index == pos.length) {
            result++;
            return;
        }

        /* Keep searching */
        for(int i = 0; i < pos.length; ++i) {
            pos[index] = i;

            if(isConflict(pos, index) == false)
                dfs(pos, index + 1);
        }

    }

    /* isConflict - Returns whether column i conflicts with previous columns. */
    private boolean isConflict(int[] pos, int index) {
        for(int i = 0; i < index; ++i) {
            if(pos[index] == pos[i] || (index - i) == Math.abs(pos[index] - pos[i]))
                return true;
        }
        return false;
    }

}

