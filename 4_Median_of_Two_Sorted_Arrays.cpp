/**
 * See https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
 *  for explanations. 
 * 
 * Very nasty details due to boundaries.
 * 
 * Trick: Make sure nums1 shorter than nums2, so that we don't have to set a
 *  region for initial l and r.
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        /* Make sure nums1 shorter than nums2, so that we don't have to set
         * a region for initial l and r */
        if (nums1.size() > nums2.size()) {
            vector<int> nums3 = nums2;
            nums2 = nums1;
            nums1 = nums3;
        }

        int l = 0, r = nums1.size();
        int total_size = nums1.size() + nums2.size();
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            /* If odd, left side contain 1 more element than right side, such
             * that mid_other index does not reduce below 0 */
            int mid_other = (total_size + 1) / 2 - mid;
            if (mid_other < nums2.size() && nums1[mid - 1] > nums2[mid_other])
                r = mid - 1;
            else
                l = mid;
        }

        int max_left = INT_MAX, min_right = INT_MIN;
        if ((total_size + 1) / 2 - l == 0)
            max_left = nums1[l - 1];
        else if (l == 0)
            max_left = nums2[(total_size + 1) / 2 - l - 1];
        else
            max_left = max(nums1[l - 1], nums2[(total_size + 1) / 2 - l - 1]);

        if (l == nums1.size() && (total_size + 1) / 2 - l == nums2.size())
            min_right = INT_MIN;
        else if (l == nums1.size())
            min_right = nums2[(total_size + 1) / 2 - l];
        else if ((total_size + 1) / 2 - l == nums2.size())
            min_right  = nums1[l];
        else
            min_right = min(nums1[l], nums2[(total_size + 1) / 2 - l]);

        if (total_size % 2)
            return max_left;
        else
            return (max_left + min_right) / 2.0;
    }
};


int main() {
    vector<int> a = {1, 2, 4};
    vector<int> b = {3};
    cout << Solution().findMedianSortedArrays(a, b) << endl;
    return 0;
}