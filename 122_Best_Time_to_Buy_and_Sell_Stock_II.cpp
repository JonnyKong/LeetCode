//
//  122. Best Time to Buy and Sell Stock II.h
//  
//
//  Created by Jonny Kong on 3/1/16.
//
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() < 2) return 0;
        
        int profit = 0;
        
        for(auto a = prices.begin(); a + 1 != prices.end(); ++a){
            
            if(*a < *(a + 1)) profit += (*(a + 1) - *a);
            
        }
        
        return profit;
        
    }
};