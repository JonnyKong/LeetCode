class Solution {
public:
    unordered_map<int, vector<int>> num2Idx;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            if (num2Idx.find(n) == num2Idx.end()) {
                num2Idx[n] = vector<int>();
            }
            num2Idx[n].push_back(i);
        }    
    }
    
    int pick(int target) {
        auto Idxs = num2Idx[target];
        return Idxs[rand() % Idxs.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
