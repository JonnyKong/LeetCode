/**
 * Bit operation.
 */

class Solution {

    public int getSum(int a, int b) {
        int c = 0;
        int p = 1;
        for(int i = 0; i < 32; ++i) {
            boolean flag = false;
            if((a & p) != 0 && (b & p) != 0 ||
                    (a & p) != 0 && (c & p) != 0 ||
                    (b & p) != 0 && (c & p) != 0) {
                flag = true;
            }
            c ^= (a & p);
            c ^= (b & p);
            if(flag)
                c |= (p << 1);
            p <<= 1;
        }
        return c;
    }
}