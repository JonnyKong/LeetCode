class Solution {

    public List<List<Integer>> permute(int[] nums) {
        ArrayList<List<Integer>> result = new ArrayList<>();

        /* Sanity check */
        if(nums.length == 0)
            return result;

        dfs(nums, result, 0);

        return result;
    }

    private void dfs(int[] nums, List<List<Integer>> result, int index) {
        if (index == nums.length - 1) {
            ArrayList<Integer> result_part = new ArrayList<>();
            for(int a : nums)
                result_part.add(new Integer(a));
            result.add(result_part);
            return;
        }

        dfs(nums, result, index + 1);
        for(int i = index + 1; i < nums.length; ++i) {
            swap(nums, index, i);
            dfs(nums, result, index + 1);
            swap(nums, index, i);
        }
    }

    private void swap(int[] nums, int a, int b) {
        int c = nums[a];
        nums[a] = nums[b];
        nums[b] = c;
    }
}