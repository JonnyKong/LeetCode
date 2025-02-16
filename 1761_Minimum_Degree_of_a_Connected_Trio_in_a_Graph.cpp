class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // Adjacency matrix
        vector<vector<int>> adjMat(n, vector<int>(n, 0));
        // List of degrees
        vector<int> degrees(n, 0);
        for (auto e : edges) {
            adjMat[e[0] - 1][e[1] - 1] = 1;
            adjMat[e[1] - 1][e[0] - 1] = 1;
            degrees[e[0] - 1]++;
            degrees[e[1] - 1]++;
        }

        int minTrioDeg = 0x7fffffff;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (adjMat[i][j] == 0)
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (adjMat[i][k] == 0 || adjMat[j][k] == 0)
                        continue;
                    // Found a trio here
                    // cout << "Found a trio: " << i << "," << j << "," << k << endl;
                    int deg = degrees[i] + degrees[j] + degrees[k] - 6;
                    minTrioDeg = min(minTrioDeg, deg);
                }
            }
        }
        
        return minTrioDeg == 0x7fffffff ? -1 : minTrioDeg;
    }
};
