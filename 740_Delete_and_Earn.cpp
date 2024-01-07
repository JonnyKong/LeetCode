class Solution {
public:
    int houseRobber(const vector<int> & nums) {
        vector<int> dp = vector<int>(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
    
    // Convert to house robber II
    int deleteAndEarn(vector<int>& nums) {
        vector<int> moneyToRob = vector<int>(10001, 0);
        for (int n : nums) {
            moneyToRob[n] += n;
        }

        return houseRobber(moneyToRob);
    }
}
