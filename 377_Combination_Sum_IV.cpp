class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> result(target + 1);
    sort(nums.begin(), nums.end());
    result[0] = 1;
    for (int j = 0; j < target + 1; ++j) {
      if (result[j] == 0) continue;
      for (int k = 0; k < nums.size(); ++k) {
        if (j + nums[k] <= target)
          result[j + nums[k]] += result[j];
        else
          break;
      }
    }
    return result.back();
  }
};