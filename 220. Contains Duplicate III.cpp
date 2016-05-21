class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int>> a;
        for(int i = 0; i < nums.size(); ++i){
            a.push_back(make_pair(nums[i], i));
        }
        sort(a.begin(), a.end(), [](const pair<int, int> & a, const pair<int, int> & b)->bool{ return a.first < b.first; });
        int fast = 0, slow = 0;
        for(fast = 1; fast < nums.size(); ++fast){
            while((long long)a[fast].first - a[slow].first > t) ++slow;
            for(int i = slow; i < fast; ++i){
                if(abs(a[i].second - a[fast].second) <= k) return 1;
            }
        }
        return 0;
    }
};