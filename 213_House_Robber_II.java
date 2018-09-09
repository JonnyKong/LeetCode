class Solution {

    public int rob(int[] nums) {

        if(nums.length == 0)
            return 0;
        else if(nums.length == 1)
            return nums[0];

        return Integer.max(rob_acyclic(Arrays.copyOfRange(nums, 0, nums.length - 1)),
                            rob_acyclic(Arrays.copyOfRange(nums, 1, nums.length)));
    }

    private int rob_acyclic(int[] nums) {

        if(nums.length == 0)
            return 0;
        else if(nums.length == 1)
            return nums[0];

        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Integer.max(nums[0], nums[1]);

        for(int i = 2; i < nums.length; ++i)
            dp[i] = Integer.max(dp[i - 2] + nums[i], dp[i - 1]);

        return dp[nums.length - 1];

    }
}