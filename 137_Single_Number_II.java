/**
 * Adds every digits up. The digits that cannot be divided by 3 belongs to
 * the number that appeared only once.
 */

class Solution {

    public int singleNumber(int[] nums) {

        int[] digits = new int[32];
        for(int i = 0; i < nums.length; ++i) {

            for(int j = 0; j < 32; ++j) {
                if((nums[i] & 1) == 1)
                    digits[32 - j - 1]++;
                nums[i] >>= 1;
            }
        }

        int result = 0;
        for(int i = 0; i < 32; ++i) {
            result <<= 1;
            if(digits[i] % 3 != 0)
                result |= 1;
        }

        return result;
    }
}