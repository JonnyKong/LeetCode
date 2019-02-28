/**
 * Greedy O(n).
 *
 * Scan through array, and record max reach. (Does not care about how to reach)
 */

class Solution {
 public:
  // bool canJump(vector<int>& nums) {
  //     /* Sanity check */
  //     if(nums[0] == 0 && nums.size() > 1)
  //         return false;

  //     for(int i = nums.size() - 2; i >= 0; --i) {
  //         if(nums[i] > 0)
  //             continue;

  //         for(int j = 1; ; ++j) {
  //             if(i - j < 0)
  //                 return false;
  //             else if(nums[i - j] > j) {
  //                 i = i - j;
  //                 break;
  //             }
  //         }
  //     }
  //     return true;
  // }

  bool canJump(vector<int>& nums) {
    int maxReach = nums[0];
    for (int index = 0; index < nums.size(); ++index) {
      if (index > maxReach) break;
      maxReach =
          maxReach > (index + nums[index]) ? maxReach : (index + nums[index]);
    }
    return maxReach >= nums.size() - 1;
  }
};