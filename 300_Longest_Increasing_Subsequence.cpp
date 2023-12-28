class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int max = 1;
    if (nums.empty()) return 0;
    vector<int> length(nums.size(), 1);
    length[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j] && length[i] < length[j] + 1) {
          length[i] = length[j] + 1;
          if (length[i] > max) max = length[i];
        }
      }
    }
    return max;
  }
};

// 2023-12-27
class Solution2 {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};