/**
 * XOR with a number like 00000...0001111...1111'b, where the number of set bits
 * equals the position of largest set bit in num.
 * 
 * In particular, for negative numbers, it is XORed with 0xffffffff. 
 */

class Solution {
    public int findComplement(int num) {
        int tmp = num;
        int mask = 0;
        while(tmp > 0) {
            tmp >>= 1;
            mask = (mask << 1) + 1;
        }
        return num ^ mask;
    }
}