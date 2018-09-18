/**
 * Bit manipulation. 
 */

class Solution {

    public boolean isPowerOfTwo(int n) {
        // for(int i = 1; i > 0; i <<= 1) {
        //     if(n == i)
        //         return true;
        // }
        // return false;
        return n > 0 && (n & (n - 1)) == 0;
    }

}