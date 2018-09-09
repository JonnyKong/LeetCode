class Solution {

    public int maxProfit(int k, int[] prices) {

        /* Sanity check */
        if(k == 0 || prices.length == 0)
            return 0;
        if(k >= prices.length / 2)          /* Quicksolve to avoid TLE */
            return quickSolve(prices);

        /* dp[i][j]: max profit in first j days with i transactions */
        int[][] dp = new int[k + 1][prices.length];
        for(int i = 1; i < k + 1; ++i) {
            int max_profit = -prices[0];    /* Max profit with a stock in hold */
            for(int j = 1; j < prices.length; ++j) {
                dp[i][j] = Integer.max(dp[i][j - 1], max_profit + prices[j]);
                max_profit = Integer.max(max_profit, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][prices.length - 1];
    }

    /* Max profit with unlimited transactions */
    private int quickSolve(int[] prices) {
        int result = 0;
        for(int i = 1; i < prices.length; ++i) {
            if(prices[i] > prices[i - 1])
                result += prices[i] - prices[i - 1];
        }
        return result;
    }

}