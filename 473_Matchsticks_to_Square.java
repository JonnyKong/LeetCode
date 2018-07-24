class Solution {

    public boolean makesquare(int[] nums) {

        /* Sanity check */
        if(nums.length == 0)
            return false;

        /* Get the width of square */
        long width = 0;
        for(int a : nums)
            width += a;
        if((width & 3) != 0)        /* Cannot make a square */
            return false;
        width >>= 2;

        boolean[] used = new boolean[nums.length];
        return dfs(nums, used, 0, 0, width, 0);
    }

    private boolean dfs(final int[] nums, boolean[] used, final int start,
                        final int acc, final long width, final int count) {
        if(count == 4) {            /* 4 valid segments are found */
            for(boolean a : used) {     /* Check if we have used all segments */
                if(a == false)
                    return false;
            }
            return true;
        }

        else if(acc == width) {     /* 1 valid segment found */
            return dfs(nums, used, 0, 0, width, count + 1);
        }

        else if(acc > width)        /* Cannot find a valid segment */
            return false;

        else {                      /* Keep searching */
            for(int i = start; i < nums.length; ++i) {
                if(used[i] == false) {
                    used[i] = true;
                    if(dfs(nums, used, i, acc + nums[i], width, count))
                        return true;
                    used[i] = false;
                }
            }
            return false;
        }

    }

}