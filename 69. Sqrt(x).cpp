class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        ++x;
        int left = 1, right = 1 << 16, mid;
        while(left < right){
            mid = (left + right) >> 1;
            if(mid * mid > x){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left - 1;
    }
    
};