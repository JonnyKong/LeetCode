class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        vector<char> ret;
        for (char c : order) {
            while (counts[c - 'a'] > 0) {
                ret.push_back(c);
                counts[c - 'a']--;
            }
        }

        for (int i = 0; i < counts.size(); i++) {
            while (counts[i] > 0) {
                ret.push_back(i + 'a');
                counts[i]--;
            }
        }
        
        return string(ret.begin(), ret.end());
    }
};
