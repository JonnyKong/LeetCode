//
//  260. Single Number III.h
//
//
//  Created by Jonny Kong on 2/29/16.
//
//

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, bool> a;

    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
      if (a.find(nums[i]) == a.end()) {  // did not find

        a[nums[i]] = 0;

      }

      else
        a.erase(nums[i]);
    }

    for (unordered_map<int, bool>::iterator p = a.begin(); p != a.end(); ++p) {
      result.push_back(p->first);
    }

    return result;
  }
};