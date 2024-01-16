class Solution {
public:
    /*
    Move a sliding window of size k, main count of frequency table within the window.

    Check the size of freq table for whether elems are unique.
    */
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return 0;
        }

        unordered_map<int, int> m;
        int i = 0;
        int j = 0;
        long long sum = 0;
        for (; j < k; j++) {
            sum += nums[j];
            if (m.find(nums[j]) != m.end()) {
                m[nums[j]] += 1;
            } else {
                m[nums[j]] = 1;
            }
        }
        long long maxSum = m.size() == k ? sum : 0;

        for (; j < nums.size(); i++, j++) {
            sum += nums[j];
            sum -= nums[i];

            if (m.find(nums[j]) != m.end()) {
                m[nums[j]] += 1;
            } else {
                m[nums[j]] = 1;
            }

            m[nums[i]]--;
            if (m[nums[i]] == 0) {
                m.erase(nums[i]);
            }

            // printf("i=%d, sum=%d\n", i, sum);
            if (m.size() == k && sum >= maxSum) {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};
