class Solution {

    public int lengthOfLIS(int[] nums) {

        /* Sanity check */
        if(nums.length == 0)
            return 0;

        /* dp[i] array stores the smallest tail of increasing array with
         *      length of i + 1. It can be easily proved that this array
         *      is monotonically increasing.
         **/
        int[] dp = new int[nums.length];
        int bound = 0;
        dp[0] = nums[0];

        for(int i = 1; i < nums.length; ++i) {

            if(nums[i] > dp[bound])         /* A longer subsequence is found */
                dp[++bound] = nums[i];

            else {                          /* Binary search */
                int lo = 0, hi = bound;
                while (lo < hi) {

                    int mid = (lo + hi) / 2;
                    
                    if(nums[i] > dp[mid])
                        lo = mid + 1;
                    else
                        hi = mid;
                }
                
                dp[lo] = nums[i];
            }

        }

        return bound + 1;

    }

}