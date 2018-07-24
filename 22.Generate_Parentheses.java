class Solution {

    public List<String> generateParenthesis(int n) {
        ArrayList<String> result = new ArrayList<>();
        StringBuilder current = new StringBuilder();

        dfs(result, current, n, n);

        return result;
    }

    private void dfs(ArrayList<String> result, StringBuilder current, int l, int r) {

        /* Termination */
        if(l == 0 && r == 0) {
            result.add(new String(current.toString()));
            return;
        }

        /* DFS */
        if(l > 0) {
            current.append('(');
            dfs(result, current, l - 1, r);
            current.deleteCharAt(current.length() - 1);
        }
        /* Pruning */
        if(l < r) {
            current.append(')');
            dfs(result, current, l, r - 1);
            current.deleteCharAt(current.length() - 1);
        }

    }

}