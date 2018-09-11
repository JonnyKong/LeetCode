/**
 * Trivial DFS.
 */

class Solution {

    public int numIslands(char[][] grid) {

        int result = 0;

        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0; j < grid[0].length; ++j) {
                if(grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }

    /* Mark all connecting 1 to 0 */
    private void dfs(char[][] grid, int m, int n) {

        grid[m][n] = '0';

        if(m - 1 >= 0 && grid[m - 1][n] == '1')
            dfs(grid, m - 1, n);
        if(m + 1 < grid.length && grid[m + 1][n] == '1')
            dfs(grid, m + 1, n);
        if(n - 1 >= 0 && grid[m][n - 1] == '1')
            dfs(grid, m, n - 1);
        if(n + 1 < grid[0].length && grid[m][n + 1] == '1')
            dfs(grid, m, n + 1);

    }

}