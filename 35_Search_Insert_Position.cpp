//
//  35. Search Insert Position.h
//  Project 1
//
//  Created by Jonny Kong on 2/28/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    vector<int>::iterator a;
    a = find(nums.begin(), nums.end(), target);
    if (a != nums.end())
      return a - nums.begin();

    else {
      a = nums.begin();

      if (*a > target) return 0;

      while (a != nums.end() - 1) {
        if (*a<target&&*(a + 1)> target) return a - nums.begin() + 1;

        ++a;
      }

      return nums.size();
    }
  }
};