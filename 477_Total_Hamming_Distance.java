/**
 * Key idea: The contributions of each bit are independent.
 * 
 * For each bit, if n bits are set and (nums.length - n) bits are not set, this
 * bit contributes n * (nums.length - n) to the final result.
 */

class Solution {

    public int totalHammingDistance(int[] nums) {

        int result = 0, count = 0;
        for(int i = 0; i < 32; ++i) {

            count = 0;
            for(int j = 0; j < nums.length; ++j) {
                if((nums[j] & 1) == 0)
                    count++;
                nums[j] >>= 1;
            }

            result += count * (nums.length - count);
        }

        return result;
    }

}