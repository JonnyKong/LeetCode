/**
 * Bitwise operation. Starting from MSB, find the first bit that differs in 
 * the two numbers. This bit and any remaining bits should be 0, while previous
 * bits remain unchanged.
 */

class Solution {

    public int rangeBitwiseAnd(int m, int n) {

        /* Calculated the first bit that differ */
        int digit = 1 << 30;
        while(digit > 0) {
            if(((m & digit) ^ (n & digit)) != 0)
                break;
            digit >>= 1;
        }

        /* All rest digits should be set to 0 */
        while(digit > 0) {
            m &= ~digit;
            digit >>= 1;
        }

        return m;
    }

}