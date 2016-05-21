class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() < 2) return 0;
        
        vector<int> maxProfit(prices.size());
        maxProfit[0] = 0;
        
        int tempMin = prices[0];
        
        vector<int>::iterator a = prices.begin() + 1;
        
        int i = 1;
        
        for(; a != prices.end(); ++a){
            
            tempMin = min(tempMin, *(a - 1));
            
            maxProfit[i] = max(maxProfit[i - 1], *a - tempMin);
            
            ++i;
            
        }
        
        return maxProfit[i - 1];
        
    }
};