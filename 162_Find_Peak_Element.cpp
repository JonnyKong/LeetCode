/**
 * Messy binary search
 * 
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        /* Sanity check */
        if (nums.size() == 1)
            return 0;
        else if(nums.size() == 2)
            return nums[0] > nums[1] ? 0 : 1;

        /* Binary search */
        int lo = 0, hi = nums.size() - 1;
        int ans = -1;
        while (1) {
            int mid = lo + (hi - lo) / 2;
            if (mid == 0 || mid == nums.size() - 1) {
                ans = mid;
                break;
            }
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                ans = mid;
                break;
            } else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};


int main() {
    vector<int> a = {3, 4, 3, 2, 1};
    int b = Solution().findPeakElement(a);
    cout << b << endl;
}