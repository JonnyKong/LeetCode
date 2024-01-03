class Solution {
public:
    vector<int> build_cumsum(const vector<int> & nums) {
        int cumsum = 0;
        vector<int> ret;
        for (int n : nums) {
            cumsum += n;
            ret.push_back(cumsum);
        }
        return ret;
    }

    int subarraySum(vector<int>& nums, int k) {
        auto cumsum = build_cumsum(nums);
        
        unordered_map<int, int> occurances;
        occurances[0] = 1;
        int ret = 0;
        for (int c : cumsum) {
            auto it = occurances.find(c - k);
            if (it != occurances.end()) {
                ret += it->second;
            }

            it = occurances.find(c);
            if (it != occurances.end()) {
                it->second++;
            } else {
                occurances[c] = 1;
            }
        }
        return ret;
    }
};
