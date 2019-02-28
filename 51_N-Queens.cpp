class Solution {
 private:
  bool conflict(const vector<int>& position, int i) {
    for (int j = 0; j < i; ++j) {
      if (position[i] == position[j] ||
          (i - j) == abs(position[i] - position[j]))
        return 1;
    }
    return 0;
  }

  void print(const vector<int>& position, vector<vector<string>>& result) {
    int n = position.size();
    vector<string> temp(n, string(n, '.'));
    for (int i = 0; i < n; ++i) {
      temp[position[i]][i] = 'Q';
    }
    result.push_back(temp);
  }

  void dfs(vector<int>& position, vector<vector<string>>& result, int i) {
    // cout << "dfs executed, depth: " << i << endl;
    int n = position.size();
    if (i == n) {  // solution found
      print(position, result);
      return;
    }
    for (int j = 0; j < n; ++j) {
      position[i] = j;
      if (!conflict(position, i)) dfs(position, result, i + 1);
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<int> position(n);
    vector<vector<string>> result;
    dfs(position, result, 0);
    return result;
  }
};