/**
 * Bit manipulation. i will eventually reach 0x80000000 < 0.
 */

class Solution {

    public boolean isPowerOfTwo(int n) {
        for(int i = 1; i > 0; i <<= 1) {
            if(n == i)
                return true;
        }
        return false;
    }

}