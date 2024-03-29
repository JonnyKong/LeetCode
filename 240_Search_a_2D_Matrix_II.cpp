class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = 0;
    int n = matrix[0].size() - 1;
    while (m < matrix.size() && n >= 0) {
      if (matrix[m][n] == target) return 1;
      if (matrix[m][n] > target)
        --n;
      else
        ++m;
    }
    return 0;
  }
};