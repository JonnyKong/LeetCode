//
//  73. Set Matrix Zeroes.h
//
//
//  Created by Jonny Kong on 2/29/16.
//
//

class Solution {
 public:
  void set(vector<vector<bool>>& a, int m, int n) {
    for (int i = 0; i < a.size(); ++i) a[i][n] = 0;
    for (int i = 0; i < a[0].size(); ++i) a[m][i] = 0;
  }

  void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<bool>> helper(matrix.size(),
                                vector<bool>(matrix[0].size(), 1));

    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) set(helper, i, j);
      }
    }

    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (!helper[i][j]) matrix[i][j] = 0;
      }
    }
  }
};