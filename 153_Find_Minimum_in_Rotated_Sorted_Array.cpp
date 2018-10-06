/**
 * Very weird. Not typical binary search.
 * 
 * Split into multiple scenarios.
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi) {

            if (nums[lo] < nums[hi])
                return nums[lo];

            int mid = lo + (hi - lo) / 2;
            int midValue = nums[mid];
            if (midValue > nums[hi])
                lo = mid + 1;
            else if(midValue < nums[lo])
                hi = mid;
        }

        return nums[lo];
    }
};

class Solution2 {
public:

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] < nums[r])
                break;

            int mid = l + (r - l) / 2;
            int midValue = nums[mid];
            if (midValue > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};

int main() {
    vector<int> a = {2, 1};
    int b = Solution().findMin(a);
    cout << b << endl;
}