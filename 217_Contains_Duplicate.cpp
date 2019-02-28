//
//  217. Contains Duplicate.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool containsDuplicate(vector<int>& nums) {
  if (nums.size() <= 1) return 0;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; ++i) {
    if (nums[i] == nums[i + 1]) return 1;
  }

  return 0;
}