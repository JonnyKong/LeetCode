class Solution {
public:
    // https://algo.monster/liteproblems/787
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dists(n, INT_MAX);
        vector<int> distsPrev(n);
        dists[src] = 0;

        for (int i = 0; i < k + 1; i++) {
            std::copy(dists.begin(), dists.end(), distsPrev.begin());
            for (const auto &flight : flights) {
                if (distsPrev[flight[0]] < INT_MAX && 
                    distsPrev[flight[0]] + flight[2] < dists[flight[1]]) {
                    dists[flight[1]] = distsPrev[flight[0]] + flight[2];
                }
            }
        }

        return dists[dst] < INT_MAX ? dists[dst] : -1;
    }
};
