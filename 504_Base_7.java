class Solution {
    public String convertToBase7(int num) {
        boolean negative = false;
        if(num < 0) {
            negative = true;
            num = ~num + 1;
        }
        int base = 1977326743, result = 0;
        while(base > 0) {
            result *= 10;
            result += num / base;
            num %= base;
            base /= 7;
        }
        if(negative) {
            result = ~result + 1;
        }
        return Integer.toString(result);
    }
}