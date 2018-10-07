/**
 * Sort + N * 2-pointers = N^2;
 * 
 * Key step: Removing duplicates.
 * Note that only final result can't contain duplicates. However, the same
 *  number can appear in the same answer. Have to be careful removing 
 *  duplicates.
 * 
 * Result uniqueness guaranteed by: Each final result is sorted. At each loop,
 *  l begins from (r + 1).
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);

        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(min_diff)) {
                    min_diff = sum - target;
                    if (min_diff == 0)   /* Pruning */
                        return target;
                }
                if (sum < target) {
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1])
                        ++l;
                    ++l;
                } else {
                    while(r - 1 >= 0 && nums[r - 1] == nums[r])
                        --r;
                    --r;
                }
            }

            /* Deal with i duplicates in the end. Possible that nums[i] == nums[l] */
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        return min_diff + target;
    }
};

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> result_tmp(3);
                    result_tmp[0] = nums[i];
                    result_tmp[1] = nums[l];
                    result_tmp[2] = nums[r];
                    result.push_back(result_tmp);
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1])
                        ++l;
                    while(r - 1 >= 0 && nums[r - 1] == nums[r])
                        --r;
                    ++l; --r;
                } else if (sum < 0) {
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1])
                        ++l;
                    ++l;
                } else {
                    while(r - 1 >= 0 && nums[r - 1] == nums[r])
                        --r;
                    --r;
                }
            }

            /* Deal with i duplicates in the end. Possible that nums[i] == nums[l] */
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        return result;
    }
};

int main() {
    vector<int> a = {-2, 0, 0, 2, 2};
    vector<vector<int>> result = Solution().threeSum(a);
    for (auto arr : result) {
        for (int i : arr) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}