class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        ArrayList<List<Integer>> result = new ArrayList<>();
        ArrayList<Integer> current = new ArrayList<>();

        /* Get the number of occurrences for each element */
        ArrayList<Integer> nums = new ArrayList<>();
        ArrayList<Integer> times = new ArrayList<>();
        for(int i = 0; i < candidates.length; ++i) {
            if(i == 0 || candidates[i] != candidates[i - 1]) {
                nums.add(Integer.valueOf(candidates[i]));
                times.add(Integer.valueOf(1));
            } else {
                times.set(times.size() - 1, times.get(times.size() - 1) + 1);
            }
        }

        dfs(result, current, nums, times, target, 0);
        return result;
    }

    private void dfs(List<List<Integer>> result, ArrayList<Integer> current,
                     final ArrayList<Integer> nums, final ArrayList<Integer> times,
                     int target, int index) {

        /* Termination */
        if(target == 0) {                   /* A combination is found */
            result.add(new ArrayList<Integer>(current));
            return;
        } else if(index == nums.size()) {   /* Out of bound */
            return;
        }

        /* DFS different combinations */
        int n;
        dfs(result, current, nums, times, target, index + 1);
        for(n = 1; n <= times.get(index); ++n) {
            /* Pruning */
            if(target - n * nums.get(index) < 0)
                break;

            current.add(nums.get(index));
            dfs(result, current, nums, times, target - n * nums.get(index), index + 1);
        }

        /* Current has to remain same after returning from each DFS step */
        while(n > 1) {
            current.remove(current.size() - 1);
            n--;
        }

    }
}