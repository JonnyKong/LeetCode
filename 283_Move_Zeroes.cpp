//
//  283. Move Zeroes.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void moveZeroes(vector<int>& nums) {
  vector<int>::iterator a = nums.begin();

  int i = 0;

  while (a != nums.end()) {
    if (*a == 0) {
      ++i;

      nums.erase(a);

    }

    else
      ++a;
  }

  for (int j = 0; j < i; ++j) nums.push_back(0);
}

// 2024-01-07
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Fast only reads, slow writes, so places travelled by fast has not been altered by slow
        int slow = 0;
        int fast = 0;
        
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        while (slow < nums.size()) {
            nums[slow] = 0;
            slow++;
        }
    }
};

/*
if arr[fast] > 0:
    arr[slow] = arr[fast]
    Slow advances
Fast advances
    

0  1  0  3  12
fs
s  f
   s  f
   s     f
      s      f

*/