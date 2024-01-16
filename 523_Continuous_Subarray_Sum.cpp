class Solution {
/*
If array[i, j-1] sums to multiple of k
-> cumsum(i) % k == cumsum(j) % k 

So, for each i, if cumsum(i) % k seen before, return true

Need to use an unordered_map to remember the indexes, so account for "length at least 2"
*/
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;  // Maps (cumsum % k) to its first appear loc
        m[0] = -1;
        int cumsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            cumsum += nums[i];
            int n_ = cumsum % k;

            auto p = m.find(n_);
            if (p == m.end()) {
                m[n_] = i;
            } else {
                if (i - p->second >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
