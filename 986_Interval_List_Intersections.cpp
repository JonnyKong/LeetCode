class Solution {
    // Scan from left to right on the axis, keep number indicating the number of current valid intervals
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<int> opens;
        vector<int> closes;

        for (auto vec: firstList) {
            opens.push_back(vec[0]);
            closes.push_back(vec[1]);
        }
        for (auto vec: secondList) {
            opens.push_back(vec[0]);
            closes.push_back(vec[1]);
        }
        sort(opens.begin(), opens.end());
        sort(closes.begin(), closes.end());

        int i = 0;
        int j = 0;
        int currentStart = 0;
        int numIntervals = 0;
        vector<vector<int>> ret;
        while (i < opens.size() || j < closes.size()) {
            if (i < opens.size() && opens[i] <= closes[j]) {
                numIntervals++;
                if (numIntervals == 2) {
                    currentStart = opens[i];
                }
                i++;
            } else {
                if (numIntervals == 2) {
                    ret.push_back({currentStart, closes[j]});
                }
                numIntervals--;
                j++;
            }
        }

        return ret;
    }
};

/*
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
opens: [0, 1, 5, 8, 13, 15, 24, 25]
closes: [2, 5, 10, 12, 23, 24, 25, 26]
*/
