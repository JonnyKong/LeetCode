class Solution {
 private:
  vector<vector<int>> result;

  inline void swap(vector<int>& a, int i, int j) {
    if (i == j) return;
    a[i] ^= a[j];
    a[j] ^= a[i];
    a[i] ^= a[j];
  }

  inline void dfs(vector<int>& nums, int current) {
    if (current == nums.size() - 1)
      result.push_back(nums);
    else {
      set<int> checked;
      dfs(nums, current + 1);
      checked.insert(nums[current]);
      for (int j = current + 1; j < nums.size(); ++j) {
        if (checked.find(nums[j]) != checked.end()) continue;
        swap(nums, current, j);
        dfs(nums, current + 1);
        swap(nums, current, j);
        checked.insert(nums[j]);
      }
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    dfs(nums, 0);
    return result;
  }
};