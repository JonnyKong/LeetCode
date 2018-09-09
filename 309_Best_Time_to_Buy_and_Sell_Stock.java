/**
 * This solution keeps 3 DP arrays. Each array records the max profit of an
 * action sequence ending correspondingly.
 */

class Solution {

    public int maxProfit(int[] prices) {

        /* Sanity check */
        if(prices.length == 0)
            return 0;

        int[] buy = new int[prices.length];
        int[] sell = new int[prices.length];
        int[] cool = new int[prices.length];
        buy[0] = -prices[0];

        for(int i = 1; i < prices.length; ++i) {
            buy[i] = Integer.max(buy[i - 1], cool[i - 1] - prices[i]);
            sell[i] = Integer.max(sell[i - 1], buy[i - 1] + prices[i]);
            cool[i] = Integer.max(cool[i - 1], Integer.max(buy[i - 1], sell[i - 1]));
        }

        return sell[prices.length - 1];
    }
}