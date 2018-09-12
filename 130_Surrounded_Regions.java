/**
 * Trivial DFS.
 */

class Solution {

    public void solve(char[][] board) {

        /* Sanity check */
        if (board.length == 0)
            return;

        /* Copy array */
        char[][] mask = new char[board.length][];
        for (int i = 0; i < board.length; ++i)
            mask[i] = board[i].clone();

        /* Mark all edge '0' areas to 'X' */
        for (int i = 0; i < mask.length; ++i) {
            if(mask[i][0] == 'O')
                dfs(mask, i, 0);
            if(mask[i][mask[0].length - 1] == 'O')
                dfs(mask, i, mask[0].length - 1);
        }
        for(int i = 0; i < mask[0].length; ++i) {
            if(mask[0][i] == 'O')
                dfs(mask, 0, i);
            if(mask[mask.length - 1][i] == 'O')
                dfs(mask, mask.length - 1, i);
        }

        /* Compare mask and board */
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == 'O' && mask[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    private void dfs(char[][] mask, int m, int n) {

        mask[m][n] = 'X';

        if(m - 1 >= 0 && mask[m - 1][n] == 'O')
            dfs(mask, m - 1, n);
        if(m + 1 < mask.length && mask[m + 1][n] == 'O')
            dfs(mask, m + 1, n);
        if(n - 1 >= 0 && mask[m][n - 1] == 'O')
            dfs(mask, m, n - 1);
        if(n + 1 < mask[0].length && mask[m][n + 1] == 'O')
            dfs(mask, m, n + 1);
    }
}