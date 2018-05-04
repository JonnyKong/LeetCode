class Solution {
    int[] pos;
    int size;
    int count;
    
    /* Returns whether first n-1 columns conflicts with column n 0-indexed */
    private boolean isConflict(int n) {
        for(int i = 0; i < n; ++i) {
            if(pos[i] == pos[n] || n-i == Math.abs(pos[i] - pos[n])) {
                return true;
            }
        }
        return false;
    }

    /* DFS the nth column 0-indexed */
    private void dfs(int n) {
        if(n == size) {
            count += 1;
            return;
        }
        for(int i = 0; i < size; ++i) {
            pos[n] = i;
            if(isConflict(n) == false) {
                dfs(n + 1);
            }
        }
    }

    public int totalNQueens(int n) {
        size = n;
        pos = new int[n];
        dfs(0);
        return count;
    }

}
