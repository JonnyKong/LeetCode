class Solution {

    public int countPrimeSetBits(int L, int R) {

        int result = 0;
        for(int i = L; i <= R; ++i) {
            int count = countBits(i);
            if(count == 2 || count == 3 || count == 5 || count == 7 ||
                    count == 11 || count == 13 || count == 17 || count == 19)
                ++result;
        }
        return result;

    }

    /* Count number of set bits between [0, 19] */
    private int countBits(int n) {
        int result = 0;
        for(int i = 0; i < 20; ++i) {
            result += ((n & 0x1) == 1) ? 1 : 0;
            n >>= 1;
        }
        return result;
    }

}