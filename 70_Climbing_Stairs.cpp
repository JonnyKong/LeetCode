//
//  70. Climbing Stairs.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
 public:
  int climbStairs(int n) {
    int *dp = new int(n);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    int result = dp[n - 1];
    delete dp;
    return result;
  }
};