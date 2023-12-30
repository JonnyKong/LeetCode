//
//  309. Best Time to Buy and Sell Stock with Cooldown.h
//  Project 1
//
//  Created by Jonny Kong on 2/28/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;

    vector<int> maxProfit(prices.size());

    maxProfit[0] = 0;

    int i;

    for (i = 1; i < maxProfit.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        maxProfit[i] = max(maxProfit[i], (j >= 2 ? maxProfit[j - 2] : 0) +
                                             prices[i] - prices[j]);
      }

      maxProfit[i] = max(maxProfit[i - 1], maxProfit[i]);
    }

    return maxProfit[i - 1];
  }
};


// 2023-12-29
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy_or_hold = vector<int>(prices.size());    
        vector<int> sell = vector<int>(prices.size());    
        vector<int> cool = vector<int>(prices.size());    

        buy_or_hold[0] = -1 * prices[0];
        sell[0] = 0;
        cool[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            buy_or_hold[i] = max(buy_or_hold[i - 1], cool[i - 1] - prices[i]);
            sell[i] = buy_or_hold[i - 1] + prices[i];
            cool[i] = max(cool[i - 1], sell[i - 1]);
        }

        return *max_element(sell.begin(), sell.end());
    }
};