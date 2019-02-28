//
//  287. Find the Duplicate Number.h
//
//
//  Created by Jonny Kong on 3/3/16.
//
//

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int result = 0;

    int a, b;

    for (int i = 0; i < 32; ++i) {
      int bit = (1 << i);

      a = 0;
      b = 0;

      for (int j = 0; j < nums.size(); ++j) {
        a += (nums[j] & bit) >> i;
      }

      for (int j = 0; j < nums.size() - 1; ++j) {
        b += (bit & (j + 1)) >> i;
      }

      if (a > b) result |= bit;
    }

    return result;
  }
};