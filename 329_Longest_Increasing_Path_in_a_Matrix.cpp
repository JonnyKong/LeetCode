class Solution {
 public:
  vector<vector<int>> visited;
  int m, n;
  int dfs(const vector<vector<int>>& matrix, int cur, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) return 0;
    if (matrix[i][j] <= cur) return 0;
    if (visited[i][j]) return visited[i][j];
    int a = dfs(matrix, matrix[i][j], i + 1, j);
    int b = dfs(matrix, matrix[i][j], i, j + 1);
    int c = dfs(matrix, matrix[i][j], i - 1, j);
    int d = dfs(matrix, matrix[i][j], i, j - 1);
    visited[i][j] = max(max(a, b), max(c, d)) + 1;
    return visited[i][j];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    m = matrix.size(), n = matrix[0].size();
    visited.resize(m, vector<int>(n));
    int maxLength = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        maxLength = max(maxLength, dfs(matrix, INT_MIN, i, j));
      }
    }
    return maxLength;
  }
};


// 2024-01-19
class Solution {
public:
    vector<vector<int>> directions = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        // cache[i][j] is the max possible number of moves
        // from that loc, including current loc
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size()));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                dfs(matrix, i, j, cache);
            }
        }

        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                result = max(result, cache[i][j]);
            }
        }
        return result;
    }

    void dfs(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & cache) {
        int result = 1;     // Returns number of moves possible from current loc, including current loc
        for (auto &d : directions) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            if (i_ >= 0 && i_ < matrix.size() && j_ >= 0 && j_ < matrix[0].size()) {
                if (matrix[i_][j_] > matrix[i][j]) {
                    int result_;
                    if (cache[i_][j_] == 0) {
                        dfs(matrix, i_, j_, cache);
                    }
                    result_ = cache[i_][j_] + 1;
                    result = max(result, result_);
                }
            }
        }
        cache[i][j] = result;
    }
};
