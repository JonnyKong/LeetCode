/**
 * First, XOR each number gives an integer equal to XOR of the two unique
 * numbers.
 * 
 * Because the two numbers are different, this integer must have a bit that
 * is 1. We can divide all numbers into two parts using this bit.
 * 
 * For each of the two parts, XOR each number gives the one that appeared
 * only once.
 */

class Solution {

    public int[] singleNumber(int[] nums) {

        /* Get a bit that is different in the two unique numbers */
        int n = 0;
        for(int i : nums)
            n ^= i;
        for(int i = 0; i < 32; ++i) {
            if(((n >> i) & 1) == 1) {
                n = 1 << i;
                break;
            }
        }

        int num1 = 0, num2 = 0;
        for(int i : nums) {
            if((i & n) == 0)
                num1 ^= i;
            else
                num2 ^= i;
        }

        return new int[]{num1, num2};
    }
}