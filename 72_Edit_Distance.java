class Solution {

    public int minDistance(String word1, String word2) {

        int[][] dp = new int[word1.length() + 1][word2.length() + 1];

        /* DP Initialization: Convert to or from empty string */
        for(int i = 0; i < dp.length; ++i)
            dp[i][0] = i;
        for(int i = 1; i < dp[0].length; ++i)
            dp[0][i] = i;

        /* DP */
        for(int i = 1; i < dp.length; ++i) {

            for(int j = 1; j < dp[0].length; ++j) {

                /* Equal */
                if(word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else {
                    int rep = dp[i - 1][j - 1] + 1;         /* Replace */
                    int ins = dp[i][j - 1] + 1;             /* Insertion */
                    int del = dp[i - 1][j] + 1;             /* Deletion */

                    dp[i][j] = Integer.min(rep, Integer.min(ins, del));
                }

            }
        }
        return dp[word1.length()][word2.length()];

    }

}