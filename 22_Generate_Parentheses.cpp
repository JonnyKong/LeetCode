class Solution {
 private:
  vector<string> result;
  string current;
  void dfs(int left, int right, string current) {
    if (left == 0) {
      for (int i = 0; i < right; ++i) current += ')';
      result.push_back(current);
      return;
    }
    dfs(left - 1, right, current + '(');
    if (left < right) dfs(left, right - 1, current + ')');
  }

 public:
  vector<string> generateParenthesis(int n) {
    dfs(n, n, string(""));
    return result;
  }
};