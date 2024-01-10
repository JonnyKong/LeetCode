class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    // Return the size of the discovered island
    void dfs(const vector<vector<int>>& grid, vector<vector<int>> &islandIds, int i, int j, int &size, int islandId) {
        // printf("visiting %d, %d, islandId %d\n", i, j, islandId);
        // assumes visited is false, and grid[i][j] == 1
        islandIds[i][j] = islandId;
        size++;

        for (auto d : directions) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            if (i_ >= 0 && i_ < grid.size() && j_ >= 0 && j_ < grid[0].size()) {
                if (islandIds[i_][j_] == -1 && grid[i_][j_] == 1) {
                    dfs(grid, islandIds, i_, j_, size, islandId);
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        // Name islands 0, 1, 2, ...
        vector<int> islandSizes;

        vector<vector<int>> islandIds(grid.size(), vector<int>(grid[0].size(), -1));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (islandIds[i][j] == -1 && grid[i][j] == 1) {
                    int size = 0;
                    dfs(grid, islandIds, i, j, size, islandSizes.size());
                    islandSizes.push_back(size);
                }
            }
        }

        if (islandSizes.size() == 0) {
            return 1;
        }

        int bestSize = *max_element(islandSizes.begin(), islandSizes.end());

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    // Add surrounding island sizes with deduplication
                    set<int> usedIslands;
                    int connectedSize = 1;

                    for (auto d : directions) {
                        int i_ = i + d[0];
                        int j_ = j + d[1];

                        if (i_ < 0 || j_ < 0 || i_ >= grid.size() || j_ >= grid[0].size()) {
                            continue;
                        }
                        if (grid[i_][j_] == 0) {
                            continue;
                        }

                        if (usedIslands.find(islandIds[i_][j_]) == usedIslands.end()) {
                            usedIslands.insert(islandIds[i_][j_]);
                            connectedSize += islandSizes[islandIds[i_][j_]];
                        }
                    }

                    bestSize = max(bestSize, connectedSize);
                }
            }
        }

        return bestSize;
    }
};
