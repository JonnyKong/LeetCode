class Solution {
    void subset_sum_dfs(const vector<int>& nums, int target, int start_idx, int &ret) {
        if (target < 0) {
            return;
        } else if (start_idx == nums.size()) {
            if (target == 0) {
                ret += 1;
            }
        } else {
            subset_sum_dfs(nums, target, start_idx + 1, ret);
            subset_sum_dfs(nums, target - nums[start_idx], start_idx + 1, ret);
        }
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int a : nums) {
            sum += a;
        }

        if ((sum + target) % 2 == 1) {
            return 0;
        }

        int subset_sum_target = (sum + target) / 2;
        int ret = 0;
        subset_sum_dfs(nums, subset_sum_target, 0, ret);
        return ret;
    }
};

/*
 * Worst case: O(N^2). Pruning not possible because numbers can be negative.
 *
 * Need to assign positive signs to a subset of numbers, negative signs to the rest.
 *
 * P = sum of all integers assigned +, N otherwise
 *
 * P + N = total
 * P - N = k
 * 2P = total + k   -> converted to a subset sum problem, enables pruning
 */
