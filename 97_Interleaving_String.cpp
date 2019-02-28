#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length(), n = s2.length();
    if (m + n != s3.length()) return false;

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, true));

    dp[0][0] = true;
    for (int i = 1; i <= m; ++i) {
      if (dp[i - 1][0] && s1[i - 1] == s3[i - 1])
        dp[i][0] = true;
      else
        dp[i][0] = false;
    }
    for (int i = 1; i <= n; ++i) {
      if (dp[0][i - 1] && s2[i - 1] == s3[i - 1])
        dp[0][i] = true;
      else
        dp[0][i] = false;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1])
          dp[i][j] = true;
        else if (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1])
          dp[i][j] = true;
        else
          dp[i][j] = false;
      }
    }

    return dp[m][n];
  }
};

int main() {
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";

  bool result = Solution().isInterleave(s1, s2, s3);

  cout << result << endl;
}