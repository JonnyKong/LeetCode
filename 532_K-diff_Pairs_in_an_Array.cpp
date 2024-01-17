class Solution {
/*
Build freq table
For each elem in the table, if there exists elem+k, increment counter
Edge case: if k == 0, if elem+k appeared twice or more, increment counter

Could have also used two-pointers, but more difficult to write (e.g. need to
increment pointers to next larger elem).
*/
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;  // freq table
        for (int n : nums) {
            if (m.count(n) > 0) {
                m[n]++;
            } else {
                m[n] = 1;
            }
        }

        int ret = 0;
        for (auto &[n, _] : m) {
            if (k == 0) {
                if (m.count(n + k) > 0 && m[n + k] > 1) {
                    ret++;
                }
            } else {
                if (m.count(n + k) > 0) {
                    ret++;
                }
            }
        }
        return ret;
    }
};
