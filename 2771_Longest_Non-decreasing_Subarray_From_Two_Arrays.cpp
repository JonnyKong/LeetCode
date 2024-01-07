class Solution {
public:
    // int max(int i, int j) {
    //     return i > j ? i : j;
    // }
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            return 0;
        }

        vector<vector<int>> dp(2, vector<int>(nums1.size(), 1));

        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] >= nums1[i - 1]) {
                dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                dp[0][i] = max(dp[0][i], dp[1][i - 1] + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                dp[1][i] = max(dp[1][i], dp[0][i - 1] + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
            }
        }
        return max(
            *max_element(dp[0].begin(), dp[0].end()),
            *max_element(dp[1].begin(), dp[1].end())
        );
    }
};

/**

dp[i, j] = 1 (max subarray len taking j-th number from array i)
for each k:
    if nums[i, j] >= nums[i - 1, k]:
        dp[i, j] = max(dp[i, j], dp[i - 1, k] + 1)

nums1 = [2, 3, 1]
nums2 = [1, 2, 1]

dp = [
    [1, 2, 0],
    [1, 2, 0]
]

nums1 = [1, 3, 2, 1]
nums2 = [2, 2, 3, 4]
dp = [
    [1, 2, 3, 1],
    [1, 2, 3, 4],
]
*/
