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
        
        if(prices.size() < 2) return 0;
        
        vector<int> maxProfit(prices.size());
        
        maxProfit[0] = 0;
        
        int i;
        
        for(i = 1; i < maxProfit.size(); ++i){
            
            for(int j = 0; j < i; ++j){
                
                maxProfit[i] = max(maxProfit[i], (j >= 2 ? maxProfit[j - 2] : 0) + prices[i] - prices[j]);
                
            }
            
            maxProfit[i] = max(maxProfit[i - 1], maxProfit[i]);
            
        }
        
        return maxProfit[i - 1];
        
    }
};