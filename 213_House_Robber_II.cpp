class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    else if (nums.size() == 1)
      return *nums.begin();

    if (nums.size() == 2) return max(*nums.begin(), *(nums.begin() + 1));

    vector<int> profitA(nums.size());  // rob the first house
    profitA[0] = nums[0];
    profitA[1] = max(nums[0], nums[1]);

    vector<int> profitB(nums.size());  // not rob the first
    profitB[0] = 0;
    profitB[1] = nums[1];
    profitB[2] = max(nums[1], nums[2]);

    int i;

    for (i = 2; i < profitA.size() - 1; ++i) {
      profitA[i] = max(profitA[i - 2] + nums[i], profitA[i - 1]);
    }

    auto result = profitA[i - 1];

    for (i = 3; i < profitB.size(); ++i) {
      profitB[i] = max(profitB[i - 2] + nums[i], profitB[i - 1]);
    }

    return max(result, profitB[i - 1]);
  }
};