class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);

        ArrayList<Integer> current = new ArrayList<>();
        ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();

        dfs(result, current, candidates, target, 0);

        return result;
    }

    private void dfs(List<List<Integer>> result, List<Integer> current,
                     final int[] candidates, int target, int start) {

        /* Termination */
        if(target == 0) {
            result.add(new ArrayList<Integer>(current));
            return;
        }

        /* Because the list is sorted, only check current and subsequent elements */
        for(int i = start; i < candidates.length; ++i) {

            /* If this candidate is too large, all following candidates are too large */
            if(candidates[i] > target)
                break;

            current.add(Integer.valueOf(candidates[i]));
            dfs(result, current, candidates, target - candidates[i], i);
            current.remove(current.size() - 1);
        }
    }

}