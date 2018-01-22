class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        vector<int> dp(nums.size(), 1);
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = i - 1; j != -1; --j) {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }
        int maxIndex = 0;
        for(int i = 1; i < dp.size(); ++i) {
            if(dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }
        
        result.resize(dp[maxIndex]);
        int pos = dp[maxIndex] - 1;
        result[pos--] = nums[maxIndex];
        for(int i = maxIndex - 1; i >= 0; --i) {
            if(result[pos + 1] % nums[i] == 0) {
                result[pos--] = nums[i];
            }
        }
        return result;
    }
};
