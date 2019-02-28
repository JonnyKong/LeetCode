//
//  62. Unique Paths.h
//  Project 1
//
//  Created by Jonny Kong on 2/28/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) return 1;

    vector<vector<int>> a(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      a[i][n - 1] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
      a[m - 1][i] = 1;
    }

    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        a[i][j] = a[i + 1][j] + a[i][j + 1];
      }
    }

    return a[0][0];
  }
};