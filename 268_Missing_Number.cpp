//
//  268. Missing Number.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
  int length = nums.size();
  int i;

  bool* occupied = new bool[length + 1];
  memset(occupied, 0, length * sizeof(bool));

  for (i = 0; i < length; ++i) {
    occupied[nums[i]] = 1;
  }

  int missingNumber;

  for (i = 0; i < length + 1; ++i) {
    if (!occupied[i]) {
      missingNumber = i;
      break;
    }
  }

  delete[] occupied;

  return missingNumber;
}

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    long long sum_all = (n * (n + 1)) >> 1;
    long long sum_actual = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum_actual += nums[i];
    }
    return sum_all - sum_actual;
  }
};

int main() {
  vector<int> input{3, 0, 1};
  int result = Solution().missingNumber(input);
  cout << result << endl;
}