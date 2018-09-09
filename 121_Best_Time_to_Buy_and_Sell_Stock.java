class Solution {

    public int maxProfit(int[] prices) {
        
        /* Sanity check */
        if(prices.length == 0)
            return 0;

        int min_buy = prices[0];        /* Minimal buy-in price */
        int max_profit = 0;             /* Max profit */

        for(int i = 1; i < prices.length; ++i) {
            int profit = prices[i] - min_buy;
            if(profit > max_profit)
                max_profit = profit;
            if(prices[i] < min_buy)
                min_buy = prices[i];
        }

        return max_profit;
    }
}