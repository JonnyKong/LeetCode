class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int count = 9;
        for(int i = 0, digit = 9; i != n - 1; ++i, --digit) count *= digit;
        return count + countNumbersWithUniqueDigits(n - 1);
    }
};