class Solution {
 public:
  vector<vector<int>> result;
  vector<int> current;
  int length;

  void dfs(const vector<int>& candidates, int target, int start) {
    if (target == 0) {
      result.push_back(current);
      return;
    }
    for (int i = start; i < length; ++i) {
      if (candidates[i] > target) break;
      current.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], i);
      current.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    length = candidates.size();
    dfs(candidates, target, 0);
    return result;
  }
};