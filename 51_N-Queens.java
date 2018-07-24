class Solution {

    public List<List<String>> solveNQueens(int n) {

        /* Sanity check */
        if(n == 0)
            return new ArrayList<List<String>>();

        ArrayList<List<String>> result = new ArrayList<>();
        int[] pos = new int[n];

        dfs(result, pos, 0);

        return result;
    }

    /* dfs */
    private void dfs(List<List<String>> result, int[] pos, int index) {
        /* One solution found */
        if(index == pos.length) {
            result.add(getResultString(pos));
            return;
        }

        /* Keep searching */
        for(int i = 0; i < pos.length; ++i) {
            pos[index] = i;

            if(isConflict(pos, index) == false)
                dfs(result, pos, index + 1);
        }

    }

    /* getResultString - Get the string form of a valid solution */
    private List<String> getResultString(int[] pos) {
        ArrayList<String> result = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < pos.length; ++i)
            sb.append(".");

        for(int i = 0; i < pos.length; ++i) {
            sb.setCharAt(pos[i], 'Q');
            result.add(sb.toString());
            sb.setCharAt(pos[i], '.');
        }

        return result;
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