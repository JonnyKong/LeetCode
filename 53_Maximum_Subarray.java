class Solution {

    public int maxSubArray(int[] nums) {

        int[] dp = new int[nums.length];
        int max = nums[0];
        dp[0] = nums[0];

        for(int i = 1; i < nums.length; ++i) {
            dp[i] = Integer.max(dp[i - 1], 0) + nums[i];

            if(dp[i] > max)
                max = dp[i];
        }

        return max;

    }

}