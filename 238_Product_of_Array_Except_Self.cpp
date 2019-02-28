//
//  238. Product of Array Except Self.h
//
//
//  Created by Jonny Kong on 2/28/16.
//
//

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size());

    result[0] = 1;
    result[1] = nums[0];
    for (int i = 2; i < nums.size(); ++i) {
      result[i] = result[i - 1] * nums[i - 1];
    }

    int m = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; --i) {
      result[i] *= m;
      m *= nums[i];
    }

    return result;
  }
};