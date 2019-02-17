#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0)
            return word2.length();
        else if (word2.length() == 0)
            return word1.length();
        
        vector<vector<int>> dp(word1.size() + 1, 
                               vector<int>(word2.size() + 1, INT_MAX));
        for (int i = 0; i < word1.size() + 1; ++i)
            dp[i][0] = i;
        for (int i = 0; i < word2.size() + 1; ++i)
            dp[0][i] = i;
        
        for (int i = 1; i < word1.size() + 1; ++i) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};