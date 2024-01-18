class Solution {
/*
[3, 1, 2]
Build cumWeights: [3, 4, 6]
Random pick from 0-5:
Picked [0, 1, 2]: return 0
Picked [3]: return 1
Picked [4, 5]: return 2

Flip coin i drawn from {0-5}:
Return idx of first elem in cumWeights > i
*/
public:
    vector<long long> cumWeight;

    Solution(vector<int>& w) {
        long long c = 0;
        for (int w_ : w) {
            c += w_;
            cumWeight.push_back(c);
        }
    }
    
    int pickIndex() {
        long long coin = rand() % cumWeight.back();
        auto it = upper_bound(cumWeight.begin(), cumWeight.end(), coin);
        return it - cumWeight.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
