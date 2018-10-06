/**
 * Binary search - O(logN).
 * 
 * 5 types of binary search types:
 * 1) Find one
 * 2) Find one with smallest index
 * 3) Find one with largest index
 * 4) Find largest number smaller than x (<)
 * 5) Find smallest number larger than x (>)
 * 
 * Carefully identify which type of binary search it is. For example, this 
 * problem belongs to type 5. (<= is equivalent to >)
 * 
 * Few things to pay attention:
 * 1) If type 4/5, make sure initial search region covers possible answer. In
 *      this problem, I added 1 to x to tackle corner cases of 0/1.
 * 2) Beware of overflow. For example, hi = x + 1 may overflow. Force type
 *      cast with hi = (long long)x + 1.
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        /* Sanity check */
        if(x == 0)
            return 0;

        /* Binary search: Find smallest number larger than x^2, then return num-1 */
        int ans = -1;
        long long lo = 0, hi = (long long)x + 1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            long long mid_value = mid * mid;
            if (mid_value < x) {
                lo = mid + 1;
            } else if (mid_value > x) {
                ans = mid;
                hi = mid - 1;
            } else if (mid_value == x) {
                lo = mid + 1;
            }
        }
        return ans - 1;
    }

    int mySqrt2(int x) {
        long long l = 0, r = x;
        while (l < r) {
            long long mid = l + (r - l + 1) / 2;
            long long midValue = mid * mid;
            if (midValue <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return r;
    }
};


int main() {
    cout << Solution().mySqrt(0x7fffffff) << endl;
}