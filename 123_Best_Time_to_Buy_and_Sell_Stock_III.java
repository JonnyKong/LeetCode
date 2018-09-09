/**
 * This solution keeps 4 variables, see comments.
 * 
 * Because release2 is always higher than release1, we can return release2
 * after traversing the array.
 * 
 */

class Solution {

    public int maxProfit(int[] prices) {

        int hold1 = Integer.MIN_VALUE;  /* Balance after buying 1st stock */
        int release1 = 0;               /* Balance after selling 1st stock */
        int hold2 = Integer.MIN_VALUE;  /* Balance after buying 2nd stock */
        int release2 = 0;               /* Balance after selling 2nd stock */

        for(int i = 0; i < prices.length; ++i) {
            hold1 = Integer.max(hold1, 0 - prices[i]);
            release1 = Integer.max(release1, hold1 + prices[i]);
            hold2 = Integer.max(hold2, release1 - prices[i]);
            release2 = Integer.max(release2, hold2 + prices[i]);
        }

        return release2;

    }

}