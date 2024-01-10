class Solution {
public:
    void dfs(const vector<int> & nums, int target, int start_idx, int & ret) {
        if (start_idx == nums.size()) {
            if (target == 0) {
                ret += 1;
            }
        } else {
            dfs(nums, target + nums[start_idx], start_idx + 1, ret);
            dfs(nums, target - nums[start_idx], start_idx + 1, ret);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ret = 0;
        dfs(nums, target, 0, ret);
        return ret;
    }
};

// Solution by converting to subset sum problem, which facilitates pruning
// https://leetcode.com/problems/target-sum/solutions/97334/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation/
/*
Need to assign positive signs to a subset of elements, and negative signs to the
remaining. Let P denote the sum of positive signed numbers, and N negative. T is
the total sum.

P + N + T
P - N = t
2P = T + t
P = (T + t) / 2     -> converted to a subset sum problem

 */
class Solution2 {
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
