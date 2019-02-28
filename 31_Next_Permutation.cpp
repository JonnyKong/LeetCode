class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 2) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int i = nums.size() - 1;
    while (nums[i - 1] >= nums[i]) {
      --i;
      if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
      }
    }
    --i;
    int minPos = nums.size() - 1;
    int minValue = INT_MAX;  // the minimal number greater than nums[i].
    for (int j = nums.size() - 1; j > i; --j) {
      if (nums[j] > nums[i] && nums[j] < minValue) {
        minPos = j;
        minValue = nums[j];
      }
    }
    int temp = nums[i];
    nums[i] = nums[minPos];
    nums[minPos] = temp;
    sort(nums.begin() + i + 1, nums.end());
    return;
  }
};
