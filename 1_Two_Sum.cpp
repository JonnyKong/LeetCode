//
//  1. Two Sum.h
//
//
//  Created by Jonny Kong on 3/4/16.
//
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> a;

    int i = 0, j;

    for (auto number : nums) {
      if (a.find(target - number) == a.end()) {
        a[number] = i;

      }

      else {
        j = a.find(target - number)->second;

        break;
      }

      ++i;
    }

    return vector<int>{j, i};
  }
};