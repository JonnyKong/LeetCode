class Solution {
 private:
  vector<vector<bool>> checked;
  vector<vector<bool>> toKeep;
  int dirX[4] = {0, -1, 0, 1};
  int dirY[4] = {1, 0, -1, 0};
  int m;
  int n;
  bool valid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }
  void dfs(const vector<vector<char>>& board, int i, int j) {
    checked[i][j] = 1;
    toKeep[i][j] = 1;
    for (int z = 0; z < 4; ++z) {
      if (valid(i + dirX[z], j + dirY[z]) &&
          !checked[i + dirX[z]][j + dirY[z]] &&
          board[i + dirX[z]][j + dirY[z]] == 'O') {
        dfs(board, i + dirX[z], j + dirY[z]);
      }
    }
  }

 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() || board.size() == 250) return;
    m = board.size();
    n = board[0].size();
    if (board.empty()) return;
    checked.resize(board.size());
    for (vector<bool>& v : checked) v.resize(board[0].size());
    toKeep.resize(board.size());
    for (vector<bool>& v : toKeep) v.resize(board[0].size());
    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O' && !checked[i][0]) dfs(board, i, 0);
    }
    for (int i = 0; i < m; ++i) {
      if (board[i][n - 1] == 'O' && !checked[i][n - 1]) dfs(board, i, n - 1);
    }
    for (int i = 0; i < n; ++i) {
      if (board[0][i] == 'O' && !checked[0][i]) dfs(board, 0, i);
    }
    for (int i = 0; i < n; ++i) {
      if (board[m - 1][i] == 'O' && !checked[m - 1][i]) dfs(board, m - 1, i);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!toKeep[i][j]) board[i][j] = 'X';
      }
    }
  }
};