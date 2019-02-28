//
//  137. Single Number II.h
//
//
//  Created by Jonny Kong on 3/1/16.
//
//

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, bool> a;

    for (int num : nums) {
      if (a.find(num) == a.end())
        a[num] = 0;

      else
        a[num] = 1;
    }

    unordered_map<int, bool>::iterator b = a.begin();

    while (b != a.end()) {
      if (b->second == 0) {
        return b->first;
      }

      ++b;
    }

    return 0;
  }
};