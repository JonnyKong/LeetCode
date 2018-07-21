class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        ArrayList<List<Integer>> result = new ArrayList<>();
        ArrayList<Integer> current = new ArrayList<>();
        dfs(result, current, nums, 0);
        return result;
    }

    private void dfs(List<List<Integer>> result, List<Integer> current, final int[] nums, int index) {

        /* Termination */
        if(index == nums.length) {
            ArrayList<Integer> result_part = new ArrayList<>(current);
            result.add(result_part);
            return;
        }

        dfs(result, current, nums, index + 1);
        current.add(Integer.valueOf(nums[index]));
        dfs(result, current, nums, index + 1);
        current.remove(current.size() - 1);     /* List current have to be unchanged */

    }

}