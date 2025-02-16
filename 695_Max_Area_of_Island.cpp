class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int area = dfs(visited, grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<bool>> &visited, const vector<vector<int>> &grid, int i, int j) {
        visited[i][j] = true;
        int ret = 1;       // Assumes grid[i][j] == 1;
        for (auto &neighbor : neighbors) {
            int i_new = i + neighbor[0];
            int j_new = j + neighbor[1];
            bool in_bound = i_new >= 0 && i_new < grid.size() && j_new >= 0 && j_new < grid[0].size();
            if (in_bound && grid[i_new][j_new] && !visited[i_new][j_new]) {
                ret += dfs(visited, grid, i_new, j_new);
            }
        }
        return ret;
    }
};
