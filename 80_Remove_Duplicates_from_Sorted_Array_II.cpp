//
//  80. Remove Duplicates from Sorted Array II.h
//
//
//  Created by Jonny Kong on 3/2/16.
//
//

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 3) return nums.size();

    auto slow = nums.begin() + 1;
    auto fast = nums.begin() + 1;

    int current = nums[0];
    int count = 1;
    int total = 1;

    while (fast != nums.end()) {
      if (*fast != current) {
        current = *fast;

        count = 1;

        *(slow++) = *(fast++);

        ++total;

      }

      else if (*fast == current && count < 2) {
        ++count;

        *(slow++) = *(fast++);

        ++total;

      }

      else {
        ++fast;
      }
    }

    return total;
  }
};