//
//  96. Unique Binary Search Trees.h
//  Project 1
//
//  Created by Jonny Kong on 3/2/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
 public:
  int numTrees(int n) {
    if (n == 0)
      return 1;

    else if (n == 1)
      return 1;

    else if (n == 2)
      return 2;

    vector<int> num(n + 1, 0);
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;

    for (int i = 3; i < n + 1; ++i) {
      for (int j = 1; j <= i; ++j) {  // root -> val = j;

        num[i] += (num[j - 1] * num[i - j]);
      }
    }

    return num[n];
  }
};