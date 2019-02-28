class Solution {
 private:
  int dirX[4] = {1, 0, -1, 0};
  int dirY[4] = {0, 1, 0, -1};
  bool valid(const vector<vector<char>>& grid, int i, int j) const {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
           grid[i][j] == '1';
  }
  void dfs(const vector<vector<char>>& grid, int i, int j) {
    checked[i][j] = 1;
    for (int z = 0; z < 4; ++z) {
      if (valid(grid, i + dirX[z], j + dirY[z]) &&
          !checked[i + dirX[z]][j + dirY[z]]) {
        dfs(grid, i + dirX[z], j + dirY[z]);
      }
    }
  }
  vector<vector<bool>> checked;

 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    checked.resize(grid.size());
    for (vector<bool>& v : checked) v.resize(grid[0].size());
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (!checked[i][j] && grid[i][j] == '1') {
          dfs(grid, i, j);
          ++count;
        }
      }
    }
    return count;
  }
};