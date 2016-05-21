class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        unordered_map<int, int> a;
        for(int num : nums){
            auto p = a.find(num);
            if(p == a.end()) a.insert({num, 1});
            else ++p -> second;
        }
        for(auto p : a){
            if(p.second > nums.size() / 3){
                result.push_back(p.first);
            }
        }
        return result;
    }
};
