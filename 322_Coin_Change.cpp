//
//  322. Coin Change.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int coinChange(vector<int>& coins, int amount) {
  if (!amount) return 0;

  sort(coins.begin(), coins.end());

  vector<int> numbers(amount + 1, INT_MAX - 1);
  numbers[0] = 0;

  int i, j;

  for (i = 1; i < amount + 1; ++i) {
    for (int j = 0; j < coins.size(); ++j) {
      if (i - coins[j] >= 0) {
        numbers[i] = min(numbers[i], numbers[i - coins[j]] + 1);

      }

      else
        break;
    }
  }

  if (numbers[amount] == INT_MAX - 1)
    return -1;
  else
    return numbers[amount];
}


// 2024-02-04
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i < dp.size(); i++) {
            for (int c : coins) {
                if (i - c >= 0 && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        if (dp.back() == INT_MAX) {
            return -1;
        } else {
            return dp.back();
        }
    }
};