class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        ArrayList<List<Integer>> result = new ArrayList<>();

        /* Sanity check */
        if(nums.length == 0)
            return result;

        Arrays.sort(nums);
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
        HashSet<Integer> used = new HashSet<>();
        used.add(Integer.valueOf(nums[index]));
        for(int i = index + 1; i < nums.length; ++i) {
            if(used.contains(Integer.valueOf(nums[i])))
                continue;
            swap(nums, index, i);
            dfs(nums, result, index + 1);
            swap(nums, index, i);
            used.add(nums[i]);
        }
    }

    private void swap(int[] nums, int a, int b) {
        int c = nums[a];
        nums[a] = nums[b];
        nums[b] = c;
    }

}