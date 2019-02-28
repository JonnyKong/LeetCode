//
//  334. Increasing Triplet Subsequence.h
//  Project 1
//
//  Created by Jonny Kong on 2/27/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

/*

 This algorithm created two vector<bool> to indicate whether there is a
 smaller(larger) number to the left(right) of this number.

 If there is one number that both vector<bool>[i] is TRUE return TRUE.

*/

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int length = nums.size();

    if (length < 3) return 0;

    vector<bool> hasLeft(length, 0);
    vector<bool> hasRight(length, 0);

    hasLeft[0] = 0;
    for (int i = 1, min = nums[0]; i < length; ++i) {
      if (nums[i] > min)
        hasLeft[i] = 1;

      else if (nums[i] < min)
        min = nums[i];
    }

    hasRight[length - 1] = 0;
    for (int i = length - 2, max = nums[length - 1]; i >= 0; --i) {
      if (nums[i] < max)
        hasRight[i] = 1;

      else if (nums[i] > max)
        max = nums[i];
    }

    for (int i = 1; i < length - 1; ++i) {
      if (hasLeft[i] & hasRight[i]) return 1;
    }

    return 0;
  }
};