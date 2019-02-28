class Solution {
  void dfs(vector<int>& current, vector<vector<int>>& result,
           const vector<int>& nums, int posStartFrom) {
    result.push_back(current);
    for (int i = posStartFrom; i < nums.size(); ++i) {
      current.push_back(nums[i]);
      dfs(current, result, nums, i + 1);
      current.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());
    dfs(current, result, nums, 0);
    return result;
  }
};