class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    else if (nums.size() == 1)
      return *nums.begin();

    if (nums.size() == 2) return max(*nums.begin(), *(nums.begin() + 1));

    vector<int> profitA(nums.size());  // rob the first house
    profitA[0] = nums[0];
    profitA[1] = max(nums[0], nums[1]);

    vector<int> profitB(nums.size());  // not rob the first
    profitB[0] = 0;
    profitB[1] = nums[1];
    profitB[2] = max(nums[1], nums[2]);

    int i;

    for (i = 2; i < profitA.size() - 1; ++i) {
      profitA[i] = max(profitA[i - 2] + nums[i], profitA[i - 1]);
    }

    auto result = profitA[i - 1];

    for (i = 3; i < profitB.size(); ++i) {
      profitB[i] = max(profitB[i - 2] + nums[i], profitB[i - 1]);
    }

    return max(result, profitB[i - 1]);
  }
};


// 2024-01-09
class Solution {
public:
    int house_robber_i(const vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        // begin inclusive, end exclusive
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else {
            vector<int> l = vector(nums.begin(), nums.end() - 1);
            vector<int> r = vector(nums.begin() + 1, nums.end());
            return max(
                house_robber_i(l),
                house_robber_i(r));
        }
    }
};