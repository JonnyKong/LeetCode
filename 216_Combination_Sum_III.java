class Solution {

    public List<List<Integer>> combinationSum3(int k, int n) {
        ArrayList<List<Integer>> result = new ArrayList<>();
        ArrayList<Integer> current = new ArrayList<>();

        dfs(result, current, n, k, 1);
        return result;
    }

    private void dfs(List<List<Integer>> result, List<Integer> current, int target, int k, int pos) {

        /* Termination */
        if(target == 0 && k == 0) { /* A valid combination is found */
            result.add(new ArrayList<Integer>(current));
            return;
        }
        else if(target == 0) {      /* Not valid number of numbers used */
            return;
        }
        else if(pos > 9) {        /* Out of bound */
            return;
        }

        dfs(result, current, target, k, pos + 1);
        current.add(Integer.valueOf(pos));
        dfs(result, current, target - pos, k - 1, pos + 1);
        current.remove(current.size() - 1);

    }
}