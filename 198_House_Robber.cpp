//
//  198. House Robber.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int rob(vector<int>& nums) {
  if (nums.empty())
    return 0;
  else if (nums.size() == 1)
    return nums[0];
  else if (nums.size() == 2)
    return max(nums[0], nums[1]);

  int size = nums.size();

  int* value = new int[size];
  value[0] = nums[0];
  value[1] = max(nums[0], nums[1]);

  for (int i = 2; i < size; ++i) {
    value[i] = max(value[i - 2] + nums[i], value[i - 1]);
  }

  int maxValue = value[size - 1];

  delete[] value;

  return maxValue;
}

// 2019-02-17
class Solution2 {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    vector<int> dp1(nums.size());  // Rob current
    vector<int> dp2(nums.size());  // No rob current
    dp1[0] = nums[0];
    dp2[0] = 0;

    for (int i = 1; i < nums.size(); ++i) {
      dp1[i] = dp2[i - 1] + nums[i];
      dp2[i] = max(dp1[i - 1], dp2[i - 1]);  // Can skip 2 houses max
    }

    return max(dp1[nums.size() - 1], dp2[nums.size() - 1]);
  }
};

// 2023-12-27
class Solution3 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        } else if (nums.size() == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// 2025-02-16
// class Solution {

/*
dp[i] means the highest profit robbing the first i houses, (the i-th house
must be robbed).

nums [1, 2, 3, 1]
dp[0] = 1; <- if only one house, best to always rob
dp[1] = max(1, 2); <- if two houses, rob the larger one
dp[2] = max(dp[0] + nums[2], dp[1])
*/

public:
    int rob(vector<int>& nums) {    
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return *std::max_element(dp.begin(), dp.end());
    }
};